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
		@brief	Platform-specific implementation of EGL-compatible surface in terms of Android platform.

		This implementation directly uses the EGL API. It represents the `EGLSurface` type.

		Implements the second layer of platform-agnostic EGL Surface type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglSurface<Black::PlatformType::Android> : public Internal::BasicEglSurface
	{
	// Platform-specific interface.
	public:
		// Connect the surface to given window.
		const bool ConnectWindow( const Black::EglDisplay& display, const Black::EglConfiguration& configuration, const ::Jni::Surface& window_surface );

		// Connect the surface to pixel buffer.
		const bool ConnectPixelBuffer(
			const Black::EglDisplay& display,
			const Black::EglConfiguration& configuration,
			const size32_t width,
			const size32_t height
		);


		// Get the handle of host EGL display for this surface.
		inline const ::EGLDisplay GetDisplayHandle() const	{ return m_display_handle; };

		// Get the handle of corresponded EGL surface.
		inline const ::EGLSurface GetHandle() const			{ return m_handle; };

	// Platform-agnostic interface.
	public:
		// Finalize the surface connection.
		void Finalize();


		// Whether the surface object is connected.
		inline const bool IsConnected() const { return m_handle != EGL_NO_SURFACE; };

	// Heirs construction and initialization.
	protected:
		EglSurface()	= default;
		~EglSurface()	= default;

	// Private state.
	private:
		::EGLDisplay	m_display_handle	= EGL_NO_DISPLAY;	// EGL display that hosts the surface.
		::EGLSurface	m_handle			= EGL_NO_SURFACE;	// Corresponded EGL surface.
	};
}
}
}
}
}
