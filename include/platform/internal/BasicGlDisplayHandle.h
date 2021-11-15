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
		@brief	Most fundamental, the basic, information about display hardware connected to GPU.

		Basic handle underlies the cross-platform type and implements the state and interface used by platform-specific types of all platforms.
		At this level there is no requirement to associate GPU adapter with display device, so user shall implement such functionality manually once it required.

		This type implements the first layer of platform-agnostic Display Handle type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlDisplayHandle
	{
	// Heirs construction and initialization.
	protected:
		BasicGlDisplayHandle()								= default;
		BasicGlDisplayHandle( const BasicGlDisplayHandle& )	= default;
		BasicGlDisplayHandle( BasicGlDisplayHandle&& )		= default;
		~BasicGlDisplayHandle()								= default;
	};
}
}
}
}
