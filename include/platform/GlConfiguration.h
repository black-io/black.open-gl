#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Implementation of EGL-compatible configuration.

		Implements the final, third layer of platform-agnostic EGL-compatible configuration type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlConfiguration final : public PlatformSpecific::GlConfiguration<Black::BUILD_PLATFORM>
	{
	};
}
}
}
