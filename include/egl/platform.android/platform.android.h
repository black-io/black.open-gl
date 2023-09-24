#pragma once


// External dependencies.
#include <EGL/egl.h>
#include <EGL/eglext.h>

#include <black/jni/android/view/WindowManager.h>
#include <black/jni/android/content/Context.h>
#include <black/jni/android/view/SurfaceHolder.h>


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
// Google Android platform definitions.
inline namespace Android
{

}
}
}
}
}


// Include internal stuff.
#include "internal/structures.h"
#include "internal/connection-visitors.h"

// Include related platform-specific stuff.
#include "macros.h"
#include "generic-types.h"

// Second layer of platform-agnostic types. Platform-specific declarations.
#include "platform-specific/GlAdapterHandle.android.h"
#include "platform-specific/GlDisplayHandle.android.h"
#include "platform-specific/GlDisplayVideoMode.android.h"

#include "platform-specific/EglConfiguration.android.h"
#include "platform-specific/EglDisplay.android.h"
#include "platform-specific/EglSurface.android.h"
#include "platform-specific/EglContext.android.h"
#include "platform-specific/EglConnection.android.h"
