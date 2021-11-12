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

	//
	template< typename TFunction >
	inline std::vector<::PIXELFORMATDESCRIPTOR*> FilterPixelFormats( std::vector<::PIXELFORMATDESCRIPTOR*>&& source_formats, TFunction function )
	{
		std::vector<::PIXELFORMATDESCRIPTOR*> result{ std::move( source_formats ) };

		std::vector<::PIXELFORMATDESCRIPTOR*>::iterator write_head = result.begin();
		for( std::vector<::PIXELFORMATDESCRIPTOR*>::const_iterator read_head = result.begin(); read_head != result.end(); ++read_head )
		{
			CCON( !function( *read_head ) );
			if( read_head != write_head )
			{
				*write_head = *read_head;
			}

			++write_head;
		}

		if( write_head != result.end() )
		{
			result.erase( write_head, result.end() );
		}

		return result;
	};
}
}
}
}
