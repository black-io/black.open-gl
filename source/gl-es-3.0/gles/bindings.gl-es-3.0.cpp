#include <black/open-gl/gl-es-3.0.h>

#include "bindings.gl-es-3.0.h"


namespace GlEs30
{
	PFNGLACTIVETEXTUREPROC							active_texture							= nullptr;
	PFNGLATTACHSHADERPROC							attach_shader							= nullptr;
	PFNGLBEGINQUERYPROC								begin_query								= nullptr;
	PFNGLBEGINTRANSFORMFEEDBACKPROC					begin_transform_feedback				= nullptr;
	PFNGLBINDATTRIBLOCATIONPROC						bind_attrib_location					= nullptr;
	PFNGLBINDBUFFERPROC								bind_buffer								= nullptr;
	PFNGLBINDBUFFERBASEPROC							bind_buffer_base						= nullptr;
	PFNGLBINDBUFFERRANGEPROC						bind_buffer_range						= nullptr;
	PFNGLBINDFRAMEBUFFERPROC						bind_framebuffer						= nullptr;
	PFNGLBINDRENDERBUFFERPROC						bind_renderbuffer						= nullptr;
	PFNGLBINDSAMPLERPROC							bind_sampler							= nullptr;
	PFNGLBINDTEXTUREPROC							bind_texture							= nullptr;
	PFNGLBINDTRANSFORMFEEDBACKPROC					bind_transform_feedback					= nullptr;
	PFNGLBINDVERTEXARRAYPROC						bind_vertex_array						= nullptr;
	PFNGLBLENDCOLORPROC								blend_color								= nullptr;
	PFNGLBLENDEQUATIONPROC							blend_equation							= nullptr;
	PFNGLBLENDEQUATIONSEPARATEPROC					blend_equation_separate					= nullptr;
	PFNGLBLENDFUNCPROC								blend_func								= nullptr;
	PFNGLBLENDFUNCSEPARATEPROC						blend_func_separate						= nullptr;
	PFNGLBLITFRAMEBUFFERPROC						blit_framebuffer						= nullptr;
	PFNGLBUFFERDATAPROC								buffer_data								= nullptr;
	PFNGLBUFFERSUBDATAPROC							buffer_sub_data							= nullptr;
	PFNGLCHECKFRAMEBUFFERSTATUSPROC					check_framebuffer_status				= nullptr;
	PFNGLCLEARPROC									clear									= nullptr;
	PFNGLCLEARBUFFERFIPROC							clear_bufferfi							= nullptr;
	PFNGLCLEARBUFFERFVPROC							clear_bufferfv							= nullptr;
	PFNGLCLEARBUFFERIVPROC							clear_bufferiv							= nullptr;
	PFNGLCLEARBUFFERUIVPROC							clear_bufferuiv							= nullptr;
	PFNGLCLEARCOLORPROC								clear_color								= nullptr;
	PFNGLCLEARDEPTHFPROC							clear_depthf							= nullptr;
	PFNGLCLEARSTENCILPROC							clear_stencil							= nullptr;
	PFNGLCLIENTWAITSYNCPROC							client_wait_sync						= nullptr;
	PFNGLCOLORMASKPROC								color_mask								= nullptr;
	PFNGLCOMPILESHADERPROC							compile_shader							= nullptr;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC					compressed_tex_image2d					= nullptr;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC					compressed_tex_image3d					= nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC				compressed_tex_sub_image2d				= nullptr;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC				compressed_tex_sub_image3d				= nullptr;
	PFNGLCOPYBUFFERSUBDATAPROC						copy_buffer_sub_data					= nullptr;
	PFNGLCOPYTEXIMAGE2DPROC							copy_tex_image2d						= nullptr;
	PFNGLCOPYTEXSUBIMAGE2DPROC						copy_tex_sub_image2d					= nullptr;
	PFNGLCOPYTEXSUBIMAGE3DPROC						copy_tex_sub_image3d					= nullptr;
	PFNGLCREATEPROGRAMPROC							create_program							= nullptr;
	PFNGLCREATESHADERPROC							create_shader							= nullptr;
	PFNGLCULLFACEPROC								cull_face								= nullptr;
	PFNGLDELETEBUFFERSPROC							delete_buffers							= nullptr;
	PFNGLDELETEFRAMEBUFFERSPROC						delete_framebuffers						= nullptr;
	PFNGLDELETEPROGRAMPROC							delete_program							= nullptr;
	PFNGLDELETEQUERIESPROC							delete_queries							= nullptr;
	PFNGLDELETERENDERBUFFERSPROC					delete_renderbuffers					= nullptr;
	PFNGLDELETESAMPLERSPROC							delete_samplers							= nullptr;
	PFNGLDELETESHADERPROC							delete_shader							= nullptr;
	PFNGLDELETESYNCPROC								delete_sync								= nullptr;
	PFNGLDELETETEXTURESPROC							delete_textures							= nullptr;
	PFNGLDELETETRANSFORMFEEDBACKSPROC				delete_transform_feedbacks				= nullptr;
	PFNGLDELETEVERTEXARRAYSPROC						delete_vertex_arrays					= nullptr;
	PFNGLDEPTHFUNCPROC								depth_func								= nullptr;
	PFNGLDEPTHMASKPROC								depth_mask								= nullptr;
	PFNGLDEPTHRANGEFPROC							depth_rangef							= nullptr;
	PFNGLDETACHSHADERPROC							detach_shader							= nullptr;
	PFNGLDISABLEPROC								disable									= nullptr;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC				disable_vertex_attrib_array				= nullptr;
	PFNGLDRAWARRAYSPROC								draw_arrays								= nullptr;
	PFNGLDRAWARRAYSINSTANCEDPROC					draw_arrays_instanced					= nullptr;
	PFNGLDRAWBUFFERSPROC							draw_buffers							= nullptr;
	PFNGLDRAWELEMENTSPROC							draw_elements							= nullptr;
	PFNGLDRAWELEMENTSINSTANCEDPROC					draw_elements_instanced					= nullptr;
	PFNGLDRAWRANGEELEMENTSPROC						draw_range_elements						= nullptr;
	PFNGLENABLEPROC									enable									= nullptr;
	PFNGLENABLEVERTEXATTRIBARRAYPROC				enable_vertex_attrib_array				= nullptr;
	PFNGLENDQUERYPROC								end_query								= nullptr;
	PFNGLENDTRANSFORMFEEDBACKPROC					end_transform_feedback					= nullptr;
	PFNGLFENCESYNCPROC								fence_sync								= nullptr;
	PFNGLFINISHPROC									finish									= nullptr;
	PFNGLFLUSHPROC									flush									= nullptr;
	PFNGLFLUSHMAPPEDBUFFERRANGEPROC					flush_mapped_buffer_range				= nullptr;
	PFNGLFRAMEBUFFERRENDERBUFFERPROC				framebuffer_renderbuffer				= nullptr;
	PFNGLFRAMEBUFFERTEXTURE2DPROC					framebuffer_texture2d					= nullptr;
	PFNGLFRAMEBUFFERTEXTURELAYERPROC				framebuffer_texture_layer				= nullptr;
	PFNGLFRONTFACEPROC								front_face								= nullptr;
	PFNGLGENBUFFERSPROC								gen_buffers								= nullptr;
	PFNGLGENFRAMEBUFFERSPROC						gen_framebuffers						= nullptr;
	PFNGLGENQUERIESPROC								gen_queries								= nullptr;
	PFNGLGENRENDERBUFFERSPROC						gen_renderbuffers						= nullptr;
	PFNGLGENSAMPLERSPROC							gen_samplers							= nullptr;
	PFNGLGENTEXTURESPROC							gen_textures							= nullptr;
	PFNGLGENTRANSFORMFEEDBACKSPROC					gen_transform_feedbacks					= nullptr;
	PFNGLGENVERTEXARRAYSPROC						gen_vertex_arrays						= nullptr;
	PFNGLGENERATEMIPMAPPROC							generate_mipmap							= nullptr;
	PFNGLGETACTIVEATTRIBPROC						get_active_attrib						= nullptr;
	PFNGLGETACTIVEUNIFORMPROC						get_active_uniform						= nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC				get_active_uniform_block_name			= nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC				get_active_uniform_blockiv				= nullptr;
	PFNGLGETACTIVEUNIFORMSIVPROC					get_active_uniformsiv					= nullptr;
	PFNGLGETATTACHEDSHADERSPROC						get_attached_shaders					= nullptr;
	PFNGLGETATTRIBLOCATIONPROC						get_attrib_location						= nullptr;
	PFNGLGETBOOLEANVPROC							get_booleanv							= nullptr;
	PFNGLGETBUFFERPARAMETERI64VPROC					get_buffer_parameteri64v				= nullptr;
	PFNGLGETBUFFERPARAMETERIVPROC					get_buffer_parameteriv					= nullptr;
	PFNGLGETBUFFERPOINTERVPROC						get_buffer_pointerv						= nullptr;
	PFNGLGETERRORPROC								get_error								= nullptr;
	PFNGLGETFLOATVPROC								get_floatv								= nullptr;
	PFNGLGETFRAGDATALOCATIONPROC					get_frag_data_location					= nullptr;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC	get_framebuffer_attachment_parameteriv	= nullptr;
	PFNGLGETINTEGER64I_VPROC						get_integer64i_v						= nullptr;
	PFNGLGETINTEGER64VPROC							get_integer64v							= nullptr;
	PFNGLGETINTEGERI_VPROC							get_integeri_v							= nullptr;
	PFNGLGETINTEGERVPROC							get_integerv							= nullptr;
	PFNGLGETINTERNALFORMATIVPROC					get_internalformativ					= nullptr;
	PFNGLGETPROGRAMBINARYPROC						get_program_binary						= nullptr;
	PFNGLGETPROGRAMINFOLOGPROC						get_program_info_log					= nullptr;
	PFNGLGETPROGRAMIVPROC							get_programiv							= nullptr;
	PFNGLGETQUERYOBJECTUIVPROC						get_query_objectuiv						= nullptr;
	PFNGLGETQUERYIVPROC								get_queryiv								= nullptr;
	PFNGLGETRENDERBUFFERPARAMETERIVPROC				get_renderbuffer_parameteriv			= nullptr;
	PFNGLGETSAMPLERPARAMETERFVPROC					get_sampler_parameterfv					= nullptr;
	PFNGLGETSAMPLERPARAMETERIVPROC					get_sampler_parameteriv					= nullptr;
	PFNGLGETSHADERINFOLOGPROC						get_shader_info_log						= nullptr;
	PFNGLGETSHADERPRECISIONFORMATPROC				get_shader_precision_format				= nullptr;
	PFNGLGETSHADERSOURCEPROC						get_shader_source						= nullptr;
	PFNGLGETSHADERIVPROC							get_shaderiv							= nullptr;
	PFNGLGETSTRINGPROC								get_string								= nullptr;
	PFNGLGETSTRINGIPROC								get_stringi								= nullptr;
	PFNGLGETSYNCIVPROC								get_synciv								= nullptr;
	PFNGLGETTEXPARAMETERFVPROC						get_tex_parameterfv						= nullptr;
	PFNGLGETTEXPARAMETERIVPROC						get_tex_parameteriv						= nullptr;
	PFNGLGETTRANSFORMFEEDBACKVARYINGPROC			get_transform_feedback_varying			= nullptr;
	PFNGLGETUNIFORMBLOCKINDEXPROC					get_uniform_block_index					= nullptr;
	PFNGLGETUNIFORMINDICESPROC						get_uniform_indices						= nullptr;
	PFNGLGETUNIFORMLOCATIONPROC						get_uniform_location					= nullptr;
	PFNGLGETUNIFORMFVPROC							get_uniformfv							= nullptr;
	PFNGLGETUNIFORMIVPROC							get_uniformiv							= nullptr;
	PFNGLGETUNIFORMUIVPROC							get_uniformuiv							= nullptr;
	PFNGLGETVERTEXATTRIBIIVPROC						get_vertex_attrib_iiv					= nullptr;
	PFNGLGETVERTEXATTRIBIUIVPROC					get_vertex_attrib_iuiv					= nullptr;
	PFNGLGETVERTEXATTRIBPOINTERVPROC				get_vertex_attrib_pointerv				= nullptr;
	PFNGLGETVERTEXATTRIBFVPROC						get_vertex_attribfv						= nullptr;
	PFNGLGETVERTEXATTRIBIVPROC						get_vertex_attribiv						= nullptr;
	PFNGLHINTPROC									hint									= nullptr;
	PFNGLINVALIDATEFRAMEBUFFERPROC					invalidate_framebuffer					= nullptr;
	PFNGLINVALIDATESUBFRAMEBUFFERPROC				invalidate_sub_framebuffer				= nullptr;
	PFNGLISBUFFERPROC								is_buffer								= nullptr;
	PFNGLISENABLEDPROC								is_enabled								= nullptr;
	PFNGLISFRAMEBUFFERPROC							is_framebuffer							= nullptr;
	PFNGLISPROGRAMPROC								is_program								= nullptr;
	PFNGLISQUERYPROC								is_query								= nullptr;
	PFNGLISRENDERBUFFERPROC							is_renderbuffer							= nullptr;
	PFNGLISSAMPLERPROC								is_sampler								= nullptr;
	PFNGLISSHADERPROC								is_shader								= nullptr;
	PFNGLISSYNCPROC									is_sync									= nullptr;
	PFNGLISTEXTUREPROC								is_texture								= nullptr;
	PFNGLISTRANSFORMFEEDBACKPROC					is_transform_feedback					= nullptr;
	PFNGLISVERTEXARRAYPROC							is_vertex_array							= nullptr;
	PFNGLLINEWIDTHPROC								line_width								= nullptr;
	PFNGLLINKPROGRAMPROC							link_program							= nullptr;
	PFNGLMAPBUFFERRANGEPROC							map_buffer_range						= nullptr;
	PFNGLPAUSETRANSFORMFEEDBACKPROC					pause_transform_feedback				= nullptr;
	PFNGLPIXELSTOREIPROC							pixel_storei							= nullptr;
	PFNGLPOLYGONOFFSETPROC							polygon_offset							= nullptr;
	PFNGLPROGRAMBINARYPROC							program_binary							= nullptr;
	PFNGLPROGRAMPARAMETERIPROC						program_parameteri						= nullptr;
	PFNGLREADBUFFERPROC								read_buffer								= nullptr;
	PFNGLREADPIXELSPROC								read_pixels								= nullptr;
	PFNGLRELEASESHADERCOMPILERPROC					release_shader_compiler					= nullptr;
	PFNGLRENDERBUFFERSTORAGEPROC					renderbuffer_storage					= nullptr;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC			renderbuffer_storage_multisample		= nullptr;
	PFNGLRESUMETRANSFORMFEEDBACKPROC				resume_transform_feedback				= nullptr;
	PFNGLSAMPLECOVERAGEPROC							sample_coverage							= nullptr;
	PFNGLSAMPLERPARAMETERFPROC						sampler_parameterf						= nullptr;
	PFNGLSAMPLERPARAMETERFVPROC						sampler_parameterfv						= nullptr;
	PFNGLSAMPLERPARAMETERIPROC						sampler_parameteri						= nullptr;
	PFNGLSAMPLERPARAMETERIVPROC						sampler_parameteriv						= nullptr;
	PFNGLSCISSORPROC								scissor									= nullptr;
	PFNGLSHADERBINARYPROC							shader_binary							= nullptr;
	PFNGLSHADERSOURCEPROC							shader_source							= nullptr;
	PFNGLSTENCILFUNCPROC							stencil_func							= nullptr;
	PFNGLSTENCILFUNCSEPARATEPROC					stencil_func_separate					= nullptr;
	PFNGLSTENCILMASKPROC							stencil_mask							= nullptr;
	PFNGLSTENCILMASKSEPARATEPROC					stencil_mask_separate					= nullptr;
	PFNGLSTENCILOPPROC								stencil_op								= nullptr;
	PFNGLSTENCILOPSEPARATEPROC						stencil_op_separate						= nullptr;
	PFNGLTEXIMAGE2DPROC								tex_image2_d							= nullptr;
	PFNGLTEXIMAGE3DPROC								tex_image3_d							= nullptr;
	PFNGLTEXPARAMETERFPROC							tex_parameterf							= nullptr;
	PFNGLTEXPARAMETERFVPROC							tex_parameterfv							= nullptr;
	PFNGLTEXPARAMETERIPROC							tex_parameteri							= nullptr;
	PFNGLTEXPARAMETERIVPROC							tex_parameteriv							= nullptr;
	PFNGLTEXSTORAGE2DPROC							tex_storage2_d							= nullptr;
	PFNGLTEXSTORAGE3DPROC							tex_storage3_d							= nullptr;
	PFNGLTEXSUBIMAGE2DPROC							tex_sub_image2_d						= nullptr;
	PFNGLTEXSUBIMAGE3DPROC							tex_sub_image3_d						= nullptr;
	PFNGLTRANSFORMFEEDBACKVARYINGSPROC				transform_feedback_varyings				= nullptr;
	PFNGLUNIFORM1FPROC								uniform1f								= nullptr;
	PFNGLUNIFORM1FVPROC								uniform1fv								= nullptr;
	PFNGLUNIFORM1IPROC								uniform1i								= nullptr;
	PFNGLUNIFORM1IVPROC								uniform1iv								= nullptr;
	PFNGLUNIFORM1UIPROC								uniform1ui								= nullptr;
	PFNGLUNIFORM1UIVPROC							uniform1uiv								= nullptr;
	PFNGLUNIFORM2FPROC								uniform2f								= nullptr;
	PFNGLUNIFORM2FVPROC								uniform2fv								= nullptr;
	PFNGLUNIFORM2IPROC								uniform2i								= nullptr;
	PFNGLUNIFORM2IVPROC								uniform2iv								= nullptr;
	PFNGLUNIFORM2UIPROC								uniform2ui								= nullptr;
	PFNGLUNIFORM2UIVPROC							uniform2uiv								= nullptr;
	PFNGLUNIFORM3FPROC								uniform3f								= nullptr;
	PFNGLUNIFORM3FVPROC								uniform3fv								= nullptr;
	PFNGLUNIFORM3IPROC								uniform3i								= nullptr;
	PFNGLUNIFORM3IVPROC								uniform3iv								= nullptr;
	PFNGLUNIFORM3UIPROC								uniform3ui								= nullptr;
	PFNGLUNIFORM3UIVPROC							uniform3uiv								= nullptr;
	PFNGLUNIFORM4FPROC								uniform4f								= nullptr;
	PFNGLUNIFORM4FVPROC								uniform4fv								= nullptr;
	PFNGLUNIFORM4IPROC								uniform4i								= nullptr;
	PFNGLUNIFORM4IVPROC								uniform4iv								= nullptr;
	PFNGLUNIFORM4UIPROC								uniform4ui								= nullptr;
	PFNGLUNIFORM4UIVPROC							uniform4uiv								= nullptr;
	PFNGLUNIFORMBLOCKBINDINGPROC					uniform_block_binding					= nullptr;
	PFNGLUNIFORMMATRIX2FVPROC						uniform_matrix2fv						= nullptr;
	PFNGLUNIFORMMATRIX2X3FVPROC						uniform_matrix2x3fv						= nullptr;
	PFNGLUNIFORMMATRIX2X4FVPROC						uniform_matrix2x4fv						= nullptr;
	PFNGLUNIFORMMATRIX3FVPROC						uniform_matrix3fv						= nullptr;
	PFNGLUNIFORMMATRIX3X2FVPROC						uniform_matrix3x2fv						= nullptr;
	PFNGLUNIFORMMATRIX3X4FVPROC						uniform_matrix3x4fv						= nullptr;
	PFNGLUNIFORMMATRIX4FVPROC						uniform_matrix4fv						= nullptr;
	PFNGLUNIFORMMATRIX4X2FVPROC						uniform_matrix4x2fv						= nullptr;
	PFNGLUNIFORMMATRIX4X3FVPROC						uniform_matrix4x3fv						= nullptr;
	PFNGLUNMAPBUFFERPROC							unmap_buffer							= nullptr;
	PFNGLUSEPROGRAMPROC								use_program								= nullptr;
	PFNGLVALIDATEPROGRAMPROC						validate_program						= nullptr;
	PFNGLVERTEXATTRIB1FPROC							vertex_attrib1f							= nullptr;
	PFNGLVERTEXATTRIB1FVPROC						vertex_attrib1fv						= nullptr;
	PFNGLVERTEXATTRIB2FPROC							vertex_attrib2f							= nullptr;
	PFNGLVERTEXATTRIB2FVPROC						vertex_attrib2fv						= nullptr;
	PFNGLVERTEXATTRIB3FPROC							vertex_attrib3f							= nullptr;
	PFNGLVERTEXATTRIB3FVPROC						vertex_attrib3fv						= nullptr;
	PFNGLVERTEXATTRIB4FPROC							vertex_attrib4f							= nullptr;
	PFNGLVERTEXATTRIB4FVPROC						vertex_attrib4fv						= nullptr;
	PFNGLVERTEXATTRIBDIVISORPROC					vertex_attrib_divisor					= nullptr;
	PFNGLVERTEXATTRIBI4IPROC						vertex_attrib_i4i						= nullptr;
	PFNGLVERTEXATTRIBI4IVPROC						vertex_attrib_i4iv						= nullptr;
	PFNGLVERTEXATTRIBI4UIPROC						vertex_attrib_i4ui						= nullptr;
	PFNGLVERTEXATTRIBI4UIVPROC						vertex_attrib_i4uiv						= nullptr;
	PFNGLVERTEXATTRIBIPOINTERPROC					vertex_attrib_i_pointer					= nullptr;
	PFNGLVERTEXATTRIBPOINTERPROC					vertex_attrib_pointer					= nullptr;
	PFNGLVIEWPORTPROC								viewport								= nullptr;
	PFNGLWAITSYNCPROC								wait_sync								= nullptr;
}
