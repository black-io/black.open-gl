#include <black/open-gl.h>

#include "egl/functions.egl-configurations.h"


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Display";
}


	const bool EglDisplay<Black::PlatformType::Android>::Connect( const Black::GlAdapterHandle& adapter_handle )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting to default display of adapter #{}.", adapter_handle.GetIndex() );

		CRETE( adapter_handle.GetIndex() != 0, false, LOG_CHANNEL, "Display may be connected only to default graphics adapter." );
		CRETE( !AcquireDisplayHandle( EGL_DEFAULT_DISPLAY ), false, LOG_CHANNEL, "Failed to connect default display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Successfully connected to default display of adapter #{}.", adapter_handle.GetIndex() );
		return true;
	}

	const bool EglDisplay<Black::PlatformType::Android>::Connect( const Black::GlDisplayHandle& display_handle )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting to display #{} of adapter #{}.", display_handle.GetIndex(), display_handle.GetAdapterIndex() );

		CRETE( display_handle.GetAdapterIndex() != 0, false, LOG_CHANNEL, "Display may be connected only to default graphics adapter." );
		CRETE( display_handle.GetHandle() != EGL_DEFAULT_DISPLAY, false, LOG_CHANNEL, "Only default display may be connected." );
		CRETE( !AcquireDisplayHandle( display_handle.GetHandle() ), false, LOG_CHANNEL, "Failed to connect given display." );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Successfully connected to display #{} of adapter #{}.", display_handle.GetIndex(), display_handle.GetAdapterIndex() );
		return true;
	}

	void EglDisplay<Black::PlatformType::Android>::Finalize()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Starting the display finalization." );

		m_handle = EGL_NO_DISPLAY;
		m_configurations.clear();

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display finalized properly." );
	}

	void EglDisplay<Black::PlatformType::Android>::UpdateConfigurations()
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "List of EGL configurations will be updated." );

		CRETE( !IsConnected(), , LOG_CHANNEL, "Unable to get configurations for disconnected display." );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Reading the EGL configurations." );
		std::vector<::EGLConfig> configurations{ BuildConfigurationsList( m_handle ) };
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Sorting the collected EGL configurations." );
		std::vector<::EGLConfig*> sorted_configurations{ SortConfiguraionsList( configurations, m_handle ) };

		m_configurations.clear();
		for( ::EGLConfig* config : sorted_configurations )
		{
			const size32_t config_index = size32_t( std::distance( configurations.data(), config ) );
			m_configurations.emplace_back( Black::EglConfiguration::ConstructionInfo{ m_handle, *config, config_index } );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "EGL configurations updated." );
	}

	std::optional<Black::EglConfiguration> EglDisplay<Black::PlatformType::Android>::FindBestWindowConfiguration() const
	{
		std::vector<const Black::EglConfiguration*> configurations;
		configurations.resize( m_configurations.size() );
		std::transform( m_configurations.begin(), m_configurations.end(), configurations.begin(), []( const Black::EglConfiguration& item ) { return &item; } );

		auto configurations_begin	= configurations.begin();
		auto configurations_end		= configurations.end();
		ENSURES_DEBUG( configurations_end > configurations_begin );

		// Keep only configurations that support OpenGL ES, allow to create the window surfaces and use the main layer of frame buffer.
		configurations_end = std::copy_if(
			configurations_begin,
			configurations_end,
			configurations_begin,
			[]( const Black::EglConfiguration* configuration ) -> const bool
			{
				const Internal::ConfigurationProperties& properties = configuration->GetProperties();

				CRET( properties.layer_index != 0, false );
				CRET( !properties.is_color_buffer, false );
				CRET( !properties.is_winwow_surface_compatible, false );
				CRET( !( properties.is_opengl_es3_api_compatible || properties.is_opengl_es2_api_compatible || properties.is_opengl_es_api_compatible ), false );

				return true;
			}
		);

		ENSURES_DEBUG( configurations_end > configurations_begin );

		// Sort the configurations by complex criteria. The best match will be stored first.
		std::sort(
			configurations_begin,
			configurations_end,
			[]( const Black::EglConfiguration* left, const Black::EglConfiguration* right ) -> const bool
			{
				const Internal::ConfigurationProperties& left_properties	= left->GetProperties();
				const Internal::ConfigurationProperties& right_properties	= right->GetProperties();

				if( left_properties.is_opengl_api_compatible != right_properties.is_opengl_api_compatible )
				{
					return left_properties.is_opengl_api_compatible && !right_properties.is_opengl_api_compatible;
				}

				if( left_properties.is_opengl_es3_api_compatible != right_properties.is_opengl_es3_api_compatible )
				{
					return left_properties.is_opengl_es3_api_compatible && !right_properties.is_opengl_es3_api_compatible;
				}

				if( left_properties.is_opengl_es2_api_compatible != right_properties.is_opengl_es2_api_compatible )
				{
					return left_properties.is_opengl_es2_api_compatible && !right_properties.is_opengl_es2_api_compatible;
				}

				if( left_properties.is_opengl_es_api_compatible != right_properties.is_opengl_es_api_compatible )
				{
					return left_properties.is_opengl_es_api_compatible && !right_properties.is_opengl_es_api_compatible;
				}

				if( left_properties.depth_bits != right_properties.depth_bits )
				{
					return left_properties.depth_bits > right_properties.depth_bits;
				}

				if( left_properties.stencil_bits != right_properties.stencil_bits )
				{
					return left_properties.stencil_bits > right_properties.stencil_bits;
				}

				if( left_properties.red_channel_bits != right_properties.red_channel_bits )
				{
					return left_properties.red_channel_bits > right_properties.red_channel_bits;
				}

				if( left_properties.blue_channel_bits != right_properties.blue_channel_bits )
				{
					return left_properties.blue_channel_bits > right_properties.blue_channel_bits;
				}

				if( left_properties.green_channel_bits != right_properties.green_channel_bits )
				{
					return left_properties.green_channel_bits > right_properties.green_channel_bits;
				}

				return left_properties.alpha_channel_bits > right_properties.alpha_channel_bits;
			}
		);

		return { *configurations.front() };
	}

	std::optional<Black::EglConfiguration> EglDisplay<Black::PlatformType::Android>::FindBestPixelBufferConfiguration(
		const Black::EglConfiguration& window_configuration
	) const
	{
		std::vector<const Black::EglConfiguration*> configurations;
		configurations.resize( m_configurations.size() );
		std::transform( m_configurations.begin(), m_configurations.end(), configurations.begin(), []( const Black::EglConfiguration& item ) { return &item; } );

		auto configurations_begin	= configurations.begin();
		auto configurations_end		= configurations.end();
		ENSURES_DEBUG( configurations_end > configurations_begin );

		// Keep only configurations that correlate with original configuration.
		configurations_end = std::copy_if(
			configurations_begin,
			configurations_end,
			configurations_begin,
			[&origin_properties = window_configuration.GetProperties()]( const Black::EglConfiguration* configuration ) -> const bool
			{
				const Internal::ConfigurationProperties& current_properties	= configuration->GetProperties();

				CRET( !current_properties.is_color_buffer, false );
				CRET( !current_properties.is_pbuffer_surface_compatible, false );
				CRET( current_properties.is_opengl_api_compatible != origin_properties.is_opengl_api_compatible, false );
				CRET( current_properties.is_opengl_es_api_compatible != origin_properties.is_opengl_es_api_compatible, false );
				CRET( current_properties.is_opengl_es2_api_compatible != origin_properties.is_opengl_es2_api_compatible, false );
				CRET( current_properties.is_opengl_es3_api_compatible != origin_properties.is_opengl_es3_api_compatible, false );
				CRET( current_properties.layer_index != origin_properties.layer_index, false );
				CRET( current_properties.bit_rate != origin_properties.bit_rate, false );
				CRET( current_properties.red_channel_bits != origin_properties.red_channel_bits, false );
				CRET( current_properties.green_channel_bits != origin_properties.green_channel_bits, false );
				CRET( current_properties.blue_channel_bits != origin_properties.blue_channel_bits, false );
				CRET( current_properties.alpha_channel_bits != origin_properties.alpha_channel_bits, false );

				return true;
			}
		);

		ENSURES_DEBUG( configurations_end > configurations_begin );

		// Sort the configurations by complex criteria. The best match will be stored first.
		std::sort(
			configurations_begin,
			configurations_end,
			[]( const Black::EglConfiguration* left, const Black::EglConfiguration* right ) -> const bool
			{
				const Internal::ConfigurationProperties& left_properties	= left->GetProperties();
				const Internal::ConfigurationProperties& right_properties	= right->GetProperties();

				if( left_properties.red_channel_bits != right_properties.red_channel_bits )
				{
					return left_properties.red_channel_bits > right_properties.red_channel_bits;
				}

				if( left_properties.blue_channel_bits != right_properties.blue_channel_bits )
				{
					return left_properties.blue_channel_bits > right_properties.blue_channel_bits;
				}

				if( left_properties.green_channel_bits != right_properties.green_channel_bits )
				{
					return left_properties.green_channel_bits > right_properties.green_channel_bits;
				}

				return left_properties.alpha_channel_bits > right_properties.alpha_channel_bits;
			}
		);

		return { *configurations.front() };
	}

	const bool EglDisplay<Black::PlatformType::Android>::AcquireDisplayHandle( ::EGLNativeDisplayType native_handle )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Connecting the display #{:X}.", uintptr_t( native_handle ) );

		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Try to connect the display via platform-oriented EGL API." );
		m_handle = ::eglGetPlatformDisplay( EGL_PLATFORM_ANDROID_KHR, native_handle, nullptr );

		if( m_handle == EGL_NO_DISPLAY )
		{
			BLACK_LOG_INFO( LOG_CHANNEL, "Unable to connect the display via platform-oriented API. Connecting via the regular EGL API." );
			m_handle = ::eglGetDisplay( native_handle );
			CRETE( m_handle == EGL_NO_DISPLAY, false, LOG_CHANNEL, "Failed to connect display, error: 0x{:08X}.", ::eglGetError() );
		}

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Display connection #{:X} is established.", uintptr_t( native_handle ) );
		return true;
	}
}
}
}
}
