#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiVideoMode::RhiVideoMode( const ConstructionInfo& info )
		: PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
