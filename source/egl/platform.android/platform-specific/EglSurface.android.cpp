#include <black/open-gl/egl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace PlatformSpecific
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Surface";
}


	const bool EglSurface<Black::PlatformType::Android>::ConnectWindow(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const ::Jni::Surface& window_surface
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to window." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "The surface is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be connected first." );
		CRETE( !configuration.GetProperties().is_winwow_surface_compatible, false, LOG_CHANNEL, "Configuration does not support windows." );

		m_display_handle	= display.GetHandle();
		m_handle			= ::eglCreateWindowSurface( m_display_handle, configuration.GetHandle(), window_surface.GetNativeWindow(), nullptr );
		CRETE( m_handle == EGL_NO_SURFACE, false, LOG_CHANNEL, "Failed to create window surface, error: 0x{:08X}.", ::eglGetError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface successfully connected to window." );
		return true;
	}

	const bool EglSurface<Black::PlatformType::Android>::ConnectPixelBuffer(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const size32_t width,
		const size32_t height
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to pixel buffer." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "The surface is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be connected first." );
		CRETE( !configuration.GetProperties().is_pbuffer_surface_compatible, false, LOG_CHANNEL, "Given configuration does not support pixel buffers." );
		CRETE( int32_t( width ) > configuration.GetProperties().maximum_pbuffer_width, false, LOG_CHANNEL, "Width limit exceeded." );
		CRETE( int32_t( height ) > configuration.GetProperties().maximum_pbuffer_height, false, LOG_CHANNEL, "Height limit exceeded." );

		const int32_t surface_attributes[]{
			EGL_WIDTH,	int32_t( width ),
			EGL_HEIGHT,	int32_t( height ),
			EGL_NONE,	EGL_NONE
		};

		m_display_handle	= display.GetHandle();
		m_handle			= ::eglCreatePbufferSurface( m_display_handle, configuration.GetHandle(), surface_attributes );
		CRETE( m_handle == EGL_NO_SURFACE, false, LOG_CHANNEL, "Failed to create pixel buffer surface, error: 0x{:08X}.", ::eglGetError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface successfully connected to pixel buffer." );
		return true;
	}

	void EglSurface<Black::PlatformType::Android>::Finalize()
	{
		CRET( !IsConnected() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface will be disconnected." );

		if( ::eglDestroySurface( m_display_handle, m_handle ) == EGL_FALSE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Destruction of EGL surface goes wrong, error: 0x{:08X}.", ::eglGetError() );
		}

		m_handle			= EGL_NO_SURFACE;
		m_display_handle	= EGL_NO_DISPLAY;
	}
}
}
}
}
}
