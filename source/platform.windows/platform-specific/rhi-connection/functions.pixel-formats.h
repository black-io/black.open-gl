#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Build the list of available pixel formats.
	std::vector<::PIXELFORMATDESCRIPTOR> BuildPixelFormatList( ::IDXGIOutput& output );

	// Sort the pixel formats.
	std::vector<::PIXELFORMATDESCRIPTOR*> SortPixelFormats( Black::PlainView<::PIXELFORMATDESCRIPTOR> pixel_formats );
}
}
}
}
