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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/RHI Display";
}


	RhiDisplay<Black::PlatformType::WindowsDesktop>::RhiDisplay( const ConstructionInfo& info )
		: m_device_desc{ std::get<0>( info ) }
		, m_default_mode{ std::get<1>( info ) }
		, m_monitor_info{ std::get<2>( info ) }
		, m_display_info{ std::get<3>( info ) }
		, m_adapter_index{ std::get<4>( info ) }
		, m_index{ std::get<5>( info ) }
	{
	}
}
}
}
}
