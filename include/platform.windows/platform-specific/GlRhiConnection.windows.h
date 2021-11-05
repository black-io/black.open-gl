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
		@brief	Platform dependent GPU connection implementation.

		Implements the second layer of platform-agnostic GPU connection type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class RhiConnection<Black::PlatformType::WindowsDesktop> : public Internal::BasicRhiConnection
	{
	// Public inner types.
	public:
		// Interface to consume the RHI adapter information.
		using AdapterInfoConsumer = Internal::RhiAdapterInformationConsumer;

		// Interface to consume the RHI display information.
		using DisplayInfoConsumer = Internal::RhiDisplayInformationConsumer;

		// Interface to consume the display video mode information.
		using VideoModeInfoConsumer = Internal::RhiVideoModeInformationConsumer;

	// Static platform-specific interface.
	public:
		// Get the list of compatible formats for display.
		static Black::PlainView<const ::DXGI_FORMAT> GetCompatibleDisplayFormats();

		// Get the bit-rate for given display format. May return `0` in case the format is not compatible.
		static const size32_t GetDisplayFormatBitrate( const ::DXGI_FORMAT format );

		// Whether the given display format is compatible for purposes of OpenGL.
		static const bool IsDisplayFormatCompatible( const ::DXGI_FORMAT format );

	// Platform-specific interface.
	public:
		// Query the interface of generic DXGI factory. May return `nullptr`.
		::IDXGIFactory* QueryGenericFactory();

		// Query the interface of extended DXGI factory. May return `nullptr`.
		::IDXGIFactory1* QueryExtendedFactory();


		// Whether the connection is initialized.
		inline const bool IsInitialized() const { return m_generic_factory != nullptr; };

	// Platform-agnostic interface.
	public:
		// Perform the finalization of connection.
		void Finalize();


		// Enumerate the GPU adapters installed in system.
		void EnumerateAdapters( AdapterInfoConsumer& consumer );

		// Enumerate the displays connected to given GPU adapter.
		void EnumerateDisplays( const Black::RhiAdapter& adapter, DisplayInfoConsumer& consumer );

		// Enumerate the video modes for given display.
		void EnumerateVideoModes( const Black::RhiDisplay& display, VideoModeInfoConsumer& consumer );

	// Heirs construction and initialization.
	protected:
		RhiConnection()		= default;
		~RhiConnection()	= default;

	// Private interface.
	private:
		// Ensure the connection is initialized.
		void EnsureInitialized();

	// Private state.
	private:
		Black::UniqueComPointer<::IDXGIFactory>		m_generic_factory;	// Generic interface of DXGI factory.
		Black::UniqueComPointer<::IDXGIFactory1>	m_extended_factory;	// Extended interface of DXGI factory.
	};
}
}
}
}
