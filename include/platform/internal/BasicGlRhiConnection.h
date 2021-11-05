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
		@brief	Basic implementation of GPU connection.

		RHI connection should implement the functionality to communicate with current hardware setup.
		All other RHI types may be used only with support of RHI connection.

		This type implements the first layer of platform-agnostic RHI connection type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlRhiConnection : private Black::NonTransferable
	{
	// Heirs construction and initialization.
	protected:
		BasicGlRhiConnection()								= default;
		BasicGlRhiConnection( const BasicGlRhiConnection& )	= default;
		~BasicGlRhiConnection()								= default;
	};
}
}
}
}
