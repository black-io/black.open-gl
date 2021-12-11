#include <black/open-gl.h>


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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Display Handle";
}


	GlDisplayHandle<Black::PlatformType::Android>::GlDisplayHandle( const ConstructionInfo& info )
		: m_handle{ std::get<0>( info ) }
		, m_adapter_index{ std::get<1>( info ) }
		, m_index{ std::get<2>( info ) }
	{
	}
}
}
}
}
