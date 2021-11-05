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
		@brief	RHI connection visitor for purposes of GPU adapters enumeration.

		This interface may be used to access the information about GPU hardware installed in system.
	*/
	class RhiAdapterInformationConsumer : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Information of RHI adapter.
		using AdapterInfo = std::tuple<::DXGI_ADAPTER_DESC1, size32_t>;

	// Public virtual interface.
	public:
		// Consume the information for RHI adapter.
		virtual void Consume( const AdapterInfo& info ) = 0;

	// Heirs construction and initialization.
	protected:
		RhiAdapterInformationConsumer()		= default;
		~RhiAdapterInformationConsumer()	= default;
	};

	/**
		@brief	RHI connection visitor for purposes of display enumeration.

		This interface may be used to access the information about displays installed in system.
	*/
	class RhiDisplayInformationConsumer : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Information of RHI display.
		using DisplayInfo = std::tuple<::DXGI_OUTPUT_DESC, ::DXGI_MODE_DESC, ::MONITORINFOEXW, ::DISPLAY_DEVICEW, size32_t, size32_t>;

	// Public virtual interface.
	public:
		// Consume the information for RHI display.
		virtual void Consume( const DisplayInfo& info ) = 0;

	// Heirs construction and initialization.
	protected:
		RhiDisplayInformationConsumer()		= default;
		~RhiDisplayInformationConsumer()	= default;
	};

	/**
		@brief	RHI connection visitor for purposes of display video modes enumeration.

		This interface may be used to access the information about video modes allowed for display.
	*/
	class RhiVideoModeInformationConsumer : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Information of display video mode.
		using VideoModeInfo = std::tuple<::DXGI_MODE_DESC>;

	// Public virtual interface.
	public:
		// Consume the information for display video mode.
		virtual void Consume( const VideoModeInfo& info ) = 0;

	// Heirs construction and initialization.
	protected:
		RhiVideoModeInformationConsumer()	= default;
		~RhiVideoModeInformationConsumer()	= default;
	};
}
}
}
}
