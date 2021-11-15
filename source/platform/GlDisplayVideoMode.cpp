#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	GlRhiVideoMode::GlRhiVideoMode( const ConstructionInfo& info )
		: PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>{ info }
	{
	}

	void GlRhiVideoMode::Swap( GlRhiVideoMode& other )
	{
		using std::swap;

		PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::Swap( other );
	}
}
}
}
