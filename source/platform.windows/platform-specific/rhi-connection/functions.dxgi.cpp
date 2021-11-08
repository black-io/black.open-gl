#include <black/open-gl.h>

#include "functions.dxgi.h"


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/RHI Connection";
}


	::IDXGIAdapter* QueryAdapterInterface( ::IDXGIFactory& factory, const size32_t adapter_index )
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the adapter instance." );
		::IDXGIAdapter*	adapter_ptr	= nullptr;
		const ::HRESULT access_result = factory.EnumAdapters( adapter_index, &adapter_ptr );
		CRETD( access_result == DXGI_ERROR_NOT_FOUND, nullptr, LOG_CHANNEL, "No adapter can be found for index #{}.", adapter_index );

		if( SUCCEEDED( access_result ) )
		{
			ENSURES_DEBUG( adapter_ptr != nullptr );
			return adapter_ptr;
		}

		BLACK_LOG_ERROR( LOG_CHANNEL, "Failed to access the interface for adapter #{}, result: 0x{:08X}.", adapter_index, access_result );
		return nullptr;
	}

	::IDXGIOutput* QueryOutputInterface( ::IDXGIAdapter& adapter, const size32_t output_index )
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the output interface for adapter." );
		::IDXGIOutput* output_ptr		= nullptr;
		const ::HRESULT access_result	= adapter.EnumOutputs( output_index, &output_ptr );
		CRETD( access_result == DXGI_ERROR_NOT_FOUND, nullptr, LOG_CHANNEL, "No output can be found for index #{}.", output_index );

		if( SUCCEEDED( access_result ) )
		{
			ENSURES_DEBUG( output_ptr );
			return output_ptr;
		}

		BLACK_LOG_ERROR( LOG_CHANNEL, "Failed to access the interface of output #{}, result: 0x{:08X}.", output_index, access_result );
		return nullptr;
	}

	::IDXGIAdapter1* QueryElevatedAdapterInterface( ::IDXGIAdapter& adapter )
	{
		BLACK_LOG_VERBOSE( LOG_CHANNEL, "Trying to query the elevated version of adapter interface." );
		::IDXGIAdapter1* elevated_adapter_ptr = nullptr;
		const ::HRESULT access_result = adapter.QueryInterface( &elevated_adapter_ptr );

		if( SUCCEEDED( access_result ) )
		{
			ENSURES_DEBUG( elevated_adapter_ptr != nullptr );
			return elevated_adapter_ptr;
		}

		BLACK_LOG_ERROR( LOG_CHANNEL, "Failed to access the elevated version of adapter interface, result: 0x{:08X}.", access_result );
		return nullptr;
	}
}
}
}
}
