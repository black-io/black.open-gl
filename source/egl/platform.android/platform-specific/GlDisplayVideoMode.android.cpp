#include <black/open-gl/egl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
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
		: m_pixel_format{ std::get<4>( info ) }
		, m_index{ std::get<5>( info ) }
	{
		m_width			= std::get<0>( info );
		m_height		= std::get<1>( info );
		m_bit_rate		= std::get<2>( info );
		m_refresh_rate	= std::get<3>( info );
		m_aspect		= m_width / float( m_height );

		m_is_compatible		= true;
		m_allow_fullscreen	= true;
		m_allow_windowed	= false;
	}

	void GlDisplayVideoMode<Black::PlatformType::Android>::Swap( GlDisplayVideoMode<Black::PlatformType::Android>& other )
	{
		BasicGlDisplayVideoMode::Swap( other );
		Black::Swap( m_pixel_format, other.m_pixel_format );
		Black::Swap( m_index, other.m_index );
	}
}
}
}
}
}
