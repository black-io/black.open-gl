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

	void RhiVideoMode::Swap( RhiVideoMode& other )
	{
		using std::swap;

		PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::Swap( other );
	}
}
}
}
