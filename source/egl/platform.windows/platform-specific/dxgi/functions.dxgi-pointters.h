#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Query the adapter interface by given ordinal number.
	::IDXGIAdapter* QueryAdapterInterface( ::IDXGIFactory& factory, const size32_t adapter_index );

	// Query the output interface by given ordinal number.
	::IDXGIOutput* QueryOutputInterface( ::IDXGIAdapter& adapter, const size32_t output_index );

	// Query the version 1 of adapter interface.
	::IDXGIAdapter1* QueryAdapterV1Interface( ::IDXGIAdapter& adapter );
}
}
}
}
