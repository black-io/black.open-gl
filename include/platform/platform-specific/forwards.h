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
		@brief	Platform dependent GPU adapter implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlRhiAdapter;

	/**
		@brief	Platform dependent Display implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlRhiDisplay;

	/**
		@brief	Platform dependent display video mode implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlRhiVideoMode;

	/**
		@brief	Platform dependent EGL-compatible configuration implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglConfiguration;

	/**
		@brief	Platform dependent EGL-compatible display implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class EglDisplay;

	/**
		@brief	Platform dependent OpenGL context implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlContext;

	/**
		@brief	Platform dependent GPU connection implementation.
		This class is statically instantiated for any of platform the framework supports.
		Each instantiation may have platform-specific code.
	*/
	template< Black::PlatformType PLATFORM_TYPE >
	class GlRhiConnection;
}
}
}
}
