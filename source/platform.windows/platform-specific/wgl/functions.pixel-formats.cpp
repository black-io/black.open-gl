#include <black/open-gl.h>

#include "functions.pixel-formats.h"

#include "bindings.wgl.h"
#include "bindings.wgl-extensions.h"
#include "functions.settings.h"


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/WGL";

	// Full list of requested attributes for pixel format description.
	// Sadly, `WGL_EXT_pixel_format` does not allows this array to be constant.
	int32_t FORMAT_ATTRIBUTE_NAMES_EXT[] {
		::Wgl::DRAW_TO_WINDOW_EXT,
		::Wgl::DRAW_TO_BITMAP_EXT,
		::Wgl::ACCELERATION_EXT,
		::Wgl::NEED_PALETTE_EXT,
		::Wgl::NEED_SYSTEM_PALETTE_EXT,
		::Wgl::SWAP_LAYER_BUFFERS_EXT,
		::Wgl::SWAP_METHOD_EXT,
		::Wgl::NUMBER_OVERLAYS_EXT,
		::Wgl::NUMBER_UNDERLAYS_EXT,
		::Wgl::TRANSPARENT_EXT,
		::Wgl::TRANSPARENT_VALUE_EXT,
		::Wgl::SHARE_DEPTH_EXT,
		::Wgl::SHARE_STENCIL_EXT,
		::Wgl::SHARE_ACCUM_EXT,
		::Wgl::SUPPORT_GDI_EXT,
		::Wgl::SUPPORT_OPENGL_EXT,
		::Wgl::DOUBLE_BUFFER_EXT,
		::Wgl::STEREO_EXT,
		::Wgl::PIXEL_TYPE_EXT,
		::Wgl::COLOR_BITS_EXT,
		::Wgl::RED_BITS_EXT,
		::Wgl::RED_SHIFT_EXT,
		::Wgl::GREEN_BITS_EXT,
		::Wgl::GREEN_SHIFT_EXT,
		::Wgl::BLUE_BITS_EXT,
		::Wgl::BLUE_SHIFT_EXT,
		::Wgl::ALPHA_BITS_EXT,
		::Wgl::ALPHA_SHIFT_EXT,
		::Wgl::ACCUM_BITS_EXT,
		::Wgl::ACCUM_RED_BITS_EXT,
		::Wgl::ACCUM_GREEN_BITS_EXT,
		::Wgl::ACCUM_BLUE_BITS_EXT,
		::Wgl::ACCUM_ALPHA_BITS_EXT,
		::Wgl::DEPTH_BITS_EXT,
		::Wgl::STENCIL_BITS_EXT,
		::Wgl::AUX_BUFFERS_EXT,
	};

	// Full list of requested attributes for pixel format description.
	const int32_t FORMAT_ATTRIBUTE_NAMES_ARB[] {
		::Wgl::DRAW_TO_WINDOW_ARB,
		::Wgl::DRAW_TO_BITMAP_ARB,
		::Wgl::ACCELERATION_ARB,
		::Wgl::NEED_PALETTE_ARB,
		::Wgl::NEED_SYSTEM_PALETTE_ARB,
		::Wgl::SWAP_LAYER_BUFFERS_ARB,
		::Wgl::SWAP_METHOD_ARB,
		::Wgl::NUMBER_OVERLAYS_ARB,
		::Wgl::NUMBER_UNDERLAYS_ARB,
		::Wgl::TRANSPARENT_ARB,
		::Wgl::TRANSPARENT_RED_VALUE_ARB,
		::Wgl::TRANSPARENT_GREEN_VALUE_ARB,
		::Wgl::TRANSPARENT_BLUE_VALUE_ARB,
		::Wgl::TRANSPARENT_ALPHA_VALUE_ARB,
		::Wgl::TRANSPARENT_INDEX_VALUE_ARB,
		::Wgl::SHARE_DEPTH_ARB,
		::Wgl::SHARE_STENCIL_ARB,
		::Wgl::SHARE_ACCUM_ARB,
		::Wgl::SUPPORT_GDI_ARB,
		::Wgl::SUPPORT_OPENGL_ARB,
		::Wgl::DOUBLE_BUFFER_ARB,
		::Wgl::STEREO_ARB,
		::Wgl::PIXEL_TYPE_ARB,
		::Wgl::COLOR_BITS_ARB,
		::Wgl::RED_BITS_ARB,
		::Wgl::RED_SHIFT_ARB,
		::Wgl::GREEN_BITS_ARB,
		::Wgl::GREEN_SHIFT_ARB,
		::Wgl::BLUE_BITS_ARB,
		::Wgl::BLUE_SHIFT_ARB,
		::Wgl::ALPHA_BITS_ARB,
		::Wgl::ALPHA_SHIFT_ARB,
		::Wgl::ACCUM_BITS_ARB,
		::Wgl::ACCUM_RED_BITS_ARB,
		::Wgl::ACCUM_GREEN_BITS_ARB,
		::Wgl::ACCUM_BLUE_BITS_ARB,
		::Wgl::ACCUM_ALPHA_BITS_ARB,
		::Wgl::DEPTH_BITS_ARB,
		::Wgl::STENCIL_BITS_ARB,
		::Wgl::AUX_BUFFERS_ARB,
	};


	// Retrieve the maximum index of valid pixel format. `0` result means the pixel formats can't be retrieved for given device context.
	const int32_t GetMaximumFormatIndex( const ::HDC device_context )
	{
		int32_t result = 0;

		if( ::Wgl::GetExtensionsState().has_wgl_ext_pixel_format )
		{
			int32_t attribute_name = ::Wgl::NUMBER_PIXEL_FORMATS_EXT;
			const bool is_succeeded = ::Wgl::get_pixel_format_attribiv_ext( device_context, 0, PFD_MAIN_PLANE, 1, &attribute_name, &result ) == TRUE;
			CRETE( !is_succeeded, 0, LOG_CHANNEL, "Failed to retrieve number of pixel formats." );

			// Max format number will be one next from formats count.
			++result;
		}
		else if( ::Wgl::GetExtensionsState().has_wgl_arb_pixel_format )
		{
			const int32_t attribute_name = ::Wgl::NUMBER_PIXEL_FORMATS_ARB;
			const bool is_succeeded = ::Wgl::get_pixel_format_attribiv_arb( device_context, 0, PFD_MAIN_PLANE, 1, &attribute_name, &result ) == TRUE;
			CRETE( !is_succeeded, 0, LOG_CHANNEL, "Failed to retrieve number of pixel formats." );

			// Max format number will be one next from formats count.
			++result;
		}
		else
		{
			result = ::Wgl::describe_pixel_format( device_context, 0, 0, nullptr );
		}

		return result;
	}

	// Read the pixel format description.
	const bool ReadPixelFormat( const ::HDC device_context, int32_t format_index, ::PIXELFORMATDESCRIPTOR& description )
	{
		if( ::Wgl::GetExtensionsState().has_wgl_ext_pixel_format )
		{
			constexpr size_t attributes_count = std::size( FORMAT_ATTRIBUTE_NAMES_EXT );
			int32_t values[ attributes_count ]{};
			const bool is_succeeded = ::Wgl::get_pixel_format_attribiv_ext(
				device_context,
				format_index,
				PFD_MAIN_PLANE,
				::UINT( attributes_count ),
				FORMAT_ATTRIBUTE_NAMES_EXT,
				values
			);
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to read pixel format description, error: 0x{:08X}.", ::GetLastError() );

			Black::ZeroMemory( description );
			description.nSize		= sizeof( description );
			description.nVersion	= 1;
			for( size32_t index = 0; index < attributes_count; ++index )
			{
				switch( FORMAT_ATTRIBUTE_NAMES_EXT[ index ] )
				{
				case ::Wgl::DRAW_TO_WINDOW_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_DRAW_TO_WINDOW );
					break;
				case ::Wgl::DRAW_TO_BITMAP_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_DRAW_TO_BITMAP );
					break;
				case ::Wgl::ACCELERATION_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::NO_ACCELERATION_EXT )? PFD_GENERIC_FORMAT : 0 );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::GENERIC_ACCELERATION_EXT )? PFD_GENERIC_ACCELERATED : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::FULL_ACCELERATION_EXT )? PFD_DIRECT3D_ACCELERATED : 0  );
					break;
				case ::Wgl::NEED_PALETTE_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_NEED_PALETTE );
					break;
				case ::Wgl::NEED_SYSTEM_PALETTE_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_NEED_SYSTEM_PALETTE );
					break;
				case ::Wgl::SWAP_LAYER_BUFFERS_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_SWAP_LAYER_BUFFERS );
					break;
				case ::Wgl::SWAP_METHOD_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::SWAP_EXCHANGE_EXT )? PFD_SWAP_EXCHANGE : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::SWAP_COPY_EXT )? PFD_SWAP_COPY : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::SWAP_UNDEFINED_EXT )? PFD_SWAP_COPY : 0  );
					break;
				case ::Wgl::NUMBER_OVERLAYS_EXT:
					description.bReserved = description.bReserved | ::BYTE( values[ index ] & 0xFU );
					break;
				case ::Wgl::NUMBER_UNDERLAYS_EXT:
					description.bReserved = description.bReserved | ::BYTE( values[ index ] & 0xFU ) >> 4;
					break;
				case ::Wgl::TRANSPARENT_EXT:
					break;
				case ::Wgl::TRANSPARENT_VALUE_EXT:
					description.dwVisibleMask = ::DWORD( values[ index ] );
					break;
				case ::Wgl::SHARE_DEPTH_EXT:
					break;
				case ::Wgl::SHARE_STENCIL_EXT:
					break;
				case ::Wgl::SHARE_ACCUM_EXT:
					break;
				case ::Wgl::SUPPORT_GDI_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_SUPPORT_GDI );
					break;
				case ::Wgl::SUPPORT_OPENGL_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_SUPPORT_OPENGL );
					break;
				case ::Wgl::DOUBLE_BUFFER_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_DOUBLEBUFFER );
					break;
				case ::Wgl::STEREO_EXT:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_STEREO );
					break;
				case ::Wgl::PIXEL_TYPE_EXT:
					switch( values[ index ] )
					{
					case ::Wgl::TYPE_COLORINDEX_EXT:
						description.iPixelType = PFD_TYPE_COLORINDEX;
						break;
					case ::Wgl::TYPE_RGBA_EXT:
						description.iPixelType = PFD_TYPE_RGBA;
						break;
					default:
						break;
					}
					break;
				case ::Wgl::COLOR_BITS_EXT:
					description.cColorBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::RED_BITS_EXT:
					description.cRedBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::RED_SHIFT_EXT:
					description.cRedShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::GREEN_BITS_EXT:
					description.cGreenBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::GREEN_SHIFT_EXT:
					description.cGreenShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::BLUE_BITS_EXT:
					description.cBlueBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::BLUE_SHIFT_EXT:
					description.cBlueShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ALPHA_BITS_EXT:
					description.cAlphaBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ALPHA_SHIFT_EXT:
					description.cAlphaShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_BITS_EXT:
					description.cAccumBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_RED_BITS_EXT:
					description.cAccumRedBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_GREEN_BITS_EXT:
					description.cAccumGreenBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_BLUE_BITS_EXT:
					description.cAccumBlueBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_ALPHA_BITS_EXT:
					description.cAccumAlphaBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::DEPTH_BITS_EXT:
					description.cDepthBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::STENCIL_BITS_EXT:
					description.cStencilBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::AUX_BUFFERS_EXT:
					description.cAuxBuffers = ::BYTE( values[ index ] );
					break;
				default:
					break;
				}
			}
		}
		else if( ::Wgl::GetExtensionsState().has_wgl_arb_pixel_format )
		{
			constexpr size_t attributes_count = std::size( FORMAT_ATTRIBUTE_NAMES_ARB );
			int32_t values[ attributes_count ]{};
			const bool is_succeeded = ::Wgl::get_pixel_format_attribiv_arb(
				device_context,
				format_index,
				PFD_MAIN_PLANE,
				::UINT( attributes_count ),
				FORMAT_ATTRIBUTE_NAMES_ARB,
				values
			);
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to read pixel format description, error: 0x{:08X}.", ::GetLastError() );

			Black::ZeroMemory( description );
			description.nSize		= sizeof( description );
			description.nVersion	= 1;
			for( size32_t index = 0; index < attributes_count; ++index )
			{
				switch( FORMAT_ATTRIBUTE_NAMES_ARB[ index ] )
				{
				case ::Wgl::DRAW_TO_WINDOW_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_DRAW_TO_WINDOW );
					break;
				case ::Wgl::DRAW_TO_BITMAP_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_DRAW_TO_BITMAP );
					break;
				case ::Wgl::ACCELERATION_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::NO_ACCELERATION_ARB )? PFD_GENERIC_FORMAT : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::GENERIC_ACCELERATION_ARB )? PFD_GENERIC_ACCELERATED : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::FULL_ACCELERATION_ARB )? PFD_DIRECT3D_ACCELERATED : 0  );
					break;
				case ::Wgl::NEED_PALETTE_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_NEED_PALETTE );
					break;
				case ::Wgl::NEED_SYSTEM_PALETTE_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_NEED_SYSTEM_PALETTE );
					break;
				case ::Wgl::SWAP_LAYER_BUFFERS_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_SWAP_LAYER_BUFFERS );
					break;
				case ::Wgl::SWAP_METHOD_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::SWAP_EXCHANGE_ARB )? PFD_SWAP_EXCHANGE : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::SWAP_COPY_ARB )? PFD_SWAP_COPY : 0  );
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == ::Wgl::SWAP_UNDEFINED_ARB )? PFD_SWAP_COPY : 0  );
					break;
				case ::Wgl::NUMBER_OVERLAYS_ARB:
					description.bReserved = description.bReserved | ::BYTE( values[ index ] & 0xFU );
					break;
				case ::Wgl::NUMBER_UNDERLAYS_ARB:
					description.bReserved = description.bReserved | ::BYTE( values[ index ] & 0xFU ) >> 4;
					break;
				case ::Wgl::TRANSPARENT_ARB:
					break;
				case ::Wgl::TRANSPARENT_RED_VALUE_ARB:
					break;
				case ::Wgl::TRANSPARENT_GREEN_VALUE_ARB:
					break;
				case ::Wgl::TRANSPARENT_BLUE_VALUE_ARB:
					break;
				case ::Wgl::TRANSPARENT_ALPHA_VALUE_ARB:
					break;
				case ::Wgl::TRANSPARENT_INDEX_VALUE_ARB:
					break;
				case ::Wgl::SHARE_DEPTH_ARB:
					break;
				case ::Wgl::SHARE_STENCIL_ARB:
					break;
				case ::Wgl::SHARE_ACCUM_ARB:
					break;
				case ::Wgl::SUPPORT_GDI_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_SUPPORT_GDI );
					break;
				case ::Wgl::SUPPORT_OPENGL_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_SUPPORT_OPENGL );
					break;
				case ::Wgl::DOUBLE_BUFFER_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_DOUBLEBUFFER );
					break;
				case ::Wgl::STEREO_ARB:
					description.dwFlags = description.dwFlags | ::DWORD( ( values[ index ] == 0 )? 0 : PFD_STEREO );
					break;
				case ::Wgl::PIXEL_TYPE_ARB:
					switch( values[ index ] )
					{
					case ::Wgl::TYPE_COLORINDEX_ARB:
						description.iPixelType = PFD_TYPE_COLORINDEX;
						break;
					case ::Wgl::TYPE_RGBA_ARB:
						description.iPixelType = PFD_TYPE_RGBA;
						break;
					default:
						break;
					}
					break;
				case ::Wgl::COLOR_BITS_ARB:
					description.cColorBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::RED_BITS_ARB:
					description.cRedBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::RED_SHIFT_ARB:
					description.cRedShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::GREEN_BITS_ARB:
					description.cGreenBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::GREEN_SHIFT_ARB:
					description.cGreenShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::BLUE_BITS_ARB:
					description.cBlueBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::BLUE_SHIFT_ARB:
					description.cBlueShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ALPHA_BITS_ARB:
					description.cAlphaBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ALPHA_SHIFT_ARB:
					description.cAlphaShift = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_BITS_ARB:
					description.cAccumBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_RED_BITS_ARB:
					description.cAccumRedBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_GREEN_BITS_ARB:
					description.cAccumGreenBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_BLUE_BITS_ARB:
					description.cAccumBlueBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::ACCUM_ALPHA_BITS_ARB:
					description.cAccumAlphaBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::DEPTH_BITS_ARB:
					description.cDepthBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::STENCIL_BITS_ARB:
					description.cStencilBits = ::BYTE( values[ index ] );
					break;
				case ::Wgl::AUX_BUFFERS_ARB:
					description.cAuxBuffers = ::BYTE( values[ index ] );
					break;
				default:
					break;
				}
			}
		}
		else
		{
			const int32_t access_result = ::Wgl::describe_pixel_format( device_context, format_index, sizeof( description ), &description );
			CRETE( access_result == 0, false, LOG_CHANNEL, "Failed to read pixel format." );
		}

		return true;
	}
}


	std::vector<::PIXELFORMATDESCRIPTOR> BuildPixelFormatList( const EglDisplay<Black::PlatformType::WindowsDesktop>& display )
	{
		std::vector<::PIXELFORMATDESCRIPTOR> pixel_formats;

		const ::HDC device_context = display.GetDeviceContext();
		const int32_t max_pixel_format_index = GetMaximumFormatIndex( device_context );
		CRETE( max_pixel_format_index < 1, pixel_formats, LOG_CHANNEL, "Failed to describe pixel formats count." );

		pixel_formats.reserve( std::max( max_pixel_format_index - 1, 0 ) );
		for( int32_t index = 1; index <= max_pixel_format_index; ++index )
		{
			::PIXELFORMATDESCRIPTOR format_description{};
			const bool is_succeeded = ReadPixelFormat( device_context, index, format_description );
			CCON( !is_succeeded );

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

	Internal::PixelBufferSettings ReadPixelBufferSettings( const EglDisplay<Black::PlatformType::WindowsDesktop>& display, const int32_t format_index )
	{
		Internal::PixelBufferSettings result;

		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();

		if( extensions.has_wgl_ext_pbuffer )
		{
			EXPECTS_DEBUG( extensions.has_wgl_ext_pixel_format );

			int32_t attribute_name	= ::Wgl::DRAW_TO_PBUFFER_EXT;
			int32_t value			= 0;
			const bool is_succeeded	= ::Wgl::get_pixel_format_attribiv_ext(
				display.GetDeviceContext(),
				format_index,
				PFD_MAIN_PLANE,
				1,
				&attribute_name,
				&value
			) == TRUE;
			CRETE( !is_succeeded, result, LOG_CHANNEL, "Failed to check the support of pixel buffers for pixel format." );
			result.is_supported = value == TRUE;
		}
		else if( extensions.has_wgl_arb_pbuffer )
		{
			EXPECTS_DEBUG( extensions.has_wgl_arb_pixel_format );

			const int32_t attribute_name	= ::Wgl::DRAW_TO_PBUFFER_ARB;
			int32_t value					= 0;
			const bool is_succeeded			= ::Wgl::get_pixel_format_attribiv_arb(
				display.GetDeviceContext(),
				format_index,
				PFD_MAIN_PLANE,
				1,
				&attribute_name,
				&value
			) == TRUE;
			CRETE( !is_succeeded, result, LOG_CHANNEL, "Failed to check the support of pixel buffers for pixel format." );
			result.is_supported = value == TRUE;
		}
		else
		{
			return result;
		}

		CRET( !result.is_supported, result );

		if( extensions.has_wgl_ext_pbuffer )
		{
			int32_t attribute_names[] {
				::Wgl::MAX_PBUFFER_WIDTH_EXT,
				::Wgl::MAX_PBUFFER_HEIGHT_EXT,
				::Wgl::MAX_PBUFFER_PIXELS_EXT,
				::Wgl::OPTIMAL_PBUFFER_WIDTH_EXT,
				::Wgl::OPTIMAL_PBUFFER_HEIGHT_EXT,
			};

			::Wgl::get_pixel_format_attribiv_ext(
				display.GetDeviceContext(),
				format_index,
				PFD_MAIN_PLANE,
				::UINT( std::size( attribute_names ) ),
				attribute_names,
				&result.maximum_width
			);
		}
		else if( extensions.has_wgl_arb_pbuffer )
		{
			const int32_t attribute_names[] {
				::Wgl::MAX_PBUFFER_WIDTH_ARB,
				::Wgl::MAX_PBUFFER_HEIGHT_ARB,
				::Wgl::MAX_PBUFFER_PIXELS_ARB,
			};

			::Wgl::get_pixel_format_attribiv_arb(
				display.GetDeviceContext(),
				format_index,
				PFD_MAIN_PLANE,
				::UINT( std::size( attribute_names ) ),
				attribute_names,
				&result.maximum_width
			);
		}

		return result;
	}
}
}
}
}
