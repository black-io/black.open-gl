#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
namespace Internal
{
	// Available API profiles.
	enum class ContextApiProfile : uint32_t
	{
		OpenGl,		// OpenGL API.
		OpenGlEs,	// OpenGL ES API.
		OpenGlSc,	// OpenGL SC API.
	};
}
}
}
}
