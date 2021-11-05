#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace Internal
{
	/**
		@brief	Basic implementation of OpenGL context object.

		This type implements the first layer of platform-agnostic OpenGL context type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlContext : private Black::NonTransferable
	{
	};
}
}
}
}
