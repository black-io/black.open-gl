#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiVideoMode::RhiVideoMode( const ConstructionArguments& arguments )
		: PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>{ arguments }
	{
	}
}
}
}
