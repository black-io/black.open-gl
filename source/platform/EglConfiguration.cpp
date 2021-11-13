#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	EglConfiguration::EglConfiguration( const ConstructionInfo& info )
		: PlatformSpecific::EglConfiguration<Black::BUILD_PLATFORM>{ info }
	{
	}
}
}
}
