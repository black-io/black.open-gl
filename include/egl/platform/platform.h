#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
// Platform-oriented definitions.
inline namespace Platform
{
// Internal platform-oriented definitions.
namespace Internal
{

}

// Platform-specific definitions.
namespace PlatformSpecific
{
	// Alias for internal definitions.
	namespace Internal = Black::OpenGl::Egl::Platform::Internal;
}
}
}
}
}


// Most fundamental definitions.
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
