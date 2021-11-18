#include <black/open-gl.h>

#include "wgl/bindings.wgl.h"
#include "wgl/bindings.wgl-extensions.h"
#include "wgl/functions.wgl-settings.h"


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


	const bool EglContext<Black::PlatformType::WindowsDesktop>::Connect( const Black::EglDisplay& display, const Black::EglConfiguration& configuration )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the context with given display." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "Context is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be already connected." );

		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();
		CRETE( !extensions.has_wgl_arb_create_context, false, LOG_CHANNEL, "Selected hardware does not support 'WGL_ARB_create_context' extension." );
		if( m_api_profile == ApiProfile::OpenGlEs )
		{
			CRETE( !extensions.has_wgl_ext_create_context_es2_profile, false, LOG_CHANNEL, "Selected hardware does not support OpenGL ES API profile." );
		}

		display.EnsurePixelFormatSet( configuration );
		const bool is_acquired = AcquireRenderingContext( display.GetDeviceContext(), nullptr );
		CRETE( !is_acquired, false, LOG_CHANNEL, "Failed to acquire rendering context for given display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context successfully connected with given display." );
		return true;
	}

	const bool EglContext<Black::PlatformType::WindowsDesktop>::Connect(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const Black::EglContext& host_context
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the context with given display and host context." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "Context is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be already connected." );
		CRETE( !host_context.IsConnected(), false, LOG_CHANNEL, "Host context should be already connected." );

		const auto& extensions = ::Wgl::GetExtensionsState();
		CRETE( !extensions.has_wgl_arb_create_context, false, LOG_CHANNEL, "Selected hardware does not support 'WGL_ARB_create_context' extension." );
		if( m_api_profile == ApiProfile::OpenGlEs )
		{
			CRETE( !extensions.has_wgl_ext_create_context_es2_profile, false, LOG_CHANNEL, "Selected hardware does not support OpenGL ES API profile." );
		}

		const bool is_acquired = AcquireRenderingContext( display.GetDeviceContext(), host_context.GetRenderingContext() );
		CRETE( !is_acquired, false, LOG_CHANNEL, "Failed to acquire rendering context for given display and host context." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context successfully connected with given display and host context." );
		return true;
	}

	void EglContext<Black::PlatformType::WindowsDesktop>::Finalize()
	{
		CRET( !IsConnected() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Context will be finalized." );
		if( ::Wgl::delete_context( m_rendering_context ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "The rendering context deletion goes wrong, result: 0x{:08X}.", ::GetLastError() );
		}

		m_rendering_context = nullptr;
	}

	const bool EglContext<Black::PlatformType::WindowsDesktop>::ResetCurrent( const Black::EglDisplay& display )
	{
		CRETE( m_is_current && !IsCurrentForThisThread(), false, LOG_CHANNEL, "Context should be reset from thread where it is current." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Given display should be already connected." );

		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();
		if( extensions.has_wgl_ext_make_current_read )
		{
			const bool	is_succeeded = ::Wgl::make_context_current_ext( nullptr, nullptr, nullptr ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}
		else if( extensions.has_wgl_arb_make_current_read )
		{
			const bool	is_succeeded = ::Wgl::make_context_current_arb( nullptr, nullptr, nullptr ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}
		else
		{
			const bool is_succeeded = ::Wgl::make_current( nullptr, nullptr ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}

		m_is_current		= false;
		m_current_thread_id	= {};
		return true;
	}

	const bool EglContext<Black::PlatformType::WindowsDesktop>::MakeCurrent( const Black::EglDisplay& display, const Black::EglSurface& target_surface )
	{
		CRET( IsCurrentForThisThread(), true );
		CRETE( m_is_current, false, LOG_CHANNEL, "Context already set as current in a different thread." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Given display should be already connected." );
		CRETE( !target_surface.IsConnected(), false, LOG_CHANNEL, "Target surface should be already connected." );

		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();
		if( extensions.has_wgl_ext_make_current_read )
		{
			const ::HDC	surface_context	= target_surface.GetSurfaceContext();
			const bool	is_succeeded	= ::Wgl::make_context_current_ext( surface_context, surface_context, m_rendering_context ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}
		else if( extensions.has_wgl_arb_make_current_read )
		{
			const ::HDC	surface_context	= target_surface.GetSurfaceContext();
			const bool	is_succeeded	= ::Wgl::make_context_current_arb( surface_context, surface_context, m_rendering_context ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}
		else
		{
			const bool is_succeeded = ::Wgl::make_current( target_surface.GetSurfaceContext(), m_rendering_context ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}

		m_is_current		= true;
		m_current_thread_id	= std::this_thread::get_id();
		return true;
	}

	const bool EglContext<Black::PlatformType::WindowsDesktop>::MakeCurrent(
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

		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();
		if( extensions.has_wgl_ext_make_current_read )
		{
			const ::HDC	rendering_surface_context	= rendering_surface.GetSurfaceContext();
			const ::HDC	reading_surface_context		= reading_surface.GetSurfaceContext();

			const bool	is_succeeded = ::Wgl::make_context_current_ext( rendering_surface_context, reading_surface_context, m_rendering_context ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}
		else if( extensions.has_wgl_arb_make_current_read )
		{
			const ::HDC	rendering_surface_context	= rendering_surface.GetSurfaceContext();
			const ::HDC	reading_surface_context		= reading_surface.GetSurfaceContext();

			const bool	is_succeeded = ::Wgl::make_context_current_arb( rendering_surface_context, reading_surface_context, m_rendering_context ) == TRUE;
			CRETE( !is_succeeded, false, LOG_CHANNEL, "Failed to make context current, error: 0x{:08X}.", ::GetLastError() );
		}
		else
		{
			BLACK_LOG_ERROR( LOG_CHANNEL, "Hardware does not support extensions to make the context current with surface for reading." );
			return false;
		}

		m_is_current		= true;
		m_current_thread_id	= std::this_thread::get_id();
		return true;
	}

	const bool EglContext<Black::PlatformType::WindowsDesktop>::AcquireRenderingContext( const ::HDC device_context, const ::HGLRC host_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Try to acquire the rendering context." );

		const int32_t context_attributes[] {
			::Wgl::CONTEXT_MAJOR_VERSION_ARB,	m_major_version,
			::Wgl::CONTEXT_MINOR_VERSION_ARB,	m_minor_version,
			::Wgl::CONTEXT_LAYER_PLANE_ARB,		0,
			::Wgl::CONTEXT_FLAGS_ARB,			BuildContextFlags(),
			::Wgl::CONTEXT_PROFILE_MASK_ARB,	BuildProfileMask(),
			0,									0,
		};

		m_rendering_context = ::Wgl::create_context_attribs_arb( device_context, host_context, context_attributes );
		CRETE( m_rendering_context == nullptr, false, LOG_CHANNEL, "Failed to create context, error: 0x{:08X}.", ::GetLastError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Rendering context is successfully acquired." );
		return true;
	}

	const int32_t EglContext<Black::PlatformType::WindowsDesktop>::BuildContextFlags() const
	{
		int32_t result = 0;

		result |= ( m_is_debugable )? ::Wgl::CONTEXT_DEBUG_BIT_ARB : 0;
		result |= ( m_is_forward_compatible )? ::Wgl::CONTEXT_FORWARD_COMPATIBLE_BIT_ARB : 0;

		return result;
	}

	const int32_t EglContext<Black::PlatformType::WindowsDesktop>::BuildProfileMask() const
	{
		int32_t result = 0;

		result |= ( m_api_profile == ApiProfile::OpenGlEs )? ::Wgl::CONTEXT_ES2_PROFILE_BIT_EXT : 0;

		return result;
	}
}
}
}
}
