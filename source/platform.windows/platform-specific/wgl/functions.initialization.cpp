#include <black/open-gl.h>
#include <black/core/algorithms.h>

#include <wingdi.h>

#include "functions.initialization.h"
#include "functions.settings.h"
#include "bindings.wgl.h"
#include "bindings.wgl-extensions.h"


namespace Wgl
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/WGL";

	// Name of stub window class.
	const wchar_t* STUB_WINDOW_CLASS_NAME = L"Black::Framework::Wgl::StubWindow";


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

		BLACK_LOG_DEBUG( LOG_CHANNEL, "OpenGL context created successfully." );
		context_guard.Cancel();
		return graphics_context;
	}

	// Destroy the OpenGL context.
	inline void DestroyGraphicsContext( const ::HGLRC graphics_context )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Deleting the OpenGL context." );

		if( ::wglDeleteContext( graphics_context ) != TRUE )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Failed to delete the graphics context, error: 0x{:08X}", ::GetLastError() );
		}
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


	const bool InitializeBindings( const Black::EglDisplay& display )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Attempt to initialize the WGL layer." );

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
		const bool is_context_set = ::wglMakeCurrent( *window_context, *graphics_context );
		CRETE( !is_context_set, false, LOG_CHANNEL, "Failed to initialize WGL." );

		// Perform the WGL initialization.
		CRETE( !LoadCoreProfile(), false, LOG_CHANNEL, "Failed to initialize WGL." );
		CRETE( !LoadExtensions(), false, LOG_CHANNEL, "Failed to initialize WGL." );

		::wglMakeCurrent( nullptr, nullptr );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL layer initialized successfully." );
		return true;
	}

	const bool LoadCoreProfile()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to load the core profile of WGL." );

		LoadFunctionAddress( choose_pixel_format, ChoosePixelFormat );
		LoadFunctionAddress( describe_pixel_format, reinterpret_cast<PFNDESCRIBEPIXELFORMATPROC>( DescribePixelFormat ) );
		LoadFunctionAddress( get_enh_meta_file_pixel_format, reinterpret_cast<PFNGETENHMETAFILEPIXELFORMATPROC>( GetEnhMetaFilePixelFormat ) );
		LoadFunctionAddress( get_pixel_format, GetPixelFormat );
		LoadFunctionAddress( set_pixel_format, SetPixelFormat );
		LoadFunctionAddress( swap_buffers, SwapBuffers );
		LoadFunctionAddress( copy_context, wglCopyContext );
		LoadFunctionAddress( create_context, wglCreateContext );
		LoadFunctionAddress( create_layer_context, wglCreateLayerContext );
		LoadFunctionAddress( delete_context, wglDeleteContext );
		LoadFunctionAddress( describe_layer_plane, reinterpret_cast<PFNWGLDESCRIBELAYERPLANEPROC>( wglDescribeLayerPlane ) );
		LoadFunctionAddress( get_current_context, wglGetCurrentContext );
		LoadFunctionAddress( get_current_dc, wglGetCurrentDC );
		LoadFunctionAddress( get_extensions_string_arb, "wglGetExtensionsStringARB" );
		LoadFunctionAddress( get_extensions_string_ext, "wglGetExtensionsStringEXT" );
		LoadFunctionAddress( get_layer_palette_entries, reinterpret_cast<PFNWGLGETLAYERPALETTEENTRIESPROC>( wglGetLayerPaletteEntries ) );
		LoadFunctionAddress( get_proc_address, wglGetProcAddress );
		LoadFunctionAddress( make_current, wglMakeCurrent );
		LoadFunctionAddress( realize_layer_palette, wglRealizeLayerPalette );
		LoadFunctionAddress( set_layer_palette_entries, wglSetLayerPaletteEntries );
		LoadFunctionAddress( share_lists, wglShareLists );
		LoadFunctionAddress( swap_layer_buffers, wglSwapLayerBuffers );
		LoadFunctionAddress( use_font_bitmaps, wglUseFontBitmapsW );
		LoadFunctionAddress( use_font_bitmaps_a, wglUseFontBitmapsA );
		LoadFunctionAddress( use_font_bitmaps_w, wglUseFontBitmapsA );
		LoadFunctionAddress( use_font_outlines, wglUseFontOutlinesW );
		LoadFunctionAddress( use_font_outlines_a, wglUseFontOutlinesA );
		LoadFunctionAddress( use_font_outlines_w, wglUseFontOutlinesW );

		const bool can_get_extensions = ( get_extensions_string_arb != nullptr ) || ( get_extensions_string_ext != nullptr );
		CRETE( !can_get_extensions, false, LOG_CHANNEL, "Failed to load core profile of WGL." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL core profile loaded." );
		return true;
	}

	const bool LoadExtensions()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Trying to load WGL extensions." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the available extensions of WGL." );
		const ExtensionsState& extensions = GetExtensionsState();

		if( extensions.has_wgl_3dl_stereo_control )
		{
			LoadFunctionAddress( set_stereo_emitter_state3d_l, "wglSetStereoEmitterState3DL" );
		}

		if( extensions.has_wgl_amd_gpu_association )
		{
			LoadFunctionAddress( blit_context_framebuffer_amd, "wglBlitContextFramebufferAMD" );
			LoadFunctionAddress( create_associated_context_amd, "wglCreateAssociatedContextAMD" );
			LoadFunctionAddress( create_associated_context_attribs_amd, "wglCreateAssociatedContextAttribsAMD" );
			LoadFunctionAddress( delete_associated_context_amd, "wglDeleteAssociatedContextAMD" );
			LoadFunctionAddress( get_context_gpu_id_amd, "wglGetContextGPUIDAMD" );
			LoadFunctionAddress( get_current_associated_context_amd, "wglGetCurrentAssociatedContextAMD" );
			LoadFunctionAddress( get_gpu_ids_amd, "wglGetGPUIDsAMD" );
			LoadFunctionAddress( get_gpu_info_amd, "wglGetGPUInfoAMD" );
			LoadFunctionAddress( make_associated_context_current_amd, "wglMakeAssociatedContextCurrentAMD" );
		}

		if( extensions.has_wgl_arb_buffer_region )
		{
			LoadFunctionAddress( create_buffer_region_arb, "wglCreateBufferRegionARB" );
			LoadFunctionAddress( delete_buffer_region_arb, "wglDeleteBufferRegionARB" );
			LoadFunctionAddress( restore_buffer_region_arb, "wglRestoreBufferRegionARB" );
			LoadFunctionAddress( save_buffer_region_arb, "wglSaveBufferRegionARB" );
		}

		if( extensions.has_wgl_arb_create_context )
		{
			LoadFunctionAddress( create_context_attribs_arb, "wglCreateContextAttribsARB" );
		}

		if( extensions.has_wgl_arb_make_current_read )
		{
			LoadFunctionAddress( get_current_read_dc_arb, "wglGetCurrentReadDCARB" );
			LoadFunctionAddress( make_context_current_arb, "wglMakeContextCurrentARB" );
		}

		if( extensions.has_wgl_arb_pbuffer )
		{
			LoadFunctionAddress( create_pbuffer_arb, "wglCreatePbufferARB" );
			LoadFunctionAddress( destroy_pbuffer_arb, "wglDestroyPbufferARB" );
			LoadFunctionAddress( get_pbuffer_dc_arb, "wglGetPbufferDCARB" );
			LoadFunctionAddress( query_pbuffer_arb, "wglQueryPbufferARB" );
			LoadFunctionAddress( release_pbuffer_dc_arb, "wglReleasePbufferDCARB" );
		}

		if( extensions.has_wgl_arb_pixel_format )
		{
			LoadFunctionAddress( choose_pixel_format_arb, "wglChoosePixelFormatARB" );
			LoadFunctionAddress( get_pixel_format_attribfv_arb, "wglGetPixelFormatAttribfvARB" );
			LoadFunctionAddress( get_pixel_format_attribiv_arb, "wglGetPixelFormatAttribivARB" );
		}

		if( extensions.has_wgl_arb_render_texture )
		{
			LoadFunctionAddress( bind_tex_image_arb, "wglBindTexImageARB" );
			LoadFunctionAddress( release_tex_image_arb, "wglReleaseTexImageARB" );
			LoadFunctionAddress( set_pbuffer_attrib_arb, "wglSetPbufferAttribARB" );
		}

		if( extensions.has_wgl_ext_display_color_table )
		{
			LoadFunctionAddress( bind_display_color_table_ext, "wglBindDisplayColorTableEXT" );
			LoadFunctionAddress( create_display_color_table_ext, "wglCreateDisplayColorTableEXT" );
			LoadFunctionAddress( destroy_display_color_table_ext, "wglDestroyDisplayColorTableEXT" );
			LoadFunctionAddress( load_display_color_table_ext, "wglLoadDisplayColorTableEXT" );
		}

		if( extensions.has_wgl_ext_make_current_read )
		{
			LoadFunctionAddress( get_current_read_dc_ext, "wglGetCurrentReadDCEXT" );
			LoadFunctionAddress( make_context_current_ext, "wglMakeContextCurrentEXT" );
		}

		if( extensions.has_wgl_ext_pbuffer )
		{
			LoadFunctionAddress( create_pbuffer_ext, "wglCreatePbufferEXT" );
			LoadFunctionAddress( destroy_pbuffer_ext, "wglDestroyPbufferEXT" );
			LoadFunctionAddress( get_pbuffer_dc_ext, "wglGetPbufferDCEXT" );
			LoadFunctionAddress( query_pbuffer_ext, "wglQueryPbufferEXT" );
			LoadFunctionAddress( release_pbuffer_dc_ext, "wglReleasePbufferDCEXT" );
		}

		if( extensions.has_wgl_ext_pixel_format )
		{
			LoadFunctionAddress( choose_pixel_format_ext, "wglChoosePixelFormatEXT" );
			LoadFunctionAddress( get_pixel_format_attribfv_ext, "wglGetPixelFormatAttribfvEXT" );
			LoadFunctionAddress( get_pixel_format_attribiv_ext, "wglGetPixelFormatAttribivEXT" );
		}

		if( extensions.has_wgl_ext_swap_control )
		{
			LoadFunctionAddress( get_swap_interval_ext, "wglGetSwapIntervalEXT" );
			LoadFunctionAddress( swap_interval_ext, "wglSwapIntervalEXT" );
		}

		if( extensions.has_wgl_i3d_digital_video_control )
		{
			LoadFunctionAddress( get_digital_video_parameters_i3d, "wglGetDigitalVideoParametersI3D" );
			LoadFunctionAddress( set_digital_video_parameters_i3d, "wglSetDigitalVideoParametersI3D" );
		}

		if( extensions.has_wgl_i3d_gamma )
		{
			LoadFunctionAddress( get_gamma_table_i3d, "wglGetGammaTableI3D" );
			LoadFunctionAddress( get_gamma_table_parameters_i3d, "wglGetGammaTableParametersI3D" );
			LoadFunctionAddress( set_gamma_table_i3d, "wglSetGammaTableI3D" );
			LoadFunctionAddress( set_gamma_table_parameters_i3d, "wglSetGammaTableParametersI3D" );
		}

		if( extensions.has_wgl_i3d_genlock )
		{
			LoadFunctionAddress( disable_genlock_i3d, "wglDisableGenlockI3D" );
			LoadFunctionAddress( enable_genlock_i3d, "wglEnableGenlockI3D" );
			LoadFunctionAddress( genlock_sample_rate_i3d, "wglGenlockSampleRateI3D" );
			LoadFunctionAddress( genlock_source_delay_i3d, "wglGenlockSourceDelayI3D" );
			LoadFunctionAddress( genlock_source_edge_i3d, "wglGenlockSourceEdgeI3D" );
			LoadFunctionAddress( genlock_source_i3d, "wglGenlockSourceI3D" );
			LoadFunctionAddress( get_genlock_sample_rate_i3d, "wglGetGenlockSampleRateI3D" );
			LoadFunctionAddress( get_genlock_source_delay_i3d, "wglGetGenlockSourceDelayI3D" );
			LoadFunctionAddress( get_genlock_source_edge_i3d, "wglGetGenlockSourceEdgeI3D" );
			LoadFunctionAddress( get_genlock_source_i3d, "wglGetGenlockSourceI3D" );
			LoadFunctionAddress( is_enabled_genlock_i3d, "wglIsEnabledGenlockI3D" );
			LoadFunctionAddress( query_genlock_max_source_delay_i3d, "wglQueryGenlockMaxSourceDelayI3D" );
		}

		if( extensions.has_wgl_i3d_image_buffer )
		{
			LoadFunctionAddress( associate_image_buffer_events_i3d, "wglAssociateImageBufferEventsI3D" );
			LoadFunctionAddress( create_image_buffer_i3d, "wglCreateImageBufferI3D" );
			LoadFunctionAddress( destroy_image_buffer_i3d, "wglDestroyImageBufferI3D" );
			LoadFunctionAddress( release_image_buffer_events_i3d, "wglReleaseImageBufferEventsI3D" );
		}

		if( extensions.has_wgl_i3d_swap_frame_lock )
		{
			LoadFunctionAddress( disable_frame_lock_i3d, "wglDisableFrameLockI3D" );
			LoadFunctionAddress( enable_frame_lock_i3d, "wglEnableFrameLockI3D" );
			LoadFunctionAddress( is_enabled_frame_lock_i3d, "wglIsEnabledFrameLockI3D" );
			LoadFunctionAddress( query_frame_lock_master_i3d, "wglQueryFrameLockMasterI3D" );
		}

		if( extensions.has_wgl_i3d_swap_frame_usage )
		{
			LoadFunctionAddress( begin_frame_tracking_i3d, "wglBeginFrameTrackingI3D" );
			LoadFunctionAddress( end_frame_tracking_i3d, "wglEndFrameTrackingI3D" );
			LoadFunctionAddress( get_frame_usage_i3d, "wglGetFrameUsageI3D" );
			LoadFunctionAddress( query_frame_tracking_i3d, "wglQueryFrameTrackingI3D" );
		}

		if( extensions.has_wgl_nv_dx_interop )
		{
			LoadFunctionAddress( dx_close_device_nv, "wglDXCloseDeviceNV" );
			LoadFunctionAddress( dx_lock_objects_nv, "wglDXLockObjectsNV" );
			LoadFunctionAddress( dx_object_access_nv, "wglDXObjectAccessNV" );
			LoadFunctionAddress( dx_open_device_nv, "wglDXOpenDeviceNV" );
			LoadFunctionAddress( dx_register_object_nv, "wglDXRegisterObjectNV" );
			LoadFunctionAddress( dx_set_resource_share_handle_nv, "wglDXSetResourceShareHandleNV" );
			LoadFunctionAddress( dx_unlock_objects_nv, "wglDXUnlockObjectsNV" );
			LoadFunctionAddress( dx_unregister_object_nv, "wglDXUnregisterObjectNV" );
		}

		if( extensions.has_wgl_nv_copy_image )
		{
			LoadFunctionAddress( copy_image_sub_data_nv, "wglCopyImageSubDataNV" );
		}

		if( extensions.has_wgl_nv_delay_before_swap )
		{
			LoadFunctionAddress( delay_before_swap_nv, "wglDelayBeforeSwapNV" );
		}

		if( extensions.has_wgl_nv_gpu_affinity )
		{
			LoadFunctionAddress( create_affinity_dc_nv, "wglCreateAffinityDCNV" );
			LoadFunctionAddress( delete_dc_nv, "wglDeleteDCNV" );
			LoadFunctionAddress( enum_gpu_devices_nv, "wglEnumGpuDevicesNV" );
			LoadFunctionAddress( enum_gpus_from_affinity_dc_nv, "wglEnumGpusFromAffinityDCNV" );
			LoadFunctionAddress( enum_gpus_nv, "wglEnumGpusNV" );
		}

		if( extensions.has_wgl_nv_present_video )
		{
			LoadFunctionAddress( bind_video_device_nv, "wglBindVideoDeviceNV" );
			LoadFunctionAddress( enumerate_video_devices_nv, "wglEnumerateVideoDevicesNV" );
			LoadFunctionAddress( query_current_context_nv, "wglQueryCurrentContextNV" );
		}

		if( extensions.has_wgl_nv_swap_group )
		{
			LoadFunctionAddress( bind_swap_barrier_nv, "wglBindSwapBarrierNV" );
			LoadFunctionAddress( join_swap_group_nv, "wglJoinSwapGroupNV" );
			LoadFunctionAddress( query_frame_count_nv, "wglQueryFrameCountNV" );
			LoadFunctionAddress( query_max_swap_groups_nv, "wglQueryMaxSwapGroupsNV" );
			LoadFunctionAddress( query_swap_group_nv, "wglQuerySwapGroupNV" );
			LoadFunctionAddress( reset_frame_count_nv, "wglResetFrameCountNV" );
		}

		if( extensions.has_wgl_nv_vertex_array_range )
		{
			LoadFunctionAddress( allocate_memory_nv, "wglAllocateMemoryNV" );
			LoadFunctionAddress( free_memory_nv, "wglFreeMemoryNV" );
		}

		if( extensions.has_wgl_nv_video_capture )
		{
			LoadFunctionAddress( bind_video_capture_device_nv, "wglBindVideoCaptureDeviceNV" );
			LoadFunctionAddress( enumerate_video_capture_devices_nv, "wglEnumerateVideoCaptureDevicesNV" );
			LoadFunctionAddress( lock_video_capture_device_nv, "wglLockVideoCaptureDeviceNV" );
			LoadFunctionAddress( query_video_capture_device_nv, "wglQueryVideoCaptureDeviceNV" );
			LoadFunctionAddress( release_video_capture_device_nv, "wglReleaseVideoCaptureDeviceNV" );
		}

		if( extensions.has_wgl_nv_video_output )
		{
			LoadFunctionAddress( bind_video_image_nv, "wglBindVideoImageNV" );
			LoadFunctionAddress( get_video_device_nv, "wglGetVideoDeviceNV" );
			LoadFunctionAddress( get_video_info_nv, "wglGetVideoInfoNV" );
			LoadFunctionAddress( release_video_device_nv, "wglReleaseVideoDeviceNV" );
			LoadFunctionAddress( release_video_image_nv, "wglReleaseVideoImageNV" );
			LoadFunctionAddress( send_pbuffer_to_video_nv, "wglSendPbufferToVideoNV" );
		}

		if( extensions.has_wgl_oml_sync_control )
		{
			LoadFunctionAddress( get_msc_rate_oml, "wglGetMscRateOML" );
			LoadFunctionAddress( get_sync_values_oml, "wglGetSyncValuesOML" );
			LoadFunctionAddress( swap_buffers_msc_oml, "wglSwapBuffersMscOML" );
			LoadFunctionAddress( swap_layer_buffers_msc_oml, "wglSwapLayerBuffersMscOML" );
			LoadFunctionAddress( wait_for_msc_oml, "wglWaitForMscOML" );
			LoadFunctionAddress( wait_for_sbc_oml, "wglWaitForSbcOML" );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "WGL extensions loaded." );
		return true;
	}
}
