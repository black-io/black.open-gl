#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	// Forward the RHI adapter to be used in platform-specific code.
	class GlRhiAdapter;

	// Forward the RHI display to be used in platform-specific code.
	class GlRhiDisplay;

	// Forward the EGL configuration to be used in platform-specific code.
	class EglConfiguration;

	// Forward the EGL display object to be used in platform-specific code.
	class EglDisplay;

	// Forward the context to be used in platform-specific code.
	class GlContext;
}
}
}
