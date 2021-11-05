#pragma once


// External dependencies.
#include <dxgi.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
// Core Windows desktop platform definitions.
inline namespace WindowsDesktop
{

}
}
}
}


// Include internal stuff.
#include "internal/connection-visitors.h"

// Include related platform-specific stuff.
#include "generic-types.h"

// Second layer of platform-agnostic types. Platform-specific declarations.
#include "platform-specific/RhiAdapter.windows.h"
#include "platform-specific/RhiDisplay.windows.h"
#include "platform-specific/RhiVideoMode.windows.h"

#include "platform-specific/GlConfiguration.windows.h"
#include "platform-specific/GlContext.windows.h"

#include "platform-specific/RhiConnection.windows.h"
