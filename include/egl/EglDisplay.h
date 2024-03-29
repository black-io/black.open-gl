#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
	/**
		@brief	EGL-compatible display object.

		Implements the final, third layer of platform-agnostic EGL display type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglDisplay final : public PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		EglDisplay() = default;
		~EglDisplay();

	// Contracts of public API.
	public:
		/// @see	EglDisplay::Finalize
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::Finalize;

		/// @see	EglDisplay::UpdateConfigurations
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::UpdateConfigurations;

		/// @see	EglDisplay::FindBestWindowConfiguration
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::FindBestWindowConfiguration;

		/// @see	EglDisplay::FindBestPixelBufferConfiguration
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::FindBestPixelBufferConfiguration;

		/// @see	EglDisplay::IsConnected
		using PlatformSpecific::EglDisplay<Black::BUILD_PLATFORM>::IsConnected;

	// Public interface.
	public:
		// Get the list of available EGL configurations for display.
		inline Black::PlainView<const Black::EglConfiguration> GetConfigurations() const { return { m_configurations.data(), m_configurations.size() }; };
	};
}
}
}
