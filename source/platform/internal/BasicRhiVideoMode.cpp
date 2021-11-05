#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace Internal
{
	void BasicRhiVideoMode::Swap( BasicRhiVideoMode& other )
	{
		using std::swap;

		swap( m_width, other.m_width );
		swap( m_height, other.m_height );
		swap( m_bit_rate, other.m_bit_rate );
		swap( m_refresh_rate, other.m_refresh_rate );
		swap( m_aspect, other.m_aspect );
		swap( m_boolean_bits, other.m_boolean_bits );
	}
}
}
}
}
