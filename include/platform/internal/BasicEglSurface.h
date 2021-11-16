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
		@brief	Basic implementation of EGL-compatible surface object.

		This type implements the first layer of platform-agnostic EGL Surface type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglSurface : private Black::NonTransferable
	{
	// Heirs construction and initialization.
	protected:
		BasicEglSurface()	= default;
		~BasicEglSurface()	= default;
	};
}
}
}
}
