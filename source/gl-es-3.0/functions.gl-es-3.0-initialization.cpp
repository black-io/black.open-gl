#include <black/open-gl/gl-es-3.0.h>

#include "gles/bindings.gl-es-3.0.h"


namespace Black
{
inline namespace OpenGl
{
inline namespace GlEs30
{
namespace
{
	// Logging channel.
	constexpr const char* LOG_CHANNEL = "Black/OpenGL/GL ES 3.0";


	// Load the address of OpenGL ES 3.0 function using the given function name.
	template< typename TFunction >
	inline void LoadFunctionAddress( TFunction& destination_popinter, const char* name, const Black::EglConnection& connection )
	{
		destination_popinter = reinterpret_cast<TFunction>( connection.GetFunctionAddress( name ) );
		if( destination_popinter == nullptr )
		{
			BLACK_LOG_WARNING( LOG_CHANNEL, "Function '{}' does not found.", std::string_view{ name } );
		}
	}
}


	void GlEnsureInitialized( const Black::EglConnection& connection )
	{
		BLACK_LOG_DEBUG( LOG_CHANNEL, "Initializing the bindings for OpenGL ES 3.0." );

		LoadFunctionAddress( ::GlEs30::active_texture, "glActiveTexture", connection );
		LoadFunctionAddress( ::GlEs30::attach_shader, "glAttachShader", connection );
		LoadFunctionAddress( ::GlEs30::begin_query, "glBeginQuery", connection );
		LoadFunctionAddress( ::GlEs30::begin_transform_feedback, "glBeginTransformFeedback", connection );
		LoadFunctionAddress( ::GlEs30::bind_attrib_location, "glBindAttribLocation", connection );
		LoadFunctionAddress( ::GlEs30::bind_buffer, "glBindBuffer", connection );
		LoadFunctionAddress( ::GlEs30::bind_buffer_base, "glBindBufferBase", connection );
		LoadFunctionAddress( ::GlEs30::bind_buffer_range, "glBindBufferRange", connection );
		LoadFunctionAddress( ::GlEs30::bind_framebuffer, "glBindFramebuffer", connection );
		LoadFunctionAddress( ::GlEs30::bind_renderbuffer, "glBindRenderbuffer", connection );
		LoadFunctionAddress( ::GlEs30::bind_sampler, "glBindSampler", connection );
		LoadFunctionAddress( ::GlEs30::bind_texture, "glBindTexture", connection );
		LoadFunctionAddress( ::GlEs30::bind_transform_feedback, "glBindTransformFeedback", connection );
		LoadFunctionAddress( ::GlEs30::bind_vertex_array, "glBindVertexArray", connection );
		LoadFunctionAddress( ::GlEs30::blend_color, "glBlendColor", connection );
		LoadFunctionAddress( ::GlEs30::blend_equation, "glBlendEquation", connection );
		LoadFunctionAddress( ::GlEs30::blend_equation_separate, "glBlendEquationSeparate", connection );
		LoadFunctionAddress( ::GlEs30::blend_func, "glBlendFunc", connection );
		LoadFunctionAddress( ::GlEs30::blend_func_separate, "glBlendFuncSeparate", connection );
		LoadFunctionAddress( ::GlEs30::blit_framebuffer, "glBlitFramebuffer", connection );
		LoadFunctionAddress( ::GlEs30::buffer_data, "glBufferData", connection );
		LoadFunctionAddress( ::GlEs30::buffer_sub_data, "glBufferSubData", connection );
		LoadFunctionAddress( ::GlEs30::check_framebuffer_status, "glCheckFramebufferStatus", connection );
		LoadFunctionAddress( ::GlEs30::clear, "glClear", connection );
		LoadFunctionAddress( ::GlEs30::clear_bufferfi, "glClearBufferfi", connection );
		LoadFunctionAddress( ::GlEs30::clear_bufferfv, "glClearBufferfv", connection );
		LoadFunctionAddress( ::GlEs30::clear_bufferiv, "glClearBufferiv", connection );
		LoadFunctionAddress( ::GlEs30::clear_bufferuiv, "glClearBufferuiv", connection );
		LoadFunctionAddress( ::GlEs30::clear_color, "glClearColor", connection );
		LoadFunctionAddress( ::GlEs30::clear_depthf, "glClearDepthf", connection );
		LoadFunctionAddress( ::GlEs30::clear_stencil, "glClearStencil", connection );
		LoadFunctionAddress( ::GlEs30::client_wait_sync, "glClientWaitSync", connection );
		LoadFunctionAddress( ::GlEs30::color_mask, "glColorMask", connection );
		LoadFunctionAddress( ::GlEs30::compile_shader, "glCompileShader", connection );
		LoadFunctionAddress( ::GlEs30::compressed_tex_image2d, "glCompressedTexImage2D", connection );
		LoadFunctionAddress( ::GlEs30::compressed_tex_image3d, "glCompressedTexImage3D", connection );
		LoadFunctionAddress( ::GlEs30::compressed_tex_sub_image2d, "glCompressedTexSubImage2D", connection );
		LoadFunctionAddress( ::GlEs30::compressed_tex_sub_image3d, "glCompressedTexSubImage3D", connection );
		LoadFunctionAddress( ::GlEs30::copy_buffer_sub_data, "glCopyBufferSubData", connection );
		LoadFunctionAddress( ::GlEs30::copy_tex_image2d, "glCopyTexImage2D", connection );
		LoadFunctionAddress( ::GlEs30::copy_tex_sub_image2d, "glCopyTexSubImage2D", connection );
		LoadFunctionAddress( ::GlEs30::copy_tex_sub_image3d, "glCopyTexSubImage3D", connection );
		LoadFunctionAddress( ::GlEs30::create_program, "glCreateProgram", connection );
		LoadFunctionAddress( ::GlEs30::create_shader, "glCreateShader", connection );
		LoadFunctionAddress( ::GlEs30::cull_face, "glCullFace", connection );
		LoadFunctionAddress( ::GlEs30::delete_buffers, "glDeleteBuffers", connection );
		LoadFunctionAddress( ::GlEs30::delete_framebuffers, "glDeleteFramebuffers", connection );
		LoadFunctionAddress( ::GlEs30::delete_program, "glDeleteProgram", connection );
		LoadFunctionAddress( ::GlEs30::delete_queries, "glDeleteQueries", connection );
		LoadFunctionAddress( ::GlEs30::delete_renderbuffers, "glDeleteRenderbuffers", connection );
		LoadFunctionAddress( ::GlEs30::delete_samplers, "glDeleteSamplers", connection );
		LoadFunctionAddress( ::GlEs30::delete_shader, "glDeleteShader", connection );
		LoadFunctionAddress( ::GlEs30::delete_sync, "glDeleteSync", connection );
		LoadFunctionAddress( ::GlEs30::delete_textures, "glDeleteTextures", connection );
		LoadFunctionAddress( ::GlEs30::delete_transform_feedbacks, "glDeleteTransformFeedbacks", connection );
		LoadFunctionAddress( ::GlEs30::delete_vertex_arrays, "glDeleteVertexArrays", connection );
		LoadFunctionAddress( ::GlEs30::depth_func, "glDepthFunc", connection );
		LoadFunctionAddress( ::GlEs30::depth_mask, "glDepthMask", connection );
		LoadFunctionAddress( ::GlEs30::depth_rangef, "glDepthRangef", connection );
		LoadFunctionAddress( ::GlEs30::detach_shader, "glDetachShader", connection );
		LoadFunctionAddress( ::GlEs30::disable, "glDisable", connection );
		LoadFunctionAddress( ::GlEs30::disable_vertex_attrib_array, "glDisableVertexAttribArray", connection );
		LoadFunctionAddress( ::GlEs30::draw_arrays, "glDrawArrays", connection );
		LoadFunctionAddress( ::GlEs30::draw_arrays_instanced, "glDrawArraysInstanced", connection );
		LoadFunctionAddress( ::GlEs30::draw_buffers, "glDrawBuffers", connection );
		LoadFunctionAddress( ::GlEs30::draw_elements, "glDrawElements", connection );
		LoadFunctionAddress( ::GlEs30::draw_elements_instanced, "glDrawElementsInstanced", connection );
		LoadFunctionAddress( ::GlEs30::draw_range_elements, "glDrawRangeElements", connection );
		LoadFunctionAddress( ::GlEs30::enable, "glEnable", connection );
		LoadFunctionAddress( ::GlEs30::enable_vertex_attrib_array, "glEnableVertexAttribArray", connection );
		LoadFunctionAddress( ::GlEs30::end_query, "glEndQuery", connection );
		LoadFunctionAddress( ::GlEs30::end_transform_feedback, "glEndTransformFeedback", connection );
		LoadFunctionAddress( ::GlEs30::fence_sync, "glFenceSync", connection );
		LoadFunctionAddress( ::GlEs30::finish, "glFinish", connection );
		LoadFunctionAddress( ::GlEs30::flush, "glFlush", connection );
		LoadFunctionAddress( ::GlEs30::flush_mapped_buffer_range, "glFlushMappedBufferRange", connection );
		LoadFunctionAddress( ::GlEs30::framebuffer_renderbuffer, "glFramebufferRenderbuffer", connection );
		LoadFunctionAddress( ::GlEs30::framebuffer_texture2d, "glFramebufferTexture2D", connection );
		LoadFunctionAddress( ::GlEs30::framebuffer_texture_layer, "glFramebufferTextureLayer", connection );
		LoadFunctionAddress( ::GlEs30::front_face, "glFrontFace", connection );
		LoadFunctionAddress( ::GlEs30::gen_buffers, "glGenBuffers", connection );
		LoadFunctionAddress( ::GlEs30::gen_framebuffers, "glGenFramebuffers", connection );
		LoadFunctionAddress( ::GlEs30::gen_queries, "glGenQueries", connection );
		LoadFunctionAddress( ::GlEs30::gen_renderbuffers, "glGenRenderbuffers", connection );
		LoadFunctionAddress( ::GlEs30::gen_samplers, "glGenSamplers", connection );
		LoadFunctionAddress( ::GlEs30::gen_textures, "glGenTextures", connection );
		LoadFunctionAddress( ::GlEs30::gen_transform_feedbacks, "glGenTransformFeedbacks", connection );
		LoadFunctionAddress( ::GlEs30::gen_vertex_arrays, "glGenVertexArrays", connection );
		LoadFunctionAddress( ::GlEs30::generate_mipmap, "glGenerateMipmap", connection );
		LoadFunctionAddress( ::GlEs30::get_active_attrib, "glGetActiveAttrib", connection );
		LoadFunctionAddress( ::GlEs30::get_active_uniform, "glGetActiveUniform", connection );
		LoadFunctionAddress( ::GlEs30::get_active_uniform_block_name, "glGetActiveUniformBlockName", connection );
		LoadFunctionAddress( ::GlEs30::get_active_uniform_blockiv, "glGetActiveUniformBlockiv", connection );
		LoadFunctionAddress( ::GlEs30::get_active_uniformsiv, "glGetActiveUniformsiv", connection );
		LoadFunctionAddress( ::GlEs30::get_attached_shaders, "glGetAttachedShaders", connection );
		LoadFunctionAddress( ::GlEs30::get_attrib_location, "glGetAttribLocation", connection );
		LoadFunctionAddress( ::GlEs30::get_booleanv, "glGetBooleanv", connection );
		LoadFunctionAddress( ::GlEs30::get_buffer_parameteri64v, "glGetBufferParameteri64v", connection );
		LoadFunctionAddress( ::GlEs30::get_buffer_parameteriv, "glGetBufferParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::get_buffer_pointerv, "glGetBufferPointerv", connection );
		LoadFunctionAddress( ::GlEs30::get_error, "glGetError", connection );
		LoadFunctionAddress( ::GlEs30::get_floatv, "glGetFloatv", connection );
		LoadFunctionAddress( ::GlEs30::get_frag_data_location, "glGetFragDataLocation", connection );
		LoadFunctionAddress( ::GlEs30::get_framebuffer_attachment_parameteriv, "glGetFramebufferAttachmentParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::get_integer64i_v, "glGetInteger64i_v", connection );
		LoadFunctionAddress( ::GlEs30::get_integer64v, "glGetInteger64v", connection );
		LoadFunctionAddress( ::GlEs30::get_integeri_v, "glGetIntegeri_v", connection );
		LoadFunctionAddress( ::GlEs30::get_integerv, "glGetIntegerv", connection );
		LoadFunctionAddress( ::GlEs30::get_internalformativ, "glGetInternalformativ", connection );
		LoadFunctionAddress( ::GlEs30::get_program_binary, "glGetProgramBinary", connection );
		LoadFunctionAddress( ::GlEs30::get_program_info_log, "glGetProgramInfoLog", connection );
		LoadFunctionAddress( ::GlEs30::get_programiv, "glGetProgramiv", connection );
		LoadFunctionAddress( ::GlEs30::get_query_objectuiv, "glGetQueryObjectuiv", connection );
		LoadFunctionAddress( ::GlEs30::get_queryiv, "glGetQueryiv", connection );
		LoadFunctionAddress( ::GlEs30::get_renderbuffer_parameteriv, "glGetRenderbufferParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::get_sampler_parameterfv, "glGetSamplerParameterfv", connection );
		LoadFunctionAddress( ::GlEs30::get_sampler_parameteriv, "glGetSamplerParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::get_shader_info_log, "glGetShaderInfoLog", connection );
		LoadFunctionAddress( ::GlEs30::get_shader_precision_format, "glGetShaderPrecisionFormat", connection );
		LoadFunctionAddress( ::GlEs30::get_shader_source, "glGetShaderSource", connection );
		LoadFunctionAddress( ::GlEs30::get_shaderiv, "glGetShaderiv", connection );
		LoadFunctionAddress( ::GlEs30::get_string, "glGetString", connection );
		LoadFunctionAddress( ::GlEs30::get_stringi, "glGetStringi", connection );
		LoadFunctionAddress( ::GlEs30::get_synciv, "glGetSynciv", connection );
		LoadFunctionAddress( ::GlEs30::get_tex_parameterfv, "glGetTexParameterfv", connection );
		LoadFunctionAddress( ::GlEs30::get_tex_parameteriv, "glGetTexParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::get_transform_feedback_varying, "glGetTransformFeedbackVarying", connection );
		LoadFunctionAddress( ::GlEs30::get_uniform_block_index, "glGetUniformBlockIndex", connection );
		LoadFunctionAddress( ::GlEs30::get_uniform_indices, "glGetUniformIndices", connection );
		LoadFunctionAddress( ::GlEs30::get_uniform_location, "glGetUniformLocation", connection );
		LoadFunctionAddress( ::GlEs30::get_uniformfv, "glGetUniformfv", connection );
		LoadFunctionAddress( ::GlEs30::get_uniformiv, "glGetUniformiv", connection );
		LoadFunctionAddress( ::GlEs30::get_uniformuiv, "glGetUniformuiv", connection );
		LoadFunctionAddress( ::GlEs30::get_vertex_attrib_iiv, "glGetVertexAttribIiv", connection );
		LoadFunctionAddress( ::GlEs30::get_vertex_attrib_iuiv, "glGetVertexAttribIuiv", connection );
		LoadFunctionAddress( ::GlEs30::get_vertex_attrib_pointerv, "glGetVertexAttribPointerv", connection );
		LoadFunctionAddress( ::GlEs30::get_vertex_attribfv, "glGetVertexAttribfv", connection );
		LoadFunctionAddress( ::GlEs30::get_vertex_attribiv, "glGetVertexAttribiv", connection );
		LoadFunctionAddress( ::GlEs30::hint, "glHint", connection );
		LoadFunctionAddress( ::GlEs30::invalidate_framebuffer, "glInvalidateFramebuffer", connection );
		LoadFunctionAddress( ::GlEs30::invalidate_sub_framebuffer, "glInvalidateSubFramebuffer", connection );
		LoadFunctionAddress( ::GlEs30::is_buffer, "glIsBuffer", connection );
		LoadFunctionAddress( ::GlEs30::is_enabled, "glIsEnabled", connection );
		LoadFunctionAddress( ::GlEs30::is_framebuffer, "glIsFramebuffer", connection );
		LoadFunctionAddress( ::GlEs30::is_program, "glIsProgram", connection );
		LoadFunctionAddress( ::GlEs30::is_query, "glIsQuery", connection );
		LoadFunctionAddress( ::GlEs30::is_renderbuffer, "glIsRenderbuffer", connection );
		LoadFunctionAddress( ::GlEs30::is_sampler, "glIsSampler", connection );
		LoadFunctionAddress( ::GlEs30::is_shader, "glIsShader", connection );
		LoadFunctionAddress( ::GlEs30::is_sync, "glIsSync", connection );
		LoadFunctionAddress( ::GlEs30::is_texture, "glIsTexture", connection );
		LoadFunctionAddress( ::GlEs30::is_transform_feedback, "glIsTransformFeedback", connection );
		LoadFunctionAddress( ::GlEs30::is_vertex_array, "glIsVertexArray", connection );
		LoadFunctionAddress( ::GlEs30::line_width, "glLineWidth", connection );
		LoadFunctionAddress( ::GlEs30::link_program, "glLinkProgram", connection );
		LoadFunctionAddress( ::GlEs30::map_buffer_range, "glMapBufferRange", connection );
		LoadFunctionAddress( ::GlEs30::pause_transform_feedback, "glPauseTransformFeedback", connection );
		LoadFunctionAddress( ::GlEs30::pixel_storei, "glPixelStorei", connection );
		LoadFunctionAddress( ::GlEs30::polygon_offset, "glPolygonOffset", connection );
		LoadFunctionAddress( ::GlEs30::program_binary, "glProgramBinary", connection );
		LoadFunctionAddress( ::GlEs30::program_parameteri, "glProgramParameteri", connection );
		LoadFunctionAddress( ::GlEs30::read_buffer, "glReadBuffer", connection );
		LoadFunctionAddress( ::GlEs30::read_pixels, "glReadPixels", connection );
		LoadFunctionAddress( ::GlEs30::release_shader_compiler, "glReleaseShaderCompiler", connection );
		LoadFunctionAddress( ::GlEs30::renderbuffer_storage, "glRenderbufferStorage", connection );
		LoadFunctionAddress( ::GlEs30::renderbuffer_storage_multisample, "glRenderbufferStorageMultisample", connection );
		LoadFunctionAddress( ::GlEs30::resume_transform_feedback, "glResumeTransformFeedback", connection );
		LoadFunctionAddress( ::GlEs30::sample_coverage, "glSampleCoverage", connection );
		LoadFunctionAddress( ::GlEs30::sampler_parameterf, "glSamplerParameterf", connection );
		LoadFunctionAddress( ::GlEs30::sampler_parameterfv, "glSamplerParameterfv", connection );
		LoadFunctionAddress( ::GlEs30::sampler_parameteri, "glSamplerParameteri", connection );
		LoadFunctionAddress( ::GlEs30::sampler_parameteriv, "glSamplerParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::scissor, "glScissor", connection );
		LoadFunctionAddress( ::GlEs30::shader_binary, "glShaderBinary", connection );
		LoadFunctionAddress( ::GlEs30::shader_source, "glShaderSource", connection );
		LoadFunctionAddress( ::GlEs30::stencil_func, "glStencilFunc", connection );
		LoadFunctionAddress( ::GlEs30::stencil_func_separate, "glStencilFuncSeparate", connection );
		LoadFunctionAddress( ::GlEs30::stencil_mask, "glStencilMask", connection );
		LoadFunctionAddress( ::GlEs30::stencil_mask_separate, "glStencilMaskSeparate", connection );
		LoadFunctionAddress( ::GlEs30::stencil_op, "glStencilOp", connection );
		LoadFunctionAddress( ::GlEs30::stencil_op_separate, "glStencilOpSeparate", connection );
		LoadFunctionAddress( ::GlEs30::tex_image2_d, "glTexImage2D", connection );
		LoadFunctionAddress( ::GlEs30::tex_image3_d, "glTexImage3D", connection );
		LoadFunctionAddress( ::GlEs30::tex_parameterf, "glTexParameterf", connection );
		LoadFunctionAddress( ::GlEs30::tex_parameterfv, "glTexParameterfv", connection );
		LoadFunctionAddress( ::GlEs30::tex_parameteri, "glTexParameteri", connection );
		LoadFunctionAddress( ::GlEs30::tex_parameteriv, "glTexParameteriv", connection );
		LoadFunctionAddress( ::GlEs30::tex_storage2_d, "glTexStorage2D", connection );
		LoadFunctionAddress( ::GlEs30::tex_storage3_d, "glTexStorage3D", connection );
		LoadFunctionAddress( ::GlEs30::tex_sub_image2_d, "glTexSubImage2D", connection );
		LoadFunctionAddress( ::GlEs30::tex_sub_image3_d, "glTexSubImage3D", connection );
		LoadFunctionAddress( ::GlEs30::transform_feedback_varyings, "glTransformFeedbackVaryings", connection );
		LoadFunctionAddress( ::GlEs30::uniform1f, "glUniform1f", connection );
		LoadFunctionAddress( ::GlEs30::uniform1fv, "glUniform1fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform1i, "glUniform1i", connection );
		LoadFunctionAddress( ::GlEs30::uniform1iv, "glUniform1iv", connection );
		LoadFunctionAddress( ::GlEs30::uniform1ui, "glUniform1ui", connection );
		LoadFunctionAddress( ::GlEs30::uniform1uiv, "glUniform1uiv", connection );
		LoadFunctionAddress( ::GlEs30::uniform2f, "glUniform2f", connection );
		LoadFunctionAddress( ::GlEs30::uniform2fv, "glUniform2fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform2i, "glUniform2i", connection );
		LoadFunctionAddress( ::GlEs30::uniform2iv, "glUniform2iv", connection );
		LoadFunctionAddress( ::GlEs30::uniform2ui, "glUniform2ui", connection );
		LoadFunctionAddress( ::GlEs30::uniform2uiv, "glUniform2uiv", connection );
		LoadFunctionAddress( ::GlEs30::uniform3f, "glUniform3f", connection );
		LoadFunctionAddress( ::GlEs30::uniform3fv, "glUniform3fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform3i, "glUniform3i", connection );
		LoadFunctionAddress( ::GlEs30::uniform3iv, "glUniform3iv", connection );
		LoadFunctionAddress( ::GlEs30::uniform3ui, "glUniform3ui", connection );
		LoadFunctionAddress( ::GlEs30::uniform3uiv, "glUniform3uiv", connection );
		LoadFunctionAddress( ::GlEs30::uniform4f, "glUniform4f", connection );
		LoadFunctionAddress( ::GlEs30::uniform4fv, "glUniform4fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform4i, "glUniform4i", connection );
		LoadFunctionAddress( ::GlEs30::uniform4iv, "glUniform4iv", connection );
		LoadFunctionAddress( ::GlEs30::uniform4ui, "glUniform4ui", connection );
		LoadFunctionAddress( ::GlEs30::uniform4uiv, "glUniform4uiv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_block_binding, "glUniformBlockBinding", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix2fv, "glUniformMatrix2fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix2x3fv, "glUniformMatrix2x3fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix2x4fv, "glUniformMatrix2x4fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix3fv, "glUniformMatrix3fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix3x2fv, "glUniformMatrix3x2fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix3x4fv, "glUniformMatrix3x4fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix4fv, "glUniformMatrix4fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix4x2fv, "glUniformMatrix4x2fv", connection );
		LoadFunctionAddress( ::GlEs30::uniform_matrix4x3fv, "glUniformMatrix4x3fv", connection );
		LoadFunctionAddress( ::GlEs30::unmap_buffer, "glUnmapBuffer", connection );
		LoadFunctionAddress( ::GlEs30::use_program, "glUseProgram", connection );
		LoadFunctionAddress( ::GlEs30::validate_program, "glValidateProgram", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib1f, "glVertexAttrib1f", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib1fv, "glVertexAttrib1fv", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib2f, "glVertexAttrib2f", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib2fv, "glVertexAttrib2fv", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib3f, "glVertexAttrib3f", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib3fv, "glVertexAttrib3fv", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib4f, "glVertexAttrib4f", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib4fv, "glVertexAttrib4fv", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_divisor, "glVertexAttribDivisor", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_i4i, "glVertexAttribI4i", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_i4iv, "glVertexAttribI4iv", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_i4ui, "glVertexAttribI4ui", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_i4uiv, "glVertexAttribI4uiv", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_i_pointer, "glVertexAttribIPointer", connection );
		LoadFunctionAddress( ::GlEs30::vertex_attrib_pointer, "glVertexAttribPointer", connection );
		LoadFunctionAddress( ::GlEs30::viewport, "glViewport", connection );
		LoadFunctionAddress( ::GlEs30::wait_sync, "glWaitSync", connection );

		BLACK_LOG_DEBUG( LOG_CHANNEL, "Bindings for OpenGL ES 3.0 successfully initialized." );
	}
}
}
}

