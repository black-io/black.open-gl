#include <black/open-gl.h>


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Configuration";

	// Mapping from EGL configuration attribute to particular configuration property.
	constexpr std::pair<::EGLint, int32_t Internal::ConfigurationProperties::*> EGL_ATTRIBUTE_ASSOCIATION[]{
		{ EGL_ALPHA_SIZE, &Internal::ConfigurationProperties::alpha_channel_bits },
		//{ EGL_ALPHA_MASK_SIZE, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		{ EGL_BLUE_SIZE, &Internal::ConfigurationProperties::blue_channel_bits },
		{ EGL_BUFFER_SIZE, &Internal::ConfigurationProperties::bit_rate },
		//{ EGL_CONFIG_CAVEAT, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		//{ EGL_CONFIG_ID, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		//{ EGL_CONFORMANT, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		{ EGL_DEPTH_SIZE, &Internal::ConfigurationProperties::depth_bits },
		{ EGL_GREEN_SIZE, &Internal::ConfigurationProperties::green_channel_bits },
		{ EGL_LEVEL, &Internal::ConfigurationProperties::layer_index },
		{ EGL_LUMINANCE_SIZE, &Internal::ConfigurationProperties::luminance_bits },
		{ EGL_MAX_PBUFFER_WIDTH, &Internal::ConfigurationProperties::maximum_pbuffer_width },
		{ EGL_MAX_PBUFFER_HEIGHT, &Internal::ConfigurationProperties::maximum_pbuffer_height },
		{ EGL_MAX_PBUFFER_PIXELS, &Internal::ConfigurationProperties::maximum_pbuffer_pixels },
		{ EGL_MAX_SWAP_INTERVAL, &Internal::ConfigurationProperties::maximum_swap_interval },
		{ EGL_MIN_SWAP_INTERVAL, &Internal::ConfigurationProperties::minimum_swap_interval },
		{ EGL_NATIVE_VISUAL_ID, &Internal::ConfigurationProperties::native_format },
		//{ EGL_NATIVE_VISUAL_TYPE, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		{ EGL_RED_SIZE, &Internal::ConfigurationProperties::red_channel_bits },
		{ EGL_SAMPLE_BUFFERS, &Internal::ConfigurationProperties::sample_buffers_count },
		{ EGL_SAMPLES, &Internal::ConfigurationProperties::sample_rate },
		{ EGL_STENCIL_SIZE, &Internal::ConfigurationProperties::stencil_bits },
		//{ EGL_TRANSPARENT_TYPE, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		//{ EGL_TRANSPARENT_RED_VALUE, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		//{ EGL_TRANSPARENT_GREEN_VALUE, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
		//{ EGL_TRANSPARENT_BLUE_VALUE, &Internal::ConfigurationProperties:: }, // TODO: Support in future.
	};

	// Mapping from EGL configuration attribute to boolean members of configuration properties.
	constexpr std::pair<::EGLint, void (*)( Internal::ConfigurationProperties&, const int32_t )> EGL_ATTRIBUTE_PREDICATES[]{
		{
			EGL_BIND_TO_TEXTURE_RGB,
			[]( Internal::ConfigurationProperties& properties, const int32_t value ) { properties.is_rgb_texture_compatible = ( value == EGL_TRUE ) != 0; }
		},
		{
			EGL_BIND_TO_TEXTURE_RGBA,
			[]( Internal::ConfigurationProperties& properties, const int32_t value ) { properties.is_rgba_texture_compatible = ( value == EGL_TRUE ) != 0; }
		},
		{
			EGL_COLOR_BUFFER_TYPE,
			[]( Internal::ConfigurationProperties& properties, const int32_t value )
			{
				properties.is_color_buffer		= ( value & EGL_RGB_BUFFER ) != 0;
				properties.is_luminance_buffer	= ( value & EGL_LUMINANCE_BUFFER ) != 0;
			}
		},
		{
			EGL_NATIVE_RENDERABLE,
			[]( Internal::ConfigurationProperties& properties, const int32_t value ) { properties.is_native_renderable = ( value == EGL_TRUE ) != 0; }
		},
		{
			EGL_RENDERABLE_TYPE,
			[]( Internal::ConfigurationProperties& properties, const int32_t value )
			{
				properties.is_opengl_api_compatible		= ( value & EGL_OPENGL_BIT ) != 0;
				properties.is_opengl_es_api_compatible	= ( value & EGL_OPENGL_ES_BIT ) != 0;
				properties.is_opengl_es2_api_compatible	= ( value & EGL_OPENGL_ES2_BIT ) != 0;
				properties.is_opengl_es3_api_compatible	= ( value & EGL_OPENGL_ES3_BIT ) != 0;
				properties.is_openvg_api_compatible		= ( value & EGL_OPENVG_BIT ) != 0;
				properties.is_interop_api_compatible	= ( value & 0x0010 ) != 0; // EGL_INTEROP_BIT_KHR		Not declared in 'egl.h' from Android.
				properties.is_openmax_api_compatible	= ( value & 0x0020 ) != 0; // EGL_OPENMAX_IL_BIT_KHR	Not declared in 'egl.h' from Android.
			}
		},
		{
			EGL_SURFACE_TYPE,
			[]( Internal::ConfigurationProperties& properties, const int32_t value )
			{
				properties.is_winwow_surface_compatible		= ( value & EGL_WINDOW_BIT ) != 0;
				properties.is_pbuffer_surface_compatible	= ( value & EGL_PBUFFER_BIT ) != 0;
				properties.is_pixmap_surface_compatible		= ( value & EGL_PIXMAP_BIT ) != 0;
			}
		},
	};
}


	EglConfiguration<Black::PlatformType::Android>::EglConfiguration( const ConstructionInfo& info )
		: m_display{ std::get<0>( info ) }
		, m_config{ std::get<1>( info ) }
		, m_index{ std::get<2>( info ) }
	{
		ReadProperties();
	}

	void EglConfiguration<Black::PlatformType::Android>::ReadProperties()
	{
		for( const auto& [ attribute_id, property_ptr ] : EGL_ATTRIBUTE_ASSOCIATION )
		{
			const bool is_succeeded = ::eglGetConfigAttrib( m_display, m_config, attribute_id, &(m_properties.*property_ptr) ) == EGL_TRUE;
			ENSURES_DEBUG( is_succeeded );
		}

		for( const auto& [ attribute_id, property_function ] : EGL_ATTRIBUTE_PREDICATES )
		{
			int32_t value = 0;
			const bool is_succeeded = ::eglGetConfigAttrib( m_display, m_config, attribute_id, &value ) == EGL_TRUE;
			ENSURES_DEBUG( is_succeeded );
			property_function( m_properties, value );
		}
	}
}
}
}
}
