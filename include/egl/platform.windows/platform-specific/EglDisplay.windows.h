#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	/**
		@brief	Platform-specific implementation of EGL-compatible display in terms of Windows Desktop platform.

		On Windows Desktop platform the EGL Display uses the DXGI interface along with WGL functions.
		Also, any OpenGL context for this display will be created using the stored device context.

		Implements the second layer of platform-agnostic EGL display type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglDisplay<Black::PlatformType::WindowsDesktop> : public Internal::BasicEglDisplay
	{
	// Platform-specific interface.
	public:
		// Perform the display connection to default display of given adapter.
		const bool Connect( const Black::GlAdapterHandle& adapter_handle, ::IDXGIFactory& factory );

		// Perform the display connection to given display.
		const bool Connect( const Black::GlDisplayHandle& display_handle, ::IDXGIFactory& factory );


		// Ensure that pixel format is set for device context of display.
		void EnsurePixelFormatSet( const Black::EglConfiguration& configuration ) const;


		// Query the interface of bound GPU adapter. May return `nullptr` if display is not connected.
		inline ::IDXGIAdapter* QueryAdapterInterface() const			{ return m_adapter_interface.get(); };

		// Query the interface of bound GPU adapter. May return `nullptr` if display is not connected.
		inline ::IDXGIAdapter1* QueryAdapterV1Interface() const			{ return m_adapter_v1_interface.get(); };

		// Query the interface of bound display. May return `nullptr` if display is not connected.
		inline ::IDXGIOutput* QueryOutputInterface() const				{ return m_output_interface.get(); };

		// Get the instance of device context. May return `nullptr` if display is not connected.
		inline const ::HDC GetDeviceContext() const						{ return m_device_context; };

		// Get the description of display device.
		inline const ::DXGI_OUTPUT_DESC& GetOutputDescription() const	{ return m_device_desc; };

		// Get the default video mode of display.
		inline const ::DXGI_MODE_DESC& GetDefaultVideoMode() const		{ return m_default_mode; };

		// Get the desktop settings of display.
		inline const ::DEVMODEW& GetDesktopSettings() const				{ return m_desktop_settings; };

		// Get the additional information about display monitor.
		inline const ::MONITORINFOEXW& GetDisplayMonitorInfo() const	{ return m_monitor_info; };

		// Get the additional information about display.
		inline const ::DISPLAY_DEVICEW& GetDisplayInfo() const			{ return m_display_info; };

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
		inline const bool IsConnected() const { return m_device_context != nullptr; };

	// Heirs construction and initialization.
	protected:
		EglDisplay()	= default;
		~EglDisplay()	= default;

	// Private interface.
	private:
		// Acquire the interface of connected GPU.
		const bool AcquireAdapterInterface( size32_t adapter_index, ::IDXGIFactory& factory );

		// Acquire the interface of connected display.
		const bool AcquireOutputInterface( size32_t output_index, ::IDXGIFactory& factory );

		// Manually collect the display information.
		const bool CollectDisplayInfo();

		// Copy the display information from given handle.
		const bool CopyDisplayInfo( const Black::GlDisplayHandle& display_handle );

		// Try to create the device context.
		const bool CreateDeviceContext();

		// Delete the owned device context.
		void DeleteDeviceContext();

	// Private state.
	private:
		Black::UniqueComPointer<::IDXGIAdapter>		m_adapter_interface;				// Owned interface of GPU device.
		Black::UniqueComPointer<::IDXGIAdapter1>	m_adapter_v1_interface;				// Owned interface of GPU device.
		Black::UniqueComPointer<::IDXGIOutput>		m_output_interface;					// Owned instance of display device.
		::HDC										m_device_context		= nullptr;	// Owned device context of display.

		::DXGI_OUTPUT_DESC	m_device_desc;		// Internal description of display device.
		::DXGI_MODE_DESC	m_default_mode;		// Default video mode of display.
		::DEVMODEW			m_desktop_settings;	// Display device desktop settings.
		::MONITORINFOEXW	m_monitor_info;		// Additional information about display.
		::DISPLAY_DEVICEW	m_display_info;		// Additional information about display.

	// Private non-state.
	private:
		mutable bool m_is_pixel_format_set = false; // Whether the pixel format is set for device context.
	};
}
}
}
}
}
