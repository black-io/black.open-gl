#include <black/open-gl/egl.h>

#include "wgl/bindings.wgl.h"
#include "wgl/bindings.wgl-extensions.h"
#include "wgl/functions.wgl-settings.h"


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


	const bool EglSurface<Black::PlatformType::WindowsDesktop>::ConnectWindow(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const ::HWND window_handle
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to window." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "The surface is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be connected first." );
		CRETE( ( configuration.GetDescription().dwFlags & PFD_DRAW_TO_WINDOW ) == 0, false, LOG_CHANNEL, "Configuration does not support windows." );

		m_type		= SurfaceType::Window;
		auto& state	= m_state.emplace<Internal::WindowSurfaceState>();

		state.host_window	= window_handle;
		m_surface_context	= ::GetDC( state.host_window );

		if( ::SetPixelFormat( m_surface_context, configuration.GetIndex(), &configuration.GetDescription() ) != TRUE )
		{
			BLACK_LOG_DEBUG( LOG_CHANNEL, "Failed to set pixel format for window surface, error: 0x{:08X}.", ::GetLastError() );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface successfully connected to window." );
		return true;
	}

	const bool EglSurface<Black::PlatformType::WindowsDesktop>::ConnectPixelBuffer(
		const Black::EglDisplay& display,
		const Black::EglConfiguration& configuration,
		const size32_t width,
		const size32_t height
	)
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the surface to pixel buffer." );

		CRETE( IsConnected(), false, LOG_CHANNEL, "The surface is already connected." );
		CRETE( !display.IsConnected(), false, LOG_CHANNEL, "Display should be connected first." );
		CRETE( !configuration.GetPixelBufferSettings().is_supported, false, LOG_CHANNEL, "Given configuration does not support pixel buffers." );
		CRETE( int32_t( width ) > configuration.GetPixelBufferSettings().maximum_width, false, LOG_CHANNEL, "Width limit exceeded." );
		CRETE( int32_t( height ) > configuration.GetPixelBufferSettings().maximum_height, false, LOG_CHANNEL, "Height limit exceeded." );

		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();
		if( extensions.has_wgl_ext_pbuffer )
		{
			::HPBUFFEREXT buffer_handle = ::Wgl::create_pbuffer_ext( display.GetDeviceContext(), configuration.GetIndex(), width, height, nullptr );
			CRETE( buffer_handle == nullptr, false, LOG_CHANNEL, "Failed to create the pixel buffer, error: 0x{:08X}.", ::GetLastError() );

			// Guard to destroy the pixel buffer object on any error.
			auto buffer_handle_guard = Black::ScopeLeaveHandler{
				[buffer_handle]()
				{
					if( ::Wgl::destroy_pbuffer_ext( buffer_handle ) != TRUE )
					{
						BLACK_LOG_WARNING( LOG_CHANNEL, "Destruction of pixel buffer goes wrong, error: 0x{:08X}.", ::GetLastError() );
					}
				}
			};

			const ::HDC surface_context = ::Wgl::get_pbuffer_dc_ext( buffer_handle );
			CRETE( surface_context == nullptr, false, LOG_CHANNEL, "Failed to get device context for pixel buffer, error: 0x{:08X}.", ::GetLastError() );

			auto& state = m_state.emplace<Internal::PixelBufferSurfaceState>();

			buffer_handle_guard.Cancel();
			m_type						= SurfaceType::PixelBuffer;
			state.owned_pixel_buffer	= buffer_handle;
			m_surface_context			= surface_context;
		}
		else if( extensions.has_wgl_arb_pbuffer )
		{
			::HPBUFFERARB buffer_handle = ::Wgl::create_pbuffer_arb( display.GetDeviceContext(), configuration.GetIndex(), width, height, nullptr );
			CRETE( buffer_handle == nullptr, false, LOG_CHANNEL, "Failed to create the pixel buffer, error: 0x{:08X}.", ::GetLastError() );

			// Guard to destroy the pixel buffer object on any error.
			auto buffer_handle_guard = Black::ScopeLeaveHandler{
				[buffer_handle]()
				{
					if( ::Wgl::destroy_pbuffer_arb( buffer_handle ) != TRUE )
					{
						BLACK_LOG_WARNING( LOG_CHANNEL, "Destruction of pixel buffer goes wrong, error: 0x{:08X}.", ::GetLastError() );
					}
				}
			};

			const ::HDC surface_context = ::Wgl::get_pbuffer_dc_arb( buffer_handle );
			CRETE( surface_context == nullptr, false, LOG_CHANNEL, "Failed to get device context for pixel buffer, error: 0x{:08X}.", ::GetLastError() );

			auto& state = m_state.emplace<Internal::PixelBufferSurfaceState>();

			buffer_handle_guard.Cancel();
			m_type						= SurfaceType::PixelBuffer;
			state.owned_pixel_buffer	= buffer_handle;
			m_surface_context			= surface_context;
		}
		else
		{
			BLACK_LOG_ERROR( LOG_CHANNEL, "Pixel buffers are not supported by selected hardware." );
			return false;
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface successfully connected to pixel buffer." );
		return true;
	}

	void EglSurface<Black::PlatformType::WindowsDesktop>::Finalize()
	{
		CRET( !IsConnected() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Surface will be disconnected." );
		switch( m_type )
		{
		case SurfaceType::Window:
			if( ::ReleaseDC( std::get<Internal::WindowSurfaceState>( m_state ).host_window, m_surface_context ) != TRUE )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Device context was not released properly on surface disconnection." );
			}
			break;
		case SurfaceType::PixelBuffer:
			DestroyPixelBuffer();
			break;
		default:
			break;
		}

		m_surface_context = nullptr;
		m_state.emplace<std::monostate>();
		m_type = SurfaceType::Undefined;
	}

	void EglSurface<Black::PlatformType::WindowsDesktop>::DestroyPixelBuffer()
	{
		const ::Wgl::ExtensionsState& extensions = ::Wgl::GetExtensionsState();

		auto& state = std::get<Internal::PixelBufferSurfaceState>( m_state );
		if( extensions.has_wgl_ext_pbuffer )
		{
			::HPBUFFEREXT buffer_handle = (::HPBUFFEREXT)state.owned_pixel_buffer;

			if( ::Wgl::release_pbuffer_dc_ext( buffer_handle, m_surface_context ) != TRUE )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to release device context of pixel buffer, error: 0x{:08X}.", ::GetLastError() );
			}

			if( ::Wgl::destroy_pbuffer_ext( buffer_handle ) != TRUE )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Destruction of pixel buffer goes wrong, error: 0x{:08X}.", ::GetLastError() );
			}
		}
		else if( extensions.has_wgl_arb_pbuffer )
		{
			::HPBUFFERARB buffer_handle = (::HPBUFFERARB)state.owned_pixel_buffer;

			if( ::Wgl::release_pbuffer_dc_arb( buffer_handle, m_surface_context ) != TRUE )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to release device context of pixel buffer, error: 0x{:08X}.", ::GetLastError() );
			}

			if( ::Wgl::destroy_pbuffer_arb( buffer_handle ) != TRUE )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Destruction of pixel buffer goes wrong, error: 0x{:08X}.", ::GetLastError() );
			}
		}
		else
		{
			BLACK_LOG_ERROR( LOG_CHANNEL, "Extensions was changed improperly. Pixel buffers now does not supported." );
		}
	}
}
}
}
}
}
