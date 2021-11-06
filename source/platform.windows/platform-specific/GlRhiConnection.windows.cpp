#include <black/open-gl.h>
#include <black/core/algorithms.h>

#include <stringapiset.h>


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

	// Suitable formats of video mode.
	constexpr ::DXGI_FORMAT VIDEO_MODE_FORMATS[]
	{
		DXGI_FORMAT_R10G10B10A2_UNORM, DXGI_FORMAT_R8G8B8A8_UNORM, DXGI_FORMAT_B8G8R8A8_UNORM, DXGI_FORMAT_B8G8R8X8_UNORM,
		DXGI_FORMAT_B4G4R4A4_UNORM, DXGI_FORMAT_B5G5R5A1_UNORM, DXGI_FORMAT_B5G6R5_UNORM
	};

	// Association of bit-rates for suitable formats of video mode.
	constexpr size32_t VIDEO_MODE_BIT_RATES[]
	{
		32, 32, 32, 32,
		16, 16, 16
	};

	static_assert( std::size( VIDEO_MODE_FORMATS ) == std::size( VIDEO_MODE_BIT_RATES ), "Number of video mode bit rates should be same as number of formats." );


	// Find the display mode that is closest to desktop display mode so it can be named as default.
	::DXGI_MODE_DESC FindDefaultDisplayMode( ::IDXGIOutput& output, const ::MONITORINFOEXW& monitor_info )
	{
		::DXGI_MODE_DESC default_display_mode{};

		::DEVMODEW device_mode{};
		device_mode.dmSize = sizeof( device_mode );
		const bool has_display_settings = ::EnumDisplaySettingsW( monitor_info.szDevice, ENUM_CURRENT_SETTINGS, &device_mode ) == TRUE;
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

	// Build the list of compatible video modes for given interface of output device.
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

	// Perform the sorting for video modes list.
	std::vector<::DXGI_MODE_DESC*> SortVideoModes( Black::PlainView<::DXGI_MODE_DESC> unsorted_video_modes )
	{
		std::vector<::DXGI_MODE_DESC*> sorted_video_modes;

		auto criteria = []( const ::DXGI_MODE_DESC* left, const ::DXGI_MODE_DESC* right ) -> bool
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

	// Wrap for WinAPI function that hides the constant arguments.
	inline const size_t WideCharToMultiByte( const Black::PlainView<char> output_buffer, const std::wstring_view input_buffer )
	{
		return ::WideCharToMultiByte(
			CP_UTF8,
			WC_NO_BEST_FIT_CHARS,
			input_buffer.data(),
			int32_t( input_buffer.size() ),
			output_buffer.data(),
			int32_t( output_buffer.size() ),
			nullptr,
			nullptr
		);
	}

	// Perform the conversion from wide string to multi-byte one.
	inline std::string ConvertWideString( const std::wstring_view wide_string )
	{
		std::string result;

		const size_t result_length = WideCharToMultiByte( {}, wide_string );
		result.resize( result_length, 'X' );
		const size_t converted_length = WideCharToMultiByte( { result.data(), result_length }, wide_string );

		EXPECTS_DEBUG( converted_length > 0 );
		EXPECTS_DEBUG( converted_length == result_length );

		return result;
	}
}


	Black::PlainView<const ::DXGI_FORMAT> GlRhiConnection<Black::PlatformType::WindowsDesktop>::GetCompatibleDisplayFormats()
	{
		return { VIDEO_MODE_FORMATS };
	}

	const size32_t GlRhiConnection<Black::PlatformType::WindowsDesktop>::GetDisplayFormatBitrate( const ::DXGI_FORMAT format )
	{
		const size_t format_index = Black::GetItemIndex( VIDEO_MODE_FORMATS, format );
		CRET( format_index == Black::UNDEFINED_INDEX, 0 );

		return VIDEO_MODE_BIT_RATES[ format_index ];
	}

	const bool GlRhiConnection<Black::PlatformType::WindowsDesktop>::IsDisplayFormatCompatible( const ::DXGI_FORMAT format )
	{
		return Black::GetItemIndex( VIDEO_MODE_FORMATS, format ) != Black::UNDEFINED_INDEX;
	}

	::IDXGIFactory* GlRhiConnection<Black::PlatformType::WindowsDesktop>::QueryGenericFactory()
	{
		EnsureInitialized();
		return m_generic_factory.get();
	}

	::IDXGIFactory1* GlRhiConnection<Black::PlatformType::WindowsDesktop>::QueryExtendedFactory()
	{
		EnsureInitialized();
		return m_extended_factory.get();
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::Finalize()
	{
		CRET( !IsInitialized() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to finalize the connection." );

		m_extended_factory.reset();
		m_generic_factory.reset();

		BLACK_LOG_INFO( LOG_CHANNEL, "Connection is finalized." );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnumerateAdapters( AdapterInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the information about GPU adapters." );

		EnsureInitialized();
		EXPECTS_DEBUG( m_generic_factory != nullptr );

		::DXGI_ADAPTER_DESC		adapter_generic_desc{};
		::DXGI_ADAPTER_DESC1	adapter_extended_desc{};
		::DXGI_OUTPUT_DESC		default_output_desc{};

		::HRESULT	access_result	= S_OK;
		size32_t	adapter_index	= 0;
		for( ; SUCCEEDED( access_result ); ++adapter_index )
		{
			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to get the information for adapter #{}.", adapter_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the adapter instance." );
			::IDXGIAdapter*	adapter_ptr	= nullptr;
			::HRESULT access_result = m_generic_factory->EnumAdapters( adapter_index, &adapter_ptr );
			CBRK( access_result == DXGI_ERROR_NOT_FOUND );
			CBRKE( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for adapter #{}, result: 0x{:08X}.", adapter_index, access_result );

			ENSURES_DEBUG( adapter_ptr != nullptr );
			Black::ScopedComPointer<::IDXGIAdapter> adapter_interface{ std::exchange( adapter_ptr, nullptr ) };

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the default output for adapter." );
			::IDXGIOutput* default_output_ptr	= nullptr;
			access_result						= adapter_interface->EnumOutputs( 0, &default_output_ptr );
			CCON( access_result == DXGI_ERROR_NOT_FOUND );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to access the output device for adapter #{}, result: 0x{:08X}.", adapter_index, access_result );

			ENSURES( default_output_ptr != nullptr );
			Black::ScopedComPointer<::IDXGIOutput> default_output_interface{ std::exchange( default_output_ptr, nullptr ) };

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of adapter." );
			access_result = adapter_interface->GetDesc( &adapter_generic_desc );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for adapter #{}.", adapter_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of default output." );
			access_result = default_output_interface->GetDesc( &default_output_desc );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for default output of adapter #{}.", adapter_index );

			if( m_extended_factory == nullptr )
			{
				// Unsafe potentially, but, since the `DESC` and `DESC1` differs only by `Flags` field, this code looks more compact and obvious.
				Black::ZeroMemory( adapter_extended_desc );
				Black::CopyMemory( reinterpret_cast<::DXGI_ADAPTER_DESC&>( adapter_extended_desc ), adapter_generic_desc );
			}
			else
			{
				BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the extended interface of adapter." );
				::IDXGIAdapter1* extended_adapter_ptr = nullptr;
				access_result = adapter_interface->QueryInterface( &extended_adapter_ptr );
				ENSURES( SUCCEEDED( access_result ) );

				ENSURES_DEBUG( extended_adapter_ptr != nullptr );
				Black::ScopedComPointer<::IDXGIAdapter1> extended_adapter_interface{ std::exchange( extended_adapter_ptr, nullptr ) };

				BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the full description of adapter." );
				access_result = extended_adapter_interface->GetDesc1( &adapter_extended_desc );
				CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for adapter #{}.", adapter_index );
			}

			// Prepare the device path.
			std::wstring_view	wide_device_path{ default_output_desc.DeviceName };
			std::string			device_path{ ConvertWideString( wide_device_path ) };
			ENSURES_DEBUG( !device_path.empty() || wide_device_path.empty() );

			// Prepare the device name.
			std::wstring_view	wide_device_name{ adapter_extended_desc.Description };
			std::string			device_name{ ConvertWideString( wide_device_name ) };
			ENSURES_DEBUG( !device_name.empty() || wide_device_name.empty() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Consuming the information of adapter." );
			consumer.Consume( device_path, device_name, AdapterInfoConsumer::AdapterInfo{ adapter_extended_desc, adapter_index } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Information about {} adapters enumerated.", adapter_index );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnumerateDisplays( const Black::GlRhiAdapter& adapter, DisplayInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the information about displays of adapter #{}.", adapter.GetIndex() );

		EnsureInitialized();
		EXPECTS_DEBUG( m_generic_factory != nullptr );

		::HRESULT access_result = S_OK;

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the instance of adapter #{}.", adapter.GetIndex() );
		::IDXGIAdapter*	adapter_ptr	= nullptr;
		access_result = m_generic_factory->EnumAdapters( adapter.GetIndex(), &adapter_ptr );
		CRETE( FAILED( access_result ), , LOG_CHANNEL, "Failed to enumerate information for adapter #{}.", adapter.GetIndex() );

		ENSURES_DEBUG( adapter_ptr != nullptr );
		Black::ScopedComPointer<::IDXGIAdapter> adapter_interface{ std::exchange( adapter_ptr, nullptr ) };

		::DXGI_OUTPUT_DESC	device_desc{};
		::MONITORINFOEXW	monitor_info{};
		::DISPLAY_DEVICEW	display_info{};

		size32_t output_index = 0;
		for( ; SUCCEEDED( access_result ); ++output_index )
		{
			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to get the information for display #{}.", output_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the display instance." );
			::IDXGIOutput* output_ptr	= nullptr;
			access_result				= adapter_interface->EnumOutputs( output_index, &output_ptr );
			CBRK( access_result == DXGI_ERROR_NOT_FOUND );
			CBRKE( FAILED( access_result ), LOG_CHANNEL, "Failed to get information for display #{} of adapter #{}.", output_index, adapter.GetIndex() );

			ENSURES_DEBUG( output_ptr != nullptr );
			Black::ScopedComPointer<::IDXGIOutput> output_interface{ std::exchange( output_ptr, nullptr ) };

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the description of display." );
			access_result = output_interface->GetDesc( &device_desc );
			CCONW( FAILED( access_result ), LOG_CHANNEL, "Failed to get description for output display #{}, result: 0x{:08X}.", output_index, access_result );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the monitor information for display." );
			monitor_info.cbSize = size32_t( sizeof( monitor_info ) );
			const bool has_monitor_info	= ::GetMonitorInfoW( device_desc.Monitor, &monitor_info ) == TRUE;
			CCONW( !has_monitor_info, LOG_CHANNEL, "Failed to get the monitor info for display #{}.", output_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the device information for display." );
			display_info.cb = size32_t( sizeof( display_info ) );
			const bool has_display_info	= ::EnumDisplayDevicesW( monitor_info.szDevice, 0, &display_info, 0 ) == TRUE;
			CCONW( !has_display_info, LOG_CHANNEL, "Failed to get device info for display #{}.", output_index );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Detecting the default display mode." );
			::DXGI_MODE_DESC default_mode{ FindDefaultDisplayMode( *output_interface, monitor_info ) };

			// Prepare the device path.
			std::wstring_view	wide_device_path{ device_desc.DeviceName };
			std::string			device_path{ ConvertWideString( wide_device_path ) };
			ENSURES_DEBUG( !device_path.empty() || wide_device_path.empty() );

			// Prepare the device name.
			std::wstring_view	wide_device_name{ display_info.DeviceString };
			std::string			device_name{ ConvertWideString( wide_device_name ) };
			ENSURES_DEBUG( !device_name.empty() || wide_device_name.empty() );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Consuming the information of display." );
			consumer.Consume(
				device_path,
				device_name,
				DisplayInfoConsumer::DisplayInfo{ device_desc, default_mode, monitor_info, display_info, adapter.GetIndex(), output_index }
			);
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Information about {} displays enumerated for adapter #{}.", output_index, adapter.GetIndex() );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnumerateVideoModes( const Black::GlRhiDisplay& display, VideoModeInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the video modes for display #{} of adapter #{}.", display.GetIndex(), display.GetAdapterIndex() );

		EnsureInitialized();
		EXPECTS_DEBUG( m_generic_factory != nullptr );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the instance of adapter #{}.", display.GetAdapterIndex() );
		::IDXGIAdapter*	adapter_ptr	= nullptr;
		::HRESULT access_result = m_generic_factory->EnumAdapters( display.GetAdapterIndex(), &adapter_ptr );
		CRETE(
			FAILED( access_result ),
			,
			LOG_CHANNEL,
			"Failed to enumerate video modes for display #{} of adapter #{}.",
			display.GetIndex(),
			display.GetAdapterIndex()
		);

		ENSURES_DEBUG( adapter_ptr != nullptr );
		Black::ScopedComPointer<::IDXGIAdapter> adapter_interface{ std::exchange( adapter_ptr, nullptr ) };

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the instance of display #{}.", display.GetIndex() );
		::IDXGIOutput* output_ptr	= nullptr;
		access_result				= adapter_interface->EnumOutputs( display.GetIndex(), &output_ptr );
		CRETE(
			FAILED( access_result ),
			,
			LOG_CHANNEL,
			"Failed to enumerate video modes for display #{} of adapter #{}.",
			display.GetIndex(),
			display.GetAdapterIndex()
		);

		ENSURES_DEBUG( output_ptr != nullptr );
		Black::ScopedComPointer<::IDXGIOutput> output_interface{ std::exchange( output_ptr, nullptr ) };

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the display video modes." );
		std::vector<::DXGI_MODE_DESC>	video_modes{ BuildVideoModeList( *output_interface ) };
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Sorting the collected video modes." );
		std::vector<::DXGI_MODE_DESC*>	sorted_video_modes{ SortVideoModes( video_modes ) };

		for( const ::DXGI_MODE_DESC* video_mode : sorted_video_modes )
		{
			EXPECTS_DEBUG( video_mode->RefreshRate.Denominator > 0 );

			BLACK_LOG_VERBOSE( LOG_CHANNEL, "Consuming the information of video mode." );
			consumer.Consume( VideoModeInfoConsumer::VideoModeInfo{ *video_mode } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Video modes enumerated for display #{} of adapter #{}.", display.GetIndex(), display.GetAdapterIndex() );
	}

	void GlRhiConnection<Black::PlatformType::WindowsDesktop>::EnsureInitialized()
	{
		CRET( IsInitialized() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to create DXGI 1.1 factory." );
		::IDXGIFactory1*	extended_factory	= nullptr;
		::IDXGIFactory*		generic_factory		= nullptr;
		::HRESULT			result				= ::CreateDXGIFactory1( __uuidof( IDXGIFactory1 ), (void**)&extended_factory );

		if( SUCCEEDED( result ) && ( extended_factory != nullptr ) )
		{
			result = extended_factory->QueryInterface( &generic_factory );
			EXPECTS( SUCCEEDED( result ) );
			EXPECTS_DEBUG( generic_factory != nullptr );

			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection will use the DXGI 1.1 factory." );
			m_extended_factory.reset( extended_factory );
			m_generic_factory.reset( generic_factory );

			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection initialized." );
			return;
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "DXGI 1.1 factory construction result: 0x{:08X}", result );
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Attempt to create DXGI 1.0 factory." );

		result = CreateDXGIFactory( __uuidof( IDXGIFactory ), (void**)&generic_factory );

		if( SUCCEEDED( result ) && ( generic_factory != nullptr ) )
		{
			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection will use the DXGI 1.0 factory." );
			m_generic_factory.reset( generic_factory );

			BLACK_LOG_INFO( LOG_CHANNEL, "GPU connection initialized." );
			return;
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "DXGI 1.0 factory construction result: 0x{:08X}", result );
		BLACK_LOG_CRITICAL( LOG_CHANNEL, "Failed to create the handle for graphics connection." );
	}
}
}
}
}
