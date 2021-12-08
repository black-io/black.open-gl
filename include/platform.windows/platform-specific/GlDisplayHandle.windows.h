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
		@brief	Platform-specific information of Display hardware in terms of WIndows Desktop platform.

		On Windows Desktop platform the handle is implemented via DXGI library.
		This type carries only description and ordinal index corresponded of `IDXGIOutput` instance.

		Implements the second layer of platform-agnostic Display Handle type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlDisplayHandle<Black::PlatformType::WindowsDesktop> : public Internal::BasicGlDisplayHandle
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::DisplayHandleInformationConsumer::DisplayInfo;

	// Platform-specific interface.
	public:
		// Get the description of display device.
		inline const ::DXGI_OUTPUT_DESC& GetDeviceDescription() const	{ return m_device_desc; };

		// Get the default video mode of display.
		inline const ::DXGI_MODE_DESC& GetDefaultVideoMode() const		{ return m_default_mode; };

		// Get the desktop settings of display.
		inline const ::DEVMODEW& GetDesktopSettings() const				{ return m_desktop_settings; };

		// Get the additional information about display monitor.
		inline const ::MONITORINFOEXW& GetDisplayMonitorInfo() const	{ return m_monitor_info; };

		// Get the additional information about display.
		inline const ::DISPLAY_DEVICEW& GetDisplayInfo() const			{ return m_display_info; };

		// Get the ordinal index of display.
		inline const size32_t GetIndex() const							{ return m_index; };

		// Get the ordinal index of GPU adapter, where the display is connected.
		inline const size32_t GetAdapterIndex() const					{ return m_adapter_index; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		GlDisplayHandle()							= delete;
		GlDisplayHandle( const GlDisplayHandle& )	= default;
		GlDisplayHandle( GlDisplayHandle&& )		= default;
		explicit GlDisplayHandle( const ConstructionInfo& info );
		~GlDisplayHandle() = default;

	// Private interface.
	private:
		// Fill the `m_desktop_settings` with valid information.
		const bool ReadDesktopSettings();

		// Fill the `m_monitor_info` with valid information.
		const bool ReadMonitorInfo();

		// Fill the `m_display_info` with valid information.
		const bool ReadDisplayInfo();

	// Private state.
	private:
		::DXGI_OUTPUT_DESC	m_device_desc;		// Internal description of display device.
		::DXGI_MODE_DESC	m_default_mode;		// Default video mode of display.
		size32_t			m_adapter_index;	// Ordinal index of GPU adapter the display connected.
		size32_t			m_index;			// Ordinal index of display.

		::DEVMODEW			m_desktop_settings;	// Desktop settings of display.
		::MONITORINFOEXW	m_monitor_info;		// Additional information about display.
		::DISPLAY_DEVICEW	m_display_info;		// Additional information about display.
	};
}
}
}
}
