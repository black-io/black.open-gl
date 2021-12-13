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
		@brief	Platform-specific implementation of EGL-compatible connection in terms of Android platform.

		This implementation directly uses EGL API.

		Implements the second layer of platform-agnostic EGL Connection type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglConnection<Black::PlatformType::Android> : public Internal::BasicEglConnection
	{
	};
}
}
}
}
