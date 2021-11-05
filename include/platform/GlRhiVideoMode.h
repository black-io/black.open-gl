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
	class GlRhiVideoMode final : public PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>
	{
	// Friendship declarations.
	public:
		// Swap the state with given instance.
		friend inline void swap( GlRhiVideoMode& left, GlRhiVideoMode& right ) { left.Swap( right ); };

	// Construction and initialization.
	public:
		GlRhiVideoMode()						= delete;
		GlRhiVideoMode( const GlRhiVideoMode& )	= default;
		GlRhiVideoMode( GlRhiVideoMode&& )		= default;
		explicit GlRhiVideoMode( const ConstructionInfo& info );
		~GlRhiVideoMode() = default;

	// Contracts of public API.
	public:
		/// @see	GlRhiVideoMode::GetWidth
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::GetWidth;

		/// @see	GlRhiVideoMode::GetHeight
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::GetHeight;

		/// @see	GlRhiVideoMode::GetBitRate
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::GetBitRate;

		/// @see	GlRhiVideoMode::GetRefreshRate
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::GetRefreshRate;

		/// @see	GlRhiVideoMode::GetAspectRatio
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::GetAspectRatio;

		/// @see	GlRhiVideoMode::IsOpenGlCompatible
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::IsOpenGlCompatible;

		/// @see	GlRhiVideoMode::HasFullscreenSupport
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::HasFullscreenSupport;

		/// @see	GlRhiVideoMode::HasWindowSupport
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::HasWindowSupport;

	// Public interface.
	public:

	// Contracts of protected API.
	private:
		/// @see	GlRhiVideoMode::Swap
		using PlatformSpecific::GlRhiVideoMode<Black::BUILD_PLATFORM>::Swap;

	// Private interface.
	private:
		// Swap the state with given instance.
		void Swap( GlRhiVideoMode& other );
	};
}
}
}
