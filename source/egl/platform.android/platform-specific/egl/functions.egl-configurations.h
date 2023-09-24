#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Build the list of available configurations for given display.
	std::vector<::EGLConfig> BuildConfigurationsList( const ::EGLDisplay display_handle );

	// Sort the list of configurations.
	std::vector<::EGLConfig*> SortConfiguraionsList( const Black::PlainView<::EGLConfig> configurations, const ::EGLDisplay display_handle );
}
}
}
}
