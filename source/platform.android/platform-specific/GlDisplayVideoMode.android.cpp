#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Video Mode";
}


	GlDisplayVideoMode<Black::PlatformType::Android>::GlDisplayVideoMode( const ConstructionInfo& info )
		: m_index{ std::get<0>( info ) }
	{
	}

	void GlDisplayVideoMode<Black::PlatformType::Android>::Swap( GlDisplayVideoMode<Black::PlatformType::Android>& other )
	{
		using std::swap;

		BasicGlDisplayVideoMode::Swap( other );
		swap( m_index, other.m_index );
	}
}
}
}
}
