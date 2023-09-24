#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
inline namespace Android
{
	/**
		@brief	Handle.
		Original type is `GLhandleARB`. Aliased type is `unsigned int` or `void *` on Apple platforms.
	*/
	using GlHandleArb = uint32_t;
}
}
}
}
}
