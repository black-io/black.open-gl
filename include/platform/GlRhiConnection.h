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
	class RhiConnection final : public PlatformSpecific::RhiConnection<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		RhiConnection() = default;
		~RhiConnection();

	// Contracts of public API.
	public:
		/// @see	RhiConnection::Finalize
		using PlatformSpecific::RhiConnection<Black::BUILD_PLATFORM>::Finalize;

		/// @see	RhiConnection::EnumerateAdapters
		using PlatformSpecific::RhiConnection<Black::BUILD_PLATFORM>::EnumerateAdapters;

		/// @see	RhiConnection::EnumerateDisplays
		using PlatformSpecific::RhiConnection<Black::BUILD_PLATFORM>::EnumerateDisplays;

		/// @see	RhiConnection::EnumerateVideoModes
		using PlatformSpecific::RhiConnection<Black::BUILD_PLATFORM>::EnumerateVideoModes;

	// Public interface.
	public:

	};
}
}
}
