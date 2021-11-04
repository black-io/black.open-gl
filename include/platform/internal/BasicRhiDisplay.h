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
		@brief	Basic implementation of display.

		RHI for display should implement the interface to identify and communicate with display device connected to particular GPU adapter.
		At this level there is no requirement to associate GPU adapter with display device, so user shall implement such functionality manually once it required.

		This type implements the first layer of platform-agnostic RHI display type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicRhiDisplay : private Black::NonMovable
	{
	// Heirs construction and initialization.
	protected:
		BasicRhiDisplay()							= default;
		BasicRhiDisplay( const BasicRhiDisplay& )	= default;
		~BasicRhiDisplay()							= default;
	};
}
}
}
}
