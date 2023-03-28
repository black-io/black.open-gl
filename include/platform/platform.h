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

// Include the platform-specific code.
#include BLACK_CURRENT_PLATFORM_HEADER

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
