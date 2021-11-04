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
		@brief	Platform dependent Display implementation in terms of windows desktop platform.

		On Windows Desktop platform the RHI to display is implemented via DXGI library.
		This type carries only description and ordinal index corresponded of `IDXGIOutput` instance.

		Implements the second layer of platform-agnostic display type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class RhiDisplay<Black::PlatformType::WindowsDesktop> : public Internal::BasicRhiDisplay
	{
	// Public inner types.
	public:
		// Construction arguments.
		using ConstructionArguments = std::tuple<::DXGI_OUTPUT_DESC, ::DXGI_MODE_DESC, ::MONITORINFOEXW, ::DISPLAY_DEVICEW, size32_t>;

	// Platform-specific interface.
	public:
		// Get the description of display device.
		inline const ::DXGI_OUTPUT_DESC& GetDeviceDescription() const	{ return m_device_desc; };

		// Get the default video mode of display.
		inline const ::DXGI_MODE_DESC& GetDefaultVideoMode() const		{ return m_default_mode; };

		// Get the additional information about display monitor.
		inline const ::MONITORINFOEXW& GetDisplayMonitorInfo() const	{ return m_monitor_info; };

		// Get the additional information about display.
		inline const ::DISPLAY_DEVICEW& GetDisplayInfo() const			{ return m_display_info; };

	// Platform-agnostic interface.
	public:
		// Get the ordinal index of display.
		inline const size32_t GetIndex() const							{ return m_index; };

	// Heirs construction and initialization.
	protected:
		RhiDisplay()					= delete;
		RhiDisplay( const RhiDisplay& )	= default;
		explicit RhiDisplay( const ConstructionArguments& arguments );
		~RhiDisplay()					= default;

	// Private state.
	private:
		::DXGI_OUTPUT_DESC	m_device_desc;		// Internal description of display device.
		::DXGI_MODE_DESC	m_default_mode;		// Default video mode of display.
		::MONITORINFOEXW	m_monitor_info;		// Additional information about display.
		::DISPLAY_DEVICEW	m_display_info;		// Additional information about display.
		size32_t			m_index;			// Ordinal index of display.
	};
}
}
}
}