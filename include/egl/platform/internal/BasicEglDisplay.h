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
		@brief	Basic implementation of EGL-compatible display object.

		This type implements the first layer of platform-agnostic EGL display type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglDisplay : private Black::NonTransferable
	{
	// Heirs construction and initialization.
	protected:
		BasicEglDisplay()	= default;
		~BasicEglDisplay()	= default;

	// Heirs state.
	protected:
		std::vector<Black::EglConfiguration> m_configurations; // List of Available configurations for display.
	};
}
}
}
}
}
