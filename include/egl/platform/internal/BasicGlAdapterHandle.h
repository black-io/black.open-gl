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
		@brief	Most fundamental, the basic, information about GPU hardware.

		Basic handle underlies the cross-platform type and implements the state and interface used by platform-specific types of all platforms.

		This type implements the first layer of platform-agnostic Adapter Handle type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlAdapterHandle
	{
	// Heirs construction and initialization.
	protected:
		BasicGlAdapterHandle()								= default;
		BasicGlAdapterHandle( const BasicGlAdapterHandle& )	= default;
		BasicGlAdapterHandle( BasicGlAdapterHandle&& )		= default;
		~BasicGlAdapterHandle()								= default;


		inline BasicGlAdapterHandle& operator = ( const BasicGlAdapterHandle& )	= default;
		inline BasicGlAdapterHandle& operator = ( BasicGlAdapterHandle&& )		= default;
	};
}
}
}
}
