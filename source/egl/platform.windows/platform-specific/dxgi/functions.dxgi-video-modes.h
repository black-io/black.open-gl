#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Find the display mode that is closest to desktop display mode so it can be named as default.
	::DXGI_MODE_DESC FindDefaultDisplayMode( ::IDXGIOutput& output, const ::DXGI_OUTPUT_DESC& output_desc );

	// Build the list of compatible video modes for given interface of output device.
	std::vector<::DXGI_MODE_DESC> BuildVideoModeList( ::IDXGIOutput& output );

	// Perform the sorting for video modes list.
	std::vector<::DXGI_MODE_DESC*> SortVideoModes( Black::PlainView<::DXGI_MODE_DESC> unsorted_video_modes );

	// Get the bit-rate for given display format. May return `0` in case the format is not compatible.
	const size32_t GetDisplayFormatBitrate( const ::DXGI_FORMAT format );

	// Whether the given display format is compatible for purposes of OpenGL.
	const bool IsDisplayFormatCompatible( const ::DXGI_FORMAT format );
}
}
}
}
