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
		@brief	Platform-specific implementation of GPU adapter handle.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlAdapterHandle;

	/**
		@brief	Platform-specific implementation of display handle.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlDisplayHandle;

	/**
		@brief	Platform-specific implementation of display video mode.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlDisplayVideoMode;

	/**
		@brief	Platform-specific implementation of EGL-compatible configuration object.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglConfiguration;

	/**
		@brief	Platform-specific implementation of EGL-compatible display object.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglDisplay;

	/**
		@brief	Platform-specific implementation of EGL-compatible surface object.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglSurface;

	/**
		@brief	Platform-specific implementations of EGL-compatible context object.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglContext;

	/**
		@brief	Platform-specific implementation of EGL connection.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglConnection;
}
}
}
}
