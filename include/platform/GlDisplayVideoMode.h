#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Video Mode object for Display.

		Implements the final, third layer of platform-agnostic display video mode type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlDisplayVideoMode final : public PlatformSpecific::GlDisplayVideoMode<Black::BUILD_PLATFORM>
	{
	// Friendship declarations.
	public:
		// Swap the state with given instance.
		friend inline void swap( GlDisplayVideoMode& left, GlDisplayVideoMode& right ) { left.Swap( right ); };

	// Construction and initialization.
	public:
		GlDisplayVideoMode()						= delete;
		GlDisplayVideoMode( const GlDisplayVideoMode& )	= default;
		GlDisplayVideoMode( GlDisplayVideoMode&& )		= default;
		explicit GlDisplayVideoMode( const ConstructionInfo& info );
		~GlDisplayVideoMode() = default;

	// Contracts of public API.
	public:

	// Public interface.
	public:
		// Get the width of resolution.
		inline const size32_t GetWidth() const			{ return m_width; };

		// Get the height of resolution.
		inline const size32_t GetHeight() const			{ return m_height; };

		// Get the bit rate.
		inline const size32_t GetBitRate() const		{ return m_bit_rate; };

		// Get the refresh rate.
		inline const size32_t GetRefreshRate() const	{ return m_refresh_rate; };

		// Get the aspect ratio, which represents `width / height` proportion.
		inline const float GetAspectRatio() const		{ return m_aspect; };


		// Whether the video mode is suitable for purposes of OpenGL.
		inline const bool IsOpenGlCompatible() const	{ return m_is_compatible; };

		// Whether the video mode may be used as full-screen display mode.
		inline const bool HasFullscreenSupport() const	{ return m_allow_fullscreen; };

		// Whether the video mode may be used for window while display in windowed mode.
		inline const bool HasWindowSupport() const		{ return m_allow_windowed; };

	// Contracts of protected API.
	private:
		/// @see	GlDisplayVideoMode::Swap
		using PlatformSpecific::GlDisplayVideoMode<Black::BUILD_PLATFORM>::Swap;

	// Private interface.
	private:
		// Swap the state with given instance.
		void Swap( GlDisplayVideoMode& other );
	};
}
}
}
