#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace Internal
{
	// Pixel format settings for pixel buffers.
	struct PixelBufferSettings final
	{
		int32_t			maximum_width	= 0;	// Value of maximum width.
		int32_t			maximum_height	= 0;	// Value of maximum height.
		int32_t			maximum_pixels	= 0;	// Maximum number of pixels allowed for single pixel buffer.
		int32_t			optimal_width	= 0;	// Value of optimal width.
		int32_t			optimal_height	= 0;	// Value of optimal height.

		union
		{
			int32_t		bits			= 0;	// Buffer to store the bits of boolean flags.

			struct
			{
				bool	is_supported	: 1;	// Whether the pixel format supports the pixel buffers.
			};
		};
	};

	// State of window surface.
	struct WindowSurfaceState final
	{
		::HWND host_window{}; // Host window of surface.
	};

	// State of pixel buffer surface.
	struct PixelBufferSurfaceState final
	{
		void* owned_pixel_buffer = nullptr; // Storage for owned pixel buffer.
	};
}
}
}
}
