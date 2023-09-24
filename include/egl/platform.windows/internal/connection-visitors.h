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
		@brief	EGL Connection visitor for purposes of GPU adapters enumeration.

		This interface may be used to access the information about GPU hardware installed in system.
	*/
	class AdapterHandleInformationConsumer : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Information of adapter.
		using AdapterInfo = std::tuple<const ::DXGI_ADAPTER_DESC1&, size32_t>;

	// Public virtual interface.
	public:
		// Consume the adapter information.
		virtual void Consume( std::string_view device_path, std::string_view device_name, const AdapterInfo& info ) = 0;

	// Heirs construction and initialization.
	protected:
		AdapterHandleInformationConsumer()	= default;
		~AdapterHandleInformationConsumer()	= default;
	};

	/**
		@brief	EGL Connection visitor for purposes of display enumeration.

		This interface may be used to access the information about displays installed in system.
	*/
	class DisplayHandleInformationConsumer : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Information of display.
		using DisplayInfo = std::tuple<const ::DXGI_OUTPUT_DESC&, const ::DXGI_MODE_DESC&, size32_t, size32_t>;

	// Public virtual interface.
	public:
		// Consume the display information.
		virtual void Consume( std::string_view device_path, std::string_view device_name, const DisplayInfo& info ) = 0;

	// Heirs construction and initialization.
	protected:
		DisplayHandleInformationConsumer()	= default;
		~DisplayHandleInformationConsumer()	= default;
	};

	/**
		@brief	EGL Connection visitor for purposes of display video modes enumeration.

		This interface may be used to access the information about video modes allowed for display.
	*/
	class DisplayVideoModeInformationConsumer : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Information of display video mode.
		using VideoModeInfo = std::tuple<const ::DXGI_MODE_DESC&>;

	// Public virtual interface.
	public:
		// Consume the information for display video mode.
		virtual void Consume( const VideoModeInfo& info ) = 0;

	// Heirs construction and initialization.
	protected:
		DisplayVideoModeInformationConsumer()	= default;
		~DisplayVideoModeInformationConsumer()	= default;
	};
}
}
}
}
