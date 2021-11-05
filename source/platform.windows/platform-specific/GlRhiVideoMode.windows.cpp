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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/RHI Video Mode";
}


	GlRhiVideoMode<Black::PlatformType::WindowsDesktop>::GlRhiVideoMode( const ConstructionInfo& info )
		: m_mode_desc{ std::get<0>( info ) }
	{
		m_width			= m_mode_desc.Width;
		m_height		= m_mode_desc.Height;
		m_bit_rate		= Black::GlRhiConnection::GetDisplayFormatBitrate( m_mode_desc.Format );
		m_refresh_rate	= m_mode_desc.RefreshRate.Numerator / std::max( m_mode_desc.RefreshRate.Denominator, 1U );
		m_aspect		= m_width / float( m_height );

		m_is_compatible		= Black::GlRhiConnection::IsDisplayFormatCompatible( m_mode_desc.Format );
		m_allow_fullscreen	= true;
		m_allow_windowed	= true;
	}

	void GlRhiVideoMode<Black::PlatformType::WindowsDesktop>::Swap( GlRhiVideoMode<Black::PlatformType::WindowsDesktop>& other )
	{
		using std::swap;

		BasicGlRhiVideoMode::Swap( other );
		swap( m_mode_desc, other.m_mode_desc );
	}
}
}
}
}
