#include <black/open-gl.h>
#include <black/core/algorithms.h>

#include "functions.settings.h"
#include "bindings.wgl.h"
#include "bindings.wgl-extensions.h"


namespace Wgl
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/WGL";


	// Get the WGL extensions using available core interface.
	inline std::string_view GetExtensionsBuffer( const ::HDC device_context )
	{
		const bool use_arb_function = ( get_extensions_string_arb != nullptr ) && ( device_context != nullptr );
		EXPECTS( use_arb_function || ( get_extensions_string_ext != nullptr ) );

		return ( use_arb_function )? get_extensions_string_arb( device_context ) : get_extensions_string_ext();
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
}


	const ExtensionsState& GetExtensionsState()
	{
		static ExtensionsState	state;
		static bool				is_initialized = false;
		CRET( is_initialized, state );

		EXPECTS_DEBUG( get_current_dc != nullptr );
		InitializeExtensionsState( state, get_current_dc() );
		is_initialized = true;
		return state;
	}
}
