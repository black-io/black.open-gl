#include <black/open-gl.h>


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Display Handle";
}


	GlDisplayHandle<Black::PlatformType::WindowsDesktop>::GlDisplayHandle( const ConstructionInfo& info )
		: m_device_desc{ std::get<0>( info ) }
		, m_default_mode{ std::get<1>( info ) }
		, m_adapter_index{ std::get<2>( info ) }
		, m_index{ std::get<3>( info ) }
	{
		EXPECTS( ReadDesktopSettings() );
		EXPECTS( ReadMonitorInfo() );
		EXPECTS( ReadDisplayInfo() );
	}

	const bool GlDisplayHandle<Black::PlatformType::WindowsDesktop>::ReadDesktopSettings()
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the desktop settings for display." );

		m_desktop_settings.dmSize	= sizeof( m_desktop_settings );
		const bool is_succeeded		= ::EnumDisplaySettingsW( m_device_desc.DeviceName, ENUM_CURRENT_SETTINGS, &m_desktop_settings ) == TRUE;
		CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to get desktop settings." );

		return true;
	}

	const bool GlDisplayHandle<Black::PlatformType::WindowsDesktop>::ReadMonitorInfo()
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the monitor information for display." );

		m_monitor_info.cbSize	= size32_t( sizeof( m_monitor_info ) );
		const bool is_succeeded	= ::GetMonitorInfoW( m_device_desc.Monitor, &m_monitor_info ) == TRUE;
		CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to get the monitor info for display #{} of adapter #{}.", m_index, m_adapter_index );

		return true;
	}

	const bool GlDisplayHandle<Black::PlatformType::WindowsDesktop>::ReadDisplayInfo()
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the device information for display." );

		m_display_info.cb		= size32_t( sizeof( m_display_info ) );
		const bool is_succeeded	= ::EnumDisplayDevicesW( m_device_desc.DeviceName, 0, &m_display_info, 0 ) == TRUE;
		CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to get device info for display #{} of adapter #{}.", m_index, m_adapter_index );

		return true;
	}
}
}
}
}
