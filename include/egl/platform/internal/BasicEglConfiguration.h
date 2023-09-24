#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace Internal
{
	/**
		@brief	Basic implementation of EGL-compatible configuration object.

		This type implements the first layer of platform-agnostic EGL configuration type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglConfiguration : private Black::NonMovable
	{
	// Heirs construction and initialization.
	protected:
		BasicEglConfiguration()									= default;
		BasicEglConfiguration( const BasicEglConfiguration& )	= default;
		~BasicEglConfiguration()								= default;
	};
}
}
}
}
}
