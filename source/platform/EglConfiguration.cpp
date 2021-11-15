#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Configuration";
}


	EglConfiguration::EglConfiguration( const ConstructionInfo& info )
		: PlatformSpecific::EglConfiguration<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
