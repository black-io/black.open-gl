#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiAdapter::RhiAdapter( const ConstructionInfo& info )
		: PlatformSpecific::RhiAdapter<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
