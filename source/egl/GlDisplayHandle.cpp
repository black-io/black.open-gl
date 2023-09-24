#include <black/open-gl/egl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Display Handle";
}


	GlDisplayHandle::GlDisplayHandle( const ConstructionInfo& info )
		: PlatformSpecific::GlDisplayHandle<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
