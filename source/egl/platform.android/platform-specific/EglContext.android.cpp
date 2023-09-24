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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Context";

	// Mapping from API profiles supported by context to EGL API enumeration.
	constexpr int32_t API_PROFILES_MAPPING[]{
		EGL_OPENGL_API,		// ApiProfile::OpenGl
		EGL_OPENGL_ES_API,	// ApiProfile::OpenGlEs
		EGL_NONE,			// ApiProfile::OpenGlSc
	};
}


	const bool EglContext<Black::PlatformType::Android>::Connect( const Black::EglDisplay& display, const Black::EglConfiguration& configuration )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the context with given display." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "Context is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be already connected." );

		m_display_handle = display.GetHandle();
		const bool is_acquired = AcquireContextHandle( configuration.GetHandle(), nullptr );
		CRETE( !is_acquired, false, LOG_CHANNEL, "Failed to acquire OpenGL context for given display." );

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

		CRETE( IsConnected(), false, LOG_CHANNEL, "Context is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be already connected." );
		CRETE( !host_context.IsConnected(), false, LOG_CHANNEL, "Host context should be already connected." );

		m_display_handle = display.GetHandle();
		const bool is_acquired = AcquireContextHandle( configuration.GetHandle(), nullptr );
		CRETE( !is_acquired, false, LOG_CHANNEL, "Failed to acquire OpenGL context for given display." );

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
		CRETE( display.GetHandle() != m_display_handle, false, LOG_CHANNEL, "Given display is not the same that was used to create context." );

		const bool is_succeeded = ::eglMakeCurrent( m_display_handle, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT ) == EGL_TRUE;
		CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to reset current context, error: 0x{:08X}.", ::eglGetError() );

		m_is_current		= false;
		m_current_thread_id	= {};
		return true;
	}

	const bool EglContext<Black::PlatformType::Android>::MakeCurrent( const Black::EglDisplay& display, const Black::EglSurface& target_surface )
	{
		CRET( IsCurrentForThisThread(), true );
		CRETE( m_is_current, false, LOG_CHANNEL, "Context already set as current in a different thread." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Given display should be already connected." );
		CRETE( display.GetHandle() != m_display_handle, false, LOG_CHANNEL, "Given display is not the same that was used to create context." );
		CRETE( !target_surface.IsConnected(), false, LOG_CHANNEL, "Target surface should be already connected." );

		const bool is_succeeded = ::eglMakeCurrent( m_display_handle, target_surface.GetHandle(), target_surface.GetHandle(), m_handle ) == EGL_TRUE;
		CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::eglGetError() );

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
		CRETE( display.GetHandle() != m_display_handle, false, LOG_CHANNEL, "Given display is not the same that was used to create context." );
		CRETE( !rendering_surface.IsConnected(), false, LOG_CHANNEL, "Rendering surface should be already connected." );
		CRETE( !reading_surface.IsConnected(), false, LOG_CHANNEL, "Reading surface should be already connected." );

		const bool is_succeeded = ::eglMakeCurrent( m_display_handle, rendering_surface.GetHandle(), reading_surface.GetHandle(), m_handle ) == EGL_TRUE;
		CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::eglGetError() );

		m_is_current		= true;
		m_current_thread_id	= std::this_thread::get_id();
		return true;
	}

	const bool EglContext<Black::PlatformType::Android>::AcquireContextHandle( const ::EGLConfig configuration, const ::EGLContext host_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Try to acquire the OpenGL context." );

		const int32_t context_attributes[] {
			EGL_CONTEXT_MAJOR_VERSION,	m_major_version,
			EGL_NONE,					EGL_NONE
		};

		CRETE( API_PROFILES_MAPPING[ Black::GetEnumValue( m_api_profile ) ] == EGL_NONE, false, LOG_CHANNEL, "Requested API profile does not supported." );

		const bool is_api_set = ::eglBindAPI( API_PROFILES_MAPPING[ Black::GetEnumValue( m_api_profile ) ] ) == EGL_TRUE;
		CRETE( !is_api_set, false, LOG_CHANNEL, "Failed to set API profile, error: 0x{:08X}.", ::eglGetError() );

		m_handle = ::eglCreateContext( m_display_handle, configuration, host_context, context_attributes );
		CRETE( m_handle == EGL_NO_CONTEXT, false, LOG_CHANNEL, "Failed to create context, error: 0x{:08X}.", ::eglGetError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "OpenGL context is successfully acquired." );
		return true;
	}
}
}
}
}
}
