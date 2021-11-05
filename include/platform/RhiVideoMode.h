#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Implementation of RHI for display video mode.

		Implements the final, third layer of platform-agnostic display video mode type.
		This type is public and may be freely used outside of subsystem.
	*/
	class RhiVideoMode final : public PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		RhiVideoMode( const RhiVideoMode& ) = default;
		explicit RhiVideoMode( const ConstructionInfo& info );
		~RhiVideoMode() = default;

	// Contracts of public API.
	public:
		/// @see	RhiVideoMode::GetWidth
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::GetWidth;

		/// @see	RhiVideoMode::GetHeight
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::GetHeight;

		/// @see	RhiVideoMode::GetBitRate
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::GetBitRate;

		/// @see	RhiVideoMode::GetRefreshRate
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::GetRefreshRate;

		/// @see	RhiVideoMode::GetAspectRatio
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::GetAspectRatio;

		/// @see	RhiVideoMode::IsOpenGlCompatible
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::IsOpenGlCompatible;

		/// @see	RhiVideoMode::HasFullscreenSupport
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::HasFullscreenSupport;

		/// @see	RhiVideoMode::HasWindowSupport
		using PlatformSpecific::RhiVideoMode<Black::BUILD_PLATFORM>::HasWindowSupport;

	// Public interface.
	public:

	};
}
}
}
