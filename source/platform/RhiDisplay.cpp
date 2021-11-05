#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiDisplay::RhiDisplay( const ConstructionInfo& info )
		: PlatformSpecific::RhiDisplay<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
