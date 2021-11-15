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
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/Adapter Handle";
}


	GlAdapterHandle<Black::PlatformType::WindowsDesktop>::GlAdapterHandle( const ConstructionInfo& info )
		: m_description{ std::get<0>( info ) }
		, m_index{ std::get<1>( info ) }
	{
	}
}
}
}
}
