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
		@brief	Basic implementation of EGL-compatible display object.

		This type implements the first layer of platform-agnostic EGL display type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglDisplay : private Black::NonTransferable
	{
	// Public interface.
	public:
		// Get the list of available EGL configurations for display.
		inline Black::PlainVector<const Black::EglConfiguration> GetConfigurations() const { return { m_configurations.data(), m_configurations.size() }; };

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
