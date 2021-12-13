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
		@brief	Platform-specific implementation of EGL-compatible context in terms of Windows Desktop platform.

		Implements the second layer of platform-agnostic EGL Context type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglContext<Black::PlatformType::WindowsDesktop> : public Internal::BasicEglContext
	{
	// Platform-specific interface.
	public:
		// Connect the context with given display.
		const bool Connect( const Black::EglDisplay& display, const Black::EglConfiguration& configuration );

		// Connect the context with given display and given host context.
		const bool Connect( const Black::EglDisplay& display, const Black::EglConfiguration& configuration, const Black::EglContext& host_context );


		// Get the rendering context.
		inline const ::HGLRC GetRenderingContext() const { return m_rendering_context; };

	// Platform-agnostic interface.
	public:
		// Finalize the context connection.
		void Finalize();


		// Make the context to be no more current for current thread.
		const bool ResetCurrent( const Black::EglDisplay& display );

		// Make the context to be current for current thread with given target surface.
		const bool MakeCurrent( const Black::EglDisplay& display, const Black::EglSurface& target_surface );

		// Make the context to be current for current thread with given target surfaces.
		const bool MakeCurrent( const Black::EglDisplay& display, const Black::EglSurface& rendering_surface, const Black::EglSurface& reading_surface );


		// Whether the context is connected.
		inline const bool IsConnected() const	{ return m_rendering_context != nullptr; };

	// Heirs construction and initialization.
	protected:
		EglContext()	= default;
		~EglContext()	= default;

	// Private interface.
	private:
		// Perform the actual OpenGL context creation.
		const bool AcquireRenderingContext( const ::HDC device_context, const ::HGLRC host_context );

		// Build the bit-mask of context flags.
		const int32_t BuildContextFlags() const;

		// Build the bit-mask of context profile flags.
		const int32_t BuildProfileMask() const;

	// Private state.
	private:
		::HGLRC m_rendering_context = nullptr; // Owned handle of rendering context.
	};
}
}
}
}
