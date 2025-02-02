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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Video Mode";
}


	GlDisplayVideoMode::GlDisplayVideoMode( const ConstructionInfo& info )
		: PlatformSpecific::GlDisplayVideoMode<Black::BUILD_PLATFORM>{ info }
	{
	}

	void GlDisplayVideoMode::Swap( GlDisplayVideoMode& other )
	{
		PlatformSpecific::GlDisplayVideoMode<Black::BUILD_PLATFORM>::Swap( other );
	}
}
}
}
