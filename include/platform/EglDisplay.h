#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	EGL-compatible display object.

		Implements the final, third layer of platform-agnostic EGL display type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglDisplay final : public PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		EglDisplay()	= default;
		~EglDisplay()	= default;

	// Contracts of public API.
	public:
		/// @see	EglDisplay::Finalize
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::Finalize;

		/// @see	EglDisplay::IsConnected
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::IsConnected;

	// Public interface.
	public:

	};
}
}
}
