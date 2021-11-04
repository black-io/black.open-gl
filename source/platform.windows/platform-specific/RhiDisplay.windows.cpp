#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	RhiDisplay<Black::PlatformType::WindowsDesktop>::RhiDisplay( const ConstructionArguments& arguments )
		: m_device_desc{ std::get<0>( arguments ) }
		, m_default_mode{ std::get<1>( arguments ) }
		, m_monitor_info{ std::get<2>( arguments ) }
		, m_display_info{ std::get<3>( arguments ) }
		, m_index{ std::get<4>( arguments ) }
	{
	}
}
}
}
}
