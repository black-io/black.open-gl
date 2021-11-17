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
		@brief	Basic implementation of EGL-compatible context object.

		This type implements the first layer of platform-agnostic EGL Context type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglContext : private Black::NonTransferable
	{
	// Heirs construction and initialization.
	protected:
		BasicEglContext()	= default;
		~BasicEglContext()	= default;
	};
}
}
}
}
