#include <black/open-gl.h>
#include <wingdi.h>

#include "functions.initialization.h"


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/RHI Connection/WGL";

	// Name of stub window class.
	const wchar_t* STUB_WINDOW_CLASS_NAME = L"WglInitializationStubClass";


	// Retrieve the desktop area represented by display.
	inline std::optional<::RECT> GetDisplayDesktopArea( ::IDXGIOutput& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to get the desktop area of display." );

		::DXGI_OUTPUT_DESC	output_description{};
		const ::HRESULT		access_result = display.GetDesc( &output_description );
		CRETE( FAILED( access_result ), {}, LOG_CHANNEL, "Failed to get display description, result - 0x{:08X}.", access_result );

		const ::RECT& result = output_description.DesktopCoordinates;
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "[{}, {}, {}, {}] area will be used.", result.left, result.top, result.right, result.bottom );
		return { result };
	}

	// Perform the registration of window class for stub window.
	inline const bool RegisterStubWindowClass()
	{
		const ::WNDCLASSW stub_window_class{
			CS_HREDRAW | CS_VREDRAW | CS_OWNDC,			// style
			::DefWindowProcW,							// lpfnWndProc
			0,											// cbClsExtra
			0,											// cbWndExtra
			::GetModuleHandleW( nullptr ),				// hInstance
			::LoadIconA( nullptr, IDI_APPLICATION ),	// hIcon
			::LoadCursorA( nullptr, IDC_ARROW ),		// hCursor
			nullptr,									// hbrBackground
			nullptr,									// lpszMenuName
			STUB_WINDOW_CLASS_NAME						// lpszClassName
		};

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to register the stub window class." );
		const ::ATOM class_atom = ::RegisterClassW( &stub_window_class );
		CRETE( class_atom == 0, false, LOG_CHANNEL, "Failed to register the stub window class." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Stub window class registered successfully." );
		return true;
	}

	// Unregister the class of stub window.
	inline void UnregisterStubWindowClass()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Stub window class will be unregistered." );
		if( ::UnregisterClassW( STUB_WINDOW_CLASS_NAME, nullptr ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to unregister the class of stub window, error: 0x{:08X}.", ::GetLastError() );
		}
	}

	// Create the window for WGL initialization.
	inline std::optional<::HWND> CreateStubWindow( const ::RECT& clip_area )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to create stub window." );
		const ::HWND stub_window = ::CreateWindowExW(
			0,
			STUB_WINDOW_CLASS_NAME,
			L"WGL Initialization Stub",
			0,
			( clip_area.left + clip_area.right ) / 2,
			( clip_area.top + clip_area.bottom ) / 2,
			0,
			0,
			nullptr,
			nullptr,
			::GetModuleHandleW( nullptr ),
			nullptr
		);
		CRETE( stub_window == nullptr, {}, LOG_CHANNEL, "Failed to create stub window, error: 0x{:08X}.", ::GetLastError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Stub window successfully created at the center of given clip area." );
		return stub_window;
	}

	// Destroy the stub window.
	inline void DestroyStubWindow( ::HWND stub_window )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Destroying the stub window." );
		if( ::DestroyWindow( stub_window ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to destroy the stub window, error: 0x{:08X}.", ::GetLastError() );
		}
	}

	// Acquire the valid device context from given window.
	inline std::optional<::HDC> AcquireDeviceContext( const ::HWND window, ::IDXGIOutput& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to Acquire the device context for window." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to get the display description." );
		::DXGI_OUTPUT_DESC output_description{};

		{
			const ::HRESULT access_result = display.GetDesc( &output_description );
			CRETE( FAILED( access_result ), {}, LOG_CHANNEL, "Failed to get display description, result - 0x{:08X}.", access_result );
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to get the desktop settings of display." );
		::DEVMODEW device_mode{};

		{
			device_mode.dmSize				= sizeof( device_mode );
			const bool has_display_settings	= ::EnumDisplaySettingsW( output_description.DeviceName, ENUM_CURRENT_SETTINGS, &device_mode ) == TRUE;
			CRETE( !has_display_settings, {}, LOG_CHANNEL, "Failed to get desktop settings." );
		}

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Accessing the device context of window." );
		const ::HDC device_context = ::GetDC( window );
		CRETE( device_context == nullptr, {}, LOG_CHANNEL, "Failed to get device context." );

		const ::PIXELFORMATDESCRIPTOR format_descriptor{
			sizeof( ::PIXELFORMATDESCRIPTOR ),							// nSize
			1,															// nVersion
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,	// dwFlags
			PFD_TYPE_RGBA,												// iPixelType
			device_mode.dmBitsPerPel,									// cColorBits
			0,															// cRedBits
			0,															// cRedShift
			0,															// cGreenBits
			0,															// cGreenShift
			0,															// cBlueBits
			0,															// cBlueShift
			8,															// cAlphaBits
			0,															// cAlphaShift
			0,															// cAccumBits
			0,															// cAccumRedBits
			0,															// cAccumGreenBits
			0,															// cAccumBlueBits
			0,															// cAccumAlphaBits
			24,															// cDepthBits
			8,															// cStencilBits
			0,															// cAuxBuffers
			PFD_MAIN_PLANE,												// iLayerType
			0,															// bReserved
			0,															// dwLayerMask
			0,															// dwVisibleMask
			0,															// dwDamageMask
		};

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Selecting the pixel format for device context." );
		const int pixel_format = ChoosePixelFormat( device_context, &format_descriptor );
		CRETE( pixel_format == 0, {}, LOG_CHANNEL, "Failed to select pixel format for device context, error: 0x{:08X}", ::GetLastError() );

		{
			const bool has_format_set = ::SetPixelFormat( device_context, pixel_format, &format_descriptor ) == TRUE;
			if( !has_format_set )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to set pixel format for device context, error: 0x{:08X}.", ::GetLastError() );
			}
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Device context acquired and configured properly." );
		return { device_context };
	}

	// Release the acquired device context.
	inline void ReleaseDeviceContext( const ::HWND window, const ::HDC device_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Releasing the device context." );
		::ReleaseDC( window, device_context );
	}

	// Create the compatible OpenGL context regardless to version and options. Once the context is created, it will be set automatically.
	inline std::optional<::HGLRC> CreateGraphicsContext( const ::HDC device_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to create the dummy OpenGL context." );

		const ::HGLRC graphics_context = ::wglCreateContext( device_context );
		CRETE( graphics_context == nullptr, {}, LOG_CHANNEL, "Failed to create OpenGL context, error: 0x{:08X}.", ::GetLastError() );

		auto context_guard = Black::ScopeLeaveHandler{
			[graphics_context]()
			{
				if( ::wglDeleteContext( graphics_context ) != TRUE )
				{
					BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to delete the graphics context, error: 0x{:08X}", ::GetLastError() );
				}
			}
		};

		const bool is_succeeded = ::wglMakeCurrent( device_context, graphics_context ) == TRUE;
		CRETE( !is_succeeded, {}, LOG_CHANNEL, "Failed to make the graphics context current, error: 0x{:08X}", ::GetLastError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "OpenGL context created successfully." );
		context_guard.Cancel();
		return graphics_context;
	}

	// Destroy the OpenGL context.
	inline void DestroyGraphicsContext( const ::HGLRC graphics_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Deleting the OpenGL context." );

		if( ::wglMakeCurrent( nullptr, nullptr ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to unbind the current context, error: 0x{:08X}.", ::GetLastError() );
		}

		if( ::wglDeleteContext( graphics_context ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to delete the graphics context, error: 0x{:08X}", ::GetLastError() );
		}
	}
}


	const bool WglInitialize( ::IDXGIOutput& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to initialize the WGL layer." );

		const auto desktop_area = GetDisplayDesktopArea( display );
		CRETE( !desktop_area.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		CRETE( !RegisterStubWindowClass(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard of window class registration.
		auto window_class_guard = Black::ScopeLeaveHandler{ UnregisterStubWindowClass };

		const auto window_handle = CreateStubWindow( *desktop_area );
		CRETE( !window_handle.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard of window lifetime.
		auto window_guard = Black::ScopeLeaveHandler{
			[window = *window_handle]()
			{
				DestroyStubWindow( window );
			}
		};

		const auto device_context = AcquireDeviceContext( *window_handle, display );
		CRETE( !device_context.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard to release the device context.
		auto context_guard = Black::ScopeLeaveHandler{
			[context = *device_context, window = *window_handle]()
			{
				ReleaseDeviceContext( window, context );
			}
		};

		const auto graphics_context = CreateGraphicsContext( *device_context );
		CRETE( graphics_context == nullptr, false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard to properly destroy the OpenGL context.
		auto gl_guard = Black::ScopeLeaveHandler{
			[context = *graphics_context]()
			{
				DestroyGraphicsContext( context );
			}
		};

		// Perform the WGL initialization.

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL layer initialized successfully." );
		return true;
	}
}
}
}
}
