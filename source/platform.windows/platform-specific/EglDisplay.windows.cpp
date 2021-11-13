#include <black/open-gl.h>

#include "rhi-connection/functions.dxgi.h"
#include "rhi-connection/functions.video-modes.h"

#include "rhi-connection/functions.pixel-formats.h"


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


	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::Connect( const Black::GlRhiAdapter& adapter, ::IDXGIFactory& factory )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting to default display of adapter #{}.", adapter.GetIndex() );

		CRETE( !AcquireAdapterInterface( adapter.GetIndex(), factory ), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !AcquireOutputInterface( 0, factory ), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !CollectDisplayInfo(), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !ReadDesktopSettings(), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );
		CRETE( !CreateDeviceContext(), false, LOG_CHANNEL, "Failed to connect to default display of adapter." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Successfully connected to default display of adapter #{}.", adapter.GetIndex() );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::Connect( const Black::GlRhiDisplay& display, ::IDXGIFactory& factory )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting to display #{} of adapter #{}.", display.GetIndex(), display.GetAdapterIndex() );

		CRETE( !AcquireAdapterInterface( display.GetAdapterIndex(), factory ), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !AcquireOutputInterface( display.GetIndex(), factory ), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !CopyDisplayInfo( display ), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !ReadDesktopSettings(), false, LOG_CHANNEL, "Failed to connect to display." );
		CRETE( !CreateDeviceContext(), false, LOG_CHANNEL, "Failed to connect to display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Successfully connected to display #{} of adapter #{}.", display.GetIndex(), display.GetAdapterIndex() );
		return true;
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
		std::vector<::PIXELFORMATDESCRIPTOR> pixel_formats{ BuildPixelFormatList( *m_output_interface ) };
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Sorting the collected pixel formats." );
		std::vector<::PIXELFORMATDESCRIPTOR*> sorted_pixel_formats{ SortPixelFormats( pixel_formats ) };

		m_configurations.clear();
		for( ::PIXELFORMATDESCRIPTOR* format : sorted_pixel_formats )
		{
			const size32_t format_index = size32_t( std::distance( pixel_formats.data(), format ) );
			m_configurations.emplace_back( Black::EglConfiguration::ConstructionInfo{ *format, format_index } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL configurations updated." );
	}

	EglDisplay<Black::PlatformType::WindowsDesktop>::~EglDisplay()
	{
		Finalize();
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
		CRETE( FAILED( access_result ), false, LOG_CHANNEL, "Failed to get description of display, result: 0x{:08X}.", access_result );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the monitor information for display." );
		m_monitor_info.cbSize = size32_t( sizeof( m_monitor_info ) );
		const bool has_monitor_info	= ::GetMonitorInfoW( m_device_desc.Monitor, &m_monitor_info ) == TRUE;
		CRETE( !has_monitor_info, false, LOG_CHANNEL, "Failed to get the monitor information for display." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the device information for display." );
		m_display_info.cb = size32_t( sizeof( m_display_info ) );
		const bool has_display_info	= ::EnumDisplayDevicesW( m_device_desc.DeviceName, 0, &m_display_info, 0 ) == TRUE;
		CRETE( !has_display_info, false, LOG_CHANNEL, "Failed to get device info for display." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Detecting the default display mode." );
		m_default_mode = FindDefaultDisplayMode( *m_output_interface, m_monitor_info );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display information collected successfully." );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::CopyDisplayInfo( const Black::GlRhiDisplay& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Copying the display information." );

		Black::CopyMemory( m_device_desc, display.GetDeviceDescription() );
		Black::CopyMemory( m_default_mode, display.GetDefaultVideoMode() );
		Black::CopyMemory( m_monitor_info, display.GetDisplayMonitorInfo() );
		Black::CopyMemory( m_display_info, display.GetDisplayInfo() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display information copied successfully." );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::WindowsDesktop>::ReadDesktopSettings()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Reading the desktop settings of display." );

		m_desktop_settings.dmSize	= sizeof( m_desktop_settings );
		const bool is_succeeded		= ::EnumDisplaySettingsW( m_device_desc.DeviceName, ENUM_CURRENT_SETTINGS, &m_desktop_settings ) == TRUE;
		CRETE( !is_succeeded, {}, LOG_CHANNEL, "Failed to get desktop settings." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display desktop settings successfully obtained." );
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
		if( ::DeleteDC( std::exchange( m_device_context, nullptr ) ) == FALSE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Device context of display was not deleted properly. No errors provided." );
		}
	}
}
}
}
}
