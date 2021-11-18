#include <black/open-gl.h>

#include "dxgi/functions.dxgi-pointters.h"
#include "dxgi/functions.dxgi-video-modes.h"

#include "wgl/bindings.wgl.h"
#include "wgl/bindings.wgl-extensions.h"
#include "wgl/functions.wgl-settings.h"
#include "wgl/functions.wgl-pixel-formats.h"


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Display";
}


	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::Connect( const Black::GlAdapterHandle& adapter_handle, ::IDXGIFactory& factory )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting to default display of adapter #{}.", adapter_handle.GetIndex() );

		CRETE( !AcquireAdapterInterface( adapter_handle.GetIndex(), factory ), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !AcquireOutputInterface( 0, factory ), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !CollectDisplayInfo(), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !CreateDeviceContext(), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Successfully connected to default display of adapter #{}.", adapter_handle.GetIndex() );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::Connect( const Black::GlDisplayHandle& display_handle, ::IDXGIFactory& factory )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting to display #{} of adapter #{}.", display_handle.GetIndex(), display_handle.GetAdapterIndex() );

		CRETE( !AcquireAdapterInterface( display_handle.GetAdapterIndex(), factory ), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !AcquireOutputInterface( display_handle.GetIndex(), factory ), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !CopyDisplayInfo( display_handle ), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !CreateDeviceContext(), false, LOG_CHANNEL, "Failed to connect to display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Successfully connected to display #{} of adapter #{}.", display_handle.GetIndex(), display_handle.GetAdapterIndex() );
		return true;
	}

	void EglDisplay<Black::PlatformType::WindowsDesktop>::EnsurePixelFormatSet( const Black::EglConfiguration& configuration ) const
	{
		CRET( m_is_pixel_format_set );
		CRETW( !IsConnected(), , LOG_CHANNEL, "Display is not connected." );

		m_is_pixel_format_set = ::SetPixelFormat( m_device_context, configuration.GetIndex(), &configuration.GetDescription() ) == TRUE;
		if( !m_is_pixel_format_set )
		{
			BLACK_LOG_DEBUG( LOG_CHANNEL, "Failed to set pixel format for device context, error: 0x{:08X}.", ::GetLastError() );
		}
	}

	void EglDisplay<Black::PlatformType::WindowsDesktop>::Finalize()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Starting the display finalization." );

		DeleteDeviceContext();
		m_output_interface.reset();
		m_adapter_v1_interface.reset();
		m_adapter_interface.reset();
		m_configurations.clear();

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display finalized properly." );
	}

	void EglDisplay<Black::PlatformType::WindowsDesktop>::UpdateConfigurations()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "List of EGL configurations will be updated." );

		CRETE( !IsConnected(), , LOG_CHANNEL, "Unable to get configurations for disconnected display." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the WGL pixel formats." );
		std::vector<::PIXELFORMATDESCRIPTOR> pixel_formats{ BuildPixelFormatList( *this ) };
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Sorting the collected pixel formats." );
		std::vector<::PIXELFORMATDESCRIPTOR*> sorted_pixel_formats{ SortPixelFormats( pixel_formats ) };

		m_configurations.clear();
		for( ::PIXELFORMATDESCRIPTOR* format : sorted_pixel_formats )
		{
			const size32_t format_index = size32_t( std::distance( pixel_formats.data(), format ) );
			m_configurations.emplace_back( Black::EglConfiguration::ConstructionInfo{ *format, ReadPixelBufferSettings( *this, format_index ), format_index } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL configurations updated." );
	}

	std::optional<Black::EglConfiguration> EglDisplay<Black::PlatformType::WindowsDesktop>::FindBestWindowConfiguration() const
	{
		std::vector<const Black::EglConfiguration*> configurations;
		configurations.resize( m_configurations.size() );
		std::transform( m_configurations.begin(), m_configurations.end(), configurations.begin(), []( const Black::EglConfiguration& item ) { return &item; } );

		auto configurations_begin	= configurations.begin();
		auto configurations_end		= configurations.end();

		// Keep only configurations that support OpenGL, allow drawing to window, provide bit-depth of desktop along with depth/stencil buffers.
		configurations_end = std::copy_if(
			configurations_begin,
			configurations_end,
			configurations_begin,
			[this]( const Black::EglConfiguration* configuration ) -> const bool
			{
				constexpr ::DWORD required_flags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
				const ::PIXELFORMATDESCRIPTOR& pixel_format = configuration->GetDescription();

				CRET( pixel_format.iLayerType != PFD_MAIN_PLANE, false );
				CRET( ( pixel_format.dwFlags & required_flags ) != required_flags, false );
				CRET( pixel_format.cColorBits != m_desktop_settings.dmBitsPerPel, false );

				return ( pixel_format.cDepthBits > 0 ) && ( pixel_format.cStencilBits > 0 );
			}
		);

		// Sort the configurations by complex criteria. The best match will be stored first.
		std::sort(
			configurations_begin,
			configurations_end,
			[]( const Black::EglConfiguration* left, const Black::EglConfiguration* right ) -> const bool
			{
				const ::PIXELFORMATDESCRIPTOR& left_format	= left->GetDescription();
				const ::PIXELFORMATDESCRIPTOR& right_format	= right->GetDescription();

				{
					const int32_t left_acceleration_flag	= left_format.dwFlags & PFD_DIRECT3D_ACCELERATED;
					const int32_t right_acceleration_flag	= right_format.dwFlags & PFD_DIRECT3D_ACCELERATED;
					if( left_acceleration_flag != right_acceleration_flag )
					{
						return left_acceleration_flag > right_acceleration_flag;
					}
				}

				{
					const int32_t left_buffering_flag	= left_format.dwFlags & PFD_DOUBLEBUFFER;
					const int32_t right_buffering_flag	= right_format.dwFlags & PFD_DOUBLEBUFFER;
					if( left_buffering_flag != right_buffering_flag )
					{
						return left_buffering_flag > right_buffering_flag;
					}
				}

				{
					const int32_t left_exchange_flag	= left_format.dwFlags & PFD_SWAP_EXCHANGE;
					const int32_t right_exchange_flag	= right_format.dwFlags & PFD_SWAP_EXCHANGE;
					if( left_exchange_flag != right_exchange_flag )
					{
						return left_exchange_flag > right_exchange_flag;
					}
				}

				if( left_format.cDepthBits != right_format.cDepthBits )
				{
					return left_format.cDepthBits > right_format.cDepthBits;
				}

				if( left_format.cStencilBits != right_format.cStencilBits )
				{
					return left_format.cStencilBits > right_format.cStencilBits;
				}

				if( left_format.cRedBits != right_format.cRedBits )
				{
					return left_format.cRedBits > right_format.cRedBits;
				}

				if( left_format.cBlueBits != right_format.cBlueBits )
				{
					return left_format.cBlueBits > right_format.cBlueBits;
				}

				if( left_format.cGreenBits != right_format.cGreenBits )
				{
					return left_format.cGreenBits > right_format.cGreenBits;
				}

				return left_format.cAlphaBits > right_format.cAlphaBits;
			}
		);

		return { *configurations.front() };
	}

	std::optional<Black::EglConfiguration> EglDisplay<Black::PlatformType::WindowsDesktop>::FindBestPixelBufferConfiguration(
		const Black::EglConfiguration& window_configuration
	) const
	{
		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();
		CRETE( !( extensions.has_wgl_ext_pbuffer || extensions.has_wgl_arb_pbuffer ), {}, LOG_CHANNEL, "Pixel buffers are not supported by GPU." );
		CRET( window_configuration.GetPixelBufferSettings().is_supported, { window_configuration } );

		std::vector<const Black::EglConfiguration*> configurations;
		configurations.resize( m_configurations.size() );
		std::transform( m_configurations.begin(), m_configurations.end(), configurations.begin(), []( const Black::EglConfiguration& item ) { return &item; } );

		auto configurations_begin	= configurations.begin();
		auto configurations_end		= configurations.end();

		// Keep only configurations that correlate with original configuration.
		configurations_end = std::copy_if(
			configurations_begin,
			configurations_end,
			configurations_begin,
			[&window_configuration, &extensions]( const Black::EglConfiguration* configuration ) -> const bool
			{
				constexpr ::DWORD required_flags = PFD_SUPPORT_OPENGL;
				const ::PIXELFORMATDESCRIPTOR& current_format = configuration->GetDescription();
				const ::PIXELFORMATDESCRIPTOR& origin_format = window_configuration.GetDescription();

				CRET( !configuration->GetPixelBufferSettings().is_supported, false );
				CRET( current_format.iLayerType != origin_format.iLayerType, false );
				CRET( ( current_format.dwFlags & required_flags ) == 0, false );
				CRET( current_format.cColorBits != origin_format.cColorBits, false );
				CRET( current_format.cRedBits != origin_format.cRedBits, false );
				CRET( current_format.cRedShift != origin_format.cRedShift, false );
				CRET( current_format.cGreenBits != origin_format.cGreenBits, false );
				CRET( current_format.cGreenShift != origin_format.cGreenShift, false );
				CRET( current_format.cBlueBits != origin_format.cBlueBits, false );
				CRET( current_format.cBlueShift != origin_format.cBlueShift, false );
				CRET( current_format.cAlphaBits != origin_format.cAlphaBits, false );
				CRET( current_format.cAlphaShift != origin_format.cAlphaShift, false );

				return true;
			}
		);

		// Sort the configurations by complex criteria. The best match will be stored first.
		std::sort(
			configurations_begin,
			configurations_end,
			[]( const Black::EglConfiguration* left, const Black::EglConfiguration* right ) -> const bool
			{
				const ::PIXELFORMATDESCRIPTOR& left_format	= left->GetDescription();
				const ::PIXELFORMATDESCRIPTOR& right_format	= right->GetDescription();

				{
					const int32_t left_acceleration_flag	= left_format.dwFlags & PFD_DIRECT3D_ACCELERATED;
					const int32_t right_acceleration_flag	= right_format.dwFlags & PFD_DIRECT3D_ACCELERATED;
					if( left_acceleration_flag != right_acceleration_flag )
					{
						return left_acceleration_flag > right_acceleration_flag;
					}
				}

				if( left_format.cRedBits != right_format.cRedBits )
				{
					return left_format.cRedBits > right_format.cRedBits;
				}

				if( left_format.cBlueBits != right_format.cBlueBits )
				{
					return left_format.cBlueBits > right_format.cBlueBits;
				}

				if( left_format.cGreenBits != right_format.cGreenBits )
				{
					return left_format.cGreenBits > right_format.cGreenBits;
				}

				return left_format.cAlphaBits > right_format.cAlphaBits;
			}
		);

		return { *configurations.front() };
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::AcquireAdapterInterface( size32_t adapter_index, ::IDXGIFactory& factory )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Capturing the interface of adapter #{}.", adapter_index );

		m_adapter_interface.reset( PlatformSpecific::QueryAdapterInterface( factory, adapter_index ) );
		CRETE( m_adapter_interface == nullptr, false, LOG_CHANNEL, "Failed to capture interface of adapter #{}.", adapter_index );

		m_adapter_v1_interface.reset( PlatformSpecific::QueryAdapterV1Interface( *m_adapter_interface ) );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Interface of adapter #{} captured successfully.", adapter_index );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::AcquireOutputInterface( size32_t output_index, ::IDXGIFactory& factory )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Capturing the interface of display #{}.", output_index );

		EXPECTS_DEBUG( m_adapter_interface != nullptr );

		m_output_interface.reset( PlatformSpecific::QueryOutputInterface( *m_adapter_interface, output_index ) );
		CRETE( m_output_interface == nullptr, false, LOG_CHANNEL, "Failed to capture interface of display #{}.", output_index );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Capturing the interface of display #{}.", output_index );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::CollectDisplayInfo()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Collecting the display information." );

		::HRESULT access_result = S_OK;

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of display." );
		access_result = m_output_interface->GetDesc( &m_device_desc );
		CRETE( FAILED( access_result ), false, LOG_CHANNEL, "Failed to read description of display, result: 0x{:08X}.", access_result );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Detecting the default display mode." );
		m_default_mode = FindDefaultDisplayMode( *m_output_interface, m_device_desc );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the desktop settings." );
		m_desktop_settings.dmSize	= sizeof( m_desktop_settings );
		const bool is_succeeded		= ::EnumDisplaySettingsW( m_device_desc.DeviceName, ENUM_CURRENT_SETTINGS, &m_desktop_settings ) == TRUE;
		CRETE( !is_succeeded, {}, LOG_CHANNEL, "Failed to read desktop settings." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the monitor information for display." );
		m_monitor_info.cbSize = size32_t( sizeof( m_monitor_info ) );
		const bool has_monitor_info	= ::GetMonitorInfoW( m_device_desc.Monitor, &m_monitor_info ) == TRUE;
		CRETE( !has_monitor_info, false, LOG_CHANNEL, "Failed to read the monitor information for display." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the device information for display." );
		m_display_info.cb = size32_t( sizeof( m_display_info ) );
		const bool has_display_info	= ::EnumDisplayDevicesW( m_device_desc.DeviceName, 0, &m_display_info, 0 ) == TRUE;
		CRETE( !has_display_info, false, LOG_CHANNEL, "Failed to read device info for display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display information collected successfully." );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::CopyDisplayInfo( const Black::GlDisplayHandle& display_handle )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Copying the display information." );

		Black::CopyMemory( m_device_desc, display_handle.GetDeviceDescription() );
		Black::CopyMemory( m_default_mode, display_handle.GetDefaultVideoMode() );
		Black::CopyMemory( m_desktop_settings, display_handle.GetDesktopSettings() );
		Black::CopyMemory( m_monitor_info, display_handle.GetDisplayMonitorInfo() );
		Black::CopyMemory( m_display_info, display_handle.GetDisplayInfo() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display information copied successfully." );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::CreateDeviceContext()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Creating the device context for display." );

		EXPECTS_DEBUG( m_device_context == nullptr );
		CRETE( m_output_interface == nullptr, false, LOG_CHANNEL, "Failed to create device context for display." );

		m_device_context = ::CreateDCW( nullptr, m_device_desc.DeviceName, nullptr, nullptr );
		CRETE( m_device_context == nullptr, false, LOG_CHANNEL, "Failed to create temporary device context." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Device context created successfully." );
		return true;
	}

	void EglDisplay<Black::PlatformType::WindowsDesktop>::DeleteDeviceContext()
	{
		CRET( m_device_context == nullptr );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Device context of display will be deleted." );
		if( ::DeleteDC( m_device_context ) == FALSE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Device context of display was not deleted properly. No errors provided." );
		}

		m_is_pixel_format_set	= false;
		m_device_context		= nullptr;
	}
}
}
}
}
