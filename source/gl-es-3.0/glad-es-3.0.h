#ifndef GLAD_GLES2_H_
#define GLAD_GLES2_H_

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifdef __gl2_h_
  #error OpenGL ES 2 header already included (API: gles2), remove previous include!
#endif
#define __gl2_h_ 1
#ifdef __gl3_h_
  #error OpenGL ES 3 header already included (API: gles2), remove previous include!
#endif
#define __gl3_h_ 1
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#define GLAD_GLES2
#define GLAD_OPTION_GLES2_LOADER

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLAD_PLATFORM_H_
#define GLAD_PLATFORM_H_

#ifndef GLAD_PLATFORM_WIN32
  #if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__)
    #define GLAD_PLATFORM_WIN32 1
  #else
    #define GLAD_PLATFORM_WIN32 0
  #endif
#endif

#ifndef GLAD_PLATFORM_APPLE
  #ifdef __APPLE__
    #define GLAD_PLATFORM_APPLE 1
  #else
    #define GLAD_PLATFORM_APPLE 0
  #endif
#endif

#ifndef GLAD_PLATFORM_EMSCRIPTEN
  #ifdef __EMSCRIPTEN__
    #define GLAD_PLATFORM_EMSCRIPTEN 1
  #else
    #define GLAD_PLATFORM_EMSCRIPTEN 0
  #endif
#endif

#ifndef GLAD_PLATFORM_UWP
  #if defined(_MSC_VER) && !defined(GLAD_INTERNAL_HAVE_WINAPIFAMILY)
    #ifdef __has_include
      #if __has_include(<winapifamily.h>)
        #define GLAD_INTERNAL_HAVE_WINAPIFAMILY 1
      #endif
    #elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
      #define GLAD_INTERNAL_HAVE_WINAPIFAMILY 1
    #endif
  #endif

  #ifdef GLAD_INTERNAL_HAVE_WINAPIFAMILY
    #include <winapifamily.h>
    #if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
      #define GLAD_PLATFORM_UWP 1
    #endif
  #endif

  #ifndef GLAD_PLATFORM_UWP
    #define GLAD_PLATFORM_UWP 0
  #endif
#endif

#ifdef __GNUC__
  #define GLAD_GNUC_EXTENSION __extension__
#else
  #define GLAD_GNUC_EXTENSION
#endif

#ifndef GLAD_API_CALL
  #if defined(GLAD_API_CALL_EXPORT)
    #if GLAD_PLATFORM_WIN32 || defined(__CYGWIN__)
      #if defined(GLAD_API_CALL_EXPORT_BUILD)
        #if defined(__GNUC__)
          #define GLAD_API_CALL __attribute__ ((dllexport)) extern
        #else
          #define GLAD_API_CALL __declspec(dllexport) extern
        #endif
      #else
        #if defined(__GNUC__)
          #define GLAD_API_CALL __attribute__ ((dllimport)) extern
        #else
          #define GLAD_API_CALL __declspec(dllimport) extern
        #endif
      #endif
    #elif defined(__GNUC__) && defined(GLAD_API_CALL_EXPORT_BUILD)
      #define GLAD_API_CALL __attribute__ ((visibility ("default"))) extern
    #else
      #define GLAD_API_CALL extern
    #endif
  #else
    #define GLAD_API_CALL extern
  #endif
#endif

#ifdef APIENTRY
  #define GLAD_API_PTR APIENTRY
#elif GLAD_PLATFORM_WIN32
  #define GLAD_API_PTR __stdcall
#else
  #define GLAD_API_PTR
#endif

#ifndef GLAPI
#define GLAPI GLAD_API_CALL
#endif

#ifndef GLAPIENTRY
#define GLAPIENTRY GLAD_API_PTR
#endif

#define GLAD_MAKE_VERSION(major, minor) (major * 10000 + minor)
#define GLAD_VERSION_MAJOR(version) (version / 10000)
#define GLAD_VERSION_MINOR(version) (version % 10000)

typedef void (*GLADapiproc)(void);

typedef GLADapiproc (*GLADloadfunc)(const char *name);
typedef GLADapiproc (*GLADuserptrloadfunc)(void *userptr, const char *name);

typedef void (*GLADprecallback)(const char *name, GLADapiproc apiproc, int len_args, ...);
typedef void (*GLADpostcallback)(void *ret, const char *name, GLADapiproc apiproc, int len_args, ...);

#endif /* GLAD_PLATFORM_H_ */

#include <KHR/khrplatform.h>

typedef unsigned int GLenum;

typedef unsigned char GLboolean;

typedef unsigned int GLbitfield;

typedef void GLvoid;

typedef khronos_int8_t GLbyte;

typedef khronos_uint8_t GLubyte;

typedef khronos_int16_t GLshort;

typedef khronos_uint16_t GLushort;

typedef int GLint;

typedef unsigned int GLuint;

typedef khronos_int32_t GLclampx;

typedef int GLsizei;

typedef khronos_float_t GLfloat;

typedef khronos_float_t GLclampf;

typedef double GLdouble;

typedef double GLclampd;

typedef void *GLeglClientBufferEXT;

typedef void *GLeglImageOES;

typedef char GLchar;

typedef char GLcharARB;

#ifdef __APPLE__
typedef void *GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif

typedef khronos_uint16_t GLhalf;

typedef khronos_uint16_t GLhalfARB;

typedef khronos_int32_t GLfixed;

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef khronos_intptr_t GLintptr;
#else
typedef khronos_intptr_t GLintptr;
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef khronos_intptr_t GLintptrARB;
#else
typedef khronos_intptr_t GLintptrARB;
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef khronos_ssize_t GLsizeiptr;
#else
typedef khronos_ssize_t GLsizeiptr;
#endif

