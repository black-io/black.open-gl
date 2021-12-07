#include <black/open-gl.h>
#include <black/core/algorithms.h>

#include <wingdi.h>

#include "functions.wgl-initialization.h"

#include "bindings.wgl.h"
#include "bindings.wgl-extensions.h"
#include "functions.wgl-settings.h"


namespace Wgl
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/WGL";

	// Name of stub window class.
	const wchar_t* STUB_WINDOW_CLASS_NAME = L"Black::Framework::WGL::StubWindow";


	// Select the best pixel format for WGL initialization.
	inline std::optional<int32_t> SelectPixelFormat( const Black::EglDisplay& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Selecting the best pixel format." );

		const ::PIXELFORMATDESCRIPTOR format_descriptor{
			sizeof( ::PIXELFORMATDESCRIPTOR ),							// nSize
			1,															// nVersion
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,	// dwFlags
			PFD_TYPE_RGBA,												// iPixelType
			::BYTE( display.GetDesktopSettings().dmBitsPerPel ),		// cColorBits
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

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Accessing the temporary device context." );
		const ::HDC device_context = ::CreateDCW( nullptr, display.GetOutputDescription().DeviceName, nullptr, nullptr );
		CRETE( device_context == nullptr, {}, LOG_CHANNEL, "Failed to create temporary device context." );

		// Guard will delete this device context on function end.
		const auto device_context_guard = Black::ScopeLeaveHandler{
			[device_context]()
			{
				if( ::DeleteDC( device_context ) != TRUE )
				{
					BLACK_LOG_WARNING( LOG_CHANNEL, "The deletion of temporary device context does not went properly." );
				}
			}
		};

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Selecting the pixel format for device context." );
		const int pixel_format = ::ChoosePixelFormat( device_context, &format_descriptor );
		CRETE( pixel_format == 0, {}, LOG_CHANNEL, "Failed to select pixel format for device context, error: 0x{:08X}", ::GetLastError() );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Pixel format #{} was chosen.", pixel_format );
		return { pixel_format };
	}

	// Create the device context for selected display.
	inline std::optional<::HDC> CreateDisplayConntext( const Black::EglDisplay& display, const int32_t pixel_format )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to create the device context for selected display." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Creating the device context for selected display." );
		const ::HDC device_context = ::CreateDCW( nullptr, display.GetOutputDescription().DeviceName, nullptr, nullptr );
		CRETE( device_context == nullptr, {}, LOG_CHANNEL, "Failed to create device context." );

		// Guard to delete the device context upon the error. It will be canceled on function success.
		auto device_context_guard = Black::ScopeLeaveHandler{
			[device_context]()
			{
				if( ::DeleteDC( device_context ) != TRUE )
				{
					BLACK_LOG_WARNING( LOG_CHANNEL, "The deletion of device context does not went properly." );
				}
			}
		};

		{
			::PIXELFORMATDESCRIPTOR format_descriptor{};
			const int32_t access_result = ::DescribePixelFormat( device_context, pixel_format, sizeof( format_descriptor ), &format_descriptor );
			CRETE( access_result == 0, {}, LOG_CHANNEL, "Failed to describe pixel format, error: 0x{:08X}.", ::GetLastError() );

			const bool has_format_set = ::SetPixelFormat( device_context, pixel_format, &format_descriptor ) == TRUE;
			if( !has_format_set )
			{
				BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to set pixel format for device context, error: 0x{:08X}.", ::GetLastError() );
			}
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Device context successfully created." );
		device_context_guard.Cancel();
		return { device_context };
	}

	// Delete the previously created device context.
	inline void DestroyDisplayContext( ::HDC device_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Device context for display will be deleted." );
		if( ::DeleteDC( device_context ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "The deletion of device context does not went properly." );
		}
	}

	// Retrieve the desktop area represented by display.
	inline std::optional<::RECT> GetDisplayDesktopArea( const Black::EglDisplay& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to get the desktop area of display." );

		const ::RECT& result = display.GetOutputDescription().DesktopCoordinates;
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
	inline std::optional<::HDC> AcquireWindowContext( const ::HWND window, const int32_t pixel_format )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to Acquire the device context for window." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Accessing the device context of window." );
		const ::HDC device_context = ::GetDC( window );
		CRETE( device_context == nullptr, {}, LOG_CHANNEL, "Failed to get device context." );

		{
			::PIXELFORMATDESCRIPTOR format_descriptor{};
			const int32_t access_result = ::DescribePixelFormat( device_context, pixel_format, sizeof( format_descriptor ), &format_descriptor );
			CRETE( access_result == 0, {}, LOG_CHANNEL, "Failed to describe pixel format, error: 0x{:08X}.", ::GetLastError() );

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
	inline void ReleaseWindowContext( const ::HWND window, const ::HDC device_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Releasing the device context of window." );
		::ReleaseDC( window, device_context );
	}

	// Create the compatible OpenGL context regardless to version and options. Once the context is created, it will be set automatically.
	inline std::optional<::HGLRC> CreateGraphicsContext( const ::HDC device_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to create the dummy OpenGL context." );

		const ::HGLRC graphics_context = ::Wgl::create_context( device_context );
		CRETE( graphics_context == nullptr, {}, LOG_CHANNEL, "Failed to create OpenGL context, error: 0x{:08X}.", ::GetLastError() );

		auto context_guard = Black::ScopeLeaveHandler{
			[graphics_context]()
			{
				if( ::Wgl::delete_context( graphics_context ) != TRUE )
				{
					BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to delete the graphics context, error: 0x{:08X}", ::GetLastError() );
				}
			}
		};

		BLACK_LOG_DEBUG( LOG_CHANNEL, "OpenGL context created successfully." );
		context_guard.Cancel();
		return graphics_context;
	}

	// Destroy the OpenGL context.
	inline void DestroyGraphicsContext( const ::HGLRC graphics_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Deleting the OpenGL context." );

		if( ::Wgl::delete_context( graphics_context ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to delete the graphics context, error: 0x{:08X}", ::GetLastError() );
		}
	}

	// Load the address of WGL function using the given function name.
	template< typename TFunction >
	inline void LoadFunctionAddress( TFunction& destination_popinter, const char* name, const Black::EglConnection& connection )
	{
		destination_popinter = reinterpret_cast<TFunction>( connection.GetFunctionAddress( name ) );
		if( destination_popinter == nullptr )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Function '{}' does not found.", std::string_view{ name } );
		}
	}
}


	const bool InitializeBindings( const Black::EglConnection& connection, const Black::EglDisplay& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to initialize the WGL layer." );

		// Load the WGL Core profile.
		CRETE( !LoadCoreProfile( connection ), false, LOG_CHANNEL, "Failed to initialize WGL." );

		const auto pixel_format = SelectPixelFormat( display );
		CRETE( !pixel_format.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		const auto display_context = CreateDisplayConntext( display, *pixel_format );
		CRETE( !display_context.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard to properly destroy the created display context.
		const auto display_context_guard = Black::ScopeLeaveHandler{
			[context = *display_context]()
			{
				DestroyDisplayContext( context );
			}
		};

		const auto graphics_context = CreateGraphicsContext( *display_context );
		CRETE( graphics_context == nullptr, false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard to properly destroy the OpenGL context.
		auto gl_guard = Black::ScopeLeaveHandler{
			[context = *graphics_context]()
			{
				DestroyGraphicsContext( context );
			}
		};

		const auto desktop_area = GetDisplayDesktopArea( display );
		CRETE( !desktop_area.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		CRETE( !RegisterStubWindowClass(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard to revert the window class registration on function end.
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

		const auto window_context = AcquireWindowContext( *window_handle, *pixel_format );
		CRETE( !window_context.has_value(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Guard to release the device context.
		auto context_guard = Black::ScopeLeaveHandler{
			[context = *window_context, window = *window_handle]()
			{
				ReleaseWindowContext( window, context );
			}
		};

		// Make the graphics context current to proceed the WGL initialization.
		const bool is_context_set = ::Wgl::make_current( *window_context, *graphics_context );
		CRETE( !is_context_set, false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Read the WGL extensions.
		CRETE( !LoadExtensions( connection ), false, LOG_CHANNEL, "Failed to initialize WGL." );

		::Wgl::make_current( nullptr, nullptr );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL layer initialized successfully." );
		return true;
	}

	const bool LoadCoreProfile( const Black::EglConnection& connection )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to load the core profile of WGL." );

		LoadFunctionAddress( copy_context, "wglCopyContext", connection );
		LoadFunctionAddress( create_context, "wglCreateContext", connection );
		LoadFunctionAddress( create_layer_context, "wglCreateLayerContext", connection );
		LoadFunctionAddress( delete_context, "wglDeleteContext", connection );
		LoadFunctionAddress( describe_layer_plane, "wglDescribeLayerPlane", connection );
		LoadFunctionAddress( get_current_context, "wglGetCurrentContext", connection );
		LoadFunctionAddress( get_current_dc, "wglGetCurrentDC", connection );
		LoadFunctionAddress( get_layer_palette_entries, "wglGetLayerPaletteEntries", connection );
		LoadFunctionAddress( get_proc_address, "wglGetProcAddress", connection );
		LoadFunctionAddress( make_current, "wglMakeCurrent", connection );
		LoadFunctionAddress( realize_layer_palette, "wglRealizeLayerPalette", connection );
		LoadFunctionAddress( set_layer_palette_entries, "wglSetLayerPaletteEntries", connection );
		LoadFunctionAddress( share_lists, "wglShareLists", connection );
		LoadFunctionAddress( swap_layer_buffers, "wglSwapLayerBuffers", connection );
		LoadFunctionAddress( use_font_bitmaps, "wglUseFontBitmapsW", connection );
		LoadFunctionAddress( use_font_bitmaps_a, "wglUseFontBitmapsA", connection );
		LoadFunctionAddress( use_font_bitmaps_w, "wglUseFontBitmapsW", connection );
		LoadFunctionAddress( use_font_outlines, "wglUseFontOutlinesW", connection );
		LoadFunctionAddress( use_font_outlines_a, "wglUseFontOutlinesA", connection );
		LoadFunctionAddress( use_font_outlines_w, "wglUseFontOutlinesW", connection );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL core profile loaded." );
		return true;
	}

	const bool LoadExtensions( const Black::EglConnection& connection )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to load WGL extensions." );

		LoadFunctionAddress( get_extensions_string_arb, "wglGetExtensionsStringARB", connection );
		LoadFunctionAddress( get_extensions_string_ext, "wglGetExtensionsStringEXT", connection );

		const bool can_get_extensions = ( get_extensions_string_arb != nullptr ) || ( get_extensions_string_ext != nullptr );
		CRETE( !can_get_extensions, false, LOG_CHANNEL, "Failed to read extensions of WGL." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the available extensions of WGL." );
		const ExtensionsState& extensions = GetExtensionsState();

		if( extensions.has_wgl_3dl_stereo_control )
		{
			LoadFunctionAddress( set_stereo_emitter_state3d_l, "wglSetStereoEmitterState3DL", connection );
		}

		if( extensions.has_wgl_amd_gpu_association )
		{
			LoadFunctionAddress( blit_context_framebuffer_amd, "wglBlitContextFramebufferAMD", connection );
			LoadFunctionAddress( create_associated_context_amd, "wglCreateAssociatedContextAMD", connection );
			LoadFunctionAddress( create_associated_context_attribs_amd, "wglCreateAssociatedContextAttribsAMD", connection );
			LoadFunctionAddress( delete_associated_context_amd, "wglDeleteAssociatedContextAMD", connection );
			LoadFunctionAddress( get_context_gpu_id_amd, "wglGetContextGPUIDAMD", connection );
			LoadFunctionAddress( get_current_associated_context_amd, "wglGetCurrentAssociatedContextAMD", connection );
			LoadFunctionAddress( get_gpu_ids_amd, "wglGetGPUIDsAMD", connection );
			LoadFunctionAddress( get_gpu_info_amd, "wglGetGPUInfoAMD", connection );
			LoadFunctionAddress( make_associated_context_current_amd, "wglMakeAssociatedContextCurrentAMD", connection );
		}

		if( extensions.has_wgl_arb_buffer_region )
		{
			LoadFunctionAddress( create_buffer_region_arb, "wglCreateBufferRegionARB", connection );
			LoadFunctionAddress( delete_buffer_region_arb, "wglDeleteBufferRegionARB", connection );
			LoadFunctionAddress( restore_buffer_region_arb, "wglRestoreBufferRegionARB", connection );
			LoadFunctionAddress( save_buffer_region_arb, "wglSaveBufferRegionARB", connection );
		}

		if( extensions.has_wgl_arb_create_context )
		{
			LoadFunctionAddress( create_context_attribs_arb, "wglCreateContextAttribsARB", connection );
		}

		if( extensions.has_wgl_arb_make_current_read )
		{
			LoadFunctionAddress( get_current_read_dc_arb, "wglGetCurrentReadDCARB", connection );
			LoadFunctionAddress( make_context_current_arb, "wglMakeContextCurrentARB", connection );
		}

		if( extensions.has_wgl_arb_pbuffer )
		{
			LoadFunctionAddress( create_pbuffer_arb, "wglCreatePbufferARB", connection );
			LoadFunctionAddress( destroy_pbuffer_arb, "wglDestroyPbufferARB", connection );
			LoadFunctionAddress( get_pbuffer_dc_arb, "wglGetPbufferDCARB", connection );
			LoadFunctionAddress( query_pbuffer_arb, "wglQueryPbufferARB", connection );
			LoadFunctionAddress( release_pbuffer_dc_arb, "wglReleasePbufferDCARB", connection );
		}

		if( extensions.has_wgl_arb_pixel_format )
		{
			LoadFunctionAddress( choose_pixel_format_arb, "wglChoosePixelFormatARB", connection );
			LoadFunctionAddress( get_pixel_format_attribfv_arb, "wglGetPixelFormatAttribfvARB", connection );
			LoadFunctionAddress( get_pixel_format_attribiv_arb, "wglGetPixelFormatAttribivARB", connection );
		}

		if( extensions.has_wgl_arb_render_texture )
		{
			LoadFunctionAddress( bind_tex_image_arb, "wglBindTexImageARB", connection );
			LoadFunctionAddress( release_tex_image_arb, "wglReleaseTexImageARB", connection );
			LoadFunctionAddress( set_pbuffer_attrib_arb, "wglSetPbufferAttribARB", connection );
		}

		if( extensions.has_wgl_ext_display_color_table )
		{
			LoadFunctionAddress( bind_display_color_table_ext, "wglBindDisplayColorTableEXT", connection );
			LoadFunctionAddress( create_display_color_table_ext, "wglCreateDisplayColorTableEXT", connection );
			LoadFunctionAddress( destroy_display_color_table_ext, "wglDestroyDisplayColorTableEXT", connection );
			LoadFunctionAddress( load_display_color_table_ext, "wglLoadDisplayColorTableEXT", connection );
		}

		if( extensions.has_wgl_ext_make_current_read )
		{
			LoadFunctionAddress( get_current_read_dc_ext, "wglGetCurrentReadDCEXT", connection );
			LoadFunctionAddress( make_context_current_ext, "wglMakeContextCurrentEXT", connection );
		}

		if( extensions.has_wgl_ext_pbuffer )
		{
			LoadFunctionAddress( create_pbuffer_ext, "wglCreatePbufferEXT", connection );
			LoadFunctionAddress( destroy_pbuffer_ext, "wglDestroyPbufferEXT", connection );
			LoadFunctionAddress( get_pbuffer_dc_ext, "wglGetPbufferDCEXT", connection );
			LoadFunctionAddress( query_pbuffer_ext, "wglQueryPbufferEXT", connection );
			LoadFunctionAddress( release_pbuffer_dc_ext, "wglReleasePbufferDCEXT", connection );
		}

		if( extensions.has_wgl_ext_pixel_format )
		{
			LoadFunctionAddress( choose_pixel_format_ext, "wglChoosePixelFormatEXT", connection );
			LoadFunctionAddress( get_pixel_format_attribfv_ext, "wglGetPixelFormatAttribfvEXT", connection );
			LoadFunctionAddress( get_pixel_format_attribiv_ext, "wglGetPixelFormatAttribivEXT", connection );
		}

		if( extensions.has_wgl_ext_swap_control )
		{
			LoadFunctionAddress( get_swap_interval_ext, "wglGetSwapIntervalEXT", connection );
			LoadFunctionAddress( swap_interval_ext, "wglSwapIntervalEXT", connection );
		}

		if( extensions.has_wgl_i3d_digital_video_control )
		{
			LoadFunctionAddress( get_digital_video_parameters_i3d, "wglGetDigitalVideoParametersI3D", connection );
			LoadFunctionAddress( set_digital_video_parameters_i3d, "wglSetDigitalVideoParametersI3D", connection );
		}

		if( extensions.has_wgl_i3d_gamma )
		{
			LoadFunctionAddress( get_gamma_table_i3d, "wglGetGammaTableI3D", connection );
			LoadFunctionAddress( get_gamma_table_parameters_i3d, "wglGetGammaTableParametersI3D", connection );
			LoadFunctionAddress( set_gamma_table_i3d, "wglSetGammaTableI3D", connection );
			LoadFunctionAddress( set_gamma_table_parameters_i3d, "wglSetGammaTableParametersI3D", connection );
		}

		if( extensions.has_wgl_i3d_genlock )
		{
			LoadFunctionAddress( disable_genlock_i3d, "wglDisableGenlockI3D", connection );
			LoadFunctionAddress( enable_genlock_i3d, "wglEnableGenlockI3D", connection );
			LoadFunctionAddress( genlock_sample_rate_i3d, "wglGenlockSampleRateI3D", connection );
			LoadFunctionAddress( genlock_source_delay_i3d, "wglGenlockSourceDelayI3D", connection );
			LoadFunctionAddress( genlock_source_edge_i3d, "wglGenlockSourceEdgeI3D", connection );
			LoadFunctionAddress( genlock_source_i3d, "wglGenlockSourceI3D", connection );
			LoadFunctionAddress( get_genlock_sample_rate_i3d, "wglGetGenlockSampleRateI3D", connection );
			LoadFunctionAddress( get_genlock_source_delay_i3d, "wglGetGenlockSourceDelayI3D", connection );
			LoadFunctionAddress( get_genlock_source_edge_i3d, "wglGetGenlockSourceEdgeI3D", connection );
			LoadFunctionAddress( get_genlock_source_i3d, "wglGetGenlockSourceI3D", connection );
			LoadFunctionAddress( is_enabled_genlock_i3d, "wglIsEnabledGenlockI3D", connection );
			LoadFunctionAddress( query_genlock_max_source_delay_i3d, "wglQueryGenlockMaxSourceDelayI3D", connection );
		}

		if( extensions.has_wgl_i3d_image_buffer )
		{
			LoadFunctionAddress( associate_image_buffer_events_i3d, "wglAssociateImageBufferEventsI3D", connection );
			LoadFunctionAddress( create_image_buffer_i3d, "wglCreateImageBufferI3D", connection );
			LoadFunctionAddress( destroy_image_buffer_i3d, "wglDestroyImageBufferI3D", connection );
			LoadFunctionAddress( release_image_buffer_events_i3d, "wglReleaseImageBufferEventsI3D", connection );
		}

		if( extensions.has_wgl_i3d_swap_frame_lock )
		{
			LoadFunctionAddress( disable_frame_lock_i3d, "wglDisableFrameLockI3D", connection );
			LoadFunctionAddress( enable_frame_lock_i3d, "wglEnableFrameLockI3D", connection );
			LoadFunctionAddress( is_enabled_frame_lock_i3d, "wglIsEnabledFrameLockI3D", connection );
			LoadFunctionAddress( query_frame_lock_master_i3d, "wglQueryFrameLockMasterI3D", connection );
		}

		if( extensions.has_wgl_i3d_swap_frame_usage )
		{
			LoadFunctionAddress( begin_frame_tracking_i3d, "wglBeginFrameTrackingI3D", connection );
			LoadFunctionAddress( end_frame_tracking_i3d, "wglEndFrameTrackingI3D", connection );
			LoadFunctionAddress( get_frame_usage_i3d, "wglGetFrameUsageI3D", connection );
			LoadFunctionAddress( query_frame_tracking_i3d, "wglQueryFrameTrackingI3D", connection );
		}

		if( extensions.has_wgl_nv_dx_interop )
		{
			LoadFunctionAddress( dx_close_device_nv, "wglDXCloseDeviceNV", connection );
			LoadFunctionAddress( dx_lock_objects_nv, "wglDXLockObjectsNV", connection );
			LoadFunctionAddress( dx_object_access_nv, "wglDXObjectAccessNV", connection );
			LoadFunctionAddress( dx_open_device_nv, "wglDXOpenDeviceNV", connection );
			LoadFunctionAddress( dx_register_object_nv, "wglDXRegisterObjectNV", connection );
			LoadFunctionAddress( dx_set_resource_share_handle_nv, "wglDXSetResourceShareHandleNV", connection );
			LoadFunctionAddress( dx_unlock_objects_nv, "wglDXUnlockObjectsNV", connection );
			LoadFunctionAddress( dx_unregister_object_nv, "wglDXUnregisterObjectNV", connection );
		}

		if( extensions.has_wgl_nv_copy_image )
		{
			LoadFunctionAddress( copy_image_sub_data_nv, "wglCopyImageSubDataNV", connection );
		}

		if( extensions.has_wgl_nv_delay_before_swap )
		{
			LoadFunctionAddress( delay_before_swap_nv, "wglDelayBeforeSwapNV", connection );
		}

		if( extensions.has_wgl_nv_gpu_affinity )
		{
			LoadFunctionAddress( create_affinity_dc_nv, "wglCreateAffinityDCNV", connection );
			LoadFunctionAddress( delete_dc_nv, "wglDeleteDCNV", connection );
			LoadFunctionAddress( enum_gpu_devices_nv, "wglEnumGpuDevicesNV", connection );
			LoadFunctionAddress( enum_gpus_from_affinity_dc_nv, "wglEnumGpusFromAffinityDCNV", connection );
			LoadFunctionAddress( enum_gpus_nv, "wglEnumGpusNV", connection );
		}

		if( extensions.has_wgl_nv_present_video )
		{
			LoadFunctionAddress( bind_video_device_nv, "wglBindVideoDeviceNV", connection );
			LoadFunctionAddress( enumerate_video_devices_nv, "wglEnumerateVideoDevicesNV", connection );
			LoadFunctionAddress( query_current_context_nv, "wglQueryCurrentContextNV", connection );
		}

		if( extensions.has_wgl_nv_swap_group )
		{
			LoadFunctionAddress( bind_swap_barrier_nv, "wglBindSwapBarrierNV", connection );
			LoadFunctionAddress( join_swap_group_nv, "wglJoinSwapGroupNV", connection );
			LoadFunctionAddress( query_frame_count_nv, "wglQueryFrameCountNV", connection );
			LoadFunctionAddress( query_max_swap_groups_nv, "wglQueryMaxSwapGroupsNV", connection );
			LoadFunctionAddress( query_swap_group_nv, "wglQuerySwapGroupNV", connection );
			LoadFunctionAddress( reset_frame_count_nv, "wglResetFrameCountNV", connection );
		}

		if( extensions.has_wgl_nv_vertex_array_range )
		{
			LoadFunctionAddress( allocate_memory_nv, "wglAllocateMemoryNV", connection );
			LoadFunctionAddress( free_memory_nv, "wglFreeMemoryNV", connection );
		}

		if( extensions.has_wgl_nv_video_capture )
		{
			LoadFunctionAddress( bind_video_capture_device_nv, "wglBindVideoCaptureDeviceNV", connection );
			LoadFunctionAddress( enumerate_video_capture_devices_nv, "wglEnumerateVideoCaptureDevicesNV", connection );
			LoadFunctionAddress( lock_video_capture_device_nv, "wglLockVideoCaptureDeviceNV", connection );
			LoadFunctionAddress( query_video_capture_device_nv, "wglQueryVideoCaptureDeviceNV", connection );
			LoadFunctionAddress( release_video_capture_device_nv, "wglReleaseVideoCaptureDeviceNV", connection );
		}

		if( extensions.has_wgl_nv_video_output )
		{
			LoadFunctionAddress( bind_video_image_nv, "wglBindVideoImageNV", connection );
			LoadFunctionAddress( get_video_device_nv, "wglGetVideoDeviceNV", connection );
			LoadFunctionAddress( get_video_info_nv, "wglGetVideoInfoNV", connection );
			LoadFunctionAddress( release_video_device_nv, "wglReleaseVideoDeviceNV", connection );
			LoadFunctionAddress( release_video_image_nv, "wglReleaseVideoImageNV", connection );
			LoadFunctionAddress( send_pbuffer_to_video_nv, "wglSendPbufferToVideoNV", connection );
		}

		if( extensions.has_wgl_oml_sync_control )
		{
			LoadFunctionAddress( get_msc_rate_oml, "wglGetMscRateOML", connection );
			LoadFunctionAddress( get_sync_values_oml, "wglGetSyncValuesOML", connection );
			LoadFunctionAddress( swap_buffers_msc_oml, "wglSwapBuffersMscOML", connection );
			LoadFunctionAddress( swap_layer_buffers_msc_oml, "wglSwapLayerBuffersMscOML", connection );
			LoadFunctionAddress( wait_for_msc_oml, "wglWaitForMscOML", connection );
			LoadFunctionAddress( wait_for_sbc_oml, "wglWaitForSbcOML", connection );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL extensions loaded." );
		return true;
	}
}
