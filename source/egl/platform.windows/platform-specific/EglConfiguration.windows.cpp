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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Configuration";
}


	EglConfiguration<Black::PlatformType::WindowsDesktop>::EglConfiguration( const ConstructionInfo& info )
		: m_description{ std::get<0>( info ) }
		, m_pixel_buffer_settings{ std::get<1>( info ) }
		, m_index{ std::get<2>( info ) }
	{
	}
}
}
}
}