#if defined(__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__) && (__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__ > 1060)
typedef khronos_ssize_t GLsizeiptrARB;
#else
typedef khronos_ssize_t GLsizeiptrARB;
#endif

typedef khronos_int64_t GLint64;

typedef khronos_int64_t GLint64EXT;

typedef khronos_uint64_t GLuint64;

typedef khronos_uint64_t GLuint64EXT;

typedef struct __GLsync *GLsync;

struct _cl_context;

struct _cl_event;

typedef void (GLAD_API_PTR *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);

typedef void (GLAD_API_PTR *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);

typedef void (GLAD_API_PTR *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);

typedef void (GLAD_API_PTR *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);

typedef unsigned short GLhalfNV;

typedef GLintptr GLvdpauSurfaceNV;

typedef void (GLAD_API_PTR *GLVULKANPROCNV)(void);



#define GL_ES_VERSION_2_0 1
GLAD_API_CALL int GLAD_ES_30_GL_ES_VERSION_2_0;
#define GL_ES_VERSION_3_0 1
GLAD_API_CALL int GLAD_ES_30_GL_ES_VERSION_3_0;


typedef void (GLAD_API_PTR *PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (GLAD_API_PTR *PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (GLAD_API_PTR *PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
typedef void (GLAD_API_PTR *PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
typedef void (GLAD_API_PTR *PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar * name);
typedef void (GLAD_API_PTR *PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (GLAD_API_PTR *PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
typedef void (GLAD_API_PTR *PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef void (GLAD_API_PTR *PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (GLAD_API_PTR *PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
typedef void (GLAD_API_PTR *PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
typedef void (GLAD_API_PTR *PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (GLAD_API_PTR *PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
typedef void (GLAD_API_PTR *PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef void (GLAD_API_PTR *PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (GLAD_API_PTR *PFNGLBLENDEQUATIONPROC)(GLenum mode);
typedef void (GLAD_API_PTR *PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (GLAD_API_PTR *PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (GLAD_API_PTR *PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (GLAD_API_PTR *PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef void (GLAD_API_PTR *PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
typedef void (GLAD_API_PTR *PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
typedef GLenum (GLAD_API_PTR *PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
typedef void (GLAD_API_PTR *PFNGLCLEARPROC)(GLbitfield mask);
typedef void (GLAD_API_PTR *PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef void (GLAD_API_PTR *PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint * value);
typedef void (GLAD_API_PTR *PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint * value);
typedef void (GLAD_API_PTR *PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (GLAD_API_PTR *PFNGLCLEARDEPTHFPROC)(GLfloat d);
typedef void (GLAD_API_PTR *PFNGLCLEARSTENCILPROC)(GLint s);
typedef GLenum (GLAD_API_PTR *PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef void (GLAD_API_PTR *PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (GLAD_API_PTR *PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (GLAD_API_PTR *PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
typedef void (GLAD_API_PTR *PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
typedef void (GLAD_API_PTR *PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
typedef void (GLAD_API_PTR *PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
typedef void (GLAD_API_PTR *PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef void (GLAD_API_PTR *PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (GLAD_API_PTR *PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAD_API_PTR *PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef GLuint (GLAD_API_PTR *PFNGLCREATEPROGRAMPROC)(void);
typedef GLuint (GLAD_API_PTR *PFNGLCREATESHADERPROC)(GLenum type);
typedef void (GLAD_API_PTR *PFNGLCULLFACEPROC)(GLenum mode);
typedef void (GLAD_API_PTR *PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint * buffers);
typedef void (GLAD_API_PTR *PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint * framebuffers);
typedef void (GLAD_API_PTR *PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (GLAD_API_PTR *PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint * ids);
typedef void (GLAD_API_PTR *PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint * renderbuffers);
typedef void (GLAD_API_PTR *PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint * samplers);
typedef void (GLAD_API_PTR *PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (GLAD_API_PTR *PFNGLDELETESYNCPROC)(GLsync sync);
typedef void (GLAD_API_PTR *PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint * textures);
typedef void (GLAD_API_PTR *PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint * ids);
typedef void (GLAD_API_PTR *PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint * arrays);
typedef void (GLAD_API_PTR *PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (GLAD_API_PTR *PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (GLAD_API_PTR *PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
typedef void (GLAD_API_PTR *PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (GLAD_API_PTR *PFNGLDISABLEPROC)(GLenum cap);
typedef void (GLAD_API_PTR *PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (GLAD_API_PTR *PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (GLAD_API_PTR *PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (GLAD_API_PTR *PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum * bufs);
typedef void (GLAD_API_PTR *PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices);
typedef void (GLAD_API_PTR *PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
typedef void (GLAD_API_PTR *PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
typedef void (GLAD_API_PTR *PFNGLENABLEPROC)(GLenum cap);
typedef void (GLAD_API_PTR *PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (GLAD_API_PTR *PFNGLENDQUERYPROC)(GLenum target);
typedef void (GLAD_API_PTR *PFNGLENDTRANSFORMFEEDBACKPROC)(void);
typedef GLsync (GLAD_API_PTR *PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
typedef void (GLAD_API_PTR *PFNGLFINISHPROC)(void);
typedef void (GLAD_API_PTR *PFNGLFLUSHPROC)(void);
typedef void (GLAD_API_PTR *PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef void (GLAD_API_PTR *PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef void (GLAD_API_PTR *PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (GLAD_API_PTR *PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef void (GLAD_API_PTR *PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (GLAD_API_PTR *PFNGLGENBUFFERSPROC)(GLsizei n, GLuint * buffers);
typedef void (GLAD_API_PTR *PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
typedef void (GLAD_API_PTR *PFNGLGENQUERIESPROC)(GLsizei n, GLuint * ids);
typedef void (GLAD_API_PTR *PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
typedef void (GLAD_API_PTR *PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint * samplers);
typedef void (GLAD_API_PTR *PFNGLGENTEXTURESPROC)(GLsizei n, GLuint * textures);
typedef void (GLAD_API_PTR *PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
typedef void (GLAD_API_PTR *PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
typedef void (GLAD_API_PTR *PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef void (GLAD_API_PTR *PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
typedef void (GLAD_API_PTR *PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
typedef void (GLAD_API_PTR *PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
typedef void (GLAD_API_PTR *PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
typedef GLint (GLAD_API_PTR *PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar * name);
typedef void (GLAD_API_PTR *PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean * data);
typedef void (GLAD_API_PTR *PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 * params);
typedef void (GLAD_API_PTR *PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void ** params);
typedef GLenum (GLAD_API_PTR *PFNGLGETERRORPROC)(void);
typedef void (GLAD_API_PTR *PFNGLGETFLOATVPROC)(GLenum pname, GLfloat * data);
typedef GLint (GLAD_API_PTR *PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar * name);
typedef void (GLAD_API_PTR *PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 * data);
typedef void (GLAD_API_PTR *PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 * data);
typedef void (GLAD_API_PTR *PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint * data);
typedef void (GLAD_API_PTR *PFNGLGETINTEGERVPROC)(GLenum pname, GLint * data);
typedef void (GLAD_API_PTR *PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
typedef void (GLAD_API_PTR *PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
typedef void (GLAD_API_PTR *PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint * params);
typedef void (GLAD_API_PTR *PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat * params);
typedef void (GLAD_API_PTR *PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
typedef void (GLAD_API_PTR *PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
typedef void (GLAD_API_PTR *PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
typedef void (GLAD_API_PTR *PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint * params);
typedef const GLubyte * (GLAD_API_PTR *PFNGLGETSTRINGPROC)(GLenum name);
typedef const GLubyte * (GLAD_API_PTR *PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
typedef void (GLAD_API_PTR *PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values);
typedef void (GLAD_API_PTR *PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
typedef void (GLAD_API_PTR *PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
typedef GLuint (GLAD_API_PTR *PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar * uniformBlockName);
typedef void (GLAD_API_PTR *PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
typedef GLint (GLAD_API_PTR *PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar * name);
typedef void (GLAD_API_PTR *PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat * params);
typedef void (GLAD_API_PTR *PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint * params);
typedef void (GLAD_API_PTR *PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint * params);
typedef void (GLAD_API_PTR *PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void ** pointer);
typedef void (GLAD_API_PTR *PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat * params);
typedef void (GLAD_API_PTR *PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint * params);
typedef void (GLAD_API_PTR *PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (GLAD_API_PTR *PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
typedef void (GLAD_API_PTR *PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef GLboolean (GLAD_API_PTR *PFNGLISBUFFERPROC)(GLuint buffer);
typedef GLboolean (GLAD_API_PTR *PFNGLISENABLEDPROC)(GLenum cap);
typedef GLboolean (GLAD_API_PTR *PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
typedef GLboolean (GLAD_API_PTR *PFNGLISPROGRAMPROC)(GLuint program);
typedef GLboolean (GLAD_API_PTR *PFNGLISQUERYPROC)(GLuint id);
typedef GLboolean (GLAD_API_PTR *PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
typedef GLboolean (GLAD_API_PTR *PFNGLISSAMPLERPROC)(GLuint sampler);
typedef GLboolean (GLAD_API_PTR *PFNGLISSHADERPROC)(GLuint shader);
typedef GLboolean (GLAD_API_PTR *PFNGLISSYNCPROC)(GLsync sync);
typedef GLboolean (GLAD_API_PTR *PFNGLISTEXTUREPROC)(GLuint texture);
typedef GLboolean (GLAD_API_PTR *PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
typedef GLboolean (GLAD_API_PTR *PFNGLISVERTEXARRAYPROC)(GLuint array);
typedef void (GLAD_API_PTR *PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (GLAD_API_PTR *PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void * (GLAD_API_PTR *PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef void (GLAD_API_PTR *PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
typedef void (GLAD_API_PTR *PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (GLAD_API_PTR *PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (GLAD_API_PTR *PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
typedef void (GLAD_API_PTR *PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
typedef void (GLAD_API_PTR *PFNGLREADBUFFERPROC)(GLenum src);
typedef void (GLAD_API_PTR *PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
typedef void (GLAD_API_PTR *PFNGLRELEASESHADERCOMPILERPROC)(void);
typedef void (GLAD_API_PTR *PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAD_API_PTR *PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAD_API_PTR *PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
typedef void (GLAD_API_PTR *PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
typedef void (GLAD_API_PTR *PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
typedef void (GLAD_API_PTR *PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat * param);
typedef void (GLAD_API_PTR *PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
typedef void (GLAD_API_PTR *PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
typedef void (GLAD_API_PTR *PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAD_API_PTR *PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length);
typedef void (GLAD_API_PTR *PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
typedef void (GLAD_API_PTR *PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (GLAD_API_PTR *PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (GLAD_API_PTR *PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (GLAD_API_PTR *PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
typedef void (GLAD_API_PTR *PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (GLAD_API_PTR *PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (GLAD_API_PTR *PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
typedef void (GLAD_API_PTR *PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
typedef void (GLAD_API_PTR *PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (GLAD_API_PTR *PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
typedef void (GLAD_API_PTR *PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (GLAD_API_PTR *PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
typedef void (GLAD_API_PTR *PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef void (GLAD_API_PTR *PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef void (GLAD_API_PTR *PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
typedef void (GLAD_API_PTR *PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
typedef void (GLAD_API_PTR *PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
typedef void (GLAD_API_PTR *PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
typedef void (GLAD_API_PTR *PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (GLAD_API_PTR *PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
typedef void (GLAD_API_PTR *PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (GLAD_API_PTR *PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
typedef void (GLAD_API_PTR *PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
typedef void (GLAD_API_PTR *PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (GLAD_API_PTR *PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (GLAD_API_PTR *PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef void (GLAD_API_PTR *PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (GLAD_API_PTR *PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (GLAD_API_PTR *PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef void (GLAD_API_PTR *PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef void (GLAD_API_PTR *PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef GLboolean (GLAD_API_PTR *PFNGLUNMAPBUFFERPROC)(GLenum target);
typedef void (GLAD_API_PTR *PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (GLAD_API_PTR *PFNGLVALIDATEPROGRAMPROC)(GLuint program);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat * v);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat * v);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat * v);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat * v);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint * v);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint * v);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
typedef void (GLAD_API_PTR *PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
typedef void (GLAD_API_PTR *PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (GLAD_API_PTR *PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);

GLAD_API_CALL PFNGLACTIVETEXTUREPROC glad_es_30_glActiveTexture;
GLAD_API_CALL PFNGLATTACHSHADERPROC glad_es_30_glAttachShader;
GLAD_API_CALL PFNGLBEGINQUERYPROC glad_es_30_glBeginQuery;
GLAD_API_CALL PFNGLBEGINTRANSFORMFEEDBACKPROC glad_es_30_glBeginTransformFeedback;
GLAD_API_CALL PFNGLBINDATTRIBLOCATIONPROC glad_es_30_glBindAttribLocation;
GLAD_API_CALL PFNGLBINDBUFFERPROC glad_es_30_glBindBuffer;
GLAD_API_CALL PFNGLBINDBUFFERBASEPROC glad_es_30_glBindBufferBase;
GLAD_API_CALL PFNGLBINDBUFFERRANGEPROC glad_es_30_glBindBufferRange;
GLAD_API_CALL PFNGLBINDFRAMEBUFFERPROC glad_es_30_glBindFramebuffer;
GLAD_API_CALL PFNGLBINDRENDERBUFFERPROC glad_es_30_glBindRenderbuffer;
GLAD_API_CALL PFNGLBINDSAMPLERPROC glad_es_30_glBindSampler;
GLAD_API_CALL PFNGLBINDTEXTUREPROC glad_es_30_glBindTexture;
GLAD_API_CALL PFNGLBINDTRANSFORMFEEDBACKPROC glad_es_30_glBindTransformFeedback;
GLAD_API_CALL PFNGLBINDVERTEXARRAYPROC glad_es_30_glBindVertexArray;
GLAD_API_CALL PFNGLBLENDCOLORPROC glad_es_30_glBlendColor;
GLAD_API_CALL PFNGLBLENDEQUATIONPROC glad_es_30_glBlendEquation;
GLAD_API_CALL PFNGLBLENDEQUATIONSEPARATEPROC glad_es_30_glBlendEquationSeparate;
GLAD_API_CALL PFNGLBLENDFUNCPROC glad_es_30_glBlendFunc;
GLAD_API_CALL PFNGLBLENDFUNCSEPARATEPROC glad_es_30_glBlendFuncSeparate;
GLAD_API_CALL PFNGLBLITFRAMEBUFFERPROC glad_es_30_glBlitFramebuffer;
GLAD_API_CALL PFNGLBUFFERDATAPROC glad_es_30_glBufferData;
GLAD_API_CALL PFNGLBUFFERSUBDATAPROC glad_es_30_glBufferSubData;
GLAD_API_CALL PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_es_30_glCheckFramebufferStatus;
GLAD_API_CALL PFNGLCLEARPROC glad_es_30_glClear;
GLAD_API_CALL PFNGLCLEARBUFFERFIPROC glad_es_30_glClearBufferfi;
GLAD_API_CALL PFNGLCLEARBUFFERFVPROC glad_es_30_glClearBufferfv;
GLAD_API_CALL PFNGLCLEARBUFFERIVPROC glad_es_30_glClearBufferiv;
GLAD_API_CALL PFNGLCLEARBUFFERUIVPROC glad_es_30_glClearBufferuiv;
GLAD_API_CALL PFNGLCLEARCOLORPROC glad_es_30_glClearColor;
GLAD_API_CALL PFNGLCLEARDEPTHFPROC glad_es_30_glClearDepthf;
GLAD_API_CALL PFNGLCLEARSTENCILPROC glad_es_30_glClearStencil;
GLAD_API_CALL PFNGLCLIENTWAITSYNCPROC glad_es_30_glClientWaitSync;
GLAD_API_CALL PFNGLCOLORMASKPROC glad_es_30_glColorMask;
GLAD_API_CALL PFNGLCOMPILESHADERPROC glad_es_30_glCompileShader;
GLAD_API_CALL PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_es_30_glCompressedTexImage2D;
GLAD_API_CALL PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_es_30_glCompressedTexImage3D;
GLAD_API_CALL PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_es_30_glCompressedTexSubImage2D;
GLAD_API_CALL PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_es_30_glCompressedTexSubImage3D;
GLAD_API_CALL PFNGLCOPYBUFFERSUBDATAPROC glad_es_30_glCopyBufferSubData;
GLAD_API_CALL PFNGLCOPYTEXIMAGE2DPROC glad_es_30_glCopyTexImage2D;
GLAD_API_CALL PFNGLCOPYTEXSUBIMAGE2DPROC glad_es_30_glCopyTexSubImage2D;
GLAD_API_CALL PFNGLCOPYTEXSUBIMAGE3DPROC glad_es_30_glCopyTexSubImage3D;
GLAD_API_CALL PFNGLCREATEPROGRAMPROC glad_es_30_glCreateProgram;
GLAD_API_CALL PFNGLCREATESHADERPROC glad_es_30_glCreateShader;
GLAD_API_CALL PFNGLCULLFACEPROC glad_es_30_glCullFace;
GLAD_API_CALL PFNGLDELETEBUFFERSPROC glad_es_30_glDeleteBuffers;
GLAD_API_CALL PFNGLDELETEFRAMEBUFFERSPROC glad_es_30_glDeleteFramebuffers;
GLAD_API_CALL PFNGLDELETEPROGRAMPROC glad_es_30_glDeleteProgram;
GLAD_API_CALL PFNGLDELETEQUERIESPROC glad_es_30_glDeleteQueries;
GLAD_API_CALL PFNGLDELETERENDERBUFFERSPROC glad_es_30_glDeleteRenderbuffers;
GLAD_API_CALL PFNGLDELETESAMPLERSPROC glad_es_30_glDeleteSamplers;
GLAD_API_CALL PFNGLDELETESHADERPROC glad_es_30_glDeleteShader;
GLAD_API_CALL PFNGLDELETESYNCPROC glad_es_30_glDeleteSync;
GLAD_API_CALL PFNGLDELETETEXTURESPROC glad_es_30_glDeleteTextures;
GLAD_API_CALL PFNGLDELETETRANSFORMFEEDBACKSPROC glad_es_30_glDeleteTransformFeedbacks;
GLAD_API_CALL PFNGLDELETEVERTEXARRAYSPROC glad_es_30_glDeleteVertexArrays;
GLAD_API_CALL PFNGLDEPTHFUNCPROC glad_es_30_glDepthFunc;
GLAD_API_CALL PFNGLDEPTHMASKPROC glad_es_30_glDepthMask;
GLAD_API_CALL PFNGLDEPTHRANGEFPROC glad_es_30_glDepthRangef;
GLAD_API_CALL PFNGLDETACHSHADERPROC glad_es_30_glDetachShader;
GLAD_API_CALL PFNGLDISABLEPROC glad_es_30_glDisable;
GLAD_API_CALL PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_es_30_glDisableVertexAttribArray;
GLAD_API_CALL PFNGLDRAWARRAYSPROC glad_es_30_glDrawArrays;
GLAD_API_CALL PFNGLDRAWARRAYSINSTANCEDPROC glad_es_30_glDrawArraysInstanced;
GLAD_API_CALL PFNGLDRAWBUFFERSPROC glad_es_30_glDrawBuffers;
GLAD_API_CALL PFNGLDRAWELEMENTSPROC glad_es_30_glDrawElements;
GLAD_API_CALL PFNGLDRAWELEMENTSINSTANCEDPROC glad_es_30_glDrawElementsInstanced;
GLAD_API_CALL PFNGLDRAWRANGEELEMENTSPROC glad_es_30_glDrawRangeElements;
GLAD_API_CALL PFNGLENABLEPROC glad_es_30_glEnable;
GLAD_API_CALL PFNGLENABLEVERTEXATTRIBARRAYPROC glad_es_30_glEnableVertexAttribArray;
GLAD_API_CALL PFNGLENDQUERYPROC glad_es_30_glEndQuery;
GLAD_API_CALL PFNGLENDTRANSFORMFEEDBACKPROC glad_es_30_glEndTransformFeedback;
GLAD_API_CALL PFNGLFENCESYNCPROC glad_es_30_glFenceSync;
GLAD_API_CALL PFNGLFINISHPROC glad_es_30_glFinish;
GLAD_API_CALL PFNGLFLUSHPROC glad_es_30_glFlush;
GLAD_API_CALL PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_es_30_glFlushMappedBufferRange;
GLAD_API_CALL PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_es_30_glFramebufferRenderbuffer;
GLAD_API_CALL PFNGLFRAMEBUFFERTEXTURE2DPROC glad_es_30_glFramebufferTexture2D;
GLAD_API_CALL PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_es_30_glFramebufferTextureLayer;
GLAD_API_CALL PFNGLFRONTFACEPROC glad_es_30_glFrontFace;
GLAD_API_CALL PFNGLGENBUFFERSPROC glad_es_30_glGenBuffers;
GLAD_API_CALL PFNGLGENFRAMEBUFFERSPROC glad_es_30_glGenFramebuffers;
GLAD_API_CALL PFNGLGENQUERIESPROC glad_es_30_glGenQueries;
GLAD_API_CALL PFNGLGENRENDERBUFFERSPROC glad_es_30_glGenRenderbuffers;
GLAD_API_CALL PFNGLGENSAMPLERSPROC glad_es_30_glGenSamplers;
GLAD_API_CALL PFNGLGENTEXTURESPROC glad_es_30_glGenTextures;
GLAD_API_CALL PFNGLGENTRANSFORMFEEDBACKSPROC glad_es_30_glGenTransformFeedbacks;
GLAD_API_CALL PFNGLGENVERTEXARRAYSPROC glad_es_30_glGenVertexArrays;
GLAD_API_CALL PFNGLGENERATEMIPMAPPROC glad_es_30_glGenerateMipmap;
GLAD_API_CALL PFNGLGETACTIVEATTRIBPROC glad_es_30_glGetActiveAttrib;
GLAD_API_CALL PFNGLGETACTIVEUNIFORMPROC glad_es_30_glGetActiveUniform;
GLAD_API_CALL PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_es_30_glGetActiveUniformBlockName;
GLAD_API_CALL PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_es_30_glGetActiveUniformBlockiv;
GLAD_API_CALL PFNGLGETACTIVEUNIFORMSIVPROC glad_es_30_glGetActiveUniformsiv;
GLAD_API_CALL PFNGLGETATTACHEDSHADERSPROC glad_es_30_glGetAttachedShaders;
GLAD_API_CALL PFNGLGETATTRIBLOCATIONPROC glad_es_30_glGetAttribLocation;
GLAD_API_CALL PFNGLGETBOOLEANVPROC glad_es_30_glGetBooleanv;
GLAD_API_CALL PFNGLGETBUFFERPARAMETERI64VPROC glad_es_30_glGetBufferParameteri64v;
GLAD_API_CALL PFNGLGETBUFFERPARAMETERIVPROC glad_es_30_glGetBufferParameteriv;
GLAD_API_CALL PFNGLGETBUFFERPOINTERVPROC glad_es_30_glGetBufferPointerv;
GLAD_API_CALL PFNGLGETERRORPROC glad_es_30_glGetError;
GLAD_API_CALL PFNGLGETFLOATVPROC glad_es_30_glGetFloatv;
GLAD_API_CALL PFNGLGETFRAGDATALOCATIONPROC glad_es_30_glGetFragDataLocation;
GLAD_API_CALL PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_es_30_glGetFramebufferAttachmentParameteriv;
GLAD_API_CALL PFNGLGETINTEGER64I_VPROC glad_es_30_glGetInteger64i_v;
GLAD_API_CALL PFNGLGETINTEGER64VPROC glad_es_30_glGetInteger64v;
GLAD_API_CALL PFNGLGETINTEGERI_VPROC glad_es_30_glGetIntegeri_v;
GLAD_API_CALL PFNGLGETINTEGERVPROC glad_es_30_glGetIntegerv;
GLAD_API_CALL PFNGLGETINTERNALFORMATIVPROC glad_es_30_glGetInternalformativ;
GLAD_API_CALL PFNGLGETPROGRAMBINARYPROC glad_es_30_glGetProgramBinary;
GLAD_API_CALL PFNGLGETPROGRAMINFOLOGPROC glad_es_30_glGetProgramInfoLog;
GLAD_API_CALL PFNGLGETPROGRAMIVPROC glad_es_30_glGetProgramiv;
GLAD_API_CALL PFNGLGETQUERYOBJECTUIVPROC glad_es_30_glGetQueryObjectuiv;
GLAD_API_CALL PFNGLGETQUERYIVPROC glad_es_30_glGetQueryiv;
GLAD_API_CALL PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_es_30_glGetRenderbufferParameteriv;
GLAD_API_CALL PFNGLGETSAMPLERPARAMETERFVPROC glad_es_30_glGetSamplerParameterfv;
GLAD_API_CALL PFNGLGETSAMPLERPARAMETERIVPROC glad_es_30_glGetSamplerParameteriv;
GLAD_API_CALL PFNGLGETSHADERINFOLOGPROC glad_es_30_glGetShaderInfoLog;
GLAD_API_CALL PFNGLGETSHADERPRECISIONFORMATPROC glad_es_30_glGetShaderPrecisionFormat;
GLAD_API_CALL PFNGLGETSHADERSOURCEPROC glad_es_30_glGetShaderSource;
GLAD_API_CALL PFNGLGETSHADERIVPROC glad_es_30_glGetShaderiv;
GLAD_API_CALL PFNGLGETSTRINGPROC glad_es_30_glGetString;
GLAD_API_CALL PFNGLGETSTRINGIPROC glad_es_30_glGetStringi;
GLAD_API_CALL PFNGLGETSYNCIVPROC glad_es_30_glGetSynciv;
GLAD_API_CALL PFNGLGETTEXPARAMETERFVPROC glad_es_30_glGetTexParameterfv;
GLAD_API_CALL PFNGLGETTEXPARAMETERIVPROC glad_es_30_glGetTexParameteriv;
GLAD_API_CALL PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_es_30_glGetTransformFeedbackVarying;
GLAD_API_CALL PFNGLGETUNIFORMBLOCKINDEXPROC glad_es_30_glGetUniformBlockIndex;
GLAD_API_CALL PFNGLGETUNIFORMINDICESPROC glad_es_30_glGetUniformIndices;
GLAD_API_CALL PFNGLGETUNIFORMLOCATIONPROC glad_es_30_glGetUniformLocation;
GLAD_API_CALL PFNGLGETUNIFORMFVPROC glad_es_30_glGetUniformfv;
GLAD_API_CALL PFNGLGETUNIFORMIVPROC glad_es_30_glGetUniformiv;
GLAD_API_CALL PFNGLGETUNIFORMUIVPROC glad_es_30_glGetUniformuiv;
GLAD_API_CALL PFNGLGETVERTEXATTRIBIIVPROC glad_es_30_glGetVertexAttribIiv;
GLAD_API_CALL PFNGLGETVERTEXATTRIBIUIVPROC glad_es_30_glGetVertexAttribIuiv;
GLAD_API_CALL PFNGLGETVERTEXATTRIBPOINTERVPROC glad_es_30_glGetVertexAttribPointerv;
GLAD_API_CALL PFNGLGETVERTEXATTRIBFVPROC glad_es_30_glGetVertexAttribfv;
GLAD_API_CALL PFNGLGETVERTEXATTRIBIVPROC glad_es_30_glGetVertexAttribiv;
GLAD_API_CALL PFNGLHINTPROC glad_es_30_glHint;
GLAD_API_CALL PFNGLINVALIDATEFRAMEBUFFERPROC glad_es_30_glInvalidateFramebuffer;
GLAD_API_CALL PFNGLINVALIDATESUBFRAMEBUFFERPROC glad_es_30_glInvalidateSubFramebuffer;
GLAD_API_CALL PFNGLISBUFFERPROC glad_es_30_glIsBuffer;
GLAD_API_CALL PFNGLISENABLEDPROC glad_es_30_glIsEnabled;
GLAD_API_CALL PFNGLISFRAMEBUFFERPROC glad_es_30_glIsFramebuffer;
GLAD_API_CALL PFNGLISPROGRAMPROC glad_es_30_glIsProgram;
GLAD_API_CALL PFNGLISQUERYPROC glad_es_30_glIsQuery;
GLAD_API_CALL PFNGLISRENDERBUFFERPROC glad_es_30_glIsRenderbuffer;
GLAD_API_CALL PFNGLISSAMPLERPROC glad_es_30_glIsSampler;
GLAD_API_CALL PFNGLISSHADERPROC glad_es_30_glIsShader;
GLAD_API_CALL PFNGLISSYNCPROC glad_es_30_glIsSync;
GLAD_API_CALL PFNGLISTEXTUREPROC glad_es_30_glIsTexture;
GLAD_API_CALL PFNGLISTRANSFORMFEEDBACKPROC glad_es_30_glIsTransformFeedback;
GLAD_API_CALL PFNGLISVERTEXARRAYPROC glad_es_30_glIsVertexArray;
GLAD_API_CALL PFNGLLINEWIDTHPROC glad_es_30_glLineWidth;
GLAD_API_CALL PFNGLLINKPROGRAMPROC glad_es_30_glLinkProgram;
GLAD_API_CALL PFNGLMAPBUFFERRANGEPROC glad_es_30_glMapBufferRange;
GLAD_API_CALL PFNGLPAUSETRANSFORMFEEDBACKPROC glad_es_30_glPauseTransformFeedback;
GLAD_API_CALL PFNGLPIXELSTOREIPROC glad_es_30_glPixelStorei;
GLAD_API_CALL PFNGLPOLYGONOFFSETPROC glad_es_30_glPolygonOffset;
GLAD_API_CALL PFNGLPROGRAMBINARYPROC glad_es_30_glProgramBinary;
GLAD_API_CALL PFNGLPROGRAMPARAMETERIPROC glad_es_30_glProgramParameteri;
GLAD_API_CALL PFNGLREADBUFFERPROC glad_es_30_glReadBuffer;
GLAD_API_CALL PFNGLREADPIXELSPROC glad_es_30_glReadPixels;
GLAD_API_CALL PFNGLRELEASESHADERCOMPILERPROC glad_es_30_glReleaseShaderCompiler;
GLAD_API_CALL PFNGLRENDERBUFFERSTORAGEPROC glad_es_30_glRenderbufferStorage;
GLAD_API_CALL PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_es_30_glRenderbufferStorageMultisample;
GLAD_API_CALL PFNGLRESUMETRANSFORMFEEDBACKPROC glad_es_30_glResumeTransformFeedback;
GLAD_API_CALL PFNGLSAMPLECOVERAGEPROC glad_es_30_glSampleCoverage;
GLAD_API_CALL PFNGLSAMPLERPARAMETERFPROC glad_es_30_glSamplerParameterf;
GLAD_API_CALL PFNGLSAMPLERPARAMETERFVPROC glad_es_30_glSamplerParameterfv;
GLAD_API_CALL PFNGLSAMPLERPARAMETERIPROC glad_es_30_glSamplerParameteri;
GLAD_API_CALL PFNGLSAMPLERPARAMETERIVPROC glad_es_30_glSamplerParameteriv;
GLAD_API_CALL PFNGLSCISSORPROC glad_es_30_glScissor;
GLAD_API_CALL PFNGLSHADERBINARYPROC glad_es_30_glShaderBinary;
GLAD_API_CALL PFNGLSHADERSOURCEPROC glad_es_30_glShaderSource;
GLAD_API_CALL PFNGLSTENCILFUNCPROC glad_es_30_glStencilFunc;
GLAD_API_CALL PFNGLSTENCILFUNCSEPARATEPROC glad_es_30_glStencilFuncSeparate;
GLAD_API_CALL PFNGLSTENCILMASKPROC glad_es_30_glStencilMask;
GLAD_API_CALL PFNGLSTENCILMASKSEPARATEPROC glad_es_30_glStencilMaskSeparate;
GLAD_API_CALL PFNGLSTENCILOPPROC glad_es_30_glStencilOp;
GLAD_API_CALL PFNGLSTENCILOPSEPARATEPROC glad_es_30_glStencilOpSeparate;
GLAD_API_CALL PFNGLTEXIMAGE2DPROC glad_es_30_glTexImage2D;
GLAD_API_CALL PFNGLTEXIMAGE3DPROC glad_es_30_glTexImage3D;
GLAD_API_CALL PFNGLTEXPARAMETERFPROC glad_es_30_glTexParameterf;
GLAD_API_CALL PFNGLTEXPARAMETERFVPROC glad_es_30_glTexParameterfv;
GLAD_API_CALL PFNGLTEXPARAMETERIPROC glad_es_30_glTexParameteri;
GLAD_API_CALL PFNGLTEXPARAMETERIVPROC glad_es_30_glTexParameteriv;
GLAD_API_CALL PFNGLTEXSTORAGE2DPROC glad_es_30_glTexStorage2D;
GLAD_API_CALL PFNGLTEXSTORAGE3DPROC glad_es_30_glTexStorage3D;
GLAD_API_CALL PFNGLTEXSUBIMAGE2DPROC glad_es_30_glTexSubImage2D;
GLAD_API_CALL PFNGLTEXSUBIMAGE3DPROC glad_es_30_glTexSubImage3D;
GLAD_API_CALL PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_es_30_glTransformFeedbackVaryings;
GLAD_API_CALL PFNGLUNIFORM1FPROC glad_es_30_glUniform1f;
GLAD_API_CALL PFNGLUNIFORM1FVPROC glad_es_30_glUniform1fv;
GLAD_API_CALL PFNGLUNIFORM1IPROC glad_es_30_glUniform1i;
GLAD_API_CALL PFNGLUNIFORM1IVPROC glad_es_30_glUniform1iv;
GLAD_API_CALL PFNGLUNIFORM1UIPROC glad_es_30_glUniform1ui;
GLAD_API_CALL PFNGLUNIFORM1UIVPROC glad_es_30_glUniform1uiv;
GLAD_API_CALL PFNGLUNIFORM2FPROC glad_es_30_glUniform2f;
GLAD_API_CALL PFNGLUNIFORM2FVPROC glad_es_30_glUniform2fv;
GLAD_API_CALL PFNGLUNIFORM2IPROC glad_es_30_glUniform2i;
GLAD_API_CALL PFNGLUNIFORM2IVPROC glad_es_30_glUniform2iv;
GLAD_API_CALL PFNGLUNIFORM2UIPROC glad_es_30_glUniform2ui;
GLAD_API_CALL PFNGLUNIFORM2UIVPROC glad_es_30_glUniform2uiv;
GLAD_API_CALL PFNGLUNIFORM3FPROC glad_es_30_glUniform3f;
GLAD_API_CALL PFNGLUNIFORM3FVPROC glad_es_30_glUniform3fv;
GLAD_API_CALL PFNGLUNIFORM3IPROC glad_es_30_glUniform3i;
GLAD_API_CALL PFNGLUNIFORM3IVPROC glad_es_30_glUniform3iv;
GLAD_API_CALL PFNGLUNIFORM3UIPROC glad_es_30_glUniform3ui;
GLAD_API_CALL PFNGLUNIFORM3UIVPROC glad_es_30_glUniform3uiv;
GLAD_API_CALL PFNGLUNIFORM4FPROC glad_es_30_glUniform4f;
GLAD_API_CALL PFNGLUNIFORM4FVPROC glad_es_30_glUniform4fv;
GLAD_API_CALL PFNGLUNIFORM4IPROC glad_es_30_glUniform4i;
GLAD_API_CALL PFNGLUNIFORM4IVPROC glad_es_30_glUniform4iv;
GLAD_API_CALL PFNGLUNIFORM4UIPROC glad_es_30_glUniform4ui;
GLAD_API_CALL PFNGLUNIFORM4UIVPROC glad_es_30_glUniform4uiv;
GLAD_API_CALL PFNGLUNIFORMBLOCKBINDINGPROC glad_es_30_glUniformBlockBinding;
GLAD_API_CALL PFNGLUNIFORMMATRIX2FVPROC glad_es_30_glUniformMatrix2fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX2X3FVPROC glad_es_30_glUniformMatrix2x3fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX2X4FVPROC glad_es_30_glUniformMatrix2x4fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX3FVPROC glad_es_30_glUniformMatrix3fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX3X2FVPROC glad_es_30_glUniformMatrix3x2fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX3X4FVPROC glad_es_30_glUniformMatrix3x4fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX4FVPROC glad_es_30_glUniformMatrix4fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX4X2FVPROC glad_es_30_glUniformMatrix4x2fv;
GLAD_API_CALL PFNGLUNIFORMMATRIX4X3FVPROC glad_es_30_glUniformMatrix4x3fv;
GLAD_API_CALL PFNGLUNMAPBUFFERPROC glad_es_30_glUnmapBuffer;
GLAD_API_CALL PFNGLUSEPROGRAMPROC glad_es_30_glUseProgram;
GLAD_API_CALL PFNGLVALIDATEPROGRAMPROC glad_es_30_glValidateProgram;
GLAD_API_CALL PFNGLVERTEXATTRIB1FPROC glad_es_30_glVertexAttrib1f;
GLAD_API_CALL PFNGLVERTEXATTRIB1FVPROC glad_es_30_glVertexAttrib1fv;
GLAD_API_CALL PFNGLVERTEXATTRIB2FPROC glad_es_30_glVertexAttrib2f;
GLAD_API_CALL PFNGLVERTEXATTRIB2FVPROC glad_es_30_glVertexAttrib2fv;
GLAD_API_CALL PFNGLVERTEXATTRIB3FPROC glad_es_30_glVertexAttrib3f;
GLAD_API_CALL PFNGLVERTEXATTRIB3FVPROC glad_es_30_glVertexAttrib3fv;
GLAD_API_CALL PFNGLVERTEXATTRIB4FPROC glad_es_30_glVertexAttrib4f;
GLAD_API_CALL PFNGLVERTEXATTRIB4FVPROC glad_es_30_glVertexAttrib4fv;
GLAD_API_CALL PFNGLVERTEXATTRIBDIVISORPROC glad_es_30_glVertexAttribDivisor;
GLAD_API_CALL PFNGLVERTEXATTRIBI4IPROC glad_es_30_glVertexAttribI4i;
GLAD_API_CALL PFNGLVERTEXATTRIBI4IVPROC glad_es_30_glVertexAttribI4iv;
GLAD_API_CALL PFNGLVERTEXATTRIBI4UIPROC glad_es_30_glVertexAttribI4ui;
GLAD_API_CALL PFNGLVERTEXATTRIBI4UIVPROC glad_es_30_glVertexAttribI4uiv;
GLAD_API_CALL PFNGLVERTEXATTRIBIPOINTERPROC glad_es_30_glVertexAttribIPointer;
GLAD_API_CALL PFNGLVERTEXATTRIBPOINTERPROC glad_es_30_glVertexAttribPointer;
GLAD_API_CALL PFNGLVIEWPORTPROC glad_es_30_glViewport;
GLAD_API_CALL PFNGLWAITSYNCPROC glad_es_30_glWaitSync;

GLAD_API_CALL int gladEs30LoadGLES2UserPtr( GLADuserptrloadfunc load, void *userptr);
GLAD_API_CALL int gladEs30LoadGLES2( GLADloadfunc load);

#ifdef __cplusplus
}
#endif
#endif
