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
		@brief	Most fundamental, the basic, information about Display video mode.

		Basic mode underlies the cross-platform type and implements the state and interface used by platform-specific types of all platforms.

		This type implements the first layer of platform-agnostic Display Video Mode type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlDisplayVideoMode
	{
	// Public interface.
	public:

	// Heirs construction and initialization.
	protected:
		BasicGlDisplayVideoMode()									= default;
		BasicGlDisplayVideoMode( const BasicGlDisplayVideoMode& )	= default;
		BasicGlDisplayVideoMode( BasicGlDisplayVideoMode&& )		= default;
		~BasicGlDisplayVideoMode()									= default;


		inline BasicGlDisplayVideoMode& operator = ( const BasicGlDisplayVideoMode& )	= default;
		inline BasicGlDisplayVideoMode& operator = ( BasicGlDisplayVideoMode&& )		= default;

	// Heirs interface.
	protected:
		// Swap the state with given instance.
		void Swap( BasicGlDisplayVideoMode& other );

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
