#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "glad-es-3.0.h"

#ifndef GLAD_IMPL_UTIL_C_
#define GLAD_IMPL_UTIL_C_

#ifdef _MSC_VER
#define GLAD_IMPL_UTIL_SSCANF sscanf_s
#else
#define GLAD_IMPL_UTIL_SSCANF sscanf
#endif

#endif /* GLAD_IMPL_UTIL_C_ */


#define GL_EXTENSIONS 0x1F03
#define GL_NUM_EXTENSIONS 0x821D
#define GL_VERSION 0x1F02


#ifdef __cplusplus
extern "C" {
#endif



int GLAD_ES_30_GL_ES_VERSION_2_0 = 0;
int GLAD_ES_30_GL_ES_VERSION_3_0 = 0;



PFNGLACTIVETEXTUREPROC glad_es_30_glActiveTexture = NULL;
PFNGLATTACHSHADERPROC glad_es_30_glAttachShader = NULL;
PFNGLBEGINQUERYPROC glad_es_30_glBeginQuery = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC glad_es_30_glBeginTransformFeedback = NULL;
PFNGLBINDATTRIBLOCATIONPROC glad_es_30_glBindAttribLocation = NULL;
PFNGLBINDBUFFERPROC glad_es_30_glBindBuffer = NULL;
PFNGLBINDBUFFERBASEPROC glad_es_30_glBindBufferBase = NULL;
PFNGLBINDBUFFERRANGEPROC glad_es_30_glBindBufferRange = NULL;
PFNGLBINDFRAMEBUFFERPROC glad_es_30_glBindFramebuffer = NULL;
PFNGLBINDRENDERBUFFERPROC glad_es_30_glBindRenderbuffer = NULL;
PFNGLBINDSAMPLERPROC glad_es_30_glBindSampler = NULL;
PFNGLBINDTEXTUREPROC glad_es_30_glBindTexture = NULL;
PFNGLBINDTRANSFORMFEEDBACKPROC glad_es_30_glBindTransformFeedback = NULL;
PFNGLBINDVERTEXARRAYPROC glad_es_30_glBindVertexArray = NULL;
PFNGLBLENDCOLORPROC glad_es_30_glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glad_es_30_glBlendEquation = NULL;
PFNGLBLENDEQUATIONSEPARATEPROC glad_es_30_glBlendEquationSeparate = NULL;
PFNGLBLENDFUNCPROC glad_es_30_glBlendFunc = NULL;
PFNGLBLENDFUNCSEPARATEPROC glad_es_30_glBlendFuncSeparate = NULL;
PFNGLBLITFRAMEBUFFERPROC glad_es_30_glBlitFramebuffer = NULL;
PFNGLBUFFERDATAPROC glad_es_30_glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glad_es_30_glBufferSubData = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glad_es_30_glCheckFramebufferStatus = NULL;
PFNGLCLEARPROC glad_es_30_glClear = NULL;
PFNGLCLEARBUFFERFIPROC glad_es_30_glClearBufferfi = NULL;
PFNGLCLEARBUFFERFVPROC glad_es_30_glClearBufferfv = NULL;
PFNGLCLEARBUFFERIVPROC glad_es_30_glClearBufferiv = NULL;
PFNGLCLEARBUFFERUIVPROC glad_es_30_glClearBufferuiv = NULL;
PFNGLCLEARCOLORPROC glad_es_30_glClearColor = NULL;
PFNGLCLEARDEPTHFPROC glad_es_30_glClearDepthf = NULL;
PFNGLCLEARSTENCILPROC glad_es_30_glClearStencil = NULL;
PFNGLCLIENTWAITSYNCPROC glad_es_30_glClientWaitSync = NULL;
PFNGLCOLORMASKPROC glad_es_30_glColorMask = NULL;
PFNGLCOMPILESHADERPROC glad_es_30_glCompileShader = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glad_es_30_glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glad_es_30_glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glad_es_30_glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glad_es_30_glCompressedTexSubImage3D = NULL;
PFNGLCOPYBUFFERSUBDATAPROC glad_es_30_glCopyBufferSubData = NULL;
PFNGLCOPYTEXIMAGE2DPROC glad_es_30_glCopyTexImage2D = NULL;
PFNGLCOPYTEXSUBIMAGE2DPROC glad_es_30_glCopyTexSubImage2D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glad_es_30_glCopyTexSubImage3D = NULL;
PFNGLCREATEPROGRAMPROC glad_es_30_glCreateProgram = NULL;
PFNGLCREATESHADERPROC glad_es_30_glCreateShader = NULL;
PFNGLCULLFACEPROC glad_es_30_glCullFace = NULL;
PFNGLDELETEBUFFERSPROC glad_es_30_glDeleteBuffers = NULL;
PFNGLDELETEFRAMEBUFFERSPROC glad_es_30_glDeleteFramebuffers = NULL;
PFNGLDELETEPROGRAMPROC glad_es_30_glDeleteProgram = NULL;
PFNGLDELETEQUERIESPROC glad_es_30_glDeleteQueries = NULL;
PFNGLDELETERENDERBUFFERSPROC glad_es_30_glDeleteRenderbuffers = NULL;
PFNGLDELETESAMPLERSPROC glad_es_30_glDeleteSamplers = NULL;
PFNGLDELETESHADERPROC glad_es_30_glDeleteShader = NULL;
PFNGLDELETESYNCPROC glad_es_30_glDeleteSync = NULL;
PFNGLDELETETEXTURESPROC glad_es_30_glDeleteTextures = NULL;
PFNGLDELETETRANSFORMFEEDBACKSPROC glad_es_30_glDeleteTransformFeedbacks = NULL;
PFNGLDELETEVERTEXARRAYSPROC glad_es_30_glDeleteVertexArrays = NULL;
PFNGLDEPTHFUNCPROC glad_es_30_glDepthFunc = NULL;
PFNGLDEPTHMASKPROC glad_es_30_glDepthMask = NULL;
PFNGLDEPTHRANGEFPROC glad_es_30_glDepthRangef = NULL;
PFNGLDETACHSHADERPROC glad_es_30_glDetachShader = NULL;
PFNGLDISABLEPROC glad_es_30_glDisable = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glad_es_30_glDisableVertexAttribArray = NULL;
PFNGLDRAWARRAYSPROC glad_es_30_glDrawArrays = NULL;
PFNGLDRAWARRAYSINSTANCEDPROC glad_es_30_glDrawArraysInstanced = NULL;
PFNGLDRAWBUFFERSPROC glad_es_30_glDrawBuffers = NULL;
PFNGLDRAWELEMENTSPROC glad_es_30_glDrawElements = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC glad_es_30_glDrawElementsInstanced = NULL;
PFNGLDRAWRANGEELEMENTSPROC glad_es_30_glDrawRangeElements = NULL;
PFNGLENABLEPROC glad_es_30_glEnable = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glad_es_30_glEnableVertexAttribArray = NULL;
PFNGLENDQUERYPROC glad_es_30_glEndQuery = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC glad_es_30_glEndTransformFeedback = NULL;
PFNGLFENCESYNCPROC glad_es_30_glFenceSync = NULL;
PFNGLFINISHPROC glad_es_30_glFinish = NULL;
PFNGLFLUSHPROC glad_es_30_glFlush = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glad_es_30_glFlushMappedBufferRange = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glad_es_30_glFramebufferRenderbuffer = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC glad_es_30_glFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glad_es_30_glFramebufferTextureLayer = NULL;
PFNGLFRONTFACEPROC glad_es_30_glFrontFace = NULL;
PFNGLGENBUFFERSPROC glad_es_30_glGenBuffers = NULL;
PFNGLGENFRAMEBUFFERSPROC glad_es_30_glGenFramebuffers = NULL;
PFNGLGENQUERIESPROC glad_es_30_glGenQueries = NULL;
PFNGLGENRENDERBUFFERSPROC glad_es_30_glGenRenderbuffers = NULL;
PFNGLGENSAMPLERSPROC glad_es_30_glGenSamplers = NULL;
PFNGLGENTEXTURESPROC glad_es_30_glGenTextures = NULL;
PFNGLGENTRANSFORMFEEDBACKSPROC glad_es_30_glGenTransformFeedbacks = NULL;
PFNGLGENVERTEXARRAYSPROC glad_es_30_glGenVertexArrays = NULL;
PFNGLGENERATEMIPMAPPROC glad_es_30_glGenerateMipmap = NULL;
PFNGLGETACTIVEATTRIBPROC glad_es_30_glGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC glad_es_30_glGetActiveUniform = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glad_es_30_glGetActiveUniformBlockName = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glad_es_30_glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC glad_es_30_glGetActiveUniformsiv = NULL;
PFNGLGETATTACHEDSHADERSPROC glad_es_30_glGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC glad_es_30_glGetAttribLocation = NULL;
PFNGLGETBOOLEANVPROC glad_es_30_glGetBooleanv = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC glad_es_30_glGetBufferParameteri64v = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glad_es_30_glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glad_es_30_glGetBufferPointerv = NULL;
PFNGLGETERRORPROC glad_es_30_glGetError = NULL;
PFNGLGETFLOATVPROC glad_es_30_glGetFloatv = NULL;
PFNGLGETFRAGDATALOCATIONPROC glad_es_30_glGetFragDataLocation = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glad_es_30_glGetFramebufferAttachmentParameteriv = NULL;
PFNGLGETINTEGER64I_VPROC glad_es_30_glGetInteger64i_v = NULL;
PFNGLGETINTEGER64VPROC glad_es_30_glGetInteger64v = NULL;
PFNGLGETINTEGERI_VPROC glad_es_30_glGetIntegeri_v = NULL;
PFNGLGETINTEGERVPROC glad_es_30_glGetIntegerv = NULL;
PFNGLGETINTERNALFORMATIVPROC glad_es_30_glGetInternalformativ = NULL;
PFNGLGETPROGRAMBINARYPROC glad_es_30_glGetProgramBinary = NULL;
PFNGLGETPROGRAMINFOLOGPROC glad_es_30_glGetProgramInfoLog = NULL;
PFNGLGETPROGRAMIVPROC glad_es_30_glGetProgramiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glad_es_30_glGetQueryObjectuiv = NULL;
PFNGLGETQUERYIVPROC glad_es_30_glGetQueryiv = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glad_es_30_glGetRenderbufferParameteriv = NULL;
PFNGLGETSAMPLERPARAMETERFVPROC glad_es_30_glGetSamplerParameterfv = NULL;
PFNGLGETSAMPLERPARAMETERIVPROC glad_es_30_glGetSamplerParameteriv = NULL;
PFNGLGETSHADERINFOLOGPROC glad_es_30_glGetShaderInfoLog = NULL;
PFNGLGETSHADERPRECISIONFORMATPROC glad_es_30_glGetShaderPrecisionFormat = NULL;
PFNGLGETSHADERSOURCEPROC glad_es_30_glGetShaderSource = NULL;
PFNGLGETSHADERIVPROC glad_es_30_glGetShaderiv = NULL;
PFNGLGETSTRINGPROC glad_es_30_glGetString = NULL;
PFNGLGETSTRINGIPROC glad_es_30_glGetStringi = NULL;
PFNGLGETSYNCIVPROC glad_es_30_glGetSynciv = NULL;
PFNGLGETTEXPARAMETERFVPROC glad_es_30_glGetTexParameterfv = NULL;
PFNGLGETTEXPARAMETERIVPROC glad_es_30_glGetTexParameteriv = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glad_es_30_glGetTransformFeedbackVarying = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC glad_es_30_glGetUniformBlockIndex = NULL;
PFNGLGETUNIFORMINDICESPROC glad_es_30_glGetUniformIndices = NULL;
PFNGLGETUNIFORMLOCATIONPROC glad_es_30_glGetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC glad_es_30_glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glad_es_30_glGetUniformiv = NULL;
PFNGLGETUNIFORMUIVPROC glad_es_30_glGetUniformuiv = NULL;
PFNGLGETVERTEXATTRIBIIVPROC glad_es_30_glGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIVPROC glad_es_30_glGetVertexAttribIuiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glad_es_30_glGetVertexAttribPointerv = NULL;
PFNGLGETVERTEXATTRIBFVPROC glad_es_30_glGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC glad_es_30_glGetVertexAttribiv = NULL;
PFNGLHINTPROC glad_es_30_glHint = NULL;
PFNGLINVALIDATEFRAMEBUFFERPROC glad_es_30_glInvalidateFramebuffer = NULL;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glad_es_30_glInvalidateSubFramebuffer = NULL;
PFNGLISBUFFERPROC glad_es_30_glIsBuffer = NULL;
PFNGLISENABLEDPROC glad_es_30_glIsEnabled = NULL;
PFNGLISFRAMEBUFFERPROC glad_es_30_glIsFramebuffer = NULL;
PFNGLISPROGRAMPROC glad_es_30_glIsProgram = NULL;
PFNGLISQUERYPROC glad_es_30_glIsQuery = NULL;
PFNGLISRENDERBUFFERPROC glad_es_30_glIsRenderbuffer = NULL;
PFNGLISSAMPLERPROC glad_es_30_glIsSampler = NULL;
PFNGLISSHADERPROC glad_es_30_glIsShader = NULL;
PFNGLISSYNCPROC glad_es_30_glIsSync = NULL;
PFNGLISTEXTUREPROC glad_es_30_glIsTexture = NULL;
PFNGLISTRANSFORMFEEDBACKPROC glad_es_30_glIsTransformFeedback = NULL;
PFNGLISVERTEXARRAYPROC glad_es_30_glIsVertexArray = NULL;
PFNGLLINEWIDTHPROC glad_es_30_glLineWidth = NULL;
PFNGLLINKPROGRAMPROC glad_es_30_glLinkProgram = NULL;
PFNGLMAPBUFFERRANGEPROC glad_es_30_glMapBufferRange = NULL;
PFNGLPAUSETRANSFORMFEEDBACKPROC glad_es_30_glPauseTransformFeedback = NULL;
PFNGLPIXELSTOREIPROC glad_es_30_glPixelStorei = NULL;
PFNGLPOLYGONOFFSETPROC glad_es_30_glPolygonOffset = NULL;
PFNGLPROGRAMBINARYPROC glad_es_30_glProgramBinary = NULL;
PFNGLPROGRAMPARAMETERIPROC glad_es_30_glProgramParameteri = NULL;
PFNGLREADBUFFERPROC glad_es_30_glReadBuffer = NULL;
PFNGLREADPIXELSPROC glad_es_30_glReadPixels = NULL;
PFNGLRELEASESHADERCOMPILERPROC glad_es_30_glReleaseShaderCompiler = NULL;
PFNGLRENDERBUFFERSTORAGEPROC glad_es_30_glRenderbufferStorage = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glad_es_30_glRenderbufferStorageMultisample = NULL;
PFNGLRESUMETRANSFORMFEEDBACKPROC glad_es_30_glResumeTransformFeedback = NULL;
PFNGLSAMPLECOVERAGEPROC glad_es_30_glSampleCoverage = NULL;
PFNGLSAMPLERPARAMETERFPROC glad_es_30_glSamplerParameterf = NULL;
PFNGLSAMPLERPARAMETERFVPROC glad_es_30_glSamplerParameterfv = NULL;
PFNGLSAMPLERPARAMETERIPROC glad_es_30_glSamplerParameteri = NULL;
PFNGLSAMPLERPARAMETERIVPROC glad_es_30_glSamplerParameteriv = NULL;
PFNGLSCISSORPROC glad_es_30_glScissor = NULL;
PFNGLSHADERBINARYPROC glad_es_30_glShaderBinary = NULL;
PFNGLSHADERSOURCEPROC glad_es_30_glShaderSource = NULL;
PFNGLSTENCILFUNCPROC glad_es_30_glStencilFunc = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glad_es_30_glStencilFuncSeparate = NULL;
PFNGLSTENCILMASKPROC glad_es_30_glStencilMask = NULL;
PFNGLSTENCILMASKSEPARATEPROC glad_es_30_glStencilMaskSeparate = NULL;
PFNGLSTENCILOPPROC glad_es_30_glStencilOp = NULL;
PFNGLSTENCILOPSEPARATEPROC glad_es_30_glStencilOpSeparate = NULL;
PFNGLTEXIMAGE2DPROC glad_es_30_glTexImage2D = NULL;
PFNGLTEXIMAGE3DPROC glad_es_30_glTexImage3D = NULL;
PFNGLTEXPARAMETERFPROC glad_es_30_glTexParameterf = NULL;
PFNGLTEXPARAMETERFVPROC glad_es_30_glTexParameterfv = NULL;
PFNGLTEXPARAMETERIPROC glad_es_30_glTexParameteri = NULL;
PFNGLTEXPARAMETERIVPROC glad_es_30_glTexParameteriv = NULL;
PFNGLTEXSTORAGE2DPROC glad_es_30_glTexStorage2D = NULL;
PFNGLTEXSTORAGE3DPROC glad_es_30_glTexStorage3D = NULL;
PFNGLTEXSUBIMAGE2DPROC glad_es_30_glTexSubImage2D = NULL;
PFNGLTEXSUBIMAGE3DPROC glad_es_30_glTexSubImage3D = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glad_es_30_glTransformFeedbackVaryings = NULL;
PFNGLUNIFORM1FPROC glad_es_30_glUniform1f = NULL;
PFNGLUNIFORM1FVPROC glad_es_30_glUniform1fv = NULL;
PFNGLUNIFORM1IPROC glad_es_30_glUniform1i = NULL;
PFNGLUNIFORM1IVPROC glad_es_30_glUniform1iv = NULL;
PFNGLUNIFORM1UIPROC glad_es_30_glUniform1ui = NULL;
PFNGLUNIFORM1UIVPROC glad_es_30_glUniform1uiv = NULL;
PFNGLUNIFORM2FPROC glad_es_30_glUniform2f = NULL;
PFNGLUNIFORM2FVPROC glad_es_30_glUniform2fv = NULL;
PFNGLUNIFORM2IPROC glad_es_30_glUniform2i = NULL;
PFNGLUNIFORM2IVPROC glad_es_30_glUniform2iv = NULL;
PFNGLUNIFORM2UIPROC glad_es_30_glUniform2ui = NULL;
PFNGLUNIFORM2UIVPROC glad_es_30_glUniform2uiv = NULL;
PFNGLUNIFORM3FPROC glad_es_30_glUniform3f = NULL;
PFNGLUNIFORM3FVPROC glad_es_30_glUniform3fv = NULL;
PFNGLUNIFORM3IPROC glad_es_30_glUniform3i = NULL;
PFNGLUNIFORM3IVPROC glad_es_30_glUniform3iv = NULL;
PFNGLUNIFORM3UIPROC glad_es_30_glUniform3ui = NULL;
PFNGLUNIFORM3UIVPROC glad_es_30_glUniform3uiv = NULL;
PFNGLUNIFORM4FPROC glad_es_30_glUniform4f = NULL;
PFNGLUNIFORM4FVPROC glad_es_30_glUniform4fv = NULL;
PFNGLUNIFORM4IPROC glad_es_30_glUniform4i = NULL;
PFNGLUNIFORM4IVPROC glad_es_30_glUniform4iv = NULL;
PFNGLUNIFORM4UIPROC glad_es_30_glUniform4ui = NULL;
PFNGLUNIFORM4UIVPROC glad_es_30_glUniform4uiv = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC glad_es_30_glUniformBlockBinding = NULL;
PFNGLUNIFORMMATRIX2FVPROC glad_es_30_glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX2X3FVPROC glad_es_30_glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glad_es_30_glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glad_es_30_glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glad_es_30_glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glad_es_30_glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glad_es_30_glUniformMatrix4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glad_es_30_glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glad_es_30_glUniformMatrix4x3fv = NULL;
PFNGLUNMAPBUFFERPROC glad_es_30_glUnmapBuffer = NULL;
PFNGLUSEPROGRAMPROC glad_es_30_glUseProgram = NULL;
PFNGLVALIDATEPROGRAMPROC glad_es_30_glValidateProgram = NULL;
PFNGLVERTEXATTRIB1FPROC glad_es_30_glVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC glad_es_30_glVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB2FPROC glad_es_30_glVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC glad_es_30_glVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB3FPROC glad_es_30_glVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC glad_es_30_glVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB4FPROC glad_es_30_glVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC glad_es_30_glVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIBDIVISORPROC glad_es_30_glVertexAttribDivisor = NULL;
PFNGLVERTEXATTRIBI4IPROC glad_es_30_glVertexAttribI4i = NULL;
PFNGLVERTEXATTRIBI4IVPROC glad_es_30_glVertexAttribI4iv = NULL;
PFNGLVERTEXATTRIBI4UIPROC glad_es_30_glVertexAttribI4ui = NULL;
PFNGLVERTEXATTRIBI4UIVPROC glad_es_30_glVertexAttribI4uiv = NULL;
PFNGLVERTEXATTRIBIPOINTERPROC glad_es_30_glVertexAttribIPointer = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glad_es_30_glVertexAttribPointer = NULL;
PFNGLVIEWPORTPROC glad_es_30_glViewport = NULL;
PFNGLWAITSYNCPROC glad_es_30_glWaitSync = NULL;


static void glad_es_30_gl_load_GL_ES_VERSION_2_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_ES_30_GL_ES_VERSION_2_0) return;
    glad_es_30_glActiveTexture = (PFNGLACTIVETEXTUREPROC) load(userptr, "glActiveTexture");
    glad_es_30_glAttachShader = (PFNGLATTACHSHADERPROC) load(userptr, "glAttachShader");
    glad_es_30_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) load(userptr, "glBindAttribLocation");
    glad_es_30_glBindBuffer = (PFNGLBINDBUFFERPROC) load(userptr, "glBindBuffer");
    glad_es_30_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) load(userptr, "glBindFramebuffer");
    glad_es_30_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) load(userptr, "glBindRenderbuffer");
    glad_es_30_glBindTexture = (PFNGLBINDTEXTUREPROC) load(userptr, "glBindTexture");
    glad_es_30_glBlendColor = (PFNGLBLENDCOLORPROC) load(userptr, "glBlendColor");
    glad_es_30_glBlendEquation = (PFNGLBLENDEQUATIONPROC) load(userptr, "glBlendEquation");
    glad_es_30_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) load(userptr, "glBlendEquationSeparate");
    glad_es_30_glBlendFunc = (PFNGLBLENDFUNCPROC) load(userptr, "glBlendFunc");
    glad_es_30_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) load(userptr, "glBlendFuncSeparate");
    glad_es_30_glBufferData = (PFNGLBUFFERDATAPROC) load(userptr, "glBufferData");
    glad_es_30_glBufferSubData = (PFNGLBUFFERSUBDATAPROC) load(userptr, "glBufferSubData");
    glad_es_30_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) load(userptr, "glCheckFramebufferStatus");
    glad_es_30_glClear = (PFNGLCLEARPROC) load(userptr, "glClear");
    glad_es_30_glClearColor = (PFNGLCLEARCOLORPROC) load(userptr, "glClearColor");
    glad_es_30_glClearDepthf = (PFNGLCLEARDEPTHFPROC) load(userptr, "glClearDepthf");
    glad_es_30_glClearStencil = (PFNGLCLEARSTENCILPROC) load(userptr, "glClearStencil");
    glad_es_30_glColorMask = (PFNGLCOLORMASKPROC) load(userptr, "glColorMask");
    glad_es_30_glCompileShader = (PFNGLCOMPILESHADERPROC) load(userptr, "glCompileShader");
    glad_es_30_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) load(userptr, "glCompressedTexImage2D");
    glad_es_30_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) load(userptr, "glCompressedTexSubImage2D");
    glad_es_30_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) load(userptr, "glCopyTexImage2D");
    glad_es_30_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) load(userptr, "glCopyTexSubImage2D");
    glad_es_30_glCreateProgram = (PFNGLCREATEPROGRAMPROC) load(userptr, "glCreateProgram");
    glad_es_30_glCreateShader = (PFNGLCREATESHADERPROC) load(userptr, "glCreateShader");
    glad_es_30_glCullFace = (PFNGLCULLFACEPROC) load(userptr, "glCullFace");
    glad_es_30_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) load(userptr, "glDeleteBuffers");
    glad_es_30_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) load(userptr, "glDeleteFramebuffers");
    glad_es_30_glDeleteProgram = (PFNGLDELETEPROGRAMPROC) load(userptr, "glDeleteProgram");
    glad_es_30_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) load(userptr, "glDeleteRenderbuffers");
    glad_es_30_glDeleteShader = (PFNGLDELETESHADERPROC) load(userptr, "glDeleteShader");
    glad_es_30_glDeleteTextures = (PFNGLDELETETEXTURESPROC) load(userptr, "glDeleteTextures");
    glad_es_30_glDepthFunc = (PFNGLDEPTHFUNCPROC) load(userptr, "glDepthFunc");
    glad_es_30_glDepthMask = (PFNGLDEPTHMASKPROC) load(userptr, "glDepthMask");
    glad_es_30_glDepthRangef = (PFNGLDEPTHRANGEFPROC) load(userptr, "glDepthRangef");
    glad_es_30_glDetachShader = (PFNGLDETACHSHADERPROC) load(userptr, "glDetachShader");
    glad_es_30_glDisable = (PFNGLDISABLEPROC) load(userptr, "glDisable");
    glad_es_30_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) load(userptr, "glDisableVertexAttribArray");
    glad_es_30_glDrawArrays = (PFNGLDRAWARRAYSPROC) load(userptr, "glDrawArrays");
    glad_es_30_glDrawElements = (PFNGLDRAWELEMENTSPROC) load(userptr, "glDrawElements");
    glad_es_30_glEnable = (PFNGLENABLEPROC) load(userptr, "glEnable");
    glad_es_30_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) load(userptr, "glEnableVertexAttribArray");
    glad_es_30_glFinish = (PFNGLFINISHPROC) load(userptr, "glFinish");
    glad_es_30_glFlush = (PFNGLFLUSHPROC) load(userptr, "glFlush");
    glad_es_30_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) load(userptr, "glFramebufferRenderbuffer");
    glad_es_30_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) load(userptr, "glFramebufferTexture2D");
    glad_es_30_glFrontFace = (PFNGLFRONTFACEPROC) load(userptr, "glFrontFace");
    glad_es_30_glGenBuffers = (PFNGLGENBUFFERSPROC) load(userptr, "glGenBuffers");
    glad_es_30_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) load(userptr, "glGenFramebuffers");
    glad_es_30_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) load(userptr, "glGenRenderbuffers");
    glad_es_30_glGenTextures = (PFNGLGENTEXTURESPROC) load(userptr, "glGenTextures");
    glad_es_30_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) load(userptr, "glGenerateMipmap");
    glad_es_30_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) load(userptr, "glGetActiveAttrib");
    glad_es_30_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) load(userptr, "glGetActiveUniform");
    glad_es_30_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) load(userptr, "glGetAttachedShaders");
    glad_es_30_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) load(userptr, "glGetAttribLocation");
    glad_es_30_glGetBooleanv = (PFNGLGETBOOLEANVPROC) load(userptr, "glGetBooleanv");
    glad_es_30_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) load(userptr, "glGetBufferParameteriv");
    glad_es_30_glGetError = (PFNGLGETERRORPROC) load(userptr, "glGetError");
    glad_es_30_glGetFloatv = (PFNGLGETFLOATVPROC) load(userptr, "glGetFloatv");
    glad_es_30_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) load(userptr, "glGetFramebufferAttachmentParameteriv");
    glad_es_30_glGetIntegerv = (PFNGLGETINTEGERVPROC) load(userptr, "glGetIntegerv");
    glad_es_30_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) load(userptr, "glGetProgramInfoLog");
    glad_es_30_glGetProgramiv = (PFNGLGETPROGRAMIVPROC) load(userptr, "glGetProgramiv");
    glad_es_30_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC) load(userptr, "glGetRenderbufferParameteriv");
    glad_es_30_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) load(userptr, "glGetShaderInfoLog");
    glad_es_30_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC) load(userptr, "glGetShaderPrecisionFormat");
    glad_es_30_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) load(userptr, "glGetShaderSource");
    glad_es_30_glGetShaderiv = (PFNGLGETSHADERIVPROC) load(userptr, "glGetShaderiv");
    glad_es_30_glGetString = (PFNGLGETSTRINGPROC) load(userptr, "glGetString");
    glad_es_30_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) load(userptr, "glGetTexParameterfv");
    glad_es_30_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) load(userptr, "glGetTexParameteriv");
    glad_es_30_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) load(userptr, "glGetUniformLocation");
    glad_es_30_glGetUniformfv = (PFNGLGETUNIFORMFVPROC) load(userptr, "glGetUniformfv");
    glad_es_30_glGetUniformiv = (PFNGLGETUNIFORMIVPROC) load(userptr, "glGetUniformiv");
    glad_es_30_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) load(userptr, "glGetVertexAttribPointerv");
    glad_es_30_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) load(userptr, "glGetVertexAttribfv");
    glad_es_30_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) load(userptr, "glGetVertexAttribiv");
    glad_es_30_glHint = (PFNGLHINTPROC) load(userptr, "glHint");
    glad_es_30_glIsBuffer = (PFNGLISBUFFERPROC) load(userptr, "glIsBuffer");
    glad_es_30_glIsEnabled = (PFNGLISENABLEDPROC) load(userptr, "glIsEnabled");
    glad_es_30_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC) load(userptr, "glIsFramebuffer");
    glad_es_30_glIsProgram = (PFNGLISPROGRAMPROC) load(userptr, "glIsProgram");
    glad_es_30_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC) load(userptr, "glIsRenderbuffer");
    glad_es_30_glIsShader = (PFNGLISSHADERPROC) load(userptr, "glIsShader");
    glad_es_30_glIsTexture = (PFNGLISTEXTUREPROC) load(userptr, "glIsTexture");
    glad_es_30_glLineWidth = (PFNGLLINEWIDTHPROC) load(userptr, "glLineWidth");
    glad_es_30_glLinkProgram = (PFNGLLINKPROGRAMPROC) load(userptr, "glLinkProgram");
    glad_es_30_glPixelStorei = (PFNGLPIXELSTOREIPROC) load(userptr, "glPixelStorei");
    glad_es_30_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC) load(userptr, "glPolygonOffset");
    glad_es_30_glReadPixels = (PFNGLREADPIXELSPROC) load(userptr, "glReadPixels");
    glad_es_30_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC) load(userptr, "glReleaseShaderCompiler");
    glad_es_30_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) load(userptr, "glRenderbufferStorage");
    glad_es_30_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) load(userptr, "glSampleCoverage");
    glad_es_30_glScissor = (PFNGLSCISSORPROC) load(userptr, "glScissor");
    glad_es_30_glShaderBinary = (PFNGLSHADERBINARYPROC) load(userptr, "glShaderBinary");
    glad_es_30_glShaderSource = (PFNGLSHADERSOURCEPROC) load(userptr, "glShaderSource");
    glad_es_30_glStencilFunc = (PFNGLSTENCILFUNCPROC) load(userptr, "glStencilFunc");
    glad_es_30_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) load(userptr, "glStencilFuncSeparate");
    glad_es_30_glStencilMask = (PFNGLSTENCILMASKPROC) load(userptr, "glStencilMask");
    glad_es_30_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) load(userptr, "glStencilMaskSeparate");
    glad_es_30_glStencilOp = (PFNGLSTENCILOPPROC) load(userptr, "glStencilOp");
    glad_es_30_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) load(userptr, "glStencilOpSeparate");
    glad_es_30_glTexImage2D = (PFNGLTEXIMAGE2DPROC) load(userptr, "glTexImage2D");
    glad_es_30_glTexParameterf = (PFNGLTEXPARAMETERFPROC) load(userptr, "glTexParameterf");
    glad_es_30_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC) load(userptr, "glTexParameterfv");
    glad_es_30_glTexParameteri = (PFNGLTEXPARAMETERIPROC) load(userptr, "glTexParameteri");
    glad_es_30_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC) load(userptr, "glTexParameteriv");
    glad_es_30_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) load(userptr, "glTexSubImage2D");
    glad_es_30_glUniform1f = (PFNGLUNIFORM1FPROC) load(userptr, "glUniform1f");
    glad_es_30_glUniform1fv = (PFNGLUNIFORM1FVPROC) load(userptr, "glUniform1fv");
    glad_es_30_glUniform1i = (PFNGLUNIFORM1IPROC) load(userptr, "glUniform1i");
    glad_es_30_glUniform1iv = (PFNGLUNIFORM1IVPROC) load(userptr, "glUniform1iv");
    glad_es_30_glUniform2f = (PFNGLUNIFORM2FPROC) load(userptr, "glUniform2f");
    glad_es_30_glUniform2fv = (PFNGLUNIFORM2FVPROC) load(userptr, "glUniform2fv");
    glad_es_30_glUniform2i = (PFNGLUNIFORM2IPROC) load(userptr, "glUniform2i");
    glad_es_30_glUniform2iv = (PFNGLUNIFORM2IVPROC) load(userptr, "glUniform2iv");
    glad_es_30_glUniform3f = (PFNGLUNIFORM3FPROC) load(userptr, "glUniform3f");
    glad_es_30_glUniform3fv = (PFNGLUNIFORM3FVPROC) load(userptr, "glUniform3fv");
    glad_es_30_glUniform3i = (PFNGLUNIFORM3IPROC) load(userptr, "glUniform3i");
    glad_es_30_glUniform3iv = (PFNGLUNIFORM3IVPROC) load(userptr, "glUniform3iv");
    glad_es_30_glUniform4f = (PFNGLUNIFORM4FPROC) load(userptr, "glUniform4f");
    glad_es_30_glUniform4fv = (PFNGLUNIFORM4FVPROC) load(userptr, "glUniform4fv");
    glad_es_30_glUniform4i = (PFNGLUNIFORM4IPROC) load(userptr, "glUniform4i");
    glad_es_30_glUniform4iv = (PFNGLUNIFORM4IVPROC) load(userptr, "glUniform4iv");
    glad_es_30_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) load(userptr, "glUniformMatrix2fv");
    glad_es_30_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) load(userptr, "glUniformMatrix3fv");
    glad_es_30_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) load(userptr, "glUniformMatrix4fv");
    glad_es_30_glUseProgram = (PFNGLUSEPROGRAMPROC) load(userptr, "glUseProgram");
    glad_es_30_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) load(userptr, "glValidateProgram");
    glad_es_30_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) load(userptr, "glVertexAttrib1f");
    glad_es_30_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) load(userptr, "glVertexAttrib1fv");
    glad_es_30_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) load(userptr, "glVertexAttrib2f");
    glad_es_30_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) load(userptr, "glVertexAttrib2fv");
    glad_es_30_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) load(userptr, "glVertexAttrib3f");
    glad_es_30_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) load(userptr, "glVertexAttrib3fv");
    glad_es_30_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) load(userptr, "glVertexAttrib4f");
    glad_es_30_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) load(userptr, "glVertexAttrib4fv");
    glad_es_30_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) load(userptr, "glVertexAttribPointer");
    glad_es_30_glViewport = (PFNGLVIEWPORTPROC) load(userptr, "glViewport");
}
static void glad_es_30_gl_load_GL_ES_VERSION_3_0( GLADuserptrloadfunc load, void* userptr) {
    if(!GLAD_ES_30_GL_ES_VERSION_3_0) return;
    glad_es_30_glBeginQuery = (PFNGLBEGINQUERYPROC) load(userptr, "glBeginQuery");
    glad_es_30_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC) load(userptr, "glBeginTransformFeedback");
    glad_es_30_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC) load(userptr, "glBindBufferBase");
    glad_es_30_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC) load(userptr, "glBindBufferRange");
    glad_es_30_glBindSampler = (PFNGLBINDSAMPLERPROC) load(userptr, "glBindSampler");
    glad_es_30_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC) load(userptr, "glBindTransformFeedback");
    glad_es_30_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) load(userptr, "glBindVertexArray");
    glad_es_30_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC) load(userptr, "glBlitFramebuffer");
    glad_es_30_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC) load(userptr, "glClearBufferfi");
    glad_es_30_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC) load(userptr, "glClearBufferfv");
    glad_es_30_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC) load(userptr, "glClearBufferiv");
    glad_es_30_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC) load(userptr, "glClearBufferuiv");
    glad_es_30_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC) load(userptr, "glClientWaitSync");
    glad_es_30_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) load(userptr, "glCompressedTexImage3D");
    glad_es_30_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) load(userptr, "glCompressedTexSubImage3D");
    glad_es_30_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC) load(userptr, "glCopyBufferSubData");
    glad_es_30_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) load(userptr, "glCopyTexSubImage3D");
    glad_es_30_glDeleteQueries = (PFNGLDELETEQUERIESPROC) load(userptr, "glDeleteQueries");
    glad_es_30_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC) load(userptr, "glDeleteSamplers");
    glad_es_30_glDeleteSync = (PFNGLDELETESYNCPROC) load(userptr, "glDeleteSync");
    glad_es_30_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC) load(userptr, "glDeleteTransformFeedbacks");
    glad_es_30_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) load(userptr, "glDeleteVertexArrays");
    glad_es_30_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC) load(userptr, "glDrawArraysInstanced");
    glad_es_30_glDrawBuffers = (PFNGLDRAWBUFFERSPROC) load(userptr, "glDrawBuffers");
    glad_es_30_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC) load(userptr, "glDrawElementsInstanced");
    glad_es_30_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) load(userptr, "glDrawRangeElements");
    glad_es_30_glEndQuery = (PFNGLENDQUERYPROC) load(userptr, "glEndQuery");
    glad_es_30_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC) load(userptr, "glEndTransformFeedback");
    glad_es_30_glFenceSync = (PFNGLFENCESYNCPROC) load(userptr, "glFenceSync");
    glad_es_30_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC) load(userptr, "glFlushMappedBufferRange");
    glad_es_30_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC) load(userptr, "glFramebufferTextureLayer");
    glad_es_30_glGenQueries = (PFNGLGENQUERIESPROC) load(userptr, "glGenQueries");
    glad_es_30_glGenSamplers = (PFNGLGENSAMPLERSPROC) load(userptr, "glGenSamplers");
    glad_es_30_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC) load(userptr, "glGenTransformFeedbacks");
    glad_es_30_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) load(userptr, "glGenVertexArrays");
    glad_es_30_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) load(userptr, "glGetActiveUniformBlockName");
    glad_es_30_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC) load(userptr, "glGetActiveUniformBlockiv");
    glad_es_30_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC) load(userptr, "glGetActiveUniformsiv");
    glad_es_30_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC) load(userptr, "glGetBufferParameteri64v");
    glad_es_30_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) load(userptr, "glGetBufferPointerv");
    glad_es_30_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC) load(userptr, "glGetFragDataLocation");
    glad_es_30_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC) load(userptr, "glGetInteger64i_v");
    glad_es_30_glGetInteger64v = (PFNGLGETINTEGER64VPROC) load(userptr, "glGetInteger64v");
    glad_es_30_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC) load(userptr, "glGetIntegeri_v");
    glad_es_30_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC) load(userptr, "glGetInternalformativ");
    glad_es_30_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC) load(userptr, "glGetProgramBinary");
    glad_es_30_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) load(userptr, "glGetQueryObjectuiv");
    glad_es_30_glGetQueryiv = (PFNGLGETQUERYIVPROC) load(userptr, "glGetQueryiv");
    glad_es_30_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC) load(userptr, "glGetSamplerParameterfv");
    glad_es_30_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC) load(userptr, "glGetSamplerParameteriv");
    glad_es_30_glGetStringi = (PFNGLGETSTRINGIPROC) load(userptr, "glGetStringi");
    glad_es_30_glGetSynciv = (PFNGLGETSYNCIVPROC) load(userptr, "glGetSynciv");
    glad_es_30_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) load(userptr, "glGetTransformFeedbackVarying");
    glad_es_30_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) load(userptr, "glGetUniformBlockIndex");
    glad_es_30_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC) load(userptr, "glGetUniformIndices");
    glad_es_30_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC) load(userptr, "glGetUniformuiv");
    glad_es_30_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC) load(userptr, "glGetVertexAttribIiv");
    glad_es_30_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC) load(userptr, "glGetVertexAttribIuiv");
    glad_es_30_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC) load(userptr, "glInvalidateFramebuffer");
    glad_es_30_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC) load(userptr, "glInvalidateSubFramebuffer");
    glad_es_30_glIsQuery = (PFNGLISQUERYPROC) load(userptr, "glIsQuery");
    glad_es_30_glIsSampler = (PFNGLISSAMPLERPROC) load(userptr, "glIsSampler");
    glad_es_30_glIsSync = (PFNGLISSYNCPROC) load(userptr, "glIsSync");
    glad_es_30_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC) load(userptr, "glIsTransformFeedback");
    glad_es_30_glIsVertexArray = (PFNGLISVERTEXARRAYPROC) load(userptr, "glIsVertexArray");
    glad_es_30_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC) load(userptr, "glMapBufferRange");
    glad_es_30_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC) load(userptr, "glPauseTransformFeedback");
    glad_es_30_glProgramBinary = (PFNGLPROGRAMBINARYPROC) load(userptr, "glProgramBinary");
    glad_es_30_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC) load(userptr, "glProgramParameteri");
    glad_es_30_glReadBuffer = (PFNGLREADBUFFERPROC) load(userptr, "glReadBuffer");
    glad_es_30_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) load(userptr, "glRenderbufferStorageMultisample");
    glad_es_30_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC) load(userptr, "glResumeTransformFeedback");
    glad_es_30_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC) load(userptr, "glSamplerParameterf");
    glad_es_30_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC) load(userptr, "glSamplerParameterfv");
    glad_es_30_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC) load(userptr, "glSamplerParameteri");
    glad_es_30_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC) load(userptr, "glSamplerParameteriv");
    glad_es_30_glTexImage3D = (PFNGLTEXIMAGE3DPROC) load(userptr, "glTexImage3D");
    glad_es_30_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC) load(userptr, "glTexStorage2D");
    glad_es_30_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC) load(userptr, "glTexStorage3D");
    glad_es_30_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) load(userptr, "glTexSubImage3D");
    glad_es_30_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC) load(userptr, "glTransformFeedbackVaryings");
    glad_es_30_glUniform1ui = (PFNGLUNIFORM1UIPROC) load(userptr, "glUniform1ui");
    glad_es_30_glUniform1uiv = (PFNGLUNIFORM1UIVPROC) load(userptr, "glUniform1uiv");
    glad_es_30_glUniform2ui = (PFNGLUNIFORM2UIPROC) load(userptr, "glUniform2ui");
    glad_es_30_glUniform2uiv = (PFNGLUNIFORM2UIVPROC) load(userptr, "glUniform2uiv");
    glad_es_30_glUniform3ui = (PFNGLUNIFORM3UIPROC) load(userptr, "glUniform3ui");
    glad_es_30_glUniform3uiv = (PFNGLUNIFORM3UIVPROC) load(userptr, "glUniform3uiv");
    glad_es_30_glUniform4ui = (PFNGLUNIFORM4UIPROC) load(userptr, "glUniform4ui");
    glad_es_30_glUniform4uiv = (PFNGLUNIFORM4UIVPROC) load(userptr, "glUniform4uiv");
    glad_es_30_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) load(userptr, "glUniformBlockBinding");
    glad_es_30_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) load(userptr, "glUniformMatrix2x3fv");
    glad_es_30_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) load(userptr, "glUniformMatrix2x4fv");
    glad_es_30_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) load(userptr, "glUniformMatrix3x2fv");
    glad_es_30_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) load(userptr, "glUniformMatrix3x4fv");
    glad_es_30_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) load(userptr, "glUniformMatrix4x2fv");
    glad_es_30_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) load(userptr, "glUniformMatrix4x3fv");
    glad_es_30_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC) load(userptr, "glUnmapBuffer");
    glad_es_30_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC) load(userptr, "glVertexAttribDivisor");
    glad_es_30_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC) load(userptr, "glVertexAttribI4i");
    glad_es_30_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC) load(userptr, "glVertexAttribI4iv");
    glad_es_30_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC) load(userptr, "glVertexAttribI4ui");
    glad_es_30_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC) load(userptr, "glVertexAttribI4uiv");
    glad_es_30_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC) load(userptr, "glVertexAttribIPointer");
    glad_es_30_glWaitSync = (PFNGLWAITSYNCPROC) load(userptr, "glWaitSync");
}



