#pragma once


// Fundamental external dependencies.
#include <optional>
#include <variant>


namespace Black
{
inline namespace OpenGl
{
// EGL interface subsystem.
inline namespace Egl
{
// Internal namespace for EGL subsystem.
namespace Internal
{

}
}
}
}


// Most fundamental definitions.
#include "forwards.h"

// Platform-specific definitions.
#include "platform/platform.h"

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
