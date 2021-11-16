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
	// Platform-specific interface.
	public:

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		EglSurface() = default;
		~EglSurface();

	// Private state.
	private:

	};
}
}
}
}
