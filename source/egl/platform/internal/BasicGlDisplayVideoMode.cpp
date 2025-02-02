#include <black/open-gl/egl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace Internal
{
	void BasicGlDisplayVideoMode::Swap( BasicGlDisplayVideoMode& other )
	{
		Black::Swap( m_width, other.m_width );
		Black::Swap( m_height, other.m_height );
		Black::Swap( m_bit_rate, other.m_bit_rate );
		Black::Swap( m_refresh_rate, other.m_refresh_rate );
		Black::Swap( m_aspect, other.m_aspect );
		Black::Swap( m_boolean_bits, other.m_boolean_bits );
	}
}
}
}
}
}
