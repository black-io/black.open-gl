#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
	/**
		@brief	EGL-compatible Connection object.

		EGL Connection object implements the bridge for platform-specific API to configure and initialize the OpenGL-related objects.

		Implements the final, third layer of platform-agnostic EGL Connection type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglConnection final : public PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		EglConnection() = default;
		~EglConnection();

	// Contracts of public API.
	public:
		/// @see	EglConnection::Finalize
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::Finalize;

		/// @see	EglConnection::SwapBuffers
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::SwapBuffers;

		/// @see	EglConnection::GetFunctionAddress
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::GetFunctionAddress;

		/// @see	EglConnection::HasCurrentContext
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::HasCurrentContext;

		/// @see	EglConnection::EnumerateAdapters
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::EnumerateAdapters;

		/// @see	EglConnection::EnumerateDisplays
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::EnumerateDisplays;

		/// @see	EglConnection::EnumerateVideoModes
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::EnumerateVideoModes;

		/// @see	EglConnection::ConnectDisplay
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::ConnectDisplay;

		/// @see	EglConnection::ConnectWindowSurface
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::ConnectWindowSurface;

		/// @see	EglConnection::ConnectPixelBufferSurface
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::ConnectPixelBufferSurface;

		/// @see	EglConnection::ConnectContext
		using PlatformSpecific::EglConnection<Black::BUILD_PLATFORM>::ConnectContext;

	// Public interface.
	public:

	};
}
}
}
