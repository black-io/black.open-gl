#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiDisplay::RhiDisplay( const ConstructionArguments& arguments )
		: PlatformSpecific::RhiDisplay<Black::BUILD_PLATFORM>{ arguments }
	{
	}
}
}
}
