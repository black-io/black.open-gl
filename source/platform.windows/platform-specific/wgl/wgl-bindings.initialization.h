#pragma once


namespace Wgl
{
	// State of WGL extensions.
	union ExtensionsState final
	{
		uint64_t	bits = 0;												// Buffer for boolean flags.

		struct
		{
			bool	has_wgl_3dfx_multisample						: 1;	// Whether the 'WGL_3DFX_multisample' extension may be used.
			bool	has_wgl_3dl_stereo_control						: 1;	// Whether the 'WGL_3DL_stereo_control' extension may be used.
			bool	has_wgl_amd_gpu_association						: 1;	// Whether the 'WGL_AMD_gpu_association' extension may be used.
			bool	has_wgl_arb_buffer_region						: 1;	// Whether the 'WGL_ARB_buffer_region' extension may be used.
			bool	has_wgl_arb_context_flush_control				: 1;	// Whether the 'WGL_ARB_context_flush_control' extension may be used.
			bool	has_wgl_arb_create_context						: 1;	// Whether the 'WGL_ARB_create_context' extension may be used.
			bool	has_wgl_arb_create_context_no_error				: 1;	// Whether the 'WGL_ARB_create_context_no_error' extension may be used.
			bool	has_wgl_arb_create_context_profile				: 1;	// Whether the 'WGL_ARB_create_context_profile' extension may be used.
			bool	has_wgl_arb_create_context_robustness			: 1;	// Whether the 'WGL_ARB_create_context_robustness' extension may be used.
			bool	has_wgl_arb_extensions_string					: 1;	// Whether the 'WGL_ARB_extensions_string' extension may be used.
			bool	has_wgl_arb_framebuffer_srgb					: 1;	// Whether the 'WGL_ARB_framebuffer_sRGB' extension may be used.
			bool	has_wgl_arb_make_current_read					: 1;	// Whether the 'WGL_ARB_make_current_read' extension may be used.
			bool	has_wgl_arb_multisample							: 1;	// Whether the 'WGL_ARB_multisample' extension may be used.
			bool	has_wgl_arb_pbuffer								: 1;	// Whether the 'WGL_ARB_pbuffer' extension may be used.
			bool	has_wgl_arb_pixel_format						: 1;	// Whether the 'WGL_ARB_pixel_format' extension may be used.
			bool	has_wgl_arb_pixel_format_float					: 1;	// Whether the 'WGL_ARB_pixel_format_float' extension may be used.
			bool	has_wgl_arb_render_texture						: 1;	// Whether the 'WGL_ARB_render_texture' extension may be used.
			bool	has_wgl_arb_robustness_application_isolation	: 1;	// Whether the 'WGL_ARB_robustness_application_isolation' extension may be used.
			bool	has_wgl_arb_robustness_share_group_isolation	: 1;	// Whether the 'WGL_ARB_robustness_share_group_isolation' extension may be used.
			bool	has_wgl_ati_pixel_format_float					: 1;	// Whether the 'WGL_ATI_pixel_format_float' extension may be used.
			bool	has_wgl_ati_render_texture_rectangle			: 1;	// Whether the 'WGL_ATI_render_texture_rectangle' extension may be used.
			bool	has_wgl_ext_colorspace							: 1;	// Whether the 'WGL_EXT_colorspace' extension may be used.
			bool	has_wgl_ext_create_context_es2_profile			: 1;	// Whether the 'WGL_EXT_create_context_es2_profile' extension may be used.
			bool	has_wgl_ext_create_context_es_profile			: 1;	// Whether the 'WGL_EXT_create_context_es_profile' extension may be used.
			bool	has_wgl_ext_depth_float							: 1;	// Whether the 'WGL_EXT_depth_float' extension may be used.
			bool	has_wgl_ext_display_color_table					: 1;	// Whether the 'WGL_EXT_display_color_table' extension may be used.
			bool	has_wgl_ext_extensions_string					: 1;	// Whether the 'WGL_EXT_extensions_string' extension may be used.
			bool	has_wgl_ext_framebuffer_srgb					: 1;	// Whether the 'WGL_EXT_framebuffer_sRGB' extension may be used.
			bool	has_wgl_ext_make_current_read					: 1;	// Whether the 'WGL_EXT_make_current_read' extension may be used.
			bool	has_wgl_ext_multisample							: 1;	// Whether the 'WGL_EXT_multisample' extension may be used.
			bool	has_wgl_ext_pbuffer								: 1;	// Whether the 'WGL_EXT_pbuffer' extension may be used.
			bool	has_wgl_ext_pixel_format						: 1;	// Whether the 'WGL_EXT_pixel_format' extension may be used.
			bool	has_wgl_ext_pixel_format_packed_float			: 1;	// Whether the 'WGL_EXT_pixel_format_packed_float' extension may be used.
			bool	has_wgl_ext_swap_control						: 1;	// Whether the 'WGL_EXT_swap_control' extension may be used.
			bool	has_wgl_ext_swap_control_tear					: 1;	// Whether the 'WGL_EXT_swap_control_tear' extension may be used.
			bool	has_wgl_i3d_digital_video_control				: 1;	// Whether the 'WGL_I3D_digital_video_control' extension may be used.
			bool	has_wgl_i3d_gamma								: 1;	// Whether the 'WGL_I3D_gamma' extension may be used.
			bool	has_wgl_i3d_genlock								: 1;	// Whether the 'WGL_I3D_genlock' extension may be used.
			bool	has_wgl_i3d_image_buffer						: 1;	// Whether the 'WGL_I3D_image_buffer' extension may be used.
			bool	has_wgl_i3d_swap_frame_lock						: 1;	// Whether the 'WGL_I3D_swap_frame_lock' extension may be used.
			bool	has_wgl_i3d_swap_frame_usage					: 1;	// Whether the 'WGL_I3D_swap_frame_usage' extension may be used.
			bool	has_wgl_nv_dx_interop							: 1;	// Whether the 'WGL_NV_DX_interop' extension may be used.
			bool	has_wgl_nv_dx_interop2							: 1;	// Whether the 'WGL_NV_DX_interop2' extension may be used.
			bool	has_wgl_nv_copy_image							: 1;	// Whether the 'WGL_NV_copy_image' extension may be used.
			bool	has_wgl_nv_delay_before_swap					: 1;	// Whether the 'WGL_NV_delay_before_swap' extension may be used.
			bool	has_wgl_nv_float_buffer							: 1;	// Whether the 'WGL_NV_float_buffer' extension may be used.
			bool	has_wgl_nv_gpu_affinity							: 1;	// Whether the 'WGL_NV_gpu_affinity' extension may be used.
			bool	has_wgl_nv_multigpu_context						: 1;	// Whether the 'WGL_NV_multigpu_context' extension may be used.
			bool	has_wgl_nv_multisample_coverage					: 1;	// Whether the 'WGL_NV_multisample_coverage' extension may be used.
			bool	has_wgl_nv_present_video						: 1;	// Whether the 'WGL_NV_present_video' extension may be used.
			bool	has_wgl_nv_render_depth_texture					: 1;	// Whether the 'WGL_NV_render_depth_texture' extension may be used.
			bool	has_wgl_nv_render_texture_rectangle				: 1;	// Whether the 'WGL_NV_render_texture_rectangle' extension may be used.
			bool	has_wgl_nv_swap_group							: 1;	// Whether the 'WGL_NV_swap_group' extension may be used.
			bool	has_wgl_nv_vertex_array_range					: 1;	// Whether the 'WGL_NV_vertex_array_range' extension may be used.
			bool	has_wgl_nv_video_capture						: 1;	// Whether the 'WGL_NV_video_capture' extension may be used.
			bool	has_wgl_nv_video_output							: 1;	// Whether the 'WGL_NV_video_output' extension may be used.
			bool	has_wgl_oml_sync_control						: 1;	// Whether the 'WGL_OML_sync_control' extension may be used.
		};
	};


	// Initialize the WGL interface for required display output device.
	const bool InitializeBindings( ::IDXGIOutput& display );

	// Perform the core interface loading for WGL API.
	const bool LoadCoreProfile();

	// Perform the loading of WGL extensions.
	const bool LoadExtensions();

	// Get the state of currently available WGL extensions.
	const ExtensionsState& GetExtensionsState();
}
