#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	GlDisplayVideoMode::GlDisplayVideoMode( const ConstructionInfo& info )
		: PlatformSpecific::GlDisplayVideoMode<Black::BUILD_PLATFORM>{ info }
	{
	}

	void GlDisplayVideoMode::Swap( GlDisplayVideoMode& other )
	{
		using std::swap;

		PlatformSpecific::GlDisplayVideoMode<Black::BUILD_PLATFORM>::Swap( other );
	}
}
}
}
