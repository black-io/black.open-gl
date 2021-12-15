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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Connection";
}


	void EglConnection<Black::PlatformType::Android>::UseApplicationContext( const ::Jni::Context& application_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to use new application context." );

		m_application_context = application_context;

		BLACK_LOG_INFO( LOG_CHANNEL, "'{}' application context will be used.", application_context.GetClass().GetName() );
	}

	void EglConnection<Black::PlatformType::Android>::Finalize()
	{
		CRET( !IsInitialized() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to finalize the connection." );

		m_application_context	= nullptr;
		m_is_api_profile_set	= false;

		BLACK_LOG_INFO( LOG_CHANNEL, "Connection is finalized." );
	}

	void EglConnection<Black::PlatformType::Android>::SwapBuffers( const Black::EglDisplay& display, const Black::EglSurface& surface )
	{
		BLACK_NON_RELEASE_CODE( CRETE( !IsInitialized(), , LOG_CHANNEL, "Connection should be initialized first." ) );
		BLACK_NON_RELEASE_CODE( CRETE( !display.IsConnected(), , LOG_CHANNEL, "Given display should be connected first." ) );
		BLACK_NON_RELEASE_CODE( CRETE( !surface.IsConnected(), , LOG_CHANNEL, "Given surface should be connected first." ) );

		const bool is_succeeded = ::eglSwapBuffers( display.GetHandle(), surface.GetHandle() ) == EGL_TRUE;
		if( !is_succeeded )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to swap buffers for given surface, error: 0x{:08X}.", ::eglGetError() );
		}
	}

	EglConnection<Black::PlatformType::Android>::RegularFunction EglConnection<Black::PlatformType::Android>::GetFunctionAddress(
		std::string_view function_name
	) const
	{
		CRETE( !IsInitialized(), nullptr, LOG_CHANNEL, "Connection should be initialized first." );
		return reinterpret_cast<RegularFunction>( ::eglGetProcAddress( function_name.data() ) );
	}

	const bool EglConnection<Black::PlatformType::Android>::HasCurrentContext() const
	{
		CRETE( !IsInitialized(), false, LOG_CHANNEL, "Connection should be initialized first." );
		return ::eglGetCurrentContext() != EGL_NO_CONTEXT;
	}

	void EglConnection<Black::PlatformType::Android>::EnumerateAdapters( AdapterInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the information about GPU adapters." );

		EnsureInitialized();

		// Currently just emulate some work, emitting the information about some default GPU.
		consumer.Consume( "/proc/gpu/0", "Default adapter", { 0 } );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Information about adapters enumerated." );
	}

	void EglConnection<Black::PlatformType::Android>::EnumerateDisplays( const Black::GlAdapterHandle& adapter_handle, DisplayInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to enumerate the information about displays of adapter #{}.", adapter_handle.GetIndex() );

		EnsureInitialized();

		CRETW( adapter_handle.GetIndex() != 0, , LOG_CHANNEL, "Only default GPU adapter can be currently queried." );

		// Currently we query only the default display for current context of application.
		const ::Jni::Display current_display = m_window_manager.GetDefaultDisplay();
		ENSURES_DEBUG( current_display.IsValid() );

		// Emulate the default display device since t he Android OS currently does not support more.
		consumer.Consume( "/proc/display/0", current_display.GetName(), { EGL_DEFAULT_DISPLAY, adapter_handle.GetIndex(), 0 } );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Information about displays enumerated for adapter #{}.", adapter_handle.GetIndex() );
	}

	void EglConnection<Black::PlatformType::Android>::EnumerateVideoModes( const Black::GlDisplayHandle& display_handle, VideoModeInfoConsumer& consumer )
	{
		BLACK_LOG_DEBUG(
			LOG_CHANNEL,
			"Attempt to enumerate the video modes for display #{} of adapter #{}.",
			display_handle.GetIndex(),
			display_handle.GetAdapterIndex()
		);

		EnsureInitialized();

		// Currently we query only the default display for current context of application.
		const ::Jni::Display current_display = m_window_manager.GetDefaultDisplay();
		ENSURES_DEBUG( current_display.IsValid() );

		const auto display_metrics = Black::JniObject::ConstructHandle<::Jni::DisplayMetrics>();
		ENSURES_DEBUG( display_metrics.IsValid() );

		const auto pixel_format_info = Black::JniObject::ConstructHandle<::Jni::PixelFormat>();
		ENSURES_DEBUG( pixel_format_info.IsValid() );

		current_display.GetRealMetrics( display_metrics );
		::Jni::PixelFormat::GetPixelFormatInfo( current_display.GetPixelFormat(), pixel_format_info );

		// Emulate the different resolutions of differently oriented display.
		consumer.Consume(
			{
				display_metrics.GetWidth(),
				display_metrics.GetHeight(),
				pixel_format_info.GetBitsPerPixel(),
				current_display.GetRefreshRate(),
				current_display.GetPixelFormat()
			}
		);

		consumer.Consume(
			{
				display_metrics.GetHeight(),
				display_metrics.GetWidth(),
				pixel_format_info.GetBitsPerPixel(),
				current_display.GetRefreshRate(),
				current_display.GetPixelFormat()
			}
		);

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Video modes enumerated for display #{} of adapter #{}.", display_handle.GetIndex(), display_handle.GetAdapterIndex() );
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectDisplay( const Black::GlAdapterHandle& adapter_handle, Black::EglDisplay& target_display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to connect the display object to adapter #{}.", adapter_handle.GetIndex() );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the display can be connected." );
		CRETE( !target_display.Connect( adapter_handle ), false, LOG_CHANNEL, "Failed to connect display object." );
		CRETE( !target_display.IsConnected(), false, LOG_CHANNEL, "Display object still disconnected after connection." );

		// @TODO: Load the EGL extensions.

		target_display.UpdateConfigurations();

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display object successfully connected to adapter #{}.", adapter_handle.GetIndex() );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectDisplay( const Black::GlDisplayHandle& display_handle, Black::EglDisplay& target_display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to connect the display object to display #{}.", display_handle.GetIndex() );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the display can be connected." );
		CRETE( !target_display.Connect( display_handle ), false, LOG_CHANNEL, "Failed to connect display object." );
		CRETE( !target_display.IsConnected(), false, LOG_CHANNEL, "Display object still disconnected after connection." );

		// @TODO: Load the EGL extensions.

		target_display.UpdateConfigurations();

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display object successfully connected to display #{}.", display_handle.GetIndex() );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectWindowSurface(
		const Black::EglDisplay& display,
		const ::Jni::Surface& window_handle,
		Black::EglSurface& target_surface
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to window with best configuration." );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the surface can be connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display object is not connected." );

		auto window_configuration = display.FindBestWindowConfiguration();
		CRETE( !window_configuration.has_value(), false, LOG_CHANNEL, "Failed to find best configuration for window." );

		const bool is_connected = ConnectWindowSurface( display, *window_configuration, window_handle, target_surface );
		CRETE( !is_connected, false, LOG_CHANNEL, "Failed to connect the surface with best window configuration." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "The surface was successfully connected to window using best configuration." );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectWindowSurface(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& surface_configuration,
		const ::Jni::Surface& window_handle,
		Black::EglSurface& target_surface
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to window with given configuration." );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the surface can be connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display object is not connected." );
		CRETE( !target_surface.ConnectWindow( display, surface_configuration, window_handle ), false, LOG_CHANNEL, "Failed to connect surface with window." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "The surface was successfully connected to window using given configuration." );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectPixelBufferSurface(
		const Black::EglDisplay& display,
		const size32_t width,
		const size32_t height,
		Black::EglSurface& target_surface
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to pixel buffer with best configuration." );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the surface can be connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display object is not connected." );

		auto window_configuration = display.FindBestWindowConfiguration();
		CRETE( !window_configuration.has_value(), false, LOG_CHANNEL, "Failed to find best configuration for window." );

		auto pixel_buffer_configuration = display.FindBestPixelBufferConfiguration( *window_configuration );
		CRETE( !pixel_buffer_configuration.has_value(), false, LOG_CHANNEL, "Failed to find best configuration for pixel buffer." );

		const bool is_connected = ConnectPixelBufferSurface( display, *pixel_buffer_configuration, width, height, target_surface );
		CRETE( !is_connected, false, LOG_CHANNEL, "Failed to connect the surface with best pixel buffer configuration." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "The surface was successfully connected to pixel buffer using best configuration." );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectPixelBufferSurface(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& surface_configuration,
		const size32_t width,
		const size32_t height,
		Black::EglSurface& target_surface
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to pixel buffer with given configuration." );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the surface can be connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display object is not connected." );

		const bool is_connected = target_surface.ConnectPixelBuffer( display, surface_configuration, width, height );
		CRETE( !is_connected, false, LOG_CHANNEL, "Failed to connect surface with pixel buffer." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "The surface was successfully connected to pixel buffer using given configuration." );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectContext(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		Black::EglContext& target_context
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the context to given display with given configuration." );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the surface can be connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display object is not connected." );

		const bool is_connected = target_context.Connect( display, configuration );
		CRETE( !is_connected, false, LOG_CHANNEL, "Failed to connect the context to display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context successfully connected to given display with given configuration." );
		return true;
	}

	const bool EglConnection<Black::PlatformType::Android>::ConnectContext(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const Black::EglContext& host_context,
		Black::EglContext& target_context
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the shared context to given display with given configuration." );

		CRETE( !IsInitialized(), false, LOG_CHANNEL, "EGL Connection should be initialized before the surface can be connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display object is not connected." );

		const bool is_connected = target_context.Connect( display, configuration, host_context );
		CRETE( !is_connected, false, LOG_CHANNEL, "Failed to connect the context to display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Shared context successfully connected to given display with given configuration." );
		return true;
	}

	void EglConnection<Black::PlatformType::Android>::EnsureInitialized()
	{
		CRET( IsInitialized() );

		EXPECTS( m_application_context.IsValid() );

		m_window_manager = m_application_context.GetSystemService( m_application_context.GetWindowServiceName() ).ConvertTo<::Jni::WindowManager>();
		ENSURES( m_window_manager.IsValid() );

		m_is_api_profile_set = ::eglBindAPI( EGL_OPENGL_ES_API ) == EGL_TRUE;
		if( !m_is_api_profile_set )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to bind API profile for EGL, error: 0x{:08X}.", ::eglGetError() );
		}
	}
}
}
}
}
