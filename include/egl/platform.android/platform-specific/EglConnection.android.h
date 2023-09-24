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
		@brief	Platform-specific implementation of EGL-compatible connection in terms of Android platform.

		This implementation directly uses EGL API.

		Implements the second layer of platform-agnostic EGL Connection type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglConnection<Black::PlatformType::Android> : public Internal::BasicEglConnection
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
		// Set the context of current application to be used.
		void UseApplicationContext( const ::Jni::Context& application_context );

		// Whether the connection is initialized.
		inline const bool IsInitialized() const { return m_window_manager.IsValid(); };

	// Platform-agnostic interface.
	public:
		// Perform the finalization of connection.
		void Finalize();


		// Perform the swap of surface buffers.
		void SwapBuffers( const Black::EglDisplay& display, const Black::EglSurface& surface );

		// Get the address of function by given name. May return `nullptr` for unknown function names.
		RegularFunction GetFunctionAddress( std::string_view function_name ) const;

		// Whether there current context present for current thread.
		const bool HasCurrentContext() const;


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
		const bool ConnectWindowSurface( const Black::EglDisplay& display, const ::Jni::Surface& window_handle, Black::EglSurface& target_surface );

		// Connect the surface with window using given display and given configuration for window surfaces.
		const bool ConnectWindowSurface(
			const Black::EglDisplay& display,
			const Black::EglConfiguration& surface_configuration,
			const ::Jni::Surface& window_handle,
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

		// Connect the context with given display and configuration.
		const bool ConnectContext( const Black::EglDisplay& display, const Black::EglConfiguration& configuration, Black::EglContext& target_context );

		// Connect the context with given display and configuration. Host context used to share the resources with target context.
		const bool ConnectContext(
			const Black::EglDisplay& display,
			const Black::EglConfiguration& configuration,
			const Black::EglContext& host_context,
			Black::EglContext& target_context
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
		::Jni::Context			m_application_context;		// Context of current application.
		::Jni::WindowManager	m_window_manager;			// Currently used window manager.

		bool			m_is_api_profile_set	= false;	// Whether the API profile was set.
	};
}
}
}
}
}
