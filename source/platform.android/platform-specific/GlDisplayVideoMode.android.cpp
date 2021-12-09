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


	GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>::GlDisplayVideoMode( const ConstructionInfo& info )
		: m_index{ std::get<0>( info ) }
	{
	}

	void GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>::Swap( GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>& other )
	{
		using std::swap;

		BasicGlDisplayVideoMode::Swap( other );
		swap( m_index, other.m_index );
	}
}
}
}
}
