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
		@brief	Basic interface of EGL-compatible connection.

		This type implements the first layer of platform-agnostic EGL Connection type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglConnection : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Regular function pointer.
		using RegularFunction = void (*)();

	// Heirs construction and initialization.
	protected:
		BasicEglConnection()	= default;
		~BasicEglConnection()	= default;
	};
}
}
}
}
