#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Suitable formats of video mode.
	inline constexpr ::DXGI_FORMAT VIDEO_MODE_FORMATS[]
	{
		DXGI_FORMAT_R10G10B10A2_UNORM, DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_B8G8R8X8_UNORM,
		DXGI_FORMAT_B4G4R4A4_UNORM, DXGI_FORMAT_B5G5R5A1_UNORM, DXGI_FORMAT_B5G6R5_UNORM
	};

	// Association of bit-rates for suitable formats of video mode.
	inline constexpr size32_t VIDEO_MODE_BIT_RATES[]
	{
		32, 32, 32, 32,
		16, 16, 16
	};

	static_assert( std::size( VIDEO_MODE_FORMATS ) == std::size( VIDEO_MODE_BIT_RATES ), "Number of video mode bit rates should be same as number of formats." );


	// Find the display mode that is closest to desktop display mode so it can be named as default.
	::DXGI_MODE_DESC FindDefaultDisplayMode( ::IDXGIOutput& output, const ::MONITORINFOEXW& monitor_info );

	// Build the list of compatible video modes for given interface of output device.
	std::vector<::DXGI_MODE_DESC> BuildVideoModeList( ::IDXGIOutput& output );

	// Perform the sorting for video modes list.
	std::vector<::DXGI_MODE_DESC*> SortVideoModes( Black::PlainView<::DXGI_MODE_DESC> unsorted_video_modes );
}
}
}
}
