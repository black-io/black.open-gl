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
		@brief	Basic information about GPU Adapter device.

		RHI for GPU adapter should implement the interface to identify and communicate with GPU hardware connected to system.

		This type implements the first layer of platform-agnostic RHI Adapter type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlRhiAdapter : private Black::NonMovable
	{
	// Heirs construction and initialization.
	protected:
		BasicGlRhiAdapter()								= default;
		BasicGlRhiAdapter( const BasicGlRhiAdapter& )	= default;
		~BasicGlRhiAdapter()							= default;
	};
}
}
}
}
