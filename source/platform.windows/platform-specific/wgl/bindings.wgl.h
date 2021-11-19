#pragma once


// Types used by functions.
#include <wingdi.h>


namespace Wgl
{
	typedef BOOL (BLACK_GL_API *PFNWGLCOPYCONTEXTPROC)(HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask);
	typedef HGLRC (BLACK_GL_API *PFNWGLCREATECONTEXTPROC)(HDC hDc);
	typedef HGLRC (BLACK_GL_API *PFNWGLCREATELAYERCONTEXTPROC)(HDC hDc, int level);
	typedef BOOL (BLACK_GL_API *PFNWGLDELETECONTEXTPROC)(HGLRC oldContext);
	typedef BOOL (BLACK_GL_API *PFNWGLDESCRIBELAYERPLANEPROC)(HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd);
	typedef HGLRC (BLACK_GL_API *PFNWGLGETCURRENTCONTEXTPROC)(void);
	typedef HDC (BLACK_GL_API *PFNWGLGETCURRENTDCPROC)(void);
	typedef const char* (BLACK_GL_API *PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC hdc);
	typedef const char* (BLACK_GL_API *PFNWGLGETEXTENSIONSSTRINGEXTPROC)(void);
	typedef int (BLACK_GL_API *PFNWGLGETLAYERPALETTEENTRIESPROC)(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);
	typedef PROC (BLACK_GL_API *PFNWGLGETPROCADDRESSPROC)(LPCSTR lpszProc);
	typedef BOOL (BLACK_GL_API *PFNWGLMAKECURRENTPROC)(HDC hDc, HGLRC newContext);
	typedef BOOL (BLACK_GL_API *PFNWGLREALIZELAYERPALETTEPROC)(HDC hdc, int iLayerPlane, BOOL bRealize);
	typedef int (BLACK_GL_API *PFNWGLSETLAYERPALETTEENTRIESPROC)(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);
	typedef BOOL (BLACK_GL_API *PFNWGLSHARELISTSPROC)(HGLRC hrcSrvShare, HGLRC hrcSrvSource);
	typedef BOOL (BLACK_GL_API *PFNWGLSWAPLAYERBUFFERSPROC)(HDC hdc, UINT fuFlags);
	typedef BOOL (BLACK_GL_API *PFNWGLUSEFONTBITMAPSPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (BLACK_GL_API *PFNWGLUSEFONTBITMAPSAPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (BLACK_GL_API *PFNWGLUSEFONTBITMAPSWPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (BLACK_GL_API *PFNWGLUSEFONTOUTLINESPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (BLACK_GL_API *PFNWGLUSEFONTOUTLINESAPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (BLACK_GL_API *PFNWGLUSEFONTOUTLINESWPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);


	constexpr uint32_t FONT_LINES = 0;
	constexpr uint32_t FONT_POLYGONS = 1;
	constexpr uint32_t SWAP_MAIN_PLANE = 0x00000001;
	constexpr uint32_t SWAP_OVERLAY1 = 0x00000002;
	constexpr uint32_t SWAP_OVERLAY10 = 0x00000400;
	constexpr uint32_t SWAP_OVERLAY11 = 0x00000800;
	constexpr uint32_t SWAP_OVERLAY12 = 0x00001000;
	constexpr uint32_t SWAP_OVERLAY13 = 0x00002000;
	constexpr uint32_t SWAP_OVERLAY14 = 0x00004000;
	constexpr uint32_t SWAP_OVERLAY15 = 0x00008000;
	constexpr uint32_t SWAP_OVERLAY2 = 0x00000004;
	constexpr uint32_t SWAP_OVERLAY3 = 0x00000008;
	constexpr uint32_t SWAP_OVERLAY4 = 0x00000010;
	constexpr uint32_t SWAP_OVERLAY5 = 0x00000020;
	constexpr uint32_t SWAP_OVERLAY6 = 0x00000040;
	constexpr uint32_t SWAP_OVERLAY7 = 0x00000080;
	constexpr uint32_t SWAP_OVERLAY8 = 0x00000100;
	constexpr uint32_t SWAP_OVERLAY9 = 0x00000200;
	constexpr uint32_t SWAP_UNDERLAY1 = 0x00010000;
	constexpr uint32_t SWAP_UNDERLAY10 = 0x02000000;
	constexpr uint32_t SWAP_UNDERLAY11 = 0x04000000;
	constexpr uint32_t SWAP_UNDERLAY12 = 0x08000000;
	constexpr uint32_t SWAP_UNDERLAY13 = 0x10000000;
	constexpr uint32_t SWAP_UNDERLAY14 = 0x20000000;
	constexpr uint32_t SWAP_UNDERLAY15 = 0x40000000;
	constexpr uint32_t SWAP_UNDERLAY2 = 0x00020000;
	constexpr uint32_t SWAP_UNDERLAY3 = 0x00040000;
	constexpr uint32_t SWAP_UNDERLAY4 = 0x00080000;
	constexpr uint32_t SWAP_UNDERLAY5 = 0x00100000;
	constexpr uint32_t SWAP_UNDERLAY6 = 0x00200000;
	constexpr uint32_t SWAP_UNDERLAY7 = 0x00400000;
	constexpr uint32_t SWAP_UNDERLAY8 = 0x00800000;
	constexpr uint32_t SWAP_UNDERLAY9 = 0x01000000;


	extern PFNWGLCOPYCONTEXTPROC				copy_context;
	extern PFNWGLCREATECONTEXTPROC				create_context;
	extern PFNWGLCREATELAYERCONTEXTPROC			create_layer_context;
	extern PFNWGLDELETECONTEXTPROC				delete_context;
	extern PFNWGLDESCRIBELAYERPLANEPROC			describe_layer_plane;
	extern PFNWGLGETCURRENTCONTEXTPROC			get_current_context;
	extern PFNWGLGETCURRENTDCPROC				get_current_dc;
	extern PFNWGLGETEXTENSIONSSTRINGARBPROC		get_extensions_string_arb;
	extern PFNWGLGETEXTENSIONSSTRINGEXTPROC		get_extensions_string_ext;
	extern PFNWGLGETLAYERPALETTEENTRIESPROC		get_layer_palette_entries;
	extern PFNWGLGETPROCADDRESSPROC				get_proc_address;
	extern PFNWGLMAKECURRENTPROC				make_current;
	extern PFNWGLREALIZELAYERPALETTEPROC		realize_layer_palette;
	extern PFNWGLSETLAYERPALETTEENTRIESPROC		set_layer_palette_entries;
	extern PFNWGLSHARELISTSPROC					share_lists;
	extern PFNWGLSWAPLAYERBUFFERSPROC			swap_layer_buffers;
	extern PFNWGLUSEFONTBITMAPSPROC				use_font_bitmaps;
	extern PFNWGLUSEFONTBITMAPSAPROC			use_font_bitmaps_a;
	extern PFNWGLUSEFONTBITMAPSWPROC			use_font_bitmaps_w;
	extern PFNWGLUSEFONTOUTLINESPROC			use_font_outlines;
	extern PFNWGLUSEFONTOUTLINESAPROC			use_font_outlines_a;
	extern PFNWGLUSEFONTOUTLINESWPROC			use_font_outlines_w;
}