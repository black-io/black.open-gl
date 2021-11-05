#pragma once


// External dependencies.
#include <optional>


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
#include "forwards.h"

// First layer of platform-agnostic types. Cross-platform basic definitions.
#include "internal/BasicRhiAdapter.h"
#include "internal/BasicRhiDisplay.h"
#include "internal/BasicRhiVideoMode.h"

#include "internal/BasicGlConfiguration.h"
#include "internal/BasicGlContext.h"

#include "internal/BasicRhiConnection.h"

// Second layer of platform-agnostic types. Platform-specific declarations.
#include "platform-specific/forwards.h"

// Select the definitions of platform-specific code for second layer.
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

// Third layer of platform-agnostic types. Public platform-agnostic definitions.
#include "RhiAdapter.h"
#include "RhiDisplay.h"
#include "RhiVideoMode.h"

#include "GlConfiguration.h"
#include "GlContext.h"

#include "RhiConnection.h"

// Deferred implementations.
