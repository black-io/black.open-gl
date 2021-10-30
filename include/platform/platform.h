#pragma once


namespace Black
{
inline namespace OpenGl
{
// Platform-specific code for OpenGL bindings.
inline namespace Platform
{
// Internal definitions for platforms.
namespace Internal
{

}

// Platform-specific declarations.
namespace PlatformSpecific
{
	// Alias the internal stuff.
	namespace Internal = Black::OpenGl::Platform::Internal;
}
}
}
}


// Include most fundamental platform stuff.

// Select the implementation of platform-specific code.
#if( BLACK_WINDOWS_DESKTOP_PLATFORM )
	#include "../platform.windows/platform.windows.h"
#elif( BLACK_MAC_OS_PLATFORM )
	#include "../platform.macos/platform.macos.h"
#elif( BLACK_LINUX_PLATFORM )
	#include "../platform.linux/platform.linux.h"
#elif( BLACK_ANDROID_PLATFORM )
	#include "../platform.android/platform.android.h"
#elif( BLACK_IOS_PLATFORM )
	#include "../platform.ios/platform.ios.h"
#else
	#error Current platform is unspecified or not defined
#endif

// Deferred implementations.
