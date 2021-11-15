#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	GlDisplayHandle::GlDisplayHandle( const ConstructionInfo& info )
		: PlatformSpecific::GlDisplayHandle<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
