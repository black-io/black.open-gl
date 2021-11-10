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