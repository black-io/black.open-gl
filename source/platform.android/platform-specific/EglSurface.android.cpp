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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Surface";
}


	const bool EglSurface<Black::PlatformType::Android>::ConnectWindow(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const ::Jni::Surface& window_surface
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to window." );

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

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface successfully connected to pixel buffer." );
		return true;
	}

	void EglSurface<Black::PlatformType::Android>::Finalize()
	{
		CRET( !IsConnected() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface will be disconnected." );

		const bool is_succeeded = ::eglDestroySurface( m_display_handle, m_handle ) == EGL_TRUE;
		if( !is_succeeded )
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
