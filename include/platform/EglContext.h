#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Implementation of OpenGL context.

		Implements the final, third layer of platform-agnostic OpenGL context type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlContext final : public PlatformSpecific::GlContext<Black::BUILD_PLATFORM>
	{
	};
}
}
}
