#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	EGL-compatible context object.

		Implements the final, third layer of platform-agnostic EGL Context type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglContext final : public PlatformSpecific::EglContext<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		EglContext() = default;
		~EglContext();

	// Contracts of public API.
	public:

	// Public interface.
	public:
	};
}
}
}
