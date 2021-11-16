#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	EGL-compatible surface object.

		Implements the final, third layer of platform-agnostic EGL Surface type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglSurface final : public PlatformSpecific::EglSurface<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		EglSurface() = default;
		~EglSurface();

	// Contracts of public API.
	public:

	// Public interface.
	public:
	};
}
}
}
