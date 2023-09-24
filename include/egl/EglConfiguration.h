#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	EGL configuration object.

		This type implements regular EGL Configuration object, or emulates it on system without EGL support.
		Check the platform-specific implementations for details.

		Implements the final, third layer of platform-agnostic EGL configuration type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglConfiguration final : public PlatformSpecific::EglConfiguration<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		explicit EglConfiguration( const ConstructionInfo& info );
		~EglConfiguration() = default;

	// Contracts of public API.
	public:

	// Public interface.
	public:

	};
}
}
}
