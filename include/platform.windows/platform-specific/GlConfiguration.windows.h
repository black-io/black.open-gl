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
		@brief	Platform dependent EGL-compatible configuration implementation.

		Implements the second layer of platform-agnostic EGL-compatible configuration type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlConfiguration<Black::PlatformType::WindowsDesktop> : public Internal::BasicGlConfiguration
	{
	};
}
}
}
}
