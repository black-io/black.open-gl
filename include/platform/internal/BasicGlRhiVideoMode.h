#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace Internal
{
	/**
		@brief	Basic implementation of display video mode.

		RHI for display video mode should implement the interface for graphics display to configure the identified video mode.

		This type implements the first layer of platform-agnostic RHI video mode type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlRhiVideoMode
	{
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

	// Heirs construction and initialization.
	protected:
		BasicGlRhiVideoMode()								= default;
		BasicGlRhiVideoMode( const BasicGlRhiVideoMode& )	= default;
		BasicGlRhiVideoMode( BasicGlRhiVideoMode&& )		= default;
		~BasicGlRhiVideoMode()								= default;

	// Heirs interface.
	protected:
		// Swap the state with given instance.
		void Swap( BasicGlRhiVideoMode& other );

	// Heirs state.
	protected:
		size32_t	m_width			= 0;	// Width in pixels.
		size32_t	m_height		= 0;	// Height in pixels.
		size32_t	m_bit_rate		= 0;	// Color depth in bits.
		size32_t	m_refresh_rate	= 0;	// Frequency of vertical synchronization in Hz.
		float		m_aspect		= 0.0f;	// Aspect of display area.

		union
		{
			uint32_t	m_boolean_bits		= 0;	// Blob for boolean values.

			struct
			{
				bool	m_is_compatible		: 1;	// Whether the video format is suitable enough to be used for OpenGL.
				bool	m_allow_fullscreen	: 1;	// Whether the video mode may be used as full-screen display mode.
				bool	m_allow_windowed	: 1;	// Whether the video mode may be used for window while display in windowed mode.
			};
		};
	};
}
}
}
}
