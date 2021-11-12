#include <black/open-gl.h>

#include "functions.pixel-formats.h"


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/RHI Connection";
}


	std::vector<::PIXELFORMATDESCRIPTOR> BuildPixelFormatList( ::IDXGIOutput& output )
	{
		std::vector<::PIXELFORMATDESCRIPTOR> pixel_formats;

		::DXGI_OUTPUT_DESC	output_description{};
		const ::HRESULT		access_result = output.GetDesc( &output_description );
		CRETE( FAILED( access_result ), pixel_formats, LOG_CHANNEL, "Failed to get display description, result - 0x{:08X}.", access_result );

		const ::HDC device_context = ::CreateDCW( nullptr, output_description.DeviceName, nullptr, nullptr );
		CRETE( device_context == nullptr, pixel_formats, LOG_CHANNEL, "Failed to create temporary device context." );

		// Guard will delete this device context on function end.
		const auto device_context_guard = Black::ScopeLeaveHandler{
			[device_context]()
			{
				if( ::DeleteDC( device_context ) != TRUE )
				{
					BLACK_LOG_WARNING( LOG_CHANNEL, "The deletion of temporary device context does not went properly." );
				}
			}
		};

		const int32_t max_pixel_format_index = ::DescribePixelFormat( device_context, 0, 0, nullptr );
		CRETE( max_pixel_format_index < 1, pixel_formats, LOG_CHANNEL, "Failed to describe pixel formats count." );

		pixel_formats.reserve( std::max( max_pixel_format_index - 1, 0 ) );
		for( int32_t index = 1; index <= max_pixel_format_index; ++index )
		{
			::PIXELFORMATDESCRIPTOR format_description{};
			const int32_t access_result = ::DescribePixelFormat( device_context, index, sizeof( format_description ), &format_description );
			CBRK( access_result == 0 );

			pixel_formats.emplace_back( format_description );
		}

		return pixel_formats;
	}

	std::vector<::PIXELFORMATDESCRIPTOR*> SortPixelFormats( Black::PlainView<::PIXELFORMATDESCRIPTOR> pixel_formats )
	{
		std::vector<::PIXELFORMATDESCRIPTOR*> sorted_pixel_formats;

		auto criteria = []( const ::PIXELFORMATDESCRIPTOR* left, const ::PIXELFORMATDESCRIPTOR* right ) -> const bool
		{
			{
				const size_t left_bit_rate	= left->cColorBits;
				const size_t right_bit_rate	= right->cColorBits;
				if( left_bit_rate != right_bit_rate )
				{
					// The more bit-rate, the best format is.
					return left_bit_rate > right_bit_rate;
				}
			}

			{
				const size_t left_depth		= left->cDepthBits;
				const size_t right_depth	= right->cDepthBits;
				if( left_depth != right_depth )
				{
					// The wider depth buffer, the better.
					return left_depth > right_depth;
				}
			}

			{
				const size_t left_stencil	= left->cStencilBits;
				const size_t right_stencil	= right->cStencilBits;
				if( left_stencil != right_stencil )
				{
					// The wider stencil buffer, the better.
					return left_stencil > right_stencil;
				}
			}


			return false;
		};

		sorted_pixel_formats.resize( pixel_formats.size() );
		std::transform( pixel_formats.begin(), pixel_formats.end(), sorted_pixel_formats.begin(), []( ::PIXELFORMATDESCRIPTOR& format ) { return &format; } );
		std::sort( sorted_pixel_formats.begin(), sorted_pixel_formats.end(), criteria );

		return sorted_pixel_formats;
	}
}
}
}
}
