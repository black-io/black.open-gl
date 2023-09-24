#include <black/open-gl/egl.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/EGL Context";
}


	EglContext::~EglContext()
	{
		Finalize();
	}

	const bool EglContext::UseSettings( const EglContext& other )
	{
		CRET( IsConnected(), false );

		SetVersion( other.m_major_version, other.m_minor_version );
		SelectApiProfile( other.m_api_profile );
		SetDebugging( other.m_is_debugable );
		SetForwardVersiosCompatible( other.m_is_forward_compatible );

		return true;
	}

	const bool EglContext::SetVersion( const int32_t major_version, const int32_t minor_version )
	{
		CRET( IsConnected(), false );

		m_major_version	= major_version;
		m_minor_version	= minor_version;
		return true;
	}

	const bool EglContext::SelectApiProfile( const ApiProfile profile )
	{
		CRET( IsConnected(), false );

		m_api_profile = profile;
		return true;
	}

	const bool EglContext::SetDebugging( const bool should_debug )
	{
		CRET( IsConnected(), false );

		m_is_debugable = should_debug;
		return true;
	}

	const bool EglContext::SetForwardVersiosCompatible( const bool allow_forward_versions )
	{
		CRET( IsConnected(), false );

		m_is_forward_compatible = allow_forward_versions;
		return true;
	}
}
}
}
