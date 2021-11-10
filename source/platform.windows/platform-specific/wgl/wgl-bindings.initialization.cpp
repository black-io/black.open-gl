#include <black/open-gl.h>
#include <black/core/algorithms.h>
#include <wingdi.h>

#include "functions.initialization.h"
#include "wgl.h"
#include "wgl.extensions.h"


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
			::BYTE( device_mode.dmBitsPerPel ),							// cColorBits
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

	// Get the WGL extensions using available core interface.
	inline std::string_view GetExtensionsBuffer( const ::HDC device_context )
	{
		const bool use_arb_function = ( ::Wgl::get_extensions_string_arb != nullptr ) && ( device_context != nullptr );
		EXPECTS( use_arb_function || ( ::Wgl::get_extensions_string_ext != nullptr ) );

		return ( use_arb_function )? ::Wgl::get_extensions_string_arb( device_context ) : ::Wgl::get_extensions_string_ext();
	}

	// Initialize the available extensions.
	void InitializeExtensionsState( ExtensionsState& state, const ::HDC device_context )
	{
		const std::string extensions_buffer{ GetExtensionsBuffer( device_context ) };
		std::vector<std::string_view> extensions;
		Black::SplitString( extensions, extensions_buffer, ' ' );

		state.bits = 0;
		CRET( extensions.empty() );

		state.has_wgl_3dfx_multisample						= Black::IsItemPresent( extensions, std::string_view{ "WGL_3DFX_multisample" } );
		state.has_wgl_3dl_stereo_control					= Black::IsItemPresent( extensions, std::string_view{ "WGL_3DL_stereo_control" } );
		state.has_wgl_amd_gpu_association					= Black::IsItemPresent( extensions, std::string_view{ "WGL_AMD_gpu_association" } );
		state.has_wgl_arb_buffer_region						= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_buffer_region" } );
		state.has_wgl_arb_context_flush_control				= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_context_flush_control" } );
		state.has_wgl_arb_create_context					= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_create_context" } );
		state.has_wgl_arb_create_context_no_error			= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_create_context_no_error" } );
		state.has_wgl_arb_create_context_profile			= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_create_context_profile" } );
		state.has_wgl_arb_create_context_robustness			= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_create_context_robustness" } );
		state.has_wgl_arb_extensions_string					= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_extensions_string" } );
		state.has_wgl_arb_framebuffer_srgb					= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_framebuffer_sRGB" } );
		state.has_wgl_arb_make_current_read					= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_make_current_read" } );
		state.has_wgl_arb_multisample						= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_multisample" } );
		state.has_wgl_arb_pbuffer							= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_pbuffer" } );
		state.has_wgl_arb_pixel_format						= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_pixel_format" } );
		state.has_wgl_arb_pixel_format_float				= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_pixel_format_float" } );
		state.has_wgl_arb_render_texture					= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_render_texture" } );
		state.has_wgl_arb_robustness_application_isolation	= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_robustness_application_isolation" } );
		state.has_wgl_arb_robustness_share_group_isolation	= Black::IsItemPresent( extensions, std::string_view{ "WGL_ARB_robustness_share_group_isolation" } );
		state.has_wgl_ati_pixel_format_float				= Black::IsItemPresent( extensions, std::string_view{ "WGL_ATI_pixel_format_float" } );
		state.has_wgl_ati_render_texture_rectangle			= Black::IsItemPresent( extensions, std::string_view{ "WGL_ATI_render_texture_rectangle" } );
		state.has_wgl_ext_colorspace						= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_colorspace" } );
		state.has_wgl_ext_create_context_es2_profile		= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_create_context_es2_profile" } );
		state.has_wgl_ext_create_context_es_profile			= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_create_context_es_profile" } );
		state.has_wgl_ext_depth_float						= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_depth_float" } );
		state.has_wgl_ext_display_color_table				= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_display_color_table" } );
		state.has_wgl_ext_extensions_string					= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_extensions_string" } );
		state.has_wgl_ext_framebuffer_srgb					= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_framebuffer_sRGB" } );
		state.has_wgl_ext_make_current_read					= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_make_current_read" } );
		state.has_wgl_ext_multisample						= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_multisample" } );
		state.has_wgl_ext_pbuffer							= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_pbuffer" } );
		state.has_wgl_ext_pixel_format						= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_pixel_format" } );
		state.has_wgl_ext_pixel_format_packed_float			= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_pixel_format_packed_float" } );
		state.has_wgl_ext_swap_control						= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_swap_control" } );
		state.has_wgl_ext_swap_control_tear					= Black::IsItemPresent( extensions, std::string_view{ "WGL_EXT_swap_control_tear" } );
		state.has_wgl_i3d_digital_video_control				= Black::IsItemPresent( extensions, std::string_view{ "WGL_I3D_digital_video_control" } );
		state.has_wgl_i3d_gamma								= Black::IsItemPresent( extensions, std::string_view{ "WGL_I3D_gamma" } );
		state.has_wgl_i3d_genlock							= Black::IsItemPresent( extensions, std::string_view{ "WGL_I3D_genlock" } );
		state.has_wgl_i3d_image_buffer						= Black::IsItemPresent( extensions, std::string_view{ "WGL_I3D_image_buffer" } );
		state.has_wgl_i3d_swap_frame_lock					= Black::IsItemPresent( extensions, std::string_view{ "WGL_I3D_swap_frame_lock" } );
		state.has_wgl_i3d_swap_frame_usage					= Black::IsItemPresent( extensions, std::string_view{ "WGL_I3D_swap_frame_usage" } );
		state.has_wgl_nv_dx_interop							= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_DX_interop" } );
		state.has_wgl_nv_dx_interop2						= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_DX_interop2" } );
		state.has_wgl_nv_copy_image							= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_copy_image" } );
		state.has_wgl_nv_delay_before_swap					= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_delay_before_swap" } );
		state.has_wgl_nv_float_buffer						= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_float_buffer" } );
		state.has_wgl_nv_gpu_affinity						= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_gpu_affinity" } );
		state.has_wgl_nv_multigpu_context					= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_multigpu_context" } );
		state.has_wgl_nv_multisample_coverage				= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_multisample_coverage" } );
		state.has_wgl_nv_present_video						= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_present_video" } );
		state.has_wgl_nv_render_depth_texture				= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_render_depth_texture" } );
		state.has_wgl_nv_render_texture_rectangle			= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_render_texture_rectangle" } );
		state.has_wgl_nv_swap_group							= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_swap_group" } );
		state.has_wgl_nv_vertex_array_range					= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_vertex_array_range" } );
		state.has_wgl_nv_video_capture						= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_video_capture" } );
		state.has_wgl_nv_video_output						= Black::IsItemPresent( extensions, std::string_view{ "WGL_NV_video_output" } );
		state.has_wgl_oml_sync_control						= Black::IsItemPresent( extensions, std::string_view{ "WGL_OML_sync_control" } );
	}

	// Access the global instance of WGL extensions state.
	ExtensionsState& AccessExtensionsState()
	{
		static ExtensionsState state;
		return state;
	}

	// Load the address of WGL function using the given function name.
	template< typename TFunction >
	inline void LoadFunctionAddress( TFunction& destination_popinter, const char* const function_name )
	{
		destination_popinter = reinterpret_cast<TFunction>( ::wglGetProcAddress( function_name ) );
	}

	// Load the address of WGL function directly.
	template< typename TFunction >
	inline void LoadFunctionAddress( TFunction& destination_popinter, TFunction source_pointer )
	{
		destination_popinter = source_pointer;
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
		CRETE( !WglLoadCoreProfile(), false, LOG_CHANNEL, "Failed to initialize WGL." );
		CRETE( !WglLoadExtensions(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL layer initialized successfully." );
		return true;
	}

	const bool WglLoadCoreProfile()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to load the core profile of WGL." );

		LoadFunctionAddress( ::Wgl::choose_pixel_format, ChoosePixelFormat );
		LoadFunctionAddress( ::Wgl::describe_pixel_format, reinterpret_cast<::Wgl::PFNDESCRIBEPIXELFORMATPROC>( DescribePixelFormat ) );
		LoadFunctionAddress( ::Wgl::get_enh_meta_file_pixel_format, reinterpret_cast<::Wgl::PFNGETENHMETAFILEPIXELFORMATPROC>( GetEnhMetaFilePixelFormat ) );
		LoadFunctionAddress( ::Wgl::get_pixel_format, GetPixelFormat );
		LoadFunctionAddress( ::Wgl::set_pixel_format, SetPixelFormat );
		LoadFunctionAddress( ::Wgl::swap_buffers, SwapBuffers );
		LoadFunctionAddress( ::Wgl::copy_context, wglCopyContext );
		LoadFunctionAddress( ::Wgl::create_context, wglCreateContext );
		LoadFunctionAddress( ::Wgl::create_layer_context, wglCreateLayerContext );
		LoadFunctionAddress( ::Wgl::delete_context, wglDeleteContext );
		LoadFunctionAddress( ::Wgl::describe_layer_plane, reinterpret_cast<::Wgl::PFNWGLDESCRIBELAYERPLANEPROC>( wglDescribeLayerPlane ) );
		LoadFunctionAddress( ::Wgl::get_current_context, wglGetCurrentContext );
		LoadFunctionAddress( ::Wgl::get_current_dc, wglGetCurrentDC );
		LoadFunctionAddress( ::Wgl::get_extensions_string_arb, "wglGetExtensionsStringARB" );
		LoadFunctionAddress( ::Wgl::get_extensions_string_ext, "wglGetExtensionsStringEXT" );
		LoadFunctionAddress( ::Wgl::get_layer_palette_entries, reinterpret_cast<::Wgl::PFNWGLGETLAYERPALETTEENTRIESPROC>( wglGetLayerPaletteEntries ) );
		LoadFunctionAddress( ::Wgl::get_proc_address, wglGetProcAddress );
		LoadFunctionAddress( ::Wgl::make_current, wglMakeCurrent );
		LoadFunctionAddress( ::Wgl::realize_layer_palette, wglRealizeLayerPalette );
		LoadFunctionAddress( ::Wgl::set_layer_palette_entries, wglSetLayerPaletteEntries );
		LoadFunctionAddress( ::Wgl::share_lists, wglShareLists );
		LoadFunctionAddress( ::Wgl::swap_layer_buffers, wglSwapLayerBuffers );
		LoadFunctionAddress( ::Wgl::use_font_bitmaps, wglUseFontBitmapsW );
		LoadFunctionAddress( ::Wgl::use_font_bitmaps_a, wglUseFontBitmapsA );
		LoadFunctionAddress( ::Wgl::use_font_bitmaps_w, wglUseFontBitmapsA );
		LoadFunctionAddress( ::Wgl::use_font_outlines, wglUseFontOutlinesW );
		LoadFunctionAddress( ::Wgl::use_font_outlines_a, wglUseFontOutlinesA );
		LoadFunctionAddress( ::Wgl::use_font_outlines_w, wglUseFontOutlinesW );

		const bool can_get_extensions = ( ::Wgl::get_extensions_string_arb != nullptr ) || ( ::Wgl::get_extensions_string_ext != nullptr );
		CRETE( !can_get_extensions, false, LOG_CHANNEL, "Failed to load core profile of WGL." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL core profile loaded." );
		return true;
	}

	const bool WglLoadExtensions()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to load WGL extensions." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the available extensions of WGL." );
		InitializeExtensionsState( AccessExtensionsState(), ::wglGetCurrentDC() );
		const ExtensionsState& extensions = GetExtensionsState();

		if( extensions.has_wgl_3dl_stereo_control )
		{
			LoadFunctionAddress( ::Wgl::set_stereo_emitter_state3d_l, "wglSetStereoEmitterState3DL" );
		}

		if( extensions.has_wgl_amd_gpu_association )
		{
			LoadFunctionAddress( ::Wgl::blit_context_framebuffer_amd, "wglBlitContextFramebufferAMD" );
			LoadFunctionAddress( ::Wgl::create_associated_context_amd, "wglCreateAssociatedContextAMD" );
			LoadFunctionAddress( ::Wgl::create_associated_context_attribs_amd, "wglCreateAssociatedContextAttribsAMD" );
			LoadFunctionAddress( ::Wgl::delete_associated_context_amd, "wglDeleteAssociatedContextAMD" );
			LoadFunctionAddress( ::Wgl::get_context_gpu_id_amd, "wglGetContextGPUIDAMD" );
			LoadFunctionAddress( ::Wgl::get_current_associated_context_amd, "wglGetCurrentAssociatedContextAMD" );
			LoadFunctionAddress( ::Wgl::get_gpu_ids_amd, "wglGetGPUIDsAMD" );
			LoadFunctionAddress( ::Wgl::get_gpu_info_amd, "wglGetGPUInfoAMD" );
			LoadFunctionAddress( ::Wgl::make_associated_context_current_amd, "wglMakeAssociatedContextCurrentAMD" );
		}

		if( extensions.has_wgl_arb_buffer_region )
		{
			LoadFunctionAddress( ::Wgl::create_buffer_region_arb, "wglCreateBufferRegionARB" );
			LoadFunctionAddress( ::Wgl::delete_buffer_region_arb, "wglDeleteBufferRegionARB" );
			LoadFunctionAddress( ::Wgl::restore_buffer_region_arb, "wglRestoreBufferRegionARB" );
			LoadFunctionAddress( ::Wgl::save_buffer_region_arb, "wglSaveBufferRegionARB" );
		}

		if( extensions.has_wgl_arb_create_context )
		{
			LoadFunctionAddress( ::Wgl::create_context_attribs_arb, "wglCreateContextAttribsARB" );
		}

		if( extensions.has_wgl_arb_make_current_read )
		{
			LoadFunctionAddress( ::Wgl::get_current_read_dc_arb, "wglGetCurrentReadDCARB" );
			LoadFunctionAddress( ::Wgl::make_context_current_arb, "wglMakeContextCurrentARB" );
		}

		if( extensions.has_wgl_arb_pbuffer )
		{
			LoadFunctionAddress( ::Wgl::create_pbuffer_arb, "wglCreatePbufferARB" );
			LoadFunctionAddress( ::Wgl::destroy_pbuffer_arb, "wglDestroyPbufferARB" );
			LoadFunctionAddress( ::Wgl::get_pbuffer_dc_arb, "wglGetPbufferDCARB" );
			LoadFunctionAddress( ::Wgl::query_pbuffer_arb, "wglQueryPbufferARB" );
			LoadFunctionAddress( ::Wgl::release_pbuffer_dc_arb, "wglReleasePbufferDCARB" );
		}

		if( extensions.has_wgl_arb_pixel_format )
		{
			LoadFunctionAddress( ::Wgl::choose_pixel_format_arb, "wglChoosePixelFormatARB" );
			LoadFunctionAddress( ::Wgl::get_pixel_format_attribfv_arb, "wglGetPixelFormatAttribfvARB" );
			LoadFunctionAddress( ::Wgl::get_pixel_format_attribiv_arb, "wglGetPixelFormatAttribivARB" );
		}

		if( extensions.has_wgl_arb_render_texture )
		{
			LoadFunctionAddress( ::Wgl::bind_tex_image_arb, "wglBindTexImageARB" );
			LoadFunctionAddress( ::Wgl::release_tex_image_arb, "wglReleaseTexImageARB" );
			LoadFunctionAddress( ::Wgl::set_pbuffer_attrib_arb, "wglSetPbufferAttribARB" );
		}

		if( extensions.has_wgl_ext_display_color_table )
		{
			LoadFunctionAddress( ::Wgl::bind_display_color_table_ext, "wglBindDisplayColorTableEXT" );
			LoadFunctionAddress( ::Wgl::create_display_color_table_ext, "wglCreateDisplayColorTableEXT" );
			LoadFunctionAddress( ::Wgl::destroy_display_color_table_ext, "wglDestroyDisplayColorTableEXT" );
			LoadFunctionAddress( ::Wgl::load_display_color_table_ext, "wglLoadDisplayColorTableEXT" );
		}

		if( extensions.has_wgl_ext_make_current_read )
		{
			LoadFunctionAddress( ::Wgl::get_current_read_dc_ext, "wglGetCurrentReadDCEXT" );
			LoadFunctionAddress( ::Wgl::make_context_current_ext, "wglMakeContextCurrentEXT" );
		}

		if( extensions.has_wgl_ext_pbuffer )
		{
			LoadFunctionAddress( ::Wgl::create_pbuffer_ext, "wglCreatePbufferEXT" );
			LoadFunctionAddress( ::Wgl::destroy_pbuffer_ext, "wglDestroyPbufferEXT" );
			LoadFunctionAddress( ::Wgl::get_pbuffer_dc_ext, "wglGetPbufferDCEXT" );
			LoadFunctionAddress( ::Wgl::query_pbuffer_ext, "wglQueryPbufferEXT" );
			LoadFunctionAddress( ::Wgl::release_pbuffer_dc_ext, "wglReleasePbufferDCEXT" );
		}

		if( extensions.has_wgl_ext_pixel_format )
		{
			LoadFunctionAddress( ::Wgl::choose_pixel_format_ext, "wglChoosePixelFormatEXT" );
			LoadFunctionAddress( ::Wgl::get_pixel_format_attribfv_ext, "wglGetPixelFormatAttribfvEXT" );
			LoadFunctionAddress( ::Wgl::get_pixel_format_attribiv_ext, "wglGetPixelFormatAttribivEXT" );
		}

		if( extensions.has_wgl_ext_swap_control )
		{
			LoadFunctionAddress( ::Wgl::get_swap_interval_ext, "wglGetSwapIntervalEXT" );
			LoadFunctionAddress( ::Wgl::swap_interval_ext, "wglSwapIntervalEXT" );
		}

		if( extensions.has_wgl_i3d_digital_video_control )
		{
			LoadFunctionAddress( ::Wgl::get_digital_video_parameters_i3d, "wglGetDigitalVideoParametersI3D" );
			LoadFunctionAddress( ::Wgl::set_digital_video_parameters_i3d, "wglSetDigitalVideoParametersI3D" );
		}

		if( extensions.has_wgl_i3d_gamma )
		{
			LoadFunctionAddress( ::Wgl::get_gamma_table_i3d, "wglGetGammaTableI3D" );
			LoadFunctionAddress( ::Wgl::get_gamma_table_parameters_i3d, "wglGetGammaTableParametersI3D" );
			LoadFunctionAddress( ::Wgl::set_gamma_table_i3d, "wglSetGammaTableI3D" );
			LoadFunctionAddress( ::Wgl::set_gamma_table_parameters_i3d, "wglSetGammaTableParametersI3D" );
		}

		if( extensions.has_wgl_i3d_genlock )
		{
			LoadFunctionAddress( ::Wgl::disable_genlock_i3d, "wglDisableGenlockI3D" );
			LoadFunctionAddress( ::Wgl::enable_genlock_i3d, "wglEnableGenlockI3D" );
			LoadFunctionAddress( ::Wgl::genlock_sample_rate_i3d, "wglGenlockSampleRateI3D" );
			LoadFunctionAddress( ::Wgl::genlock_source_delay_i3d, "wglGenlockSourceDelayI3D" );
			LoadFunctionAddress( ::Wgl::genlock_source_edge_i3d, "wglGenlockSourceEdgeI3D" );
			LoadFunctionAddress( ::Wgl::genlock_source_i3d, "wglGenlockSourceI3D" );
			LoadFunctionAddress( ::Wgl::get_genlock_sample_rate_i3d, "wglGetGenlockSampleRateI3D" );
			LoadFunctionAddress( ::Wgl::get_genlock_source_delay_i3d, "wglGetGenlockSourceDelayI3D" );
			LoadFunctionAddress( ::Wgl::get_genlock_source_edge_i3d, "wglGetGenlockSourceEdgeI3D" );
			LoadFunctionAddress( ::Wgl::get_genlock_source_i3d, "wglGetGenlockSourceI3D" );
			LoadFunctionAddress( ::Wgl::is_enabled_genlock_i3d, "wglIsEnabledGenlockI3D" );
			LoadFunctionAddress( ::Wgl::query_genlock_max_source_delay_i3d, "wglQueryGenlockMaxSourceDelayI3D" );
		}

		if( extensions.has_wgl_i3d_image_buffer )
		{
			LoadFunctionAddress( ::Wgl::associate_image_buffer_events_i3d, "wglAssociateImageBufferEventsI3D" );
			LoadFunctionAddress( ::Wgl::create_image_buffer_i3d, "wglCreateImageBufferI3D" );
			LoadFunctionAddress( ::Wgl::destroy_image_buffer_i3d, "wglDestroyImageBufferI3D" );
			LoadFunctionAddress( ::Wgl::release_image_buffer_events_i3d, "wglReleaseImageBufferEventsI3D" );
		}

		if( extensions.has_wgl_i3d_swap_frame_lock )
		{
			LoadFunctionAddress( ::Wgl::disable_frame_lock_i3d, "wglDisableFrameLockI3D" );
			LoadFunctionAddress( ::Wgl::enable_frame_lock_i3d, "wglEnableFrameLockI3D" );
			LoadFunctionAddress( ::Wgl::is_enabled_frame_lock_i3d, "wglIsEnabledFrameLockI3D" );
			LoadFunctionAddress( ::Wgl::query_frame_lock_master_i3d, "wglQueryFrameLockMasterI3D" );
		}

		if( extensions.has_wgl_i3d_swap_frame_usage )
		{
			LoadFunctionAddress( ::Wgl::begin_frame_tracking_i3d, "wglBeginFrameTrackingI3D" );
			LoadFunctionAddress( ::Wgl::end_frame_tracking_i3d, "wglEndFrameTrackingI3D" );
			LoadFunctionAddress( ::Wgl::get_frame_usage_i3d, "wglGetFrameUsageI3D" );
			LoadFunctionAddress( ::Wgl::query_frame_tracking_i3d, "wglQueryFrameTrackingI3D" );
		}

		if( extensions.has_wgl_nv_dx_interop )
		{
			LoadFunctionAddress( ::Wgl::dx_close_device_nv, "wglDXCloseDeviceNV" );
			LoadFunctionAddress( ::Wgl::dx_lock_objects_nv, "wglDXLockObjectsNV" );
			LoadFunctionAddress( ::Wgl::dx_object_access_nv, "wglDXObjectAccessNV" );
			LoadFunctionAddress( ::Wgl::dx_open_device_nv, "wglDXOpenDeviceNV" );
			LoadFunctionAddress( ::Wgl::dx_register_object_nv, "wglDXRegisterObjectNV" );
			LoadFunctionAddress( ::Wgl::dx_set_resource_share_handle_nv, "wglDXSetResourceShareHandleNV" );
			LoadFunctionAddress( ::Wgl::dx_unlock_objects_nv, "wglDXUnlockObjectsNV" );
			LoadFunctionAddress( ::Wgl::dx_unregister_object_nv, "wglDXUnregisterObjectNV" );
		}

		if( extensions.has_wgl_nv_copy_image )
		{
			LoadFunctionAddress( ::Wgl::copy_image_sub_data_nv, "wglCopyImageSubDataNV" );
		}

		if( extensions.has_wgl_nv_delay_before_swap )
		{
			LoadFunctionAddress( ::Wgl::delay_before_swap_nv, "wglDelayBeforeSwapNV" );
		}

		if( extensions.has_wgl_nv_gpu_affinity )
		{
			LoadFunctionAddress( ::Wgl::create_affinity_dc_nv, "wglCreateAffinityDCNV" );
			LoadFunctionAddress( ::Wgl::delete_dc_nv, "wglDeleteDCNV" );
			LoadFunctionAddress( ::Wgl::enum_gpu_devices_nv, "wglEnumGpuDevicesNV" );
			LoadFunctionAddress( ::Wgl::enum_gpus_from_affinity_dc_nv, "wglEnumGpusFromAffinityDCNV" );
			LoadFunctionAddress( ::Wgl::enum_gpus_nv, "wglEnumGpusNV" );
		}

		if( extensions.has_wgl_nv_present_video )
		{
			LoadFunctionAddress( ::Wgl::bind_video_device_nv, "wglBindVideoDeviceNV" );
			LoadFunctionAddress( ::Wgl::enumerate_video_devices_nv, "wglEnumerateVideoDevicesNV" );
			LoadFunctionAddress( ::Wgl::query_current_context_nv, "wglQueryCurrentContextNV" );
		}

		if( extensions.has_wgl_nv_swap_group )
		{
			LoadFunctionAddress( ::Wgl::bind_swap_barrier_nv, "wglBindSwapBarrierNV" );
			LoadFunctionAddress( ::Wgl::join_swap_group_nv, "wglJoinSwapGroupNV" );
			LoadFunctionAddress( ::Wgl::query_frame_count_nv, "wglQueryFrameCountNV" );
			LoadFunctionAddress( ::Wgl::query_max_swap_groups_nv, "wglQueryMaxSwapGroupsNV" );
			LoadFunctionAddress( ::Wgl::query_swap_group_nv, "wglQuerySwapGroupNV" );
			LoadFunctionAddress( ::Wgl::reset_frame_count_nv, "wglResetFrameCountNV" );
		}

		if( extensions.has_wgl_nv_vertex_array_range )
		{
			LoadFunctionAddress( ::Wgl::allocate_memory_nv, "wglAllocateMemoryNV" );
			LoadFunctionAddress( ::Wgl::free_memory_nv, "wglFreeMemoryNV" );
		}

		if( extensions.has_wgl_nv_video_capture )
		{
			LoadFunctionAddress( ::Wgl::bind_video_capture_device_nv, "wglBindVideoCaptureDeviceNV" );
			LoadFunctionAddress( ::Wgl::enumerate_video_capture_devices_nv, "wglEnumerateVideoCaptureDevicesNV" );
			LoadFunctionAddress( ::Wgl::lock_video_capture_device_nv, "wglLockVideoCaptureDeviceNV" );
			LoadFunctionAddress( ::Wgl::query_video_capture_device_nv, "wglQueryVideoCaptureDeviceNV" );
			LoadFunctionAddress( ::Wgl::release_video_capture_device_nv, "wglReleaseVideoCaptureDeviceNV" );
		}

		if( extensions.has_wgl_nv_video_output )
		{
			LoadFunctionAddress( ::Wgl::bind_video_image_nv, "wglBindVideoImageNV" );
			LoadFunctionAddress( ::Wgl::get_video_device_nv, "wglGetVideoDeviceNV" );
			LoadFunctionAddress( ::Wgl::get_video_info_nv, "wglGetVideoInfoNV" );
			LoadFunctionAddress( ::Wgl::release_video_device_nv, "wglReleaseVideoDeviceNV" );
			LoadFunctionAddress( ::Wgl::release_video_image_nv, "wglReleaseVideoImageNV" );
			LoadFunctionAddress( ::Wgl::send_pbuffer_to_video_nv, "wglSendPbufferToVideoNV" );
		}

		if( extensions.has_wgl_oml_sync_control )
		{
			LoadFunctionAddress( ::Wgl::get_msc_rate_oml, "wglGetMscRateOML" );
			LoadFunctionAddress( ::Wgl::get_sync_values_oml, "wglGetSyncValuesOML" );
			LoadFunctionAddress( ::Wgl::swap_buffers_msc_oml, "wglSwapBuffersMscOML" );
			LoadFunctionAddress( ::Wgl::swap_layer_buffers_msc_oml, "wglSwapLayerBuffersMscOML" );
			LoadFunctionAddress( ::Wgl::wait_for_msc_oml, "wglWaitForMscOML" );
			LoadFunctionAddress( ::Wgl::wait_for_sbc_oml, "wglWaitForSbcOML" );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL extensions loaded." );
		return true;
	}

	const ExtensionsState& GetExtensionsState()
	{
		return AccessExtensionsState();
	}
}
}
}
}
