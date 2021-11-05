#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	/**
		@brief	Platform dependent OpenGL context implementation.

		Implements the second layer of platform-agnostic OpenGL context type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlContext<Black::PlatformType::WindowsDesktop> : public Internal::BasicGlContext
	{
	};
}
}
}
}
