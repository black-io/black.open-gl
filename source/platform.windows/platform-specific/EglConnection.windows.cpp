#include <black/open-gl.h>
#include <black/core/algorithms.h>

#include "rhi-connection/functions.dxgi.h"
#include "rhi-connection/functions.video-modes.h"
#include "rhi-connection/functions.strings.h"

#include "wgl/wgl-bindings.initialization.h"
#include "wgl/wgl-bindings.h"
#include "wgl/wgl-bindings.extensions.h"


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/RHI Connection";
}


	Black::PlainView<const ::DXGI_FORMAT> GlRhiConnection<Black::PlatformType::WindowsDesktop>::GetCompatibleDisplayFormats()
	{
		return { VIDEO_MODE_FORMATS };
	}

	const size32_t GlRhiConnection<Black::PlatformType::WindowsDesktop>::GetDisplayFormatBitrate( const ::DXGI_FORMAT format )
	{
		const size_t format_index = Black::GetItemIndex( VIDEO_MODE_FORMATS, format );
		CRET( format_index == Black::UNDEFINED_INDEX, 0 );

		return VIDEO_MODE_BIT_RATES[ format_index ];
	}

	const bool GlRhiConnection<Black::PlatformType::WindowsDesktop>::IsDisplayFormatCompatible( const ::DXGI_FORMAT format )
	{
		return Black::GetItemIndex( VIDEO_MODE_FORMATS, format ) != Black::UNDEFINED_INDEX;
	}

	::IDXGIFactory* GlRhiConnection<Black::PlatformType::WindowsDesktop>::QueryGenericFactory()
	{
		EnsureInitialized();
		return m_generic_factory.get();
	}

	::IDXGIFactory1* GlRhiConnection<Black::PlatformType::WindowsDesktop>::QueryExtendedFactory()
	{
		EnsureInitialized();
		return m_extended_factory.get();
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::Finalize()
	{
		CRET( !IsInitialized() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to finalize the connection." );

		m_extended_factory.reset();
		m_generic_factory.reset();

		BLACK_LOG_INFO( LOG_CHANNEL, "Connection is finalized." );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnumerateAdapters( AdapterInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the information about GPU adapters." );

		EnsureInitialized();
		EXPECTS_DEBUG( m_generic_factory != nullptr );

		::DXGI_ADAPTER_DESC		adapter_generic_desc{};
		::DXGI_ADAPTER_DESC1	adapter_extended_desc{};
		::DXGI_OUTPUT_DESC		default_output_desc{};

		::HRESULT	access_result	= S_OK;
		size32_t	adapter_index	= 0;
		for( ; SUCCEEDED( access_result ); ++adapter_index )
		{
			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to get the information for adapter #{}.", adapter_index );

			Black::ScopedComPointer<::IDXGIAdapter> adapter_interface{ QueryAdapterInterface( *m_generic_factory, adapter_index ) };
			CBRK( adapter_interface.IsEmpty() );

			Black::ScopedComPointer<::IDXGIOutput> default_output_interface{ QueryOutputInterface( *adapter_interface, 0 ) };
			CCON( default_output_interface.IsEmpty() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of adapter." );
			access_result = adapter_interface->GetDesc( &adapter_generic_desc );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for adapter #{}.", adapter_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of default output." );
			access_result = default_output_interface->GetDesc( &default_output_desc );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for default output of adapter #{}.", adapter_index );

			if( m_extended_factory == nullptr )
			{
				// Unsafe potentially, but, since the `DESC` and `DESC1` differs only by `Flags` field, this code looks more compact and obvious.
				Black::ZeroMemory( adapter_extended_desc );
				Black::CopyMemory( reinterpret_cast<::DXGI_ADAPTER_DESC&>( adapter_extended_desc ), adapter_generic_desc );
			}
			else
			{
				Black::ScopedComPointer<::IDXGIAdapter1> elevated_adapter_interface{ QueryAdapterV1Interface( *adapter_interface ) };
				EXPECTS( !elevated_adapter_interface.IsEmpty() );

				BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the full description of adapter." );
				access_result = elevated_adapter_interface->GetDesc1( &adapter_extended_desc );
				CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for adapter #{}.", adapter_index );
			}

			// Prepare the device path.
			std::wstring_view	wide_device_path{ default_output_desc.DeviceName };
			std::string			device_path{ ConvertWideString( wide_device_path ) };
			ENSURES_DEBUG( !device_path.empty() || wide_device_path.empty() );

			// Prepare the device name.
			std::wstring_view	wide_device_name{ adapter_extended_desc.Description };
			std::string			device_name{ ConvertWideString( wide_device_name ) };
			ENSURES_DEBUG( !device_name.empty() || wide_device_name.empty() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Consuming the information of adapter." );
			consumer.Consume( device_path, device_name, AdapterInfoConsumer::AdapterInfo{ adapter_extended_desc, adapter_index } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Information about {} adapters enumerated.", adapter_index );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnumerateDisplays( const Black::GlRhiAdapter& adapter, DisplayInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the information about displays of adapter #{}.", adapter.GetIndex() );

		EnsureInitialized();
		EXPECTS_DEBUG( m_generic_factory != nullptr );

		::HRESULT access_result = S_OK;

		Black::ScopedComPointer<::IDXGIAdapter> adapter_interface{ QueryAdapterInterface( *m_generic_factory, adapter.GetIndex() ) };
		CRETE( !adapter_interface, , LOG_CHANNEL, "Failed to enumerate displays for adapter #{}.", adapter.GetIndex() );

		::DXGI_OUTPUT_DESC	device_desc{};
		::MONITORINFOEXW	monitor_info{};
		::DISPLAY_DEVICEW	display_info{};

		size32_t output_index = 0;
		for( ; SUCCEEDED( access_result ); ++output_index )
		{
			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to get the information for display #{}.", output_index );

			Black::ScopedComPointer<::IDXGIOutput> output_interface{ QueryOutputInterface( *adapter_interface, output_index ) };
			CBRK( output_interface.IsEmpty() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of display." );
			access_result = output_interface->GetDesc( &device_desc );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get description for output display #{}, result: 0x{:08X}.", output_index, access_result );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the monitor information for display." );
			monitor_info.cbSize = size32_t( sizeof( monitor_info ) );
			const bool has_monitor_info	= ::GetMonitorInfoW( device_desc.Monitor, &monitor_info ) == TRUE;
			CCONW( !has_monitor_info, LOG_CHANNEL, "Failed to get the monitor info for display #{}.", output_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the device information for display." );
			display_info.cb = size32_t( sizeof( display_info ) );
			const bool has_display_info	= ::EnumDisplayDevicesW( monitor_info.szDevice, 0, &display_info, 0 ) == TRUE;
			CCONW( !has_display_info, LOG_CHANNEL, "Failed to get device info for display #{}.", output_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Detecting the default display mode." );
			::DXGI_MODE_DESC default_mode{ FindDefaultDisplayMode( *output_interface, monitor_info ) };

			// Prepare the device path.
			std::wstring_view	wide_device_path{ device_desc.DeviceName };
			std::string			device_path{ ConvertWideString( wide_device_path ) };
			ENSURES_DEBUG( !device_path.empty() || wide_device_path.empty() );

			// Prepare the device name.
			std::wstring_view	wide_device_name{ display_info.DeviceString };
			std::string			device_name{ ConvertWideString( wide_device_name ) };
			ENSURES_DEBUG( !device_name.empty() || wide_device_name.empty() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Consuming the information of display." );
			consumer.Consume(
				device_path,
				device_name,
				DisplayInfoConsumer::DisplayInfo{ device_desc, default_mode, monitor_info, display_info, adapter.GetIndex(), output_index }
			);
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Information about {} displays enumerated for adapter #{}.", output_index, adapter.GetIndex() );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnumerateVideoModes( const Black::GlRhiDisplay& display, VideoModeInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the video modes for display #{} of adapter #{}.", display.GetIndex(), display.GetAdapterIndex() );

		EnsureInitialized();
		EXPECTS_DEBUG( m_generic_factory != nullptr );

		::HRESULT access_result = S_OK;

		Black::ScopedComPointer<::IDXGIAdapter> adapter_interface{ QueryAdapterInterface( *m_generic_factory, display.GetAdapterIndex() ) };
		CRETE(
			!adapter_interface,
			,
			LOG_CHANNEL,
			"Failed to enumerate video modes for display #{} of adapter #{}.",
			display.GetIndex(),
			display.GetAdapterIndex()
		);

		Black::ScopedComPointer<::IDXGIOutput> output_interface{ QueryOutputInterface( *adapter_interface, display.GetIndex() ) };
		CRETE(
			!output_interface,
			,
			LOG_CHANNEL,
			"Failed to enumerate video modes for display #{} of adapter #{}.",
			display.GetIndex(),
			display.GetAdapterIndex()
		);

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the display video modes." );
		std::vector<::DXGI_MODE_DESC>	video_modes{ BuildVideoModeList( *output_interface ) };
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Sorting the collected video modes." );
		std::vector<::DXGI_MODE_DESC*>	sorted_video_modes{ SortVideoModes( video_modes ) };

		for( const ::DXGI_MODE_DESC* video_mode : sorted_video_modes )
		{
			CCON( video_mode->RefreshRate.Denominator == 0 );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Consuming the information of video mode." );
			consumer.Consume( VideoModeInfoConsumer::VideoModeInfo{ *video_mode } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Video modes enumerated for display #{} of adapter #{}.", display.GetIndex(), display.GetAdapterIndex() );
	}

	const bool GlRhiConnection<Black::PlatformType::WindowsDesktop>::ConnectDisplay( const Black::GlRhiAdapter& adapter_handle, Black::EglDisplay& target_display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to connect the display object to adapter #{}.", adapter_handle.GetIndex() );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the display can be connected." );
		CRETE( !target_display.Connect( adapter_handle, *m_generic_factory ), false, LOG_CHANNEL, "Failed to connect display object." );
		CRETE( !target_display.IsConnected(), false, LOG_CHANNEL, "Display object still disconnected after connection." );
		CRETE( !::Wgl::InitializeBindings( target_display ), false, LOG_CHANNEL, "Failed to initialize WGL for selected display." );

		target_display.UpdateConfigurations();

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display object successfully connected to adapter #{}.", adapter_handle.GetIndex() );
		return true;
	}

	const bool GlRhiConnection<Black::PlatformType::WindowsDesktop>::ConnectDisplay( const Black::GlRhiDisplay& display_handle, Black::EglDisplay& target_display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to connect the display object to display #{}.", display_handle.GetIndex() );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the display can be connected." );
		CRETE( !target_display.Connect( display_handle, *m_generic_factory ), false, LOG_CHANNEL, "Failed to connect display object." );
		CRETE( !target_display.IsConnected(), false, LOG_CHANNEL, "Display object still disconnected after connection." );
		CRETE( !::Wgl::InitializeBindings( target_display ), false, LOG_CHANNEL, "Failed to initialize WGL for selected display." );

		target_display.UpdateConfigurations();

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display object successfully connected to display #{}.", display_handle.GetIndex() );
		return true;
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnsureInitialized()
	{
		CRET( IsInitialized() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to create DXGI 1.1 factory." );
		::IDXGIFactory1*	extended_factory	= nullptr;
		::IDXGIFactory*		generic_factory		= nullptr;
		::HRESULT			result				= ::CreateDXGIFactory1( __uuidof( IDXGIFactory1 ), (void**)&extended_factory );

		if( SUCCEEDED( result ) && ( extended_factory != nullptr ) )
		{
			result = extended_factory->QueryInterface( &generic_factory );
			EXPECTS( SUCCEEDED( result ) );
			EXPECTS_DEBUG( generic_factory != nullptr );

			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection will use the DXGI 1.1 factory." );
			m_extended_factory.reset( extended_factory );
			m_generic_factory.reset( generic_factory );

			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection initialized." );
			return;
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "DXGI 1.1 factory construction result: 0x{:08X}", result );
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to create DXGI 1.0 factory." );

		result = CreateDXGIFactory( __uuidof( IDXGIFactory ), (void**)&generic_factory );

		if( SUCCEEDED( result ) && ( generic_factory != nullptr ) )
		{
			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection will use the DXGI 1.0 factory." );
			m_generic_factory.reset( generic_factory );

			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection initialized." );
			return;
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "DXGI 1.0 factory construction result: 0x{:08X}", result );
		BLACK_LOG_CRITICAL( LOG_CHANNEL, "Failed to create the handle for graphics connection." );
	}
}
}
}
}
