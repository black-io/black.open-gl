#include <black/open-gl/egl.h>

#include "functions.egl-configurations.h"


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
	// Properties cache for EGL configuration sorting.
	struct CachedConfigurationProperties final
	{
		int32_t color_bit_rate;		// Bit-rate of color buffer.
		int32_t depth_bit_rate;		// Bit-rate of depth buffer.
		int32_t stencil_bit_rate;	// Bit-rate of stencil buffer.
	};


	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL";


	// Get the ordinal index of current configuration by given pointer.
	inline size_t GetConfigurationIndex( const ::EGLConfig* first_configuration, const ::EGLConfig* current_configuration )
	{
		return std::distance( first_configuration, current_configuration );
	}
}


	std::vector<::EGLConfig> BuildConfigurationsList( const ::EGLDisplay display_handle )
	{
		std::vector<::EGLConfig> configurations;

		{
			int32_t configurations_count = 0;
			const bool is_succeeded = ::eglGetConfigs( display_handle, nullptr, 0, &configurations_count ) == EGL_TRUE;
			CRETE( !is_succeeded, configurations, LOG_CHANNEL, "Failed to get the count of EGL configurations." );
			configurations.resize( configurations_count );
		}

		int32_t stored_configurations = 0;
		const bool is_succeeded = ::eglGetConfigs( display_handle, configurations.data(), int32_t( configurations.size() ), &stored_configurations ) == EGL_TRUE;
		CRETE( !is_succeeded, {}, LOG_CHANNEL, "Failed to store EGL configurations." );

		if( stored_configurations < configurations.size() )
		{
			configurations.resize( stored_configurations );
			configurations.shrink_to_fit();
		}

		return configurations;
	}

	std::vector<::EGLConfig*> SortConfiguraionsList( const Black::PlainView<::EGLConfig> configurations, const ::EGLDisplay display_handle )
	{
		std::vector<::EGLConfig*> sorted_configurations;

		std::vector<CachedConfigurationProperties> configuration_properties_cache;

		auto criteria = [first_config = configurations.data(), &configuration_properties_cache]( const ::EGLConfig* left, const ::EGLConfig* right ) -> const bool
		{
			const auto& left_properties		= configuration_properties_cache[ GetConfigurationIndex( first_config, left ) ];
			const auto& right_properties	= configuration_properties_cache[ GetConfigurationIndex( first_config, right ) ];

			{
				const size_t left_bit_rate	= left_properties.color_bit_rate;
				const size_t right_bit_rate	= right_properties.color_bit_rate;
				if( left_bit_rate != right_bit_rate )
				{
					// The more bit-rate, the best format is.
					return left_bit_rate > right_bit_rate;
				}
			}

			{
				const size_t left_depth		= left_properties.depth_bit_rate;
				const size_t right_depth	= right_properties.depth_bit_rate;
				if( left_depth != right_depth )
				{
					// The wider depth buffer, the better.
					return left_depth > right_depth;
				}
			}

			return left_properties.stencil_bit_rate > right_properties.stencil_bit_rate;
		};

		auto properties_collector = [&display_handle]( const ::EGLConfig configuration ) -> CachedConfigurationProperties
		{
			CachedConfigurationProperties properties{};

			EXPECTS( ::eglGetConfigAttrib( display_handle, configuration, EGL_BUFFER_SIZE, &properties.color_bit_rate ) == EGL_TRUE );
			EXPECTS( ::eglGetConfigAttrib( display_handle, configuration, EGL_DEPTH_SIZE, &properties.depth_bit_rate ) == EGL_TRUE );
			EXPECTS( ::eglGetConfigAttrib( display_handle, configuration, EGL_STENCIL_SIZE, &properties.stencil_bit_rate ) == EGL_TRUE );

			return properties;
		};

		configuration_properties_cache.resize( configurations.size() );
		std::transform( configurations.begin(), configurations.end(), configuration_properties_cache.begin(), properties_collector );

		sorted_configurations.resize( configurations.size() );
		std::transform( configurations.begin(), configurations.end(), sorted_configurations.begin(), []( ::EGLConfig& config ) { return &config; } );
		std::sort( sorted_configurations.begin(), sorted_configurations.end(), criteria );

		return sorted_configurations;
	}
}
}
}
}
}
