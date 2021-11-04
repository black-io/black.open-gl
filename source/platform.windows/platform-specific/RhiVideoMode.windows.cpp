#include <black/open-gl.h>
#include <black/core/algorithms.h>


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

	// Suitable formats of video mode.
	constexpr ::DXGI_FORMAT VIDEO_MODE_FORMATS[]
	{
		DXGI_FORMAT_R10G10B10A2_UNORM, DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_B8G8R8X8_UNORM,
		DXGI_FORMAT_B4G4R4A4_UNORM, DXGI_FORMAT_B5G5R5A1_UNORM, DXGI_FORMAT_B5G6R5_UNORM
	};

	// Association of bit-rates for suitable formats of video mode.
	const size32_t VIDEO_MODE_BIT_RATES[]
	{
		32, 32, 32, 32,
		16, 16, 16
	};
}


	RhiVideoMode<Black::PlatformType::WindowsDesktop>::RhiVideoMode( const ConstructionArguments& arguments )
		: m_mode_desc{ std::get<0>( arguments ) }
	{
		const size_t format_index		= Black::GetItemIndex( VIDEO_MODE_FORMATS, m_mode_desc.Format );
		const bool is_format_suitable	= format_index != Black::UNDEFINED_INDEX;

		m_width			= m_mode_desc.Width;
		m_height		= m_mode_desc.Height;
		m_bit_rate		= ( is_format_suitable )? VIDEO_MODE_BIT_RATES[ format_index ] : 0;
		m_refresh_rate	= m_mode_desc.RefreshRate.Numerator / std::max( m_mode_desc.RefreshRate.Denominator, 1U );
		m_aspect		= m_width / float( m_height );

		m_is_compatible		= is_format_suitable;
		m_allow_fullscreen	= true;
		m_allow_windowed	= true;
	}
}
}
}
}
