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
		@brief	Platform-specific implementation of EGL-compatible surface in terms of Windows Desktop platform.

		On Windows Desktop platform the surface implements the interface for windows and pixel buffers.
		WIndows are specified by HWND type. Pixel buffers are available only through WGL extensions: WGL_EXT_pbuffer or WGL_ARB_pbuffer.

		Implements the second layer of platform-agnostic EGL Surface type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglSurface<Black::PlatformType::WindowsDesktop> : public Internal::BasicEglSurface
	{
	// Inner public types.
	public:
		// Type of surface.
		using SurfaceType = Internal::SurfaceType;

	// Platform-specific interface.
	public:
		// Connect the surface to given window.
		const bool ConnectWindow( const Black::EglDisplay& display, const Black::EglConfiguration& configuration, const ::HWND window_handle );

		// Connect the surface to pixel buffer.
		const bool ConnectPixelBuffer(
			const Black::EglDisplay& display,
			const Black::EglConfiguration& configuration,
			const size32_t width,
			const size32_t height
		);


		// Get the surface context.
		inline const ::HDC GetSurfaceContext() const { return m_surface_context; };

	// Platform-agnostic interface.
	public:
		// Finalize the surface connection.
		void Finalize();


		// Whether the surface object is connected.
		inline const bool IsConnected() const		{ return m_surface_context != nullptr; };

		// Get the type of surface.
		inline const SurfaceType GetType() const	{ return m_type; };

	// Heirs construction and initialization.
	protected:
		EglSurface()	= default;
		~EglSurface()	= default;

	// Private types.
	private:
		// Internal state composition.
		using SurfaceState = std::variant<
			std::monostate,						// Type of surface is undefined.
			Internal::WindowSurfaceState,		// For window surfaces.
			Internal::PixelBufferSurfaceState	// For pixel buffer surfaces.
		>;

	// Private interface.
	private:
		// Destroy the owned pixel buffer surface.
		void DestroyPixelBuffer();

	// Private state.
	private:
		::HDC			m_surface_context	= nullptr;					// Usable surface context.
		SurfaceState	m_state				{ std::monostate{} };		// Composition of internal state.
		SurfaceType		m_type				= SurfaceType::Undefined;	// Type of surface connection.
	};
}
}
}
}
