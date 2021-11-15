#include <black/open-gl.h>

#include "bindings.wgl.h"


namespace Wgl
{
	PFNCHOOSEPIXELFORMATPROC			choose_pixel_format				= nullptr;
	PFNDESCRIBEPIXELFORMATPROC			describe_pixel_format			= nullptr;
	PFNGETENHMETAFILEPIXELFORMATPROC	get_enh_meta_file_pixel_format	= nullptr;
	PFNGETPIXELFORMATPROC				get_pixel_format				= nullptr;
	PFNSETPIXELFORMATPROC				set_pixel_format				= nullptr;
	PFNSWAPBUFFERSPROC					swap_buffers					= nullptr;
	PFNWGLCOPYCONTEXTPROC				copy_context					= nullptr;
	PFNWGLCREATECONTEXTPROC				create_context					= nullptr;
	PFNWGLCREATELAYERCONTEXTPROC		create_layer_context			= nullptr;
	PFNWGLDELETECONTEXTPROC				delete_context					= nullptr;
	PFNWGLDESCRIBELAYERPLANEPROC		describe_layer_plane			= nullptr;
	PFNWGLGETCURRENTCONTEXTPROC			get_current_context				= nullptr;
	PFNWGLGETCURRENTDCPROC				get_current_dc					= nullptr;
	PFNWGLGETEXTENSIONSSTRINGARBPROC	get_extensions_string_arb		= nullptr;
	PFNWGLGETEXTENSIONSSTRINGEXTPROC	get_extensions_string_ext		= nullptr;
	PFNWGLGETLAYERPALETTEENTRIESPROC	get_layer_palette_entries		= nullptr;
	PFNWGLGETPROCADDRESSPROC			get_proc_address				= nullptr;
	PFNWGLMAKECURRENTPROC				make_current					= nullptr;
	PFNWGLREALIZELAYERPALETTEPROC		realize_layer_palette			= nullptr;
	PFNWGLSETLAYERPALETTEENTRIESPROC	set_layer_palette_entries		= nullptr;
	PFNWGLSHARELISTSPROC				share_lists						= nullptr;
	PFNWGLSWAPLAYERBUFFERSPROC			swap_layer_buffers				= nullptr;
	PFNWGLUSEFONTBITMAPSPROC			use_font_bitmaps				= nullptr;
	PFNWGLUSEFONTBITMAPSAPROC			use_font_bitmaps_a				= nullptr;
	PFNWGLUSEFONTBITMAPSWPROC			use_font_bitmaps_w				= nullptr;
	PFNWGLUSEFONTOUTLINESPROC			use_font_outlines				= nullptr;
	PFNWGLUSEFONTOUTLINESAPROC			use_font_outlines_a				= nullptr;
	PFNWGLUSEFONTOUTLINESWPROC			use_font_outlines_w				= nullptr;
}
