#pragma once


// Types used by functions.
#include <wingdi.h>
#include <gl/GL.h>


struct _GPU_DEVICE {
	DWORD  cb;
	CHAR   DeviceName[32];
	CHAR   DeviceString[128];
	DWORD  Flags;
	RECT   rcVirtualScreen;
};

DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);

typedef struct _GPU_DEVICE GPU_DEVICE;
typedef struct _GPU_DEVICE *PGPU_DEVICE;


namespace Wgl
{
	typedef void* (BLACK_GL_API *PFNWGLALLOCATEMEMORYNVPROC)(GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority);
	typedef BOOL (BLACK_GL_API *PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC)(HDC hDC, const HANDLE * pEvent, const LPVOID * pAddress, const DWORD * pSize, UINT count);
	typedef BOOL (BLACK_GL_API *PFNWGLBEGINFRAMETRACKINGI3DPROC)(void);
	typedef GLboolean (BLACK_GL_API *PFNWGLBINDDISPLAYCOLORTABLEEXTPROC)(GLushort id);
	typedef BOOL (BLACK_GL_API *PFNWGLBINDSWAPBARRIERNVPROC)(GLuint group, GLuint barrier);
	typedef BOOL (BLACK_GL_API *PFNWGLBINDTEXIMAGEARBPROC)(HPBUFFERARB hPbuffer, int iBuffer);
	typedef BOOL (BLACK_GL_API *PFNWGLBINDVIDEOCAPTUREDEVICENVPROC)(UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLBINDVIDEODEVICENVPROC)(HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int * piAttribList);
	typedef BOOL (BLACK_GL_API *PFNWGLBINDVIDEOIMAGENVPROC)(HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
	typedef VOID (BLACK_GL_API *PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC)(HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
	typedef BOOL (BLACK_GL_API *PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
	typedef BOOL (BLACK_GL_API *PFNWGLCHOOSEPIXELFORMATEXTPROC)(HDC hdc, const int * piAttribIList, const FLOAT * pfAttribFList, UINT nMaxFormats, int * piFormats, UINT * nNumFormats);
	typedef BOOL (BLACK_GL_API *PFNWGLCOPYIMAGESUBDATANVPROC)(HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
	typedef HDC (BLACK_GL_API *PFNWGLCREATEAFFINITYDCNVPROC)(const HGPUNV * phGpuList);
	typedef HGLRC (BLACK_GL_API *PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC)(UINT id);
	typedef HGLRC (BLACK_GL_API *PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC)(UINT id, HGLRC hShareContext, const int * attribList);
	typedef HANDLE (BLACK_GL_API *PFNWGLCREATEBUFFERREGIONARBPROC)(HDC hDC, int iLayerPlane, UINT uType);
	typedef HGLRC (BLACK_GL_API *PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC hDC, HGLRC hShareContext, const int * attribList);
	typedef GLboolean (BLACK_GL_API *PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC)(GLushort id);
	typedef LPVOID (BLACK_GL_API *PFNWGLCREATEIMAGEBUFFERI3DPROC)(HDC hDC, DWORD dwSize, UINT uFlags);
	typedef HPBUFFERARB (BLACK_GL_API *PFNWGLCREATEPBUFFERARBPROC)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
	typedef HPBUFFEREXT (BLACK_GL_API *PFNWGLCREATEPBUFFEREXTPROC)(HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int * piAttribList);
	typedef BOOL (BLACK_GL_API *PFNWGLDXCLOSEDEVICENVPROC)(HANDLE hDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLDXLOCKOBJECTSNVPROC)(HANDLE hDevice, GLint count, HANDLE * hObjects);
	typedef BOOL (BLACK_GL_API *PFNWGLDXOBJECTACCESSNVPROC)(HANDLE hObject, GLenum access);
	typedef HANDLE (BLACK_GL_API *PFNWGLDXOPENDEVICENVPROC)(void * dxDevice);
	typedef HANDLE (BLACK_GL_API *PFNWGLDXREGISTEROBJECTNVPROC)(HANDLE hDevice, void * dxObject, GLuint name, GLenum type, GLenum access);
	typedef BOOL (BLACK_GL_API *PFNWGLDXSETRESOURCESHAREHANDLENVPROC)(void * dxObject, HANDLE shareHandle);
	typedef BOOL (BLACK_GL_API *PFNWGLDXUNLOCKOBJECTSNVPROC)(HANDLE hDevice, GLint count, HANDLE * hObjects);
	typedef BOOL (BLACK_GL_API *PFNWGLDXUNREGISTEROBJECTNVPROC)(HANDLE hDevice, HANDLE hObject);
	typedef BOOL (BLACK_GL_API *PFNWGLDELAYBEFORESWAPNVPROC)(HDC hDC, GLfloat seconds);
	typedef BOOL (BLACK_GL_API *PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC)(HGLRC hglrc);
	typedef VOID (BLACK_GL_API *PFNWGLDELETEBUFFERREGIONARBPROC)(HANDLE hRegion);
	typedef BOOL (BLACK_GL_API *PFNWGLDELETEDCNVPROC)(HDC hdc);
	typedef VOID (BLACK_GL_API *PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC)(GLushort id);
	typedef BOOL (BLACK_GL_API *PFNWGLDESTROYIMAGEBUFFERI3DPROC)(HDC hDC, LPVOID pAddress);
	typedef BOOL (BLACK_GL_API *PFNWGLDESTROYPBUFFERARBPROC)(HPBUFFERARB hPbuffer);
	typedef BOOL (BLACK_GL_API *PFNWGLDESTROYPBUFFEREXTPROC)(HPBUFFEREXT hPbuffer);
	typedef BOOL (BLACK_GL_API *PFNWGLDISABLEFRAMELOCKI3DPROC)(void);
	typedef BOOL (BLACK_GL_API *PFNWGLDISABLEGENLOCKI3DPROC)(HDC hDC);
	typedef BOOL (BLACK_GL_API *PFNWGLENABLEFRAMELOCKI3DPROC)(void);
	typedef BOOL (BLACK_GL_API *PFNWGLENABLEGENLOCKI3DPROC)(HDC hDC);
	typedef BOOL (BLACK_GL_API *PFNWGLENDFRAMETRACKINGI3DPROC)(void);
	typedef BOOL (BLACK_GL_API *PFNWGLENUMGPUDEVICESNVPROC)(HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLENUMGPUSFROMAFFINITYDCNVPROC)(HDC hAffinityDC, UINT iGpuIndex, HGPUNV * hGpu);
	typedef BOOL (BLACK_GL_API *PFNWGLENUMGPUSNVPROC)(UINT iGpuIndex, HGPUNV * phGpu);
	typedef UINT (BLACK_GL_API *PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC)(HDC hDc, HVIDEOINPUTDEVICENV * phDeviceList);
	typedef int (BLACK_GL_API *PFNWGLENUMERATEVIDEODEVICESNVPROC)(HDC hDc, HVIDEOOUTPUTDEVICENV * phDeviceList);
	typedef void (BLACK_GL_API *PFNWGLFREEMEMORYNVPROC)(void * pointer);
	typedef BOOL (BLACK_GL_API *PFNWGLGENLOCKSAMPLERATEI3DPROC)(HDC hDC, UINT uRate);
	typedef BOOL (BLACK_GL_API *PFNWGLGENLOCKSOURCEDELAYI3DPROC)(HDC hDC, UINT uDelay);
	typedef BOOL (BLACK_GL_API *PFNWGLGENLOCKSOURCEEDGEI3DPROC)(HDC hDC, UINT uEdge);
	typedef BOOL (BLACK_GL_API *PFNWGLGENLOCKSOURCEI3DPROC)(HDC hDC, UINT uSource);
	typedef UINT (BLACK_GL_API *PFNWGLGETCONTEXTGPUIDAMDPROC)(HGLRC hglrc);
	typedef HGLRC (BLACK_GL_API *PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC)(void);
	typedef HDC (BLACK_GL_API *PFNWGLGETCURRENTREADDCARBPROC)(void);
	typedef HDC (BLACK_GL_API *PFNWGLGETCURRENTREADDCEXTPROC)(void);
	typedef BOOL (BLACK_GL_API *PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC)(HDC hDC, int iAttribute, int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLGETFRAMEUSAGEI3DPROC)(float * pUsage);
	typedef UINT (BLACK_GL_API *PFNWGLGETGPUIDSAMDPROC)(UINT maxCount, UINT * ids);
	typedef INT (BLACK_GL_API *PFNWGLGETGPUINFOAMDPROC)(UINT id, INT property, GLenum dataType, UINT size, void * data);
	typedef BOOL (BLACK_GL_API *PFNWGLGETGAMMATABLEI3DPROC)(HDC hDC, int iEntries, USHORT * puRed, USHORT * puGreen, USHORT * puBlue);
	typedef BOOL (BLACK_GL_API *PFNWGLGETGAMMATABLEPARAMETERSI3DPROC)(HDC hDC, int iAttribute, int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLGETGENLOCKSAMPLERATEI3DPROC)(HDC hDC, UINT * uRate);
	typedef BOOL (BLACK_GL_API *PFNWGLGETGENLOCKSOURCEDELAYI3DPROC)(HDC hDC, UINT * uDelay);
	typedef BOOL (BLACK_GL_API *PFNWGLGETGENLOCKSOURCEEDGEI3DPROC)(HDC hDC, UINT * uEdge);
	typedef BOOL (BLACK_GL_API *PFNWGLGETGENLOCKSOURCEI3DPROC)(HDC hDC, UINT * uSource);
	typedef BOOL (BLACK_GL_API *PFNWGLGETMSCRATEOMLPROC)(HDC hdc, INT32 * numerator, INT32 * denominator);
	typedef HDC (BLACK_GL_API *PFNWGLGETPBUFFERDCARBPROC)(HPBUFFERARB hPbuffer);
	typedef HDC (BLACK_GL_API *PFNWGLGETPBUFFERDCEXTPROC)(HPBUFFEREXT hPbuffer);
	typedef BOOL (BLACK_GL_API *PFNWGLGETPIXELFORMATATTRIBFVARBPROC)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, FLOAT * pfValues);
	typedef BOOL (BLACK_GL_API *PFNWGLGETPIXELFORMATATTRIBFVEXTPROC)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, FLOAT * pfValues);
	typedef BOOL (BLACK_GL_API *PFNWGLGETPIXELFORMATATTRIBIVARBPROC)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int * piAttributes, int * piValues);
	typedef BOOL (BLACK_GL_API *PFNWGLGETPIXELFORMATATTRIBIVEXTPROC)(HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int * piAttributes, int * piValues);
	typedef int (BLACK_GL_API *PFNWGLGETSWAPINTERVALEXTPROC)(void);
	typedef BOOL (BLACK_GL_API *PFNWGLGETSYNCVALUESOMLPROC)(HDC hdc, INT64 * ust, INT64 * msc, INT64 * sbc);
	typedef BOOL (BLACK_GL_API *PFNWGLGETVIDEODEVICENVPROC)(HDC hDC, int numDevices, HPVIDEODEV * hVideoDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLGETVIDEOINFONVPROC)(HPVIDEODEV hpVideoDevice, unsigned long * pulCounterOutputPbuffer, unsigned long * pulCounterOutputVideo);
	typedef BOOL (BLACK_GL_API *PFNWGLISENABLEDFRAMELOCKI3DPROC)(BOOL * pFlag);
	typedef BOOL (BLACK_GL_API *PFNWGLISENABLEDGENLOCKI3DPROC)(HDC hDC, BOOL * pFlag);
	typedef BOOL (BLACK_GL_API *PFNWGLJOINSWAPGROUPNVPROC)(HDC hDC, GLuint group);
	typedef GLboolean (BLACK_GL_API *PFNWGLLOADDISPLAYCOLORTABLEEXTPROC)(const GLushort * table, GLuint length);
	typedef BOOL (BLACK_GL_API *PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC)(HGLRC hglrc);
	typedef BOOL (BLACK_GL_API *PFNWGLMAKECONTEXTCURRENTARBPROC)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	typedef BOOL (BLACK_GL_API *PFNWGLMAKECONTEXTCURRENTEXTPROC)(HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYCURRENTCONTEXTNVPROC)(int iAttribute, int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYFRAMECOUNTNVPROC)(HDC hDC, GLuint * count);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYFRAMELOCKMASTERI3DPROC)(BOOL * pFlag);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYFRAMETRACKINGI3DPROC)(DWORD * pFrameCount, DWORD * pMissedFrames, float * pLastMissedUsage);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC)(HDC hDC, UINT * uMaxLineDelay, UINT * uMaxPixelDelay);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYMAXSWAPGROUPSNVPROC)(HDC hDC, GLuint * maxGroups, GLuint * maxBarriers);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYPBUFFERARBPROC)(HPBUFFERARB hPbuffer, int iAttribute, int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYPBUFFEREXTPROC)(HPBUFFEREXT hPbuffer, int iAttribute, int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYSWAPGROUPNVPROC)(HDC hDC, GLuint * group, GLuint * barrier);
	typedef BOOL (BLACK_GL_API *PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC)(HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC)(HDC hDC, const LPVOID * pAddress, UINT count);
	typedef int (BLACK_GL_API *PFNWGLRELEASEPBUFFERDCARBPROC)(HPBUFFERARB hPbuffer, HDC hDC);
	typedef int (BLACK_GL_API *PFNWGLRELEASEPBUFFERDCEXTPROC)(HPBUFFEREXT hPbuffer, HDC hDC);
	typedef BOOL (BLACK_GL_API *PFNWGLRELEASETEXIMAGEARBPROC)(HPBUFFERARB hPbuffer, int iBuffer);
	typedef BOOL (BLACK_GL_API *PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC)(HDC hDc, HVIDEOINPUTDEVICENV hDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLRELEASEVIDEODEVICENVPROC)(HPVIDEODEV hVideoDevice);
	typedef BOOL (BLACK_GL_API *PFNWGLRELEASEVIDEOIMAGENVPROC)(HPBUFFERARB hPbuffer, int iVideoBuffer);
	typedef BOOL (BLACK_GL_API *PFNWGLRESETFRAMECOUNTNVPROC)(HDC hDC);
	typedef BOOL (BLACK_GL_API *PFNWGLRESTOREBUFFERREGIONARBPROC)(HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);
	typedef BOOL (BLACK_GL_API *PFNWGLSAVEBUFFERREGIONARBPROC)(HANDLE hRegion, int x, int y, int width, int height);
	typedef BOOL (BLACK_GL_API *PFNWGLSENDPBUFFERTOVIDEONVPROC)(HPBUFFERARB hPbuffer, int iBufferType, unsigned long * pulCounterPbuffer, BOOL bBlock);
	typedef BOOL (BLACK_GL_API *PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC)(HDC hDC, int iAttribute, const int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLSETGAMMATABLEI3DPROC)(HDC hDC, int iEntries, const USHORT * puRed, const USHORT * puGreen, const USHORT * puBlue);
	typedef BOOL (BLACK_GL_API *PFNWGLSETGAMMATABLEPARAMETERSI3DPROC)(HDC hDC, int iAttribute, const int * piValue);
	typedef BOOL (BLACK_GL_API *PFNWGLSETPBUFFERATTRIBARBPROC)(HPBUFFERARB hPbuffer, const int * piAttribList);
	typedef BOOL (BLACK_GL_API *PFNWGLSETSTEREOEMITTERSTATE3DLPROC)(HDC hDC, UINT uState);
	typedef INT64 (BLACK_GL_API *PFNWGLSWAPBUFFERSMSCOMLPROC)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
	typedef BOOL (BLACK_GL_API *PFNWGLSWAPINTERVALEXTPROC)(int interval);
	typedef INT64 (BLACK_GL_API *PFNWGLSWAPLAYERBUFFERSMSCOMLPROC)(HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
	typedef BOOL (BLACK_GL_API *PFNWGLWAITFORMSCOMLPROC)(HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 * ust, INT64 * msc, INT64 * sbc);
	typedef BOOL (BLACK_GL_API *PFNWGLWAITFORSBCOMLPROC)(HDC hdc, INT64 target_sbc, INT64 * ust, INT64 * msc, INT64 * sbc);


	constexpr uint32_t ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV = 0x20D0;
	constexpr uint32_t ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB = 0x2054;
	constexpr uint32_t ERROR_INVALID_PIXEL_TYPE_ARB = 0x2043;
	constexpr uint32_t ERROR_INVALID_PIXEL_TYPE_EXT = 0x2043;
	constexpr uint32_t ERROR_INVALID_PROFILE_ARB = 0x2096;
	constexpr uint32_t ERROR_INVALID_VERSION_ARB = 0x2095;
	constexpr uint32_t ERROR_MISSING_AFFINITY_MASK_NV = 0x20D1;
	constexpr uint32_t ACCELERATION_ARB = 0x2003;
	constexpr uint32_t ACCELERATION_EXT = 0x2003;
	constexpr uint32_t ACCESS_READ_ONLY_NV = 0x00000000;
	constexpr uint32_t ACCESS_READ_WRITE_NV = 0x00000001;
	constexpr uint32_t ACCESS_WRITE_DISCARD_NV = 0x00000002;
	constexpr uint32_t ACCUM_ALPHA_BITS_ARB = 0x2021;
	constexpr uint32_t ACCUM_ALPHA_BITS_EXT = 0x2021;
	constexpr uint32_t ACCUM_BITS_ARB = 0x201D;
	constexpr uint32_t ACCUM_BITS_EXT = 0x201D;
	constexpr uint32_t ACCUM_BLUE_BITS_ARB = 0x2020;
	constexpr uint32_t ACCUM_BLUE_BITS_EXT = 0x2020;
	constexpr uint32_t ACCUM_GREEN_BITS_ARB = 0x201F;
	constexpr uint32_t ACCUM_GREEN_BITS_EXT = 0x201F;
	constexpr uint32_t ACCUM_RED_BITS_ARB = 0x201E;
	constexpr uint32_t ACCUM_RED_BITS_EXT = 0x201E;
	constexpr uint32_t ALPHA_BITS_ARB = 0x201B;
	constexpr uint32_t ALPHA_BITS_EXT = 0x201B;
	constexpr uint32_t ALPHA_SHIFT_ARB = 0x201C;
	constexpr uint32_t ALPHA_SHIFT_EXT = 0x201C;
	constexpr uint32_t AUX0_ARB = 0x2087;
	constexpr uint32_t AUX1_ARB = 0x2088;
	constexpr uint32_t AUX2_ARB = 0x2089;
	constexpr uint32_t AUX3_ARB = 0x208A;
	constexpr uint32_t AUX4_ARB = 0x208B;
	constexpr uint32_t AUX5_ARB = 0x208C;
	constexpr uint32_t AUX6_ARB = 0x208D;
	constexpr uint32_t AUX7_ARB = 0x208E;
	constexpr uint32_t AUX8_ARB = 0x208F;
	constexpr uint32_t AUX9_ARB = 0x2090;
	constexpr uint32_t AUX_BUFFERS_ARB = 0x2024;
	constexpr uint32_t AUX_BUFFERS_EXT = 0x2024;
	constexpr uint32_t BACK_COLOR_BUFFER_BIT_ARB = 0x00000002;
	constexpr uint32_t BACK_LEFT_ARB = 0x2085;
	constexpr uint32_t BACK_RIGHT_ARB = 0x2086;
	constexpr uint32_t BIND_TO_TEXTURE_DEPTH_NV = 0x20A3;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV = 0x20A4;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV = 0x20B4;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV = 0x20B3;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV = 0x20B2;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV = 0x20B1;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_RGBA_NV = 0x20A1;
	constexpr uint32_t BIND_TO_TEXTURE_RECTANGLE_RGB_NV = 0x20A0;
	constexpr uint32_t BIND_TO_TEXTURE_RGBA_ARB = 0x2071;
	constexpr uint32_t BIND_TO_TEXTURE_RGB_ARB = 0x2070;
	constexpr uint32_t BIND_TO_VIDEO_RGBA_NV = 0x20C1;
	constexpr uint32_t BIND_TO_VIDEO_RGB_AND_DEPTH_NV = 0x20C2;
	constexpr uint32_t BIND_TO_VIDEO_RGB_NV = 0x20C0;
	constexpr uint32_t BLUE_BITS_ARB = 0x2019;
	constexpr uint32_t BLUE_BITS_EXT = 0x2019;
	constexpr uint32_t BLUE_SHIFT_ARB = 0x201A;
	constexpr uint32_t BLUE_SHIFT_EXT = 0x201A;
	constexpr uint32_t COLORSPACE_EXT = 0x309D;
	constexpr uint32_t COLORSPACE_LINEAR_EXT = 0x308A;
	constexpr uint32_t COLORSPACE_SRGB_EXT = 0x3089;
	constexpr uint32_t COLOR_BITS_ARB = 0x2014;
	constexpr uint32_t COLOR_BITS_EXT = 0x2014;
	constexpr uint32_t COLOR_SAMPLES_NV = 0x20B9;
	constexpr uint32_t CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB = 0x00000002;
	constexpr uint32_t CONTEXT_CORE_PROFILE_BIT_ARB = 0x00000001;
	constexpr uint32_t CONTEXT_DEBUG_BIT_ARB = 0x00000001;
	constexpr uint32_t CONTEXT_ES2_PROFILE_BIT_EXT = 0x00000004;
	constexpr uint32_t CONTEXT_ES_PROFILE_BIT_EXT = 0x00000004;
	constexpr uint32_t CONTEXT_FLAGS_ARB = 0x2094;
	constexpr uint32_t CONTEXT_FORWARD_COMPATIBLE_BIT_ARB = 0x00000002;
	constexpr uint32_t CONTEXT_LAYER_PLANE_ARB = 0x2093;
	constexpr uint32_t CONTEXT_MAJOR_VERSION_ARB = 0x2091;
	constexpr uint32_t CONTEXT_MINOR_VERSION_ARB = 0x2092;
	constexpr uint32_t CONTEXT_MULTIGPU_ATTRIB_AFR_NV = 0x20AC;
	constexpr uint32_t CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV = 0x20AD;
	constexpr uint32_t CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV = 0x20AE;
	constexpr uint32_t CONTEXT_MULTIGPU_ATTRIB_NV = 0x20AA;
	constexpr uint32_t CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV = 0x20AB;
	constexpr uint32_t CONTEXT_OPENGL_NO_ERROR_ARB = 0x31B3;
	constexpr uint32_t CONTEXT_PROFILE_MASK_ARB = 0x9126;
	constexpr uint32_t CONTEXT_RELEASE_BEHAVIOR_ARB = 0x2097;
	constexpr uint32_t CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB = 0x2098;
	constexpr uint32_t CONTEXT_RELEASE_BEHAVIOR_NONE_ARB = 0;
	constexpr uint32_t CONTEXT_RESET_ISOLATION_BIT_ARB = 0x00000008;
	constexpr uint32_t CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB = 0x8256;
	constexpr uint32_t CONTEXT_ROBUST_ACCESS_BIT_ARB = 0x00000004;
	constexpr uint32_t COVERAGE_SAMPLES_NV = 0x2042;
	constexpr uint32_t CUBE_MAP_FACE_ARB = 0x207C;
	constexpr uint32_t DEPTH_BITS_ARB = 0x2022;
	constexpr uint32_t DEPTH_BITS_EXT = 0x2022;
	constexpr uint32_t DEPTH_BUFFER_BIT_ARB = 0x00000004;
	constexpr uint32_t DEPTH_COMPONENT_NV = 0x20A7;
	constexpr uint32_t DEPTH_FLOAT_EXT = 0x2040;
	constexpr uint32_t DEPTH_TEXTURE_FORMAT_NV = 0x20A5;
	constexpr uint32_t DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D = 0x2050;
	constexpr uint32_t DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D = 0x2051;
	constexpr uint32_t DIGITAL_VIDEO_CURSOR_INCLUDED_I3D = 0x2052;
	constexpr uint32_t DIGITAL_VIDEO_GAMMA_CORRECTED_I3D = 0x2053;
	constexpr uint32_t DOUBLE_BUFFER_ARB = 0x2011;
	constexpr uint32_t DOUBLE_BUFFER_EXT = 0x2011;
	constexpr uint32_t DRAW_TO_BITMAP_ARB = 0x2002;
	constexpr uint32_t DRAW_TO_BITMAP_EXT = 0x2002;
	constexpr uint32_t DRAW_TO_PBUFFER_ARB = 0x202D;
	constexpr uint32_t DRAW_TO_PBUFFER_EXT = 0x202D;
	constexpr uint32_t DRAW_TO_WINDOW_ARB = 0x2001;
	constexpr uint32_t DRAW_TO_WINDOW_EXT = 0x2001;
	constexpr uint32_t FLOAT_COMPONENTS_NV = 0x20B0;
	constexpr uint32_t FRAMEBUFFER_SRGB_CAPABLE_ARB = 0x20A9;
	constexpr uint32_t FRAMEBUFFER_SRGB_CAPABLE_EXT = 0x20A9;
	constexpr uint32_t FRONT_COLOR_BUFFER_BIT_ARB = 0x00000001;
	constexpr uint32_t FRONT_LEFT_ARB = 0x2083;
	constexpr uint32_t FRONT_RIGHT_ARB = 0x2084;
	constexpr uint32_t FULL_ACCELERATION_ARB = 0x2027;
	constexpr uint32_t FULL_ACCELERATION_EXT = 0x2027;
	constexpr uint32_t GAMMA_EXCLUDE_DESKTOP_I3D = 0x204F;
	constexpr uint32_t GAMMA_TABLE_SIZE_I3D = 0x204E;
	constexpr uint32_t GENERIC_ACCELERATION_ARB = 0x2026;
	constexpr uint32_t GENERIC_ACCELERATION_EXT = 0x2026;
	constexpr uint32_t GENLOCK_SOURCE_DIGITAL_FIELD_I3D = 0x2049;
	constexpr uint32_t GENLOCK_SOURCE_DIGITAL_SYNC_I3D = 0x2048;
	constexpr uint32_t GENLOCK_SOURCE_EDGE_BOTH_I3D = 0x204C;
	constexpr uint32_t GENLOCK_SOURCE_EDGE_FALLING_I3D = 0x204A;
	constexpr uint32_t GENLOCK_SOURCE_EDGE_RISING_I3D = 0x204B;
	constexpr uint32_t GENLOCK_SOURCE_EXTERNAL_FIELD_I3D = 0x2046;
	constexpr uint32_t GENLOCK_SOURCE_EXTERNAL_SYNC_I3D = 0x2045;
	constexpr uint32_t GENLOCK_SOURCE_EXTERNAL_TTL_I3D = 0x2047;
	constexpr uint32_t GENLOCK_SOURCE_MULTIVIEW_I3D = 0x2044;
	constexpr uint32_t GPU_CLOCK_AMD = 0x21A4;
	constexpr uint32_t GPU_FASTEST_TARGET_GPUS_AMD = 0x21A2;
	constexpr uint32_t GPU_NUM_PIPES_AMD = 0x21A5;
	constexpr uint32_t GPU_NUM_RB_AMD = 0x21A7;
	constexpr uint32_t GPU_NUM_SIMD_AMD = 0x21A6;
	constexpr uint32_t GPU_NUM_SPI_AMD = 0x21A8;
	constexpr uint32_t GPU_OPENGL_VERSION_STRING_AMD = 0x1F02;
	constexpr uint32_t GPU_RAM_AMD = 0x21A3;
	constexpr uint32_t GPU_RENDERER_STRING_AMD = 0x1F01;
	constexpr uint32_t GPU_VENDOR_AMD = 0x1F00;
	constexpr uint32_t GREEN_BITS_ARB = 0x2017;
	constexpr uint32_t GREEN_BITS_EXT = 0x2017;
	constexpr uint32_t GREEN_SHIFT_ARB = 0x2018;
	constexpr uint32_t GREEN_SHIFT_EXT = 0x2018;
	constexpr uint32_t IMAGE_BUFFER_LOCK_I3D = 0x00000002;
	constexpr uint32_t IMAGE_BUFFER_MIN_ACCESS_I3D = 0x00000001;
	constexpr uint32_t LOSE_CONTEXT_ON_RESET_ARB = 0x8252;
	constexpr uint32_t MAX_PBUFFER_HEIGHT_ARB = 0x2030;
	constexpr uint32_t MAX_PBUFFER_HEIGHT_EXT = 0x2030;
	constexpr uint32_t MAX_PBUFFER_PIXELS_ARB = 0x202E;
	constexpr uint32_t MAX_PBUFFER_PIXELS_EXT = 0x202E;
	constexpr uint32_t MAX_PBUFFER_WIDTH_ARB = 0x202F;
	constexpr uint32_t MAX_PBUFFER_WIDTH_EXT = 0x202F;
	constexpr uint32_t MIPMAP_LEVEL_ARB = 0x207B;
	constexpr uint32_t MIPMAP_TEXTURE_ARB = 0x2074;
	constexpr uint32_t NEED_PALETTE_ARB = 0x2004;
	constexpr uint32_t NEED_PALETTE_EXT = 0x2004;
	constexpr uint32_t NEED_SYSTEM_PALETTE_ARB = 0x2005;
	constexpr uint32_t NEED_SYSTEM_PALETTE_EXT = 0x2005;
	constexpr uint32_t NO_ACCELERATION_ARB = 0x2025;
	constexpr uint32_t NO_ACCELERATION_EXT = 0x2025;
	constexpr uint32_t NO_RESET_NOTIFICATION_ARB = 0x8261;
	constexpr uint32_t NO_TEXTURE_ARB = 0x2077;
	constexpr uint32_t NUMBER_OVERLAYS_ARB = 0x2008;
	constexpr uint32_t NUMBER_OVERLAYS_EXT = 0x2008;
	constexpr uint32_t NUMBER_PIXEL_FORMATS_ARB = 0x2000;
	constexpr uint32_t NUMBER_PIXEL_FORMATS_EXT = 0x2000;
	constexpr uint32_t NUMBER_UNDERLAYS_ARB = 0x2009;
	constexpr uint32_t NUMBER_UNDERLAYS_EXT = 0x2009;
	constexpr uint32_t NUM_VIDEO_CAPTURE_SLOTS_NV = 0x20CF;
	constexpr uint32_t NUM_VIDEO_SLOTS_NV = 0x20F0;
	constexpr uint32_t OPTIMAL_PBUFFER_HEIGHT_EXT = 0x2032;
	constexpr uint32_t OPTIMAL_PBUFFER_WIDTH_EXT = 0x2031;
	constexpr uint32_t PBUFFER_HEIGHT_ARB = 0x2035;
	constexpr uint32_t PBUFFER_HEIGHT_EXT = 0x2035;
	constexpr uint32_t PBUFFER_LARGEST_ARB = 0x2033;
	constexpr uint32_t PBUFFER_LARGEST_EXT = 0x2033;
	constexpr uint32_t PBUFFER_LOST_ARB = 0x2036;
	constexpr uint32_t PBUFFER_WIDTH_ARB = 0x2034;
	constexpr uint32_t PBUFFER_WIDTH_EXT = 0x2034;
	constexpr uint32_t PIXEL_TYPE_ARB = 0x2013;
	constexpr uint32_t PIXEL_TYPE_EXT = 0x2013;
	constexpr uint32_t RED_BITS_ARB = 0x2015;
	constexpr uint32_t RED_BITS_EXT = 0x2015;
	constexpr uint32_t RED_SHIFT_ARB = 0x2016;
	constexpr uint32_t RED_SHIFT_EXT = 0x2016;
	constexpr uint32_t SAMPLES_3DFX = 0x2061;
	constexpr uint32_t SAMPLES_ARB = 0x2042;
	constexpr uint32_t SAMPLES_EXT = 0x2042;
	constexpr uint32_t SAMPLE_BUFFERS_3DFX = 0x2060;
	constexpr uint32_t SAMPLE_BUFFERS_ARB = 0x2041;
	constexpr uint32_t SAMPLE_BUFFERS_EXT = 0x2041;
	constexpr uint32_t SHARE_ACCUM_ARB = 0x200E;
	constexpr uint32_t SHARE_ACCUM_EXT = 0x200E;
	constexpr uint32_t SHARE_DEPTH_ARB = 0x200C;
	constexpr uint32_t SHARE_DEPTH_EXT = 0x200C;
	constexpr uint32_t SHARE_STENCIL_ARB = 0x200D;
	constexpr uint32_t SHARE_STENCIL_EXT = 0x200D;
	constexpr uint32_t STENCIL_BITS_ARB = 0x2023;
	constexpr uint32_t STENCIL_BITS_EXT = 0x2023;
	constexpr uint32_t STENCIL_BUFFER_BIT_ARB = 0x00000008;
	constexpr uint32_t STEREO_ARB = 0x2012;
	constexpr uint32_t STEREO_EMITTER_DISABLE_3DL = 0x2056;
	constexpr uint32_t STEREO_EMITTER_ENABLE_3DL = 0x2055;
	constexpr uint32_t STEREO_EXT = 0x2012;
	constexpr uint32_t STEREO_POLARITY_INVERT_3DL = 0x2058;
	constexpr uint32_t STEREO_POLARITY_NORMAL_3DL = 0x2057;
	constexpr uint32_t SUPPORT_GDI_ARB = 0x200F;
	constexpr uint32_t SUPPORT_GDI_EXT = 0x200F;
	constexpr uint32_t SUPPORT_OPENGL_ARB = 0x2010;
	constexpr uint32_t SUPPORT_OPENGL_EXT = 0x2010;
	constexpr uint32_t SWAP_COPY_ARB = 0x2029;
	constexpr uint32_t SWAP_COPY_EXT = 0x2029;
	constexpr uint32_t SWAP_EXCHANGE_ARB = 0x2028;
	constexpr uint32_t SWAP_EXCHANGE_EXT = 0x2028;
	constexpr uint32_t SWAP_LAYER_BUFFERS_ARB = 0x2006;
	constexpr uint32_t SWAP_LAYER_BUFFERS_EXT = 0x2006;
	constexpr uint32_t SWAP_METHOD_ARB = 0x2007;
	constexpr uint32_t SWAP_METHOD_EXT = 0x2007;
	constexpr uint32_t SWAP_UNDEFINED_ARB = 0x202A;
	constexpr uint32_t SWAP_UNDEFINED_EXT = 0x202A;
	constexpr uint32_t TEXTURE_1D_ARB = 0x2079;
	constexpr uint32_t TEXTURE_2D_ARB = 0x207A;
	constexpr uint32_t TEXTURE_CUBE_MAP_ARB = 0x2078;
	constexpr uint32_t TEXTURE_CUBE_MAP_NEGATIVE_X_ARB = 0x207E;
	constexpr uint32_t TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB = 0x2080;
	constexpr uint32_t TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB = 0x2082;
	constexpr uint32_t TEXTURE_CUBE_MAP_POSITIVE_X_ARB = 0x207D;
	constexpr uint32_t TEXTURE_CUBE_MAP_POSITIVE_Y_ARB = 0x207F;
	constexpr uint32_t TEXTURE_CUBE_MAP_POSITIVE_Z_ARB = 0x2081;
	constexpr uint32_t TEXTURE_DEPTH_COMPONENT_NV = 0x20A6;
	constexpr uint32_t TEXTURE_FLOAT_RGBA_NV = 0x20B8;
	constexpr uint32_t TEXTURE_FLOAT_RGB_NV = 0x20B7;
	constexpr uint32_t TEXTURE_FLOAT_RG_NV = 0x20B6;
	constexpr uint32_t TEXTURE_FLOAT_R_NV = 0x20B5;
	constexpr uint32_t TEXTURE_FORMAT_ARB = 0x2072;
	constexpr uint32_t TEXTURE_RECTANGLE_ATI = 0x21A5;
	constexpr uint32_t TEXTURE_RECTANGLE_NV = 0x20A2;
	constexpr uint32_t TEXTURE_RGBA_ARB = 0x2076;
	constexpr uint32_t TEXTURE_RGB_ARB = 0x2075;
	constexpr uint32_t TEXTURE_TARGET_ARB = 0x2073;
	constexpr uint32_t TRANSPARENT_ALPHA_VALUE_ARB = 0x203A;
	constexpr uint32_t TRANSPARENT_ARB = 0x200A;
	constexpr uint32_t TRANSPARENT_BLUE_VALUE_ARB = 0x2039;
	constexpr uint32_t TRANSPARENT_EXT = 0x200A;
	constexpr uint32_t TRANSPARENT_GREEN_VALUE_ARB = 0x2038;
	constexpr uint32_t TRANSPARENT_INDEX_VALUE_ARB = 0x203B;
	constexpr uint32_t TRANSPARENT_RED_VALUE_ARB = 0x2037;
	constexpr uint32_t TRANSPARENT_VALUE_EXT = 0x200B;
	constexpr uint32_t TYPE_COLORINDEX_ARB = 0x202C;
	constexpr uint32_t TYPE_COLORINDEX_EXT = 0x202C;
	constexpr uint32_t TYPE_RGBA_ARB = 0x202B;
	constexpr uint32_t TYPE_RGBA_EXT = 0x202B;
	constexpr uint32_t TYPE_RGBA_FLOAT_ARB = 0x21A0;
	constexpr uint32_t TYPE_RGBA_FLOAT_ATI = 0x21A0;
	constexpr uint32_t TYPE_RGBA_UNSIGNED_FLOAT_EXT = 0x20A8;
	constexpr uint32_t UNIQUE_ID_NV = 0x20CE;
	constexpr uint32_t VIDEO_OUT_ALPHA_NV = 0x20C4;
	constexpr uint32_t VIDEO_OUT_COLOR_AND_ALPHA_NV = 0x20C6;
	constexpr uint32_t VIDEO_OUT_COLOR_AND_DEPTH_NV = 0x20C7;
	constexpr uint32_t VIDEO_OUT_COLOR_NV = 0x20C3;
	constexpr uint32_t VIDEO_OUT_DEPTH_NV = 0x20C5;
	constexpr uint32_t VIDEO_OUT_FIELD_1 = 0x20C9;
	constexpr uint32_t VIDEO_OUT_FIELD_2 = 0x20CA;
	constexpr uint32_t VIDEO_OUT_FRAME = 0x20C8;
	constexpr uint32_t VIDEO_OUT_STACKED_FIELDS_1_2 = 0x20CB;
	constexpr uint32_t VIDEO_OUT_STACKED_FIELDS_2_1 = 0x20CC;


	extern PFNWGLALLOCATEMEMORYNVPROC						allocate_memory_nv;
	extern PFNWGLASSOCIATEIMAGEBUFFEREVENTSI3DPROC			associate_image_buffer_events_i3d;
	extern PFNWGLBEGINFRAMETRACKINGI3DPROC					begin_frame_tracking_i3d;
	extern PFNWGLBINDDISPLAYCOLORTABLEEXTPROC				bind_display_color_table_ext;
	extern PFNWGLBINDSWAPBARRIERNVPROC						bind_swap_barrier_nv;
	extern PFNWGLBINDTEXIMAGEARBPROC						bind_tex_image_arb;
	extern PFNWGLBINDVIDEOCAPTUREDEVICENVPROC				bind_video_capture_device_nv;
	extern PFNWGLBINDVIDEODEVICENVPROC						bind_video_device_nv;
	extern PFNWGLBINDVIDEOIMAGENVPROC						bind_video_image_nv;
	extern PFNWGLBLITCONTEXTFRAMEBUFFERAMDPROC				blit_context_framebuffer_amd;
	extern PFNWGLCHOOSEPIXELFORMATARBPROC					choose_pixel_format_arb;
	extern PFNWGLCHOOSEPIXELFORMATEXTPROC					choose_pixel_format_ext;
	extern PFNWGLCOPYIMAGESUBDATANVPROC						copy_image_sub_data_nv;
	extern PFNWGLCREATEAFFINITYDCNVPROC						create_affinity_dc_nv;
	extern PFNWGLCREATEASSOCIATEDCONTEXTAMDPROC				create_associated_context_amd;
	extern PFNWGLCREATEASSOCIATEDCONTEXTATTRIBSAMDPROC		create_associated_context_attribs_amd;
	extern PFNWGLCREATEBUFFERREGIONARBPROC					create_buffer_region_arb;
	extern PFNWGLCREATECONTEXTATTRIBSARBPROC				create_context_attribs_arb;
	extern PFNWGLCREATEDISPLAYCOLORTABLEEXTPROC				create_display_color_table_ext;
	extern PFNWGLCREATEIMAGEBUFFERI3DPROC					create_image_buffer_i3d;
	extern PFNWGLCREATEPBUFFERARBPROC						create_pbuffer_arb;
	extern PFNWGLCREATEPBUFFEREXTPROC						create_pbuffer_ext;
	extern PFNWGLDXCLOSEDEVICENVPROC						dx_close_device_nv;
	extern PFNWGLDXLOCKOBJECTSNVPROC						dx_lock_objects_nv;
	extern PFNWGLDXOBJECTACCESSNVPROC						dx_object_access_nv;
	extern PFNWGLDXOPENDEVICENVPROC							dx_open_device_nv;
	extern PFNWGLDXREGISTEROBJECTNVPROC						dx_register_object_nv;
	extern PFNWGLDXSETRESOURCESHAREHANDLENVPROC				dx_set_resource_share_handle_nv;
	extern PFNWGLDXUNLOCKOBJECTSNVPROC						dx_unlock_objects_nv;
	extern PFNWGLDXUNREGISTEROBJECTNVPROC					dx_unregister_object_nv;
	extern PFNWGLDELAYBEFORESWAPNVPROC						delay_before_swap_nv;
	extern PFNWGLDELETEASSOCIATEDCONTEXTAMDPROC				delete_associated_context_amd;
	extern PFNWGLDELETEBUFFERREGIONARBPROC					delete_buffer_region_arb;
	extern PFNWGLDELETEDCNVPROC								delete_dc_nv;
	extern PFNWGLDESTROYDISPLAYCOLORTABLEEXTPROC			destroy_display_color_table_ext;
	extern PFNWGLDESTROYIMAGEBUFFERI3DPROC					destroy_image_buffer_i3d;
	extern PFNWGLDESTROYPBUFFERARBPROC						destroy_pbuffer_arb;
	extern PFNWGLDESTROYPBUFFEREXTPROC						destroy_pbuffer_ext;
	extern PFNWGLDISABLEFRAMELOCKI3DPROC					disable_frame_lock_i3d;
	extern PFNWGLDISABLEGENLOCKI3DPROC						disable_genlock_i3d;
	extern PFNWGLENABLEFRAMELOCKI3DPROC						enable_frame_lock_i3d;
	extern PFNWGLENABLEGENLOCKI3DPROC						enable_genlock_i3d;
	extern PFNWGLENDFRAMETRACKINGI3DPROC					end_frame_tracking_i3d;
	extern PFNWGLENUMGPUDEVICESNVPROC						enum_gpu_devices_nv;
	extern PFNWGLENUMGPUSFROMAFFINITYDCNVPROC				enum_gpus_from_affinity_dc_nv;
	extern PFNWGLENUMGPUSNVPROC								enum_gpus_nv;
	extern PFNWGLENUMERATEVIDEOCAPTUREDEVICESNVPROC			enumerate_video_capture_devices_nv;
	extern PFNWGLENUMERATEVIDEODEVICESNVPROC				enumerate_video_devices_nv;
	extern PFNWGLFREEMEMORYNVPROC							free_memory_nv;
	extern PFNWGLGENLOCKSAMPLERATEI3DPROC					genlock_sample_rate_i3d;
	extern PFNWGLGENLOCKSOURCEDELAYI3DPROC					genlock_source_delay_i3d;
	extern PFNWGLGENLOCKSOURCEEDGEI3DPROC					genlock_source_edge_i3d;
	extern PFNWGLGENLOCKSOURCEI3DPROC						genlock_source_i3d;
	extern PFNWGLGETCONTEXTGPUIDAMDPROC						get_context_gpu_id_amd;
	extern PFNWGLGETCURRENTASSOCIATEDCONTEXTAMDPROC			get_current_associated_context_amd;
	extern PFNWGLGETCURRENTREADDCARBPROC					get_current_read_dc_arb;
	extern PFNWGLGETCURRENTREADDCEXTPROC					get_current_read_dc_ext;
	extern PFNWGLGETDIGITALVIDEOPARAMETERSI3DPROC			get_digital_video_parameters_i3d;
	extern PFNWGLGETFRAMEUSAGEI3DPROC						get_frame_usage_i3d;
	extern PFNWGLGETGPUIDSAMDPROC							get_gpu_ids_amd;
	extern PFNWGLGETGPUINFOAMDPROC							get_gpu_info_amd;
	extern PFNWGLGETGAMMATABLEI3DPROC						get_gamma_table_i3d;
	extern PFNWGLGETGAMMATABLEPARAMETERSI3DPROC				get_gamma_table_parameters_i3d;
	extern PFNWGLGETGENLOCKSAMPLERATEI3DPROC				get_genlock_sample_rate_i3d;
	extern PFNWGLGETGENLOCKSOURCEDELAYI3DPROC				get_genlock_source_delay_i3d;
	extern PFNWGLGETGENLOCKSOURCEEDGEI3DPROC				get_genlock_source_edge_i3d;
	extern PFNWGLGETGENLOCKSOURCEI3DPROC					get_genlock_source_i3d;
	extern PFNWGLGETMSCRATEOMLPROC							get_msc_rate_oml;
	extern PFNWGLGETPBUFFERDCARBPROC						get_pbuffer_dc_arb;
	extern PFNWGLGETPBUFFERDCEXTPROC						get_pbuffer_dc_ext;
	extern PFNWGLGETPIXELFORMATATTRIBFVARBPROC				get_pixel_format_attribfv_arb;
	extern PFNWGLGETPIXELFORMATATTRIBFVEXTPROC				get_pixel_format_attribfv_ext;
	extern PFNWGLGETPIXELFORMATATTRIBIVARBPROC				get_pixel_format_attribiv_arb;
	extern PFNWGLGETPIXELFORMATATTRIBIVEXTPROC				get_pixel_format_attribiv_ext;
	extern PFNWGLGETSWAPINTERVALEXTPROC						get_swap_interval_ext;
	extern PFNWGLGETSYNCVALUESOMLPROC						get_sync_values_oml;
	extern PFNWGLGETVIDEODEVICENVPROC						get_video_device_nv;
	extern PFNWGLGETVIDEOINFONVPROC							get_video_info_nv;
	extern PFNWGLISENABLEDFRAMELOCKI3DPROC					is_enabled_frame_lock_i3d;
	extern PFNWGLISENABLEDGENLOCKI3DPROC					is_enabled_genlock_i3d;
	extern PFNWGLJOINSWAPGROUPNVPROC						join_swap_group_nv;
	extern PFNWGLLOADDISPLAYCOLORTABLEEXTPROC				load_display_color_table_ext;
	extern PFNWGLLOCKVIDEOCAPTUREDEVICENVPROC				lock_video_capture_device_nv;
	extern PFNWGLMAKEASSOCIATEDCONTEXTCURRENTAMDPROC		make_associated_context_current_amd;
	extern PFNWGLMAKECONTEXTCURRENTARBPROC					make_context_current_arb;
	extern PFNWGLMAKECONTEXTCURRENTEXTPROC					make_context_current_ext;
	extern PFNWGLQUERYCURRENTCONTEXTNVPROC					query_current_context_nv;
	extern PFNWGLQUERYFRAMECOUNTNVPROC						query_frame_count_nv;
	extern PFNWGLQUERYFRAMELOCKMASTERI3DPROC				query_frame_lock_master_i3d;
	extern PFNWGLQUERYFRAMETRACKINGI3DPROC					query_frame_tracking_i3d;
	extern PFNWGLQUERYGENLOCKMAXSOURCEDELAYI3DPROC			query_genlock_max_source_delay_i3d;
	extern PFNWGLQUERYMAXSWAPGROUPSNVPROC					query_max_swap_groups_nv;
	extern PFNWGLQUERYPBUFFERARBPROC						query_pbuffer_arb;
	extern PFNWGLQUERYPBUFFEREXTPROC						query_pbuffer_ext;
	extern PFNWGLQUERYSWAPGROUPNVPROC						query_swap_group_nv;
	extern PFNWGLQUERYVIDEOCAPTUREDEVICENVPROC				query_video_capture_device_nv;
	extern PFNWGLRELEASEIMAGEBUFFEREVENTSI3DPROC			release_image_buffer_events_i3d;
	extern PFNWGLRELEASEPBUFFERDCARBPROC					release_pbuffer_dc_arb;
	extern PFNWGLRELEASEPBUFFERDCEXTPROC					release_pbuffer_dc_ext;
	extern PFNWGLRELEASETEXIMAGEARBPROC						release_tex_image_arb;
	extern PFNWGLRELEASEVIDEOCAPTUREDEVICENVPROC			release_video_capture_device_nv;
	extern PFNWGLRELEASEVIDEODEVICENVPROC					release_video_device_nv;
	extern PFNWGLRELEASEVIDEOIMAGENVPROC					release_video_image_nv;
	extern PFNWGLRESETFRAMECOUNTNVPROC						reset_frame_count_nv;
	extern PFNWGLRESTOREBUFFERREGIONARBPROC					restore_buffer_region_arb;
	extern PFNWGLSAVEBUFFERREGIONARBPROC					save_buffer_region_arb;
	extern PFNWGLSENDPBUFFERTOVIDEONVPROC					send_pbuffer_to_video_nv;
	extern PFNWGLSETDIGITALVIDEOPARAMETERSI3DPROC			set_digital_video_parameters_i3d;
	extern PFNWGLSETGAMMATABLEI3DPROC						set_gamma_table_i3d;
	extern PFNWGLSETGAMMATABLEPARAMETERSI3DPROC				set_gamma_table_parameters_i3d;
	extern PFNWGLSETPBUFFERATTRIBARBPROC					set_pbuffer_attrib_arb;
	extern PFNWGLSETSTEREOEMITTERSTATE3DLPROC				set_stereo_emitter_state3d_l;
	extern PFNWGLSWAPBUFFERSMSCOMLPROC						swap_buffers_msc_oml;
	extern PFNWGLSWAPINTERVALEXTPROC						swap_interval_ext;
	extern PFNWGLSWAPLAYERBUFFERSMSCOMLPROC					swap_layer_buffers_msc_oml;
	extern PFNWGLWAITFORMSCOMLPROC							wait_for_msc_oml;
	extern PFNWGLWAITFORSBCOMLPROC							wait_for_sbc_oml;
}
