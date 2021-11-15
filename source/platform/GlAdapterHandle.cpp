#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	GlRhiAdapter::GlRhiAdapter( const ConstructionInfo& info )
		: PlatformSpecific::GlRhiAdapter<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
