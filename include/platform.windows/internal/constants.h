#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace Internal
{
	// Type of surface.
	enum class SurfaceType : uint32_t
	{
		Undefined = 0,	// Type is undefined.
		Window,			// Surface connected to window.
		PixelBuffer,	// Surface connected to pixel buffer.
		FrameBuffer,	// Surface connected to frame buffer.
	};
}
}
}
}
