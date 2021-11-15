#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	GlRhiDisplay::GlRhiDisplay( const ConstructionInfo& info )
		: PlatformSpecific::GlRhiDisplay<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
