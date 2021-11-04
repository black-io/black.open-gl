#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiAdapter::RhiAdapter( const ConstructionArguments& arguments )
		: PlatformSpecific::RhiAdapter<Black::BUILD_PLATFORM>{ arguments }
	{
	}
}
}
}
