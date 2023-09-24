#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace Internal
{
	// EGL configuration properties.
	struct ConfigurationProperties final
	{
		int32_t			native_format					= 0;	// Result of `EGL_NATIVE_VISUAL_ID`.
		int32_t			red_channel_bits				= 0;	// Result of `EGL_RED_SIZE`.
		int32_t			green_channel_bits				= 0;	// Result of `EGL_GREEN_SIZE`.
		int32_t			blue_channel_bits				= 0;	// Result of `EGL_BLUE_SIZE`.
		int32_t			alpha_channel_bits				= 0;	// Result of `EGL_ALPHA_SIZE`.
		int32_t			bit_rate						= 0;	// Result of `EGL_BUFFER_SIZE`.
		int32_t			sample_rate						= 0;	// Result of `EGL_SAMPLES`.
		int32_t			sample_buffers_count			= 0;	// Result of `EGL_SAMPLE_BUFFERS`.
		int32_t			depth_bits						= 0;	// Result of `EGL_DEPTH_SIZE`.
		int32_t			stencil_bits					= 0;	// Result of `EGL_STENCIL_SIZE`.
		int32_t			luminance_bits					= 0;	// Result of `EGL_LUMINANCE_SIZE`.
		int32_t			minimum_swap_interval			= 0;	// Result of `EGL_MIN_SWAP_INTERVAL`.
		int32_t			maximum_swap_interval			= 0;	// Result of `EGL_MAX_SWAP_INTERVAL`.
		int32_t			maximum_pbuffer_width			= 0;	// Result of `EGL_MAX_PBUFFER_WIDTH`.
		int32_t			maximum_pbuffer_height			= 0;	// Result of `EGL_MAX_PBUFFER_HEIGHT`.
		int32_t			maximum_pbuffer_pixels			= 0;	// Result of `EGL_MAX_PBUFFER_PIXELS`.
		int32_t			layer_index						= 0;	// Result of `EGL_LEVEL`.

		union
		{
			int32_t		bits							= 0;	// Buffer to store the bits of boolean flags.

			struct
			{
				bool	is_native_renderable			: 1;	// Result of `EGL_NATIVE_RENDERABLE`.
				bool	is_opengl_api_compatible		: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_OPENGL_BIT` bit up.
				bool	is_opengl_es_api_compatible		: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_OPENGL_ES_BIT` bit up.
				bool	is_opengl_es2_api_compatible	: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_OPENGL_ES2_BIT` bit up.
				bool	is_opengl_es3_api_compatible	: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_OPENGL_ES3_BIT` bit up.
				bool	is_openvg_api_compatible		: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_OPENVG_BIT` bit up.
				bool	is_interop_api_compatible		: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_INTEROP_BIT_KHR` bit up.
				bool	is_openmax_api_compatible		: 1;	// If `EGL_RENDERABLE_TYPE` has `EGL_OPENMAX_IL_BIT_KHR` bit up.
				bool	is_winwow_surface_compatible	: 1;	// If `EGL_SURFACE_TYPE` has `EGL_WINDOW_BIT` bit up.
				bool	is_pbuffer_surface_compatible	: 1;	// If `EGL_SURFACE_TYPE` has `EGL_PBUFFER_BIT` bit up.
				bool	is_pixmap_surface_compatible	: 1;	// If `EGL_SURFACE_TYPE` has `EGL_PIXMAP_BIT` bit up.
				bool	is_color_buffer					: 1;	// If `EGL_COLOR_BUFFER_TYPE` == `EGL_RGB_BUFFER`.
				bool	is_luminance_buffer				: 1;	// If `EGL_COLOR_BUFFER_TYPE` == `EGL_LUMINANCE_BUFFER`.
				bool	is_rgb_texture_compatible		: 1;	// Result of `EGL_BIND_TO_TEXTURE_RGB`.
				bool	is_rgba_texture_compatible		: 1;	// Result of `EGL_BIND_TO_TEXTURE_RGBA`.
			};
		};
	};
}
}
}
}
}
