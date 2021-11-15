#pragma once


// Types used by functions.
#include <wingdi.h>
#include <gl/GL.h>


namespace Wgl
{
	typedef int (WINAPI *PFNCHOOSEPIXELFORMATPROC)(HDC hDc, const PIXELFORMATDESCRIPTOR * pPfd);
	typedef int (WINAPI *PFNDESCRIBEPIXELFORMATPROC)(HDC hdc, int ipfd, UINT cjpfd, const PIXELFORMATDESCRIPTOR * ppfd);
	typedef UINT (WINAPI *PFNGETENHMETAFILEPIXELFORMATPROC)(HENHMETAFILE hemf, const PIXELFORMATDESCRIPTOR * ppfd);
	typedef int (WINAPI *PFNGETPIXELFORMATPROC)(HDC hdc);
	typedef BOOL (WINAPI *PFNSETPIXELFORMATPROC)(HDC hdc, int ipfd, const PIXELFORMATDESCRIPTOR * ppfd);
	typedef BOOL (WINAPI *PFNSWAPBUFFERSPROC)(HDC hdc);
	typedef BOOL (WINAPI *PFNWGLCOPYCONTEXTPROC)(HGLRC hglrcSrc, HGLRC hglrcDst, UINT mask);
	typedef HGLRC (WINAPI *PFNWGLCREATECONTEXTPROC)(HDC hDc);
	typedef HGLRC (WINAPI *PFNWGLCREATELAYERCONTEXTPROC)(HDC hDc, int level);
	typedef BOOL (WINAPI *PFNWGLDELETECONTEXTPROC)(HGLRC oldContext);
	typedef BOOL (WINAPI *PFNWGLDESCRIBELAYERPLANEPROC)(HDC hDc, int pixelFormat, int layerPlane, UINT nBytes, const LAYERPLANEDESCRIPTOR * plpd);
	typedef HGLRC (WINAPI *PFNWGLGETCURRENTCONTEXTPROC)(void);
	typedef HDC (WINAPI *PFNWGLGETCURRENTDCPROC)(void);
	typedef const char* (WINAPI *PFNWGLGETEXTENSIONSSTRINGARBPROC)(HDC hdc);
	typedef const char* (WINAPI *PFNWGLGETEXTENSIONSSTRINGEXTPROC)(void);
	typedef int (WINAPI *PFNWGLGETLAYERPALETTEENTRIESPROC)(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);
	typedef PROC (WINAPI *PFNWGLGETPROCADDRESSPROC)(LPCSTR lpszProc);
	typedef BOOL (WINAPI *PFNWGLMAKECURRENTPROC)(HDC hDc, HGLRC newContext);
	typedef BOOL (WINAPI *PFNWGLREALIZELAYERPALETTEPROC)(HDC hdc, int iLayerPlane, BOOL bRealize);
	typedef int (WINAPI *PFNWGLSETLAYERPALETTEENTRIESPROC)(HDC hdc, int iLayerPlane, int iStart, int cEntries, const COLORREF * pcr);
	typedef BOOL (WINAPI *PFNWGLSHARELISTSPROC)(HGLRC hrcSrvShare, HGLRC hrcSrvSource);
	typedef BOOL (WINAPI *PFNWGLSWAPLAYERBUFFERSPROC)(HDC hdc, UINT fuFlags);
	typedef BOOL (WINAPI *PFNWGLUSEFONTBITMAPSPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (WINAPI *PFNWGLUSEFONTBITMAPSAPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (WINAPI *PFNWGLUSEFONTBITMAPSWPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase);
	typedef BOOL (WINAPI *PFNWGLUSEFONTOUTLINESPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (WINAPI *PFNWGLUSEFONTOUTLINESAPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);
	typedef BOOL (WINAPI *PFNWGLUSEFONTOUTLINESWPROC)(HDC hDC, DWORD first, DWORD count, DWORD listBase, FLOAT deviation, FLOAT extrusion, int format, LPGLYPHMETRICSFLOAT lpgmf);


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


	extern PFNCHOOSEPIXELFORMATPROC				choose_pixel_format;
	extern PFNDESCRIBEPIXELFORMATPROC			describe_pixel_format;
	extern PFNGETENHMETAFILEPIXELFORMATPROC		get_enh_meta_file_pixel_format;
	extern PFNGETPIXELFORMATPROC				get_pixel_format;
	extern PFNSETPIXELFORMATPROC				set_pixel_format;
	extern PFNSWAPBUFFERSPROC					swap_buffers;
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