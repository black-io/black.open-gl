#include <black/open-gl/egl.h>


#include "dxgi/functions.dxgi-video-modes.h"


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


	GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>::GlDisplayVideoMode( const ConstructionInfo& info )
		: m_mode_desc{ std::get<0>( info ) }
	{
		m_width			= m_mode_desc.Width;
		m_height		= m_mode_desc.Height;
		m_bit_rate		= GetDisplayFormatBitrate( m_mode_desc.Format );
		m_refresh_rate	= m_mode_desc.RefreshRate.Numerator / std::max( m_mode_desc.RefreshRate.Denominator, 1U );
		m_aspect		= m_width / float( m_height );

		m_is_compatible		= IsDisplayFormatCompatible( m_mode_desc.Format );
		m_allow_fullscreen	= true;
		m_allow_windowed	= true;
	}

	void GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>::Swap( GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>& other )
	{
		BasicGlDisplayVideoMode::Swap( other );
		Black::Swap( m_mode_desc, other.m_mode_desc );
	}
}
}
}
}
}
