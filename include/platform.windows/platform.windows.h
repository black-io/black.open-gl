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
#include "internal/structures.h"
#include "internal/connection-visitors.h"

// Include related platform-specific stuff.
#include "generic-types.h"

// Second layer of platform-agnostic types. Platform-specific declarations.
#include "platform-specific/GlAdapterHandle.windows.h"
#include "platform-specific/GlDisplayHandle.windows.h"
#include "platform-specific/GlDisplayVideoMode.windows.h"

#include "platform-specific/EglConfiguration.windows.h"
#include "platform-specific/EglDisplay.windows.h"
#include "platform-specific/EglConnection.windows.h"