#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
#define GLAD_GL_IS_SOME_NEW_VERSION 1
#else
#define GLAD_GL_IS_SOME_NEW_VERSION 0
#endif

static int glad_es_30_gl_get_extensions( int version, const char **out_exts, unsigned int *out_num_exts_i, char ***out_exts_i) {
#if GLAD_GL_IS_SOME_NEW_VERSION
    if(GLAD_VERSION_MAJOR(version) < 3) {
#else
    (void) version;
    (void) out_num_exts_i;
    (void) out_exts_i;
#endif
        if (glad_es_30_glGetString == NULL) {
            return 0;
        }
        *out_exts = (const char *)glad_es_30_glGetString(GL_EXTENSIONS);
#if GLAD_GL_IS_SOME_NEW_VERSION
    } else {
        unsigned int index = 0;
        unsigned int num_exts_i = 0;
        char **exts_i = NULL;
        if (glad_es_30_glGetStringi == NULL || glad_es_30_glGetIntegerv == NULL) {
            return 0;
        }
        glad_es_30_glGetIntegerv(GL_NUM_EXTENSIONS, (int*) &num_exts_i);
        if (num_exts_i > 0) {
            exts_i = (char **) malloc(num_exts_i * (sizeof *exts_i));
        }
        if (exts_i == NULL) {
            return 0;
        }
        for(index = 0; index < num_exts_i; index++) {
            const char *gl_str_tmp = (const char*) glad_es_30_glGetStringi(GL_EXTENSIONS, index);
            size_t len = strlen(gl_str_tmp) + 1;

            char *local_str = (char*) malloc(len * sizeof(char));
            if(local_str != NULL) {
                memcpy(local_str, gl_str_tmp, len * sizeof(char));
            }

            exts_i[index] = local_str;
        }

        *out_num_exts_i = num_exts_i;
        *out_exts_i = exts_i;
    }
#endif
    return 1;
}
static void glad_es_30_gl_free_extensions(char **exts_i, unsigned int num_exts_i) {
    if (exts_i != NULL) {
        unsigned int index;
        for(index = 0; index < num_exts_i; index++) {
            free((void *) (exts_i[index]));
        }
        free((void *)exts_i);
        exts_i = NULL;
    }
}
static int glad_es_30_gl_has_extension(int version, const char *exts, unsigned int num_exts_i, char **exts_i, const char *ext) {
    if(GLAD_VERSION_MAJOR(version) < 3 || !GLAD_GL_IS_SOME_NEW_VERSION) {
        const char *extensions;
        const char *loc;
        const char *terminator;
        extensions = exts;
        if(extensions == NULL || ext == NULL) {
            return 0;
        }
        while(1) {
            loc = strstr(extensions, ext);
            if(loc == NULL) {
                return 0;
            }
            terminator = loc + strlen(ext);
            if((loc == extensions || *(loc - 1) == ' ') &&
                (*terminator == ' ' || *terminator == '\0')) {
                return 1;
            }
            extensions = terminator;
        }
    } else {
        unsigned int index;
        for(index = 0; index < num_exts_i; index++) {
            const char *e = exts_i[index];
            if(strcmp(e, ext) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

static GLADapiproc glad_es_30_gl_get_proc_from_userptr(void *userptr, const char* name) {
    return (GLAD_GNUC_EXTENSION (GLADapiproc (*)(const char *name)) userptr)(name);
}

static int glad_es_30_gl_find_extensions_gles2( int version) {
    const char *exts = NULL;
    unsigned int num_exts_i = 0;
    char **exts_i = NULL;
    if (!glad_es_30_gl_get_extensions(version, &exts, &num_exts_i, &exts_i)) return 0;

    (void) glad_es_30_gl_has_extension;

    glad_es_30_gl_free_extensions(exts_i, num_exts_i);

    return 1;
}

static int glad_es_30_gl_find_core_gles2(void) {
    int i;
    const char* version;
    const char* prefixes[] = {
        "OpenGL ES-CM ",
        "OpenGL ES-CL ",
        "OpenGL ES ",
        "OpenGL SC ",
        NULL
    };
    int major = 0;
    int minor = 0;
    version = (const char*) glad_es_30_glGetString(GL_VERSION);
    if (!version) return 0;
    for (i = 0;  prefixes[i];  i++) {
        const size_t length = strlen(prefixes[i]);
        if (strncmp(version, prefixes[i], length) == 0) {
            version += length;
            break;
        }
    }

    GLAD_IMPL_UTIL_SSCANF(version, "%d.%d", &major, &minor);

    GLAD_ES_30_GL_ES_VERSION_2_0 = (major == 2 && minor >= 0) || major > 2;
    GLAD_ES_30_GL_ES_VERSION_3_0 = (major == 3 && minor >= 0) || major > 3;

    return GLAD_MAKE_VERSION(major, minor);
}

int gladEs30LoadGLES2UserPtr( GLADuserptrloadfunc load, void *userptr) {
    int version;

    glad_es_30_glGetString = (PFNGLGETSTRINGPROC) load(userptr, "glGetString");
    if(glad_es_30_glGetString == NULL) return 0;
    if(glad_es_30_glGetString(GL_VERSION) == NULL) return 0;
    version = glad_es_30_gl_find_core_gles2();

    glad_es_30_gl_load_GL_ES_VERSION_2_0(load, userptr);
    glad_es_30_gl_load_GL_ES_VERSION_3_0(load, userptr);

    if (!glad_es_30_gl_find_extensions_gles2(version)) return 0;

    return version;
}


int gladEs30LoadGLES2( GLADloadfunc load) {
    return gladEs30LoadGLES2UserPtr( glad_es_30_gl_get_proc_from_userptr, GLAD_GNUC_EXTENSION (void*) load);
}

#ifdef __cplusplus
}
#endif
