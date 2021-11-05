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
		@brief	Basic implementation of EGL-compatible configuration object.

		This type implements the first layer of platform-agnostic GL configuration type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicGlConfiguration : private Black::NonTransferable
	{
	};
}
}
}
}
