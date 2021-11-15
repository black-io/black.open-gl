#include <black/open-gl.h>
#include <black/core/algorithms.h>

#include "functions.dxgi-video-modes.h"


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/DXGI";

	// Suitable formats of video mode.
	constexpr ::DXGI_FORMAT VIDEO_MODE_FORMATS[] {
		DXGI_FORMAT_R10G10B10A2_UNORM, DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_B8G8R8X8_UNORM,
		DXGI_FORMAT_B4G4R4A4_UNORM, DXGI_FORMAT_B5G5R5A1_UNORM, DXGI_FORMAT_B5G6R5_UNORM
	};

	// Association of bit-rates for suitable formats of video mode.
	constexpr size32_t VIDEO_MODE_BIT_RATES[] {
		32, 32, 32, 32,
		16, 16, 16
	};

	static_assert( std::size( VIDEO_MODE_FORMATS ) == std::size( VIDEO_MODE_BIT_RATES ), "Number of video mode bit rates should be same as number of formats." );
}


	::DXGI_MODE_DESC FindDefaultDisplayMode( ::IDXGIOutput& output, const ::DXGI_OUTPUT_DESC& output_desc )
	{
		::DXGI_MODE_DESC default_display_mode{};

		::DEVMODEW device_mode{};
		device_mode.dmSize = sizeof( device_mode );
		const bool has_display_settings = ::EnumDisplaySettingsW( output_desc.DeviceName, ENUM_CURRENT_SETTINGS, &device_mode ) == TRUE;
		EXPECTS_DEBUG( has_display_settings );

		const bool has_refresh_rate = device_mode.dmDisplayFrequency > 1;

		::DXGI_MODE_DESC mode_desc{};
		mode_desc.Width						= device_mode.dmPelsWidth;
		mode_desc.Height					= device_mode.dmPelsHeight;
		mode_desc.RefreshRate.Numerator		= ( has_refresh_rate )? device_mode.dmDisplayFrequency : 0;
		mode_desc.RefreshRate.Denominator	= ( has_refresh_rate )? 1 : 0;
		mode_desc.Format					= ( device_mode.dmBitsPerPel == 64 )? DXGI_FORMAT_R16G16B16A16_UNORM : DXGI_FORMAT_R8G8B8A8_UNORM;
		mode_desc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		mode_desc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to detect the DXGI desktop settings for display." );
		const ::HRESULT access_result = output.FindClosestMatchingMode( &mode_desc, &default_display_mode, nullptr );
		EXPECTS( SUCCEEDED( access_result ) );

		return default_display_mode;
	}

	std::vector<::DXGI_MODE_DESC> BuildVideoModeList( ::IDXGIOutput& output )
	{
		constexpr uint32_t video_mode_flags = DXGI_ENUM_MODES_INTERLACED;

		std::vector<::DXGI_MODE_DESC> video_modes;

		::HRESULT access_result = S_OK;
		std::vector<::DXGI_MODE_DESC> current_modes_buffer;
		for( const ::DXGI_FORMAT video_mode_format : VIDEO_MODE_FORMATS )
		{
			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the video modes count for format {}", video_mode_format );
			size32_t modes_count = 0;
			access_result = output.GetDisplayModeList( video_mode_format, video_mode_flags, &modes_count, nullptr );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to read count of video modes for format {}.", video_mode_format );
			CCOND( modes_count == 0, LOG_CHANNEL, "No video modes found for format {}.", video_mode_format );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the video modes for format {}.", video_mode_format );
			current_modes_buffer.resize( modes_count );
			access_result = output.GetDisplayModeList( video_mode_format, video_mode_flags, &modes_count, current_modes_buffer.data() );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to read count of video modes for format {}.", video_mode_format );
			ENSURES_DEBUG( modes_count == current_modes_buffer.size() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "{} video modes included to selection.", current_modes_buffer.size() );
			video_modes.reserve( video_modes.size() + current_modes_buffer.size() );
			std::copy( current_modes_buffer.begin(), current_modes_buffer.end(), std::back_inserter( video_modes ) );
		}

		return video_modes;
	}

	std::vector<::DXGI_MODE_DESC*> SortVideoModes( Black::PlainView<::DXGI_MODE_DESC> unsorted_video_modes )
	{
		std::vector<::DXGI_MODE_DESC*> sorted_video_modes;

		auto criteria = []( const ::DXGI_MODE_DESC* left, const ::DXGI_MODE_DESC* right ) -> const bool
		{
			{
				const ::DXGI_FORMAT left_format		= left->Format;
				const ::DXGI_FORMAT right_format	= right->Format;
				if( left_format != right_format )
				{
					// The most first condition is the order of suitable format.
					return Black::GetItemIndex( VIDEO_MODE_FORMATS, left_format ) < Black::GetItemIndex( VIDEO_MODE_FORMATS, right_format );
				}
			}

			{
				const size32_t left_width	= left->Width;
				const size32_t right_width	= right->Width;
				// The wider - the better.
				CRET( left_width != right_width, left_width > right_width );
			}

			EXPECTS_DEBUG( left->RefreshRate.Denominator > 0 );
			EXPECTS_DEBUG( right->RefreshRate.Denominator > 0 );

			const size32_t left_frequency	= left->RefreshRate.Numerator / left->RefreshRate.Denominator;
			const size32_t right_frequency	= right->RefreshRate.Numerator / right->RefreshRate.Denominator;
			// The higher the presentation frequency - the better.
			return left_frequency > right_frequency;
		};

		sorted_video_modes.resize( unsorted_video_modes.size() );
		std::transform( unsorted_video_modes.begin(), unsorted_video_modes.end(), sorted_video_modes.begin(), []( ::DXGI_MODE_DESC& mode ) { return &mode; } );
		std::sort( sorted_video_modes.begin(), sorted_video_modes.end(), criteria );

		return sorted_video_modes;
	}

	const size32_t GetDisplayFormatBitrate( const ::DXGI_FORMAT format )
	{
		const size_t format_index = Black::GetItemIndex( VIDEO_MODE_FORMATS, format );
		CRET( format_index == Black::UNDEFINED_INDEX, 0 );

		return VIDEO_MODE_BIT_RATES[ format_index ];
	}

	const bool IsDisplayFormatCompatible( const ::DXGI_FORMAT format )
	{
		return Black::GetItemIndex( VIDEO_MODE_FORMATS, format ) != Black::UNDEFINED_INDEX;
	}
}
}
}
}
