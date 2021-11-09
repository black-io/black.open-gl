#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Initialize the WGL interface for required display output device.
	const bool WglInitialize( ::IDXGIOutput& display );
}
}
}
}
