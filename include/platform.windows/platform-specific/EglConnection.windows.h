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
		@brief	Platform-specific implementation of EGL-compatible connection in terms of Windows Desktop platform.

		Windows Desktop platform operates with DXGI and WGL implementations.
		Devices are enumerated with DXGI, but the most of OpenGL-related functional is implemented with WGL and WGL extensions.

		Implements the second layer of platform-agnostic EGL Connection type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglConnection<Black::PlatformType::WindowsDesktop> : public Internal::BasicEglConnection
	{
	// Public inner types.
	public:
		// Interface to consume the RHI adapter information.
		using AdapterInfoConsumer = Internal::AdapterHandleInformationConsumer;

		// Interface to consume the RHI display information.
		using DisplayInfoConsumer = Internal::DisplayHandleInformationConsumer;

		// Interface to consume the display video mode information.
		using VideoModeInfoConsumer = Internal::DisplayVideoModeInformationConsumer;

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
		void EnumerateDisplays( const Black::GlAdapterHandle& adapter_handle, DisplayInfoConsumer& consumer );

		// Enumerate the video modes for given display.
		void EnumerateVideoModes( const Black::GlDisplayHandle& display_handle, VideoModeInfoConsumer& consumer );


		// Perform the EGL display connection to given adapter.
		const bool ConnectDisplay( const Black::GlAdapterHandle& adapter_handle, Black::EglDisplay& target_display );

		// Perform the EGL display connection to given display.
		const bool ConnectDisplay( const Black::GlDisplayHandle& display_handle, Black::EglDisplay& target_display );

		// Connect the surface with window using given display and best configuration for window surfaces.
		const bool ConnectWindowSurface( const Black::EglDisplay& display, const ::HWND window_handle, Black::EglSurface& target_surface );

		// Connect the surface with window using given display and given configuration for window surfaces.
		const bool ConnectWindowSurface(
			const Black::EglDisplay& display,
			const Black::EglConfiguration& surface_configuration,
			const ::HWND window_handle,
			Black::EglSurface& target_surface
		);

		// Connect the surface with pixel buffer using given display and best configuration for pixel buffer surfaces.
		const bool ConnectPixelBufferSurface(
			const Black::EglDisplay& display,
			const size32_t width,
			const size32_t height,
			Black::EglSurface& target_surface
		);

		// Connect the surface with pixel buffer using given display and given configuration for pixel buffer surfaces.
		const bool ConnectPixelBufferSurface(
			const Black::EglDisplay& display,
			const Black::EglConfiguration& surface_configuration,
			const size32_t width,
			const size32_t height,
			Black::EglSurface& target_surface
		);

	// Heirs construction and initialization.
	protected:
		EglConnection()		= default;
		~EglConnection()	= default;

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
