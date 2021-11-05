#include <black/open-gl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	RhiConnection::~RhiConnection()
	{
		Finalize();
	}
}
}
}
