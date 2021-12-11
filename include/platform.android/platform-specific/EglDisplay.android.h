#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	/**
		@brief	Platform-specific implementation of EGL-compatible display in terms of Android platform.

		This implementation directly uses the EGL API. It represents the `EGLDisplay` type.

		Implements the second layer of platform-agnostic EGL display type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglDisplay<Black::PlatformType::Android> : public Internal::BasicEglDisplay
	{
	// Platform-specific interface.
	public:
		// Perform the display connection to default display of given adapter.
		const bool Connect( const Black::GlAdapterHandle& adapter_handle );

		// Perform the display connection to given display.
		const bool Connect( const Black::GlDisplayHandle& display_handle );


		// Get the handle of corresponded EGL display.
		inline ::EGLDisplay GetHandle() const	{ return m_handle; };

	// Platform-agnostic interface.
	public:
		// Finalize the device connection.
		void Finalize();


		// Update the available configurations for connected display.
		void UpdateConfigurations();

		// Find the best configuration for window surfaces.
		std::optional<Black::EglConfiguration> FindBestWindowConfiguration() const;

		// Find the best configuration for pixel buffer surfaces.
		std::optional<Black::EglConfiguration> FindBestPixelBufferConfiguration( const Black::EglConfiguration& window_configuration ) const;


		// Whether the display is connected to device.
		inline const bool IsConnected() const { return m_handle != EGL_NO_DISPLAY; };

	// Heirs construction and initialization.
	protected:
		EglDisplay()	= default;
		~EglDisplay()	= default;

	// Private interface.
	private:
		// Acquire the display handle from its native one.
		const bool AcquireDisplayHandle( ::EGLNativeDisplayType native_handle );

	// Private state.
	private:
		::EGLDisplay m_handle = EGL_NO_DISPLAY; // Corresponded EGL display.
	};
}
}
}
}
