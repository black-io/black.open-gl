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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Adapter Handle";
}


	GlAdapterHandle::GlAdapterHandle( const ConstructionInfo& info )
		: PlatformSpecific::GlAdapterHandle<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
