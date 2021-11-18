#pragma once


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


namespace GlEs30
{
	typedef void (BLACK_GL_API *PFNGLACTIVETEXTUREPROC)(GLenum texture);
	typedef void (BLACK_GL_API *PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
	typedef void (BLACK_GL_API *PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
	typedef void (BLACK_GL_API *PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum primitiveMode);
	typedef void (BLACK_GL_API *PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar * name);
	typedef void (BLACK_GL_API *PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
	typedef void (BLACK_GL_API *PFNGLBINDBUFFERBASEPROC)(GLenum target, GLuint index, GLuint buffer);
	typedef void (BLACK_GL_API *PFNGLBINDBUFFERRANGEPROC)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
	typedef void (BLACK_GL_API *PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
	typedef void (BLACK_GL_API *PFNGLBINDRENDERBUFFERPROC)(GLenum target, GLuint renderbuffer);
	typedef void (BLACK_GL_API *PFNGLBINDSAMPLERPROC)(GLuint unit, GLuint sampler);
	typedef void (BLACK_GL_API *PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
	typedef void (BLACK_GL_API *PFNGLBINDTRANSFORMFEEDBACKPROC)(GLenum target, GLuint id);
	typedef void (BLACK_GL_API *PFNGLBINDVERTEXARRAYPROC)(GLuint array);
	typedef void (BLACK_GL_API *PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	typedef void (BLACK_GL_API *PFNGLBLENDEQUATIONPROC)(GLenum mode);
	typedef void (BLACK_GL_API *PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
	typedef void (BLACK_GL_API *PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
	typedef void (BLACK_GL_API *PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
	typedef void (BLACK_GL_API *PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	typedef void (BLACK_GL_API *PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void * data, GLenum usage);
	typedef void (BLACK_GL_API *PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data);
	typedef GLenum (BLACK_GL_API *PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);
	typedef void (BLACK_GL_API *PFNGLCLEARPROC)(GLbitfield mask);
	typedef void (BLACK_GL_API *PFNGLCLEARBUFFERFIPROC)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
	typedef void (BLACK_GL_API *PFNGLCLEARBUFFERFVPROC)(GLenum buffer, GLint drawbuffer, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLCLEARBUFFERIVPROC)(GLenum buffer, GLint drawbuffer, const GLint * value);
	typedef void (BLACK_GL_API *PFNGLCLEARBUFFERUIVPROC)(GLenum buffer, GLint drawbuffer, const GLuint * value);
	typedef void (BLACK_GL_API *PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	typedef void (BLACK_GL_API *PFNGLCLEARDEPTHFPROC)(GLfloat d);
	typedef void (BLACK_GL_API *PFNGLCLEARSTENCILPROC)(GLint s);
	typedef GLenum (BLACK_GL_API *PFNGLCLIENTWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);
	typedef void (BLACK_GL_API *PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
	typedef void (BLACK_GL_API *PFNGLCOMPILESHADERPROC)(GLuint shader);
	typedef void (BLACK_GL_API *PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data);
	typedef void (BLACK_GL_API *PFNGLCOMPRESSEDTEXIMAGE3DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data);
	typedef void (BLACK_GL_API *PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data);
	typedef void (BLACK_GL_API *PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data);
	typedef void (BLACK_GL_API *PFNGLCOPYBUFFERSUBDATAPROC)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
	typedef void (BLACK_GL_API *PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
	typedef void (BLACK_GL_API *PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (BLACK_GL_API *PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef GLuint (BLACK_GL_API *PFNGLCREATEPROGRAMPROC)(void);
	typedef GLuint (BLACK_GL_API *PFNGLCREATESHADERPROC)(GLenum type);
	typedef void (BLACK_GL_API *PFNGLCULLFACEPROC)(GLenum mode);
	typedef void (BLACK_GL_API *PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint * buffers);
	typedef void (BLACK_GL_API *PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint * framebuffers);
	typedef void (BLACK_GL_API *PFNGLDELETEPROGRAMPROC)(GLuint program);
	typedef void (BLACK_GL_API *PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint * ids);
	typedef void (BLACK_GL_API *PFNGLDELETERENDERBUFFERSPROC)(GLsizei n, const GLuint * renderbuffers);
	typedef void (BLACK_GL_API *PFNGLDELETESAMPLERSPROC)(GLsizei count, const GLuint * samplers);
	typedef void (BLACK_GL_API *PFNGLDELETESHADERPROC)(GLuint shader);
	typedef void (BLACK_GL_API *PFNGLDELETESYNCPROC)(GLsync sync);
	typedef void (BLACK_GL_API *PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint * textures);
	typedef void (BLACK_GL_API *PFNGLDELETETRANSFORMFEEDBACKSPROC)(GLsizei n, const GLuint * ids);
	typedef void (BLACK_GL_API *PFNGLDELETEVERTEXARRAYSPROC)(GLsizei n, const GLuint * arrays);
	typedef void (BLACK_GL_API *PFNGLDEPTHFUNCPROC)(GLenum func);
	typedef void (BLACK_GL_API *PFNGLDEPTHMASKPROC)(GLboolean flag);
	typedef void (BLACK_GL_API *PFNGLDEPTHRANGEFPROC)(GLfloat n, GLfloat f);
	typedef void (BLACK_GL_API *PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
	typedef void (BLACK_GL_API *PFNGLDISABLEPROC)(GLenum cap);
	typedef void (BLACK_GL_API *PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
	typedef void (BLACK_GL_API *PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
	typedef void (BLACK_GL_API *PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
	typedef void (BLACK_GL_API *PFNGLDRAWBUFFERSPROC)(GLsizei n, const GLenum * bufs);
	typedef void (BLACK_GL_API *PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices);
	typedef void (BLACK_GL_API *PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount);
	typedef void (BLACK_GL_API *PFNGLDRAWRANGEELEMENTSPROC)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices);
	typedef void (BLACK_GL_API *PFNGLENABLEPROC)(GLenum cap);
	typedef void (BLACK_GL_API *PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
	typedef void (BLACK_GL_API *PFNGLENDQUERYPROC)(GLenum target);
	typedef void (BLACK_GL_API *PFNGLENDTRANSFORMFEEDBACKPROC)(void);
	typedef GLsync (BLACK_GL_API *PFNGLFENCESYNCPROC)(GLenum condition, GLbitfield flags);
	typedef void (BLACK_GL_API *PFNGLFINISHPROC)(void);
	typedef void (BLACK_GL_API *PFNGLFLUSHPROC)(void);
	typedef void (BLACK_GL_API *PFNGLFLUSHMAPPEDBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length);
	typedef void (BLACK_GL_API *PFNGLFRAMEBUFFERRENDERBUFFERPROC)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
	typedef void (BLACK_GL_API *PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
	typedef void (BLACK_GL_API *PFNGLFRAMEBUFFERTEXTURELAYERPROC)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
	typedef void (BLACK_GL_API *PFNGLFRONTFACEPROC)(GLenum mode);
	typedef void (BLACK_GL_API *PFNGLGENBUFFERSPROC)(GLsizei n, GLuint * buffers);
	typedef void (BLACK_GL_API *PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint * framebuffers);
	typedef void (BLACK_GL_API *PFNGLGENQUERIESPROC)(GLsizei n, GLuint * ids);
	typedef void (BLACK_GL_API *PFNGLGENRENDERBUFFERSPROC)(GLsizei n, GLuint * renderbuffers);
	typedef void (BLACK_GL_API *PFNGLGENSAMPLERSPROC)(GLsizei count, GLuint * samplers);
	typedef void (BLACK_GL_API *PFNGLGENTEXTURESPROC)(GLsizei n, GLuint * textures);
	typedef void (BLACK_GL_API *PFNGLGENTRANSFORMFEEDBACKSPROC)(GLsizei n, GLuint * ids);
	typedef void (BLACK_GL_API *PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint * arrays);
	typedef void (BLACK_GL_API *PFNGLGENERATEMIPMAPPROC)(GLenum target);
	typedef void (BLACK_GL_API *PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
	typedef void (BLACK_GL_API *PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
	typedef void (BLACK_GL_API *PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName);
	typedef void (BLACK_GL_API *PFNGLGETACTIVEUNIFORMBLOCKIVPROC)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETACTIVEUNIFORMSIVPROC)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders);
	typedef GLint (BLACK_GL_API *PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar * name);
	typedef void (BLACK_GL_API *PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean * data);
	typedef void (BLACK_GL_API *PFNGLGETBUFFERPARAMETERI64VPROC)(GLenum target, GLenum pname, GLint64 * params);
	typedef void (BLACK_GL_API *PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void ** params);
	typedef GLenum (BLACK_GL_API *PFNGLGETERRORPROC)(void);
	typedef void (BLACK_GL_API *PFNGLGETFLOATVPROC)(GLenum pname, GLfloat * data);
	typedef GLint (BLACK_GL_API *PFNGLGETFRAGDATALOCATIONPROC)(GLuint program, const GLchar * name);
	typedef void (BLACK_GL_API *PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETINTEGER64I_VPROC)(GLenum target, GLuint index, GLint64 * data);
	typedef void (BLACK_GL_API *PFNGLGETINTEGER64VPROC)(GLenum pname, GLint64 * data);
	typedef void (BLACK_GL_API *PFNGLGETINTEGERI_VPROC)(GLenum target, GLuint index, GLint * data);
	typedef void (BLACK_GL_API *PFNGLGETINTEGERVPROC)(GLenum pname, GLint * data);
	typedef void (BLACK_GL_API *PFNGLGETINTERNALFORMATIVPROC)(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETPROGRAMBINARYPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLenum * binaryFormat, void * binary);
	typedef void (BLACK_GL_API *PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
	typedef void (BLACK_GL_API *PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint * params);
	typedef void (BLACK_GL_API *PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETRENDERBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, GLfloat * params);
	typedef void (BLACK_GL_API *PFNGLGETSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
	typedef void (BLACK_GL_API *PFNGLGETSHADERPRECISIONFORMATPROC)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
	typedef void (BLACK_GL_API *PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
	typedef void (BLACK_GL_API *PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint * params);
	typedef const GLubyte * (BLACK_GL_API *PFNGLGETSTRINGPROC)(GLenum name);
	typedef const GLubyte * (BLACK_GL_API *PFNGLGETSTRINGIPROC)(GLenum name, GLuint index);
	typedef void (BLACK_GL_API *PFNGLGETSYNCIVPROC)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values);
	typedef void (BLACK_GL_API *PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat * params);
	typedef void (BLACK_GL_API *PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name);
	typedef GLuint (BLACK_GL_API *PFNGLGETUNIFORMBLOCKINDEXPROC)(GLuint program, const GLchar * uniformBlockName);
	typedef void (BLACK_GL_API *PFNGLGETUNIFORMINDICESPROC)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices);
	typedef GLint (BLACK_GL_API *PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar * name);
	typedef void (BLACK_GL_API *PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat * params);
	typedef void (BLACK_GL_API *PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETUNIFORMUIVPROC)(GLuint program, GLint location, GLuint * params);
	typedef void (BLACK_GL_API *PFNGLGETVERTEXATTRIBIIVPROC)(GLuint index, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint index, GLenum pname, GLuint * params);
	typedef void (BLACK_GL_API *PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void ** pointer);
	typedef void (BLACK_GL_API *PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat * params);
	typedef void (BLACK_GL_API *PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint * params);
	typedef void (BLACK_GL_API *PFNGLHINTPROC)(GLenum target, GLenum mode);
	typedef void (BLACK_GL_API *PFNGLINVALIDATEFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments);
	typedef void (BLACK_GL_API *PFNGLINVALIDATESUBFRAMEBUFFERPROC)(GLenum target, GLsizei numAttachments, const GLenum * attachments, GLint x, GLint y, GLsizei width, GLsizei height);
	typedef GLboolean (BLACK_GL_API *PFNGLISBUFFERPROC)(GLuint buffer);
	typedef GLboolean (BLACK_GL_API *PFNGLISENABLEDPROC)(GLenum cap);
	typedef GLboolean (BLACK_GL_API *PFNGLISFRAMEBUFFERPROC)(GLuint framebuffer);
	typedef GLboolean (BLACK_GL_API *PFNGLISPROGRAMPROC)(GLuint program);
	typedef GLboolean (BLACK_GL_API *PFNGLISQUERYPROC)(GLuint id);
	typedef GLboolean (BLACK_GL_API *PFNGLISRENDERBUFFERPROC)(GLuint renderbuffer);
	typedef GLboolean (BLACK_GL_API *PFNGLISSAMPLERPROC)(GLuint sampler);
	typedef GLboolean (BLACK_GL_API *PFNGLISSHADERPROC)(GLuint shader);
	typedef GLboolean (BLACK_GL_API *PFNGLISSYNCPROC)(GLsync sync);
	typedef GLboolean (BLACK_GL_API *PFNGLISTEXTUREPROC)(GLuint texture);
	typedef GLboolean (BLACK_GL_API *PFNGLISTRANSFORMFEEDBACKPROC)(GLuint id);
	typedef GLboolean (BLACK_GL_API *PFNGLISVERTEXARRAYPROC)(GLuint array);
	typedef void (BLACK_GL_API *PFNGLLINEWIDTHPROC)(GLfloat width);
	typedef void (BLACK_GL_API *PFNGLLINKPROGRAMPROC)(GLuint program);
	typedef void * (BLACK_GL_API *PFNGLMAPBUFFERRANGEPROC)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
	typedef void (BLACK_GL_API *PFNGLPAUSETRANSFORMFEEDBACKPROC)(void);
	typedef void (BLACK_GL_API *PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
	typedef void (BLACK_GL_API *PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
	typedef void (BLACK_GL_API *PFNGLPROGRAMBINARYPROC)(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length);
	typedef void (BLACK_GL_API *PFNGLPROGRAMPARAMETERIPROC)(GLuint program, GLenum pname, GLint value);
	typedef void (BLACK_GL_API *PFNGLREADBUFFERPROC)(GLenum src);
	typedef void (BLACK_GL_API *PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels);
	typedef void (BLACK_GL_API *PFNGLRELEASESHADERCOMPILERPROC)(void);
	typedef void (BLACK_GL_API *PFNGLRENDERBUFFERSTORAGEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (BLACK_GL_API *PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (BLACK_GL_API *PFNGLRESUMETRANSFORMFEEDBACKPROC)(void);
	typedef void (BLACK_GL_API *PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
	typedef void (BLACK_GL_API *PFNGLSAMPLERPARAMETERFPROC)(GLuint sampler, GLenum pname, GLfloat param);
	typedef void (BLACK_GL_API *PFNGLSAMPLERPARAMETERFVPROC)(GLuint sampler, GLenum pname, const GLfloat * param);
	typedef void (BLACK_GL_API *PFNGLSAMPLERPARAMETERIPROC)(GLuint sampler, GLenum pname, GLint param);
	typedef void (BLACK_GL_API *PFNGLSAMPLERPARAMETERIVPROC)(GLuint sampler, GLenum pname, const GLint * param);
	typedef void (BLACK_GL_API *PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (BLACK_GL_API *PFNGLSHADERBINARYPROC)(GLsizei count, const GLuint * shaders, GLenum binaryFormat, const void * binary, GLsizei length);
	typedef void (BLACK_GL_API *PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length);
	typedef void (BLACK_GL_API *PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
	typedef void (BLACK_GL_API *PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
	typedef void (BLACK_GL_API *PFNGLSTENCILMASKPROC)(GLuint mask);
	typedef void (BLACK_GL_API *PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
	typedef void (BLACK_GL_API *PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
	typedef void (BLACK_GL_API *PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
	typedef void (BLACK_GL_API *PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels);
	typedef void (BLACK_GL_API *PFNGLTEXIMAGE3DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels);
	typedef void (BLACK_GL_API *PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
	typedef void (BLACK_GL_API *PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat * params);
	typedef void (BLACK_GL_API *PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
	typedef void (BLACK_GL_API *PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint * params);
	typedef void (BLACK_GL_API *PFNGLTEXSTORAGE2DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
	typedef void (BLACK_GL_API *PFNGLTEXSTORAGE3DPROC)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
	typedef void (BLACK_GL_API *PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels);
	typedef void (BLACK_GL_API *PFNGLTEXSUBIMAGE3DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels);
	typedef void (BLACK_GL_API *PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode);
	typedef void (BLACK_GL_API *PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
	typedef void (BLACK_GL_API *PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
	typedef void (BLACK_GL_API *PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM1UIPROC)(GLint location, GLuint v0);
	typedef void (BLACK_GL_API *PFNGLUNIFORM1UIVPROC)(GLint location, GLsizei count, const GLuint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
	typedef void (BLACK_GL_API *PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
	typedef void (BLACK_GL_API *PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM2UIPROC)(GLint location, GLuint v0, GLuint v1);
	typedef void (BLACK_GL_API *PFNGLUNIFORM2UIVPROC)(GLint location, GLsizei count, const GLuint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
	typedef void (BLACK_GL_API *PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
	typedef void (BLACK_GL_API *PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM3UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2);
	typedef void (BLACK_GL_API *PFNGLUNIFORM3UIVPROC)(GLint location, GLsizei count, const GLuint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
	typedef void (BLACK_GL_API *PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
	typedef void (BLACK_GL_API *PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORM4UIPROC)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
	typedef void (BLACK_GL_API *PFNGLUNIFORM4UIVPROC)(GLint location, GLsizei count, const GLuint * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMBLOCKBINDINGPROC)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX2X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX2X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX3X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX3X4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX4X2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef void (BLACK_GL_API *PFNGLUNIFORMMATRIX4X3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
	typedef GLboolean (BLACK_GL_API *PFNGLUNMAPBUFFERPROC)(GLenum target);
	typedef void (BLACK_GL_API *PFNGLUSEPROGRAMPROC)(GLuint program);
	typedef void (BLACK_GL_API *PFNGLVALIDATEPROGRAMPROC)(GLuint program);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat * v);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat * v);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat * v);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat * v);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBI4IPROC)(GLuint index, GLint x, GLint y, GLint z, GLint w);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBI4IVPROC)(GLuint index, const GLint * v);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBI4UIPROC)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBI4UIVPROC)(GLuint index, const GLuint * v);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer);
	typedef void (BLACK_GL_API *PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
	typedef void (BLACK_GL_API *PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
	typedef void (BLACK_GL_API *PFNGLWAITSYNCPROC)(GLsync sync, GLbitfield flags, GLuint64 timeout);


	extern PFNGLACTIVETEXTUREPROC							active_texture;
	extern PFNGLATTACHSHADERPROC							attach_shader;
	extern PFNGLBEGINQUERYPROC								begin_query;
	extern PFNGLBEGINTRANSFORMFEEDBACKPROC					begin_transform_feedback;
	extern PFNGLBINDATTRIBLOCATIONPROC						bind_attrib_location;
	extern PFNGLBINDBUFFERPROC								bind_buffer;
	extern PFNGLBINDBUFFERBASEPROC							bind_buffer_base;
	extern PFNGLBINDBUFFERRANGEPROC							bind_buffer_range;
	extern PFNGLBINDFRAMEBUFFERPROC							bind_framebuffer;
	extern PFNGLBINDRENDERBUFFERPROC						bind_renderbuffer;
	extern PFNGLBINDSAMPLERPROC								bind_sampler;
	extern PFNGLBINDTEXTUREPROC								bind_texture;
	extern PFNGLBINDTRANSFORMFEEDBACKPROC					bind_transform_feedback;
	extern PFNGLBINDVERTEXARRAYPROC							bind_vertex_array;
	extern PFNGLBLENDCOLORPROC								blend_color;
	extern PFNGLBLENDEQUATIONPROC							blend_equation;
	extern PFNGLBLENDEQUATIONSEPARATEPROC					blend_equation_separate;
	extern PFNGLBLENDFUNCPROC								blend_func;
	extern PFNGLBLENDFUNCSEPARATEPROC						blend_func_separate;
	extern PFNGLBLITFRAMEBUFFERPROC							blit_framebuffer;
	extern PFNGLBUFFERDATAPROC								buffer_data;
	extern PFNGLBUFFERSUBDATAPROC							buffer_sub_data;
	extern PFNGLCHECKFRAMEBUFFERSTATUSPROC					check_framebuffer_status;
	extern PFNGLCLEARPROC									clear;
	extern PFNGLCLEARBUFFERFIPROC							clear_bufferfi;
	extern PFNGLCLEARBUFFERFVPROC							clear_bufferfv;
	extern PFNGLCLEARBUFFERIVPROC							clear_bufferiv;
	extern PFNGLCLEARBUFFERUIVPROC							clear_bufferuiv;
	extern PFNGLCLEARCOLORPROC								clear_color;
	extern PFNGLCLEARDEPTHFPROC								clear_depthf;
	extern PFNGLCLEARSTENCILPROC							clear_stencil;
	extern PFNGLCLIENTWAITSYNCPROC							client_wait_sync;
	extern PFNGLCOLORMASKPROC								color_mask;
	extern PFNGLCOMPILESHADERPROC							compile_shader;
	extern PFNGLCOMPRESSEDTEXIMAGE2DPROC					compressed_tex_image2d;
	extern PFNGLCOMPRESSEDTEXIMAGE3DPROC					compressed_tex_image3d;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC					compressed_tex_sub_image2d;
	extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC					compressed_tex_sub_image3d;
	extern PFNGLCOPYBUFFERSUBDATAPROC						copy_buffer_sub_data;
	extern PFNGLCOPYTEXIMAGE2DPROC							copy_tex_image2d;
	extern PFNGLCOPYTEXSUBIMAGE2DPROC						copy_tex_sub_image2d;
	extern PFNGLCOPYTEXSUBIMAGE3DPROC						copy_tex_sub_image3d;
	extern PFNGLCREATEPROGRAMPROC							create_program;
	extern PFNGLCREATESHADERPROC							create_shader;
	extern PFNGLCULLFACEPROC								cull_face;
	extern PFNGLDELETEBUFFERSPROC							delete_buffers;
	extern PFNGLDELETEFRAMEBUFFERSPROC						delete_framebuffers;
	extern PFNGLDELETEPROGRAMPROC							delete_program;
	extern PFNGLDELETEQUERIESPROC							delete_queries;
	extern PFNGLDELETERENDERBUFFERSPROC						delete_renderbuffers;
	extern PFNGLDELETESAMPLERSPROC							delete_samplers;
	extern PFNGLDELETESHADERPROC							delete_shader;
	extern PFNGLDELETESYNCPROC								delete_sync;
	extern PFNGLDELETETEXTURESPROC							delete_textures;
	extern PFNGLDELETETRANSFORMFEEDBACKSPROC				delete_transform_feedbacks;
	extern PFNGLDELETEVERTEXARRAYSPROC						delete_vertex_arrays;
	extern PFNGLDEPTHFUNCPROC								depth_func;
	extern PFNGLDEPTHMASKPROC								depth_mask;
	extern PFNGLDEPTHRANGEFPROC								depth_rangef;
	extern PFNGLDETACHSHADERPROC							detach_shader;
	extern PFNGLDISABLEPROC									disable;
	extern PFNGLDISABLEVERTEXATTRIBARRAYPROC				disable_vertex_attrib_array;
	extern PFNGLDRAWARRAYSPROC								draw_arrays;
	extern PFNGLDRAWARRAYSINSTANCEDPROC						draw_arrays_instanced;
	extern PFNGLDRAWBUFFERSPROC								draw_buffers;
	extern PFNGLDRAWELEMENTSPROC							draw_elements;
	extern PFNGLDRAWELEMENTSINSTANCEDPROC					draw_elements_instanced;
	extern PFNGLDRAWRANGEELEMENTSPROC						draw_range_elements;
	extern PFNGLENABLEPROC									enable;
	extern PFNGLENABLEVERTEXATTRIBARRAYPROC					enable_vertex_attrib_array;
	extern PFNGLENDQUERYPROC								end_query;
	extern PFNGLENDTRANSFORMFEEDBACKPROC					end_transform_feedback;
	extern PFNGLFENCESYNCPROC								fence_sync;
	extern PFNGLFINISHPROC									finish;
	extern PFNGLFLUSHPROC									flush;
	extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC					flush_mapped_buffer_range;
	extern PFNGLFRAMEBUFFERRENDERBUFFERPROC					framebuffer_renderbuffer;
	extern PFNGLFRAMEBUFFERTEXTURE2DPROC					framebuffer_texture2d;
	extern PFNGLFRAMEBUFFERTEXTURELAYERPROC					framebuffer_texture_layer;
	extern PFNGLFRONTFACEPROC								front_face;
	extern PFNGLGENBUFFERSPROC								gen_buffers;
	extern PFNGLGENFRAMEBUFFERSPROC							gen_framebuffers;
	extern PFNGLGENQUERIESPROC								gen_queries;
	extern PFNGLGENRENDERBUFFERSPROC						gen_renderbuffers;
	extern PFNGLGENSAMPLERSPROC								gen_samplers;
	extern PFNGLGENTEXTURESPROC								gen_textures;
	extern PFNGLGENTRANSFORMFEEDBACKSPROC					gen_transform_feedbacks;
	extern PFNGLGENVERTEXARRAYSPROC							gen_vertex_arrays;
	extern PFNGLGENERATEMIPMAPPROC							generate_mipmap;
	extern PFNGLGETACTIVEATTRIBPROC							get_active_attrib;
	extern PFNGLGETACTIVEUNIFORMPROC						get_active_uniform;
	extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC				get_active_uniform_block_name;
	extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC					get_active_uniform_blockiv;
	extern PFNGLGETACTIVEUNIFORMSIVPROC						get_active_uniformsiv;
	extern PFNGLGETATTACHEDSHADERSPROC						get_attached_shaders;
	extern PFNGLGETATTRIBLOCATIONPROC						get_attrib_location;
	extern PFNGLGETBOOLEANVPROC								get_booleanv;
	extern PFNGLGETBUFFERPARAMETERI64VPROC					get_buffer_parameteri64v;
	extern PFNGLGETBUFFERPARAMETERIVPROC					get_buffer_parameteriv;
	extern PFNGLGETBUFFERPOINTERVPROC						get_buffer_pointerv;
	extern PFNGLGETERRORPROC								get_error;
	extern PFNGLGETFLOATVPROC								get_floatv;
	extern PFNGLGETFRAGDATALOCATIONPROC						get_frag_data_location;
	extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC		get_framebuffer_attachment_parameteriv;
	extern PFNGLGETINTEGER64I_VPROC							get_integer64i_v;
	extern PFNGLGETINTEGER64VPROC							get_integer64v;
	extern PFNGLGETINTEGERI_VPROC							get_integeri_v;
	extern PFNGLGETINTEGERVPROC								get_integerv;
	extern PFNGLGETINTERNALFORMATIVPROC						get_internalformativ;
	extern PFNGLGETPROGRAMBINARYPROC						get_program_binary;
	extern PFNGLGETPROGRAMINFOLOGPROC						get_program_info_log;
	extern PFNGLGETPROGRAMIVPROC							get_programiv;
	extern PFNGLGETQUERYOBJECTUIVPROC						get_query_objectuiv;
	extern PFNGLGETQUERYIVPROC								get_queryiv;
	extern PFNGLGETRENDERBUFFERPARAMETERIVPROC				get_renderbuffer_parameteriv;
	extern PFNGLGETSAMPLERPARAMETERFVPROC					get_sampler_parameterfv;
	extern PFNGLGETSAMPLERPARAMETERIVPROC					get_sampler_parameteriv;
	extern PFNGLGETSHADERINFOLOGPROC						get_shader_info_log;
	extern PFNGLGETSHADERPRECISIONFORMATPROC				get_shader_precision_format;
	extern PFNGLGETSHADERSOURCEPROC							get_shader_source;
	extern PFNGLGETSHADERIVPROC								get_shaderiv;
	extern PFNGLGETSTRINGPROC								get_string;
	extern PFNGLGETSTRINGIPROC								get_stringi;
	extern PFNGLGETSYNCIVPROC								get_synciv;
	extern PFNGLGETTEXPARAMETERFVPROC						get_tex_parameterfv;
	extern PFNGLGETTEXPARAMETERIVPROC						get_tex_parameteriv;
	extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC				get_transform_feedback_varying;
	extern PFNGLGETUNIFORMBLOCKINDEXPROC					get_uniform_block_index;
	extern PFNGLGETUNIFORMINDICESPROC						get_uniform_indices;
	extern PFNGLGETUNIFORMLOCATIONPROC						get_uniform_location;
	extern PFNGLGETUNIFORMFVPROC							get_uniformfv;
	extern PFNGLGETUNIFORMIVPROC							get_uniformiv;
	extern PFNGLGETUNIFORMUIVPROC							get_uniformuiv;
	extern PFNGLGETVERTEXATTRIBIIVPROC						get_vertex_attrib_iiv;
	extern PFNGLGETVERTEXATTRIBIUIVPROC						get_vertex_attrib_iuiv;
	extern PFNGLGETVERTEXATTRIBPOINTERVPROC					get_vertex_attrib_pointerv;
	extern PFNGLGETVERTEXATTRIBFVPROC						get_vertex_attribfv;
	extern PFNGLGETVERTEXATTRIBIVPROC						get_vertex_attribiv;
	extern PFNGLHINTPROC									hint;
	extern PFNGLINVALIDATEFRAMEBUFFERPROC					invalidate_framebuffer;
	extern PFNGLINVALIDATESUBFRAMEBUFFERPROC				invalidate_sub_framebuffer;
	extern PFNGLISBUFFERPROC								is_buffer;
	extern PFNGLISENABLEDPROC								is_enabled;
	extern PFNGLISFRAMEBUFFERPROC							is_framebuffer;
	extern PFNGLISPROGRAMPROC								is_program;
	extern PFNGLISQUERYPROC									is_query;
	extern PFNGLISRENDERBUFFERPROC							is_renderbuffer;
	extern PFNGLISSAMPLERPROC								is_sampler;
	extern PFNGLISSHADERPROC								is_shader;
	extern PFNGLISSYNCPROC									is_sync;
	extern PFNGLISTEXTUREPROC								is_texture;
	extern PFNGLISTRANSFORMFEEDBACKPROC						is_transform_feedback;
	extern PFNGLISVERTEXARRAYPROC							is_vertex_array;
	extern PFNGLLINEWIDTHPROC								line_width;
	extern PFNGLLINKPROGRAMPROC								link_program;
	extern PFNGLMAPBUFFERRANGEPROC							map_buffer_range;
	extern PFNGLPAUSETRANSFORMFEEDBACKPROC					pause_transform_feedback;
	extern PFNGLPIXELSTOREIPROC								pixel_storei;
	extern PFNGLPOLYGONOFFSETPROC							polygon_offset;
	extern PFNGLPROGRAMBINARYPROC							program_binary;
	extern PFNGLPROGRAMPARAMETERIPROC						program_parameteri;
	extern PFNGLREADBUFFERPROC								read_buffer;
	extern PFNGLREADPIXELSPROC								read_pixels;
	extern PFNGLRELEASESHADERCOMPILERPROC					release_shader_compiler;
	extern PFNGLRENDERBUFFERSTORAGEPROC						renderbuffer_storage;
	extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC			renderbuffer_storage_multisample;
	extern PFNGLRESUMETRANSFORMFEEDBACKPROC					resume_transform_feedback;
	extern PFNGLSAMPLECOVERAGEPROC							sample_coverage;
	extern PFNGLSAMPLERPARAMETERFPROC						sampler_parameterf;
	extern PFNGLSAMPLERPARAMETERFVPROC						sampler_parameterfv;
	extern PFNGLSAMPLERPARAMETERIPROC						sampler_parameteri;
	extern PFNGLSAMPLERPARAMETERIVPROC						sampler_parameteriv;
	extern PFNGLSCISSORPROC									scissor;
	extern PFNGLSHADERBINARYPROC							shader_binary;
	extern PFNGLSHADERSOURCEPROC							shader_source;
	extern PFNGLSTENCILFUNCPROC								stencil_func;
	extern PFNGLSTENCILFUNCSEPARATEPROC						stencil_func_separate;
	extern PFNGLSTENCILMASKPROC								stencil_mask;
	extern PFNGLSTENCILMASKSEPARATEPROC						stencil_mask_separate;
	extern PFNGLSTENCILOPPROC								stencil_op;
	extern PFNGLSTENCILOPSEPARATEPROC						stencil_op_separate;
	extern PFNGLTEXIMAGE2DPROC								tex_image2_d;
	extern PFNGLTEXIMAGE3DPROC								tex_image3_d;
	extern PFNGLTEXPARAMETERFPROC							tex_parameterf;
	extern PFNGLTEXPARAMETERFVPROC							tex_parameterfv;
	extern PFNGLTEXPARAMETERIPROC							tex_parameteri;
	extern PFNGLTEXPARAMETERIVPROC							tex_parameteriv;
	extern PFNGLTEXSTORAGE2DPROC							tex_storage2_d;
	extern PFNGLTEXSTORAGE3DPROC							tex_storage3_d;
	extern PFNGLTEXSUBIMAGE2DPROC							tex_sub_image2_d;
	extern PFNGLTEXSUBIMAGE3DPROC							tex_sub_image3_d;
	extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC				transform_feedback_varyings;
	extern PFNGLUNIFORM1FPROC								uniform1f;
	extern PFNGLUNIFORM1FVPROC								uniform1fv;
	extern PFNGLUNIFORM1IPROC								uniform1i;
	extern PFNGLUNIFORM1IVPROC								uniform1iv;
	extern PFNGLUNIFORM1UIPROC								uniform1ui;
	extern PFNGLUNIFORM1UIVPROC								uniform1uiv;
	extern PFNGLUNIFORM2FPROC								uniform2f;
	extern PFNGLUNIFORM2FVPROC								uniform2fv;
	extern PFNGLUNIFORM2IPROC								uniform2i;
	extern PFNGLUNIFORM2IVPROC								uniform2iv;
	extern PFNGLUNIFORM2UIPROC								uniform2ui;
	extern PFNGLUNIFORM2UIVPROC								uniform2uiv;
	extern PFNGLUNIFORM3FPROC								uniform3f;
	extern PFNGLUNIFORM3FVPROC								uniform3fv;
	extern PFNGLUNIFORM3IPROC								uniform3i;
	extern PFNGLUNIFORM3IVPROC								uniform3iv;
	extern PFNGLUNIFORM3UIPROC								uniform3ui;
	extern PFNGLUNIFORM3UIVPROC								uniform3uiv;
	extern PFNGLUNIFORM4FPROC								uniform4f;
	extern PFNGLUNIFORM4FVPROC								uniform4fv;
	extern PFNGLUNIFORM4IPROC								uniform4i;
	extern PFNGLUNIFORM4IVPROC								uniform4iv;
	extern PFNGLUNIFORM4UIPROC								uniform4ui;
	extern PFNGLUNIFORM4UIVPROC								uniform4uiv;
	extern PFNGLUNIFORMBLOCKBINDINGPROC						uniform_block_binding;
	extern PFNGLUNIFORMMATRIX2FVPROC						uniform_matrix2fv;
	extern PFNGLUNIFORMMATRIX2X3FVPROC						uniform_matrix2x3fv;
	extern PFNGLUNIFORMMATRIX2X4FVPROC						uniform_matrix2x4fv;
	extern PFNGLUNIFORMMATRIX3FVPROC						uniform_matrix3fv;
	extern PFNGLUNIFORMMATRIX3X2FVPROC						uniform_matrix3x2fv;
	extern PFNGLUNIFORMMATRIX3X4FVPROC						uniform_matrix3x4fv;
	extern PFNGLUNIFORMMATRIX4FVPROC						uniform_matrix4fv;
	extern PFNGLUNIFORMMATRIX4X2FVPROC						uniform_matrix4x2fv;
	extern PFNGLUNIFORMMATRIX4X3FVPROC						uniform_matrix4x3fv;
	extern PFNGLUNMAPBUFFERPROC								unmap_buffer;
	extern PFNGLUSEPROGRAMPROC								use_program;
	extern PFNGLVALIDATEPROGRAMPROC							validate_program;
	extern PFNGLVERTEXATTRIB1FPROC							vertex_attrib1f;
	extern PFNGLVERTEXATTRIB1FVPROC							vertex_attrib1fv;
	extern PFNGLVERTEXATTRIB2FPROC							vertex_attrib2f;
	extern PFNGLVERTEXATTRIB2FVPROC							vertex_attrib2fv;
	extern PFNGLVERTEXATTRIB3FPROC							vertex_attrib3f;
	extern PFNGLVERTEXATTRIB3FVPROC							vertex_attrib3fv;
	extern PFNGLVERTEXATTRIB4FPROC							vertex_attrib4f;
	extern PFNGLVERTEXATTRIB4FVPROC							vertex_attrib4fv;
	extern PFNGLVERTEXATTRIBDIVISORPROC						vertex_attrib_divisor;
	extern PFNGLVERTEXATTRIBI4IPROC							vertex_attrib_i4i;
	extern PFNGLVERTEXATTRIBI4IVPROC						vertex_attrib_i4iv;
	extern PFNGLVERTEXATTRIBI4UIPROC						vertex_attrib_i4ui;
	extern PFNGLVERTEXATTRIBI4UIVPROC						vertex_attrib_i4uiv;
	extern PFNGLVERTEXATTRIBIPOINTERPROC					vertex_attrib_i_pointer;
	extern PFNGLVERTEXATTRIBPOINTERPROC						vertex_attrib_pointer;
	extern PFNGLVIEWPORTPROC								viewport;
	extern PFNGLWAITSYNCPROC								wait_sync;
}
