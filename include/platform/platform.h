#pragma once


// External dependencies.
#include <optional>
#include <variant>


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
#include "internal/constants.h"

// First layer of platform-agnostic types. Cross-platform basic definitions.
#include "internal/BasicGlAdapterHandle.h"
#include "internal/BasicGlDisplayHandle.h"
#include "internal/BasicGlDisplayVideoMode.h"

#include "internal/BasicEglConfiguration.h"
#include "internal/BasicEglDisplay.h"
#include "internal/BasicEglSurface.h"
#include "internal/BasicEglContext.h"
#include "internal/BasicEglConnection.h"

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
#include "GlAdapterHandle.h"
#include "GlDisplayHandle.h"
#include "GlDisplayVideoMode.h"

#include "EglConfiguration.h"
#include "EglDisplay.h"
#include "EglSurface.h"
#include "EglContext.h"
#include "EglConnection.h"

// Deferred implementations.
