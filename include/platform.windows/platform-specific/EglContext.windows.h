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

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		EglContext()	= default;
		~EglContext()	= default;

	// Private state.
	private:

	};
}
}
}
}
