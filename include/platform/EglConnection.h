#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Implementation of RHI for GPU connection.

		Implements the final, third layer of platform-agnostic GPU connection type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlRhiConnection final : public PlatformSpecific::GlRhiConnection<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		GlRhiConnection() = default;
		~GlRhiConnection();

	// Contracts of public API.
	public:
		/// @see	GlRhiConnection::Finalize
		using PlatformSpecific::GlRhiConnection<Black::BUILD_PLATFORM>::Finalize;

		/// @see	GlRhiConnection::EnumerateAdapters
		using PlatformSpecific::GlRhiConnection<Black::BUILD_PLATFORM>::EnumerateAdapters;

		/// @see	GlRhiConnection::EnumerateDisplays
		using PlatformSpecific::GlRhiConnection<Black::BUILD_PLATFORM>::EnumerateDisplays;

		/// @see	GlRhiConnection::EnumerateVideoModes
		using PlatformSpecific::GlRhiConnection<Black::BUILD_PLATFORM>::EnumerateVideoModes;

	// Public interface.
	public:

	};
}
}
}
