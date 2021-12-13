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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Context";
}


	const bool EglContext<Black::PlatformType::Android>::Connect( const Black::EglDisplay& display, const Black::EglConfiguration& configuration )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the context with given display." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "Context is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be already connected." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context successfully connected with given display." );
		return true;
	}

	const bool EglContext<Black::PlatformType::Android>::Connect(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const Black::EglContext& host_context
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the context with given display and host context." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context successfully connected with given display and host context." );
		return true;
	}

	void EglContext<Black::PlatformType::Android>::Finalize()
	{
		CRET( !IsConnected() );

		EXPECTS( !IsCurrent() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context will be finalized." );
		if( ::eglDestroyContext( m_display_handle, m_handle ) == EGL_FALSE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Destruction of EGL context goes wrong, error: 0x{:08X}.", ::eglGetError() );
		}

		m_handle			= EGL_NO_CONTEXT;
		m_display_handle	= EGL_NO_DISPLAY;
	}

	const bool EglContext<Black::PlatformType::Android>::ResetCurrent( const Black::EglDisplay& display )
	{
		CRETE( m_is_current && !IsCurrentForThisThread(), false, LOG_CHANNEL, "Context should be reset from thread where it is current." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Given display should be already connected." );

		m_is_current		= false;
		m_current_thread_id	= {};
		return true;
	}

	const bool EglContext<Black::PlatformType::Android>::MakeCurrent( const Black::EglDisplay& display, const Black::EglSurface& target_surface )
	{
		CRET( IsCurrentForThisThread(), true );
		CRETE( m_is_current, false, LOG_CHANNEL, "Context already set as current in a different thread." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Given display should be already connected." );
		CRETE( !target_surface.IsConnected(), false, LOG_CHANNEL, "Target surface should be already connected." );

		m_is_current		= true;
		m_current_thread_id	= std::this_thread::get_id();
		return true;
	}

	const bool EglContext<Black::PlatformType::Android>::MakeCurrent(
		const Black::EglDisplay& display,
		const Black::EglSurface& rendering_surface,
		const Black::EglSurface& reading_surface
	)
	{
		CRET( IsCurrentForThisThread(), true );
		CRETE( m_is_current, false, LOG_CHANNEL, "Context already set as current in a different thread." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Given display should be already connected." );
		CRETE( !rendering_surface.IsConnected(), false, LOG_CHANNEL, "Rendering surface should be already connected." );
		CRETE( !reading_surface.IsConnected(), false, LOG_CHANNEL, "Reading surface should be already connected." );

		m_is_current		= true;
		m_current_thread_id	= std::this_thread::get_id();
		return true;
	}
}
}
}
}
