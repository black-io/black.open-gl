#include <black/open-gl/gl-es-3.0.h>

#include "gles/bindings.gl-es-3.0.h"


namespace Black
{
inline namespace OpenGl
{
inline namespace GlEs30
{
	void GlActiveTexture( TextureUnit texture )
	{
		::GlEs30::active_texture( Black::GetEnumValue( texture ) );
	}

	void GlAttachShader( Black::GlProgram program, Black::GlShader shader )
	{
		::GlEs30::attach_shader( static_cast<GLuint>( Black::GetEnumValue( program ) ), static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlBeginQuery( QueryTarget target, Black::GlQuery id )
	{
		::GlEs30::begin_query( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	void GlBeginTransformFeedback( PrimitiveType primitive_mode )
	{
		::GlEs30::begin_transform_feedback( Black::GetEnumValue( primitive_mode ) );
	}

	void GlBindAttribLocation( Black::GlProgram program, uint32_t index, const char * name )
	{
		::GlEs30::bind_attrib_location( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, reinterpret_cast<const GLchar *>( name ) );
	}

	void GlBindBuffer( BufferTargetARB target, Black::GlBuffer buffer )
	{
		::GlEs30::bind_buffer( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( buffer ) ) );
	}

	void GlBindBufferBase( BufferTargetARB target, uint32_t index, Black::GlBuffer buffer )
	{
		::GlEs30::bind_buffer_base( Black::GetEnumValue( target ), index, static_cast<GLuint>( Black::GetEnumValue( buffer ) ) );
	}

	void GlBindBufferRange( BufferTargetARB target, uint32_t index, Black::GlBuffer buffer, intptr_t offset, ptrdiff_t size )
	{
		::GlEs30::bind_buffer_range( Black::GetEnumValue( target ), index, static_cast<GLuint>( Black::GetEnumValue( buffer ) ), offset, size );
	}

	void GlBindFramebuffer( FramebufferTarget target, Black::GlFrameBuffer framebuffer )
	{
		::GlEs30::bind_framebuffer( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( framebuffer ) ) );
	}

	void GlBindRenderbuffer( RenderbufferTarget target, Black::GlRenderBuffer renderbuffer )
	{
		::GlEs30::bind_renderbuffer( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( renderbuffer ) ) );
	}

	void GlBindSampler( uint32_t unit, Black::GlSampler sampler )
	{
		::GlEs30::bind_sampler( unit, static_cast<GLuint>( Black::GetEnumValue( sampler ) ) );
	}

	void GlBindTexture( TextureTarget target, Black::GlTexture texture )
	{
		::GlEs30::bind_texture( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( texture ) ) );
	}

	void GlBindTransformFeedback( BindTransformFeedbackTarget target, Black::GlTransformFeedback id )
	{
		::GlEs30::bind_transform_feedback( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	void GlBindVertexArray( Black::GlBuffer array )
	{
		::GlEs30::bind_vertex_array( static_cast<GLuint>( Black::GetEnumValue( array ) ) );
	}

	void GlBlendColor( float red, float green, float blue, float alpha )
	{
		::GlEs30::blend_color( red, green, blue, alpha );
	}

	void GlBlendEquation( BlendEquationModeEXT mode )
	{
		::GlEs30::blend_equation( Black::GetEnumValue( mode ) );
	}

	void GlBlendEquationSeparate( BlendEquationModeEXT mode_r_g_b, BlendEquationModeEXT mode_alpha )
	{
		::GlEs30::blend_equation_separate( Black::GetEnumValue( mode_r_g_b ), Black::GetEnumValue( mode_alpha ) );
	}

	void GlBlendFunc( BlendingFactor sfactor, BlendingFactor dfactor )
	{
		::GlEs30::blend_func( Black::GetEnumValue( sfactor ), Black::GetEnumValue( dfactor ) );
	}

	void GlBlendFuncSeparate( BlendingFactor sfactor_r_g_b, BlendingFactor dfactor_r_g_b, BlendingFactor sfactor_alpha, BlendingFactor dfactor_alpha )
	{
		::GlEs30::blend_func_separate( Black::GetEnumValue( sfactor_r_g_b ), Black::GetEnumValue( dfactor_r_g_b ), Black::GetEnumValue( sfactor_alpha ), Black::GetEnumValue( dfactor_alpha ) );
	}

	void GlBlitFramebuffer( int32_t src_x0, int32_t src_y0, int32_t src_x1, int32_t src_y1, int32_t dst_x0, int32_t dst_y0, int32_t dst_x1, int32_t dst_y1, ClearBufferMask mask, BlitFramebufferFilter filter )
	{
		::GlEs30::blit_framebuffer( src_x0, src_y0, src_x1, src_y1, dst_x0, dst_y0, dst_x1, dst_y1, static_cast<GLbitfield>( mask ), Black::GetEnumValue( filter ) );
	}

	void GlBufferData( BufferTargetARB target, ptrdiff_t size, const void * data, BufferUsageARB usage )
	{
		::GlEs30::buffer_data( Black::GetEnumValue( target ), size, data, Black::GetEnumValue( usage ) );
	}

	void GlBufferSubData( BufferTargetARB target, intptr_t offset, ptrdiff_t size, const void * data )
	{
		::GlEs30::buffer_sub_data( Black::GetEnumValue( target ), offset, size, data );
	}

	FramebufferStatus GlCheckFramebufferStatus( FramebufferTarget target )
	{
		return FramebufferStatus{ ::GlEs30::check_framebuffer_status( Black::GetEnumValue( target ) ) };
	}

	void GlClear( ClearBufferMask mask )
	{
		::GlEs30::clear( static_cast<GLbitfield>( mask ) );
	}

	void GlClearBufferfi( Buffer buffer, int32_t drawbuffer, float depth, int32_t stencil )
	{
		::GlEs30::clear_bufferfi( Black::GetEnumValue( buffer ), drawbuffer, depth, stencil );
	}

	void GlClearBufferfv( Buffer buffer, int32_t drawbuffer, const float * value )
	{
		::GlEs30::clear_bufferfv( Black::GetEnumValue( buffer ), drawbuffer, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlClearBufferiv( Buffer buffer, int32_t drawbuffer, const int32_t * value )
	{
		::GlEs30::clear_bufferiv( Black::GetEnumValue( buffer ), drawbuffer, reinterpret_cast<const GLint *>( value ) );
	}

	void GlClearBufferuiv( Buffer buffer, int32_t drawbuffer, const uint32_t * value )
	{
		::GlEs30::clear_bufferuiv( Black::GetEnumValue( buffer ), drawbuffer, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlClearColor( float red, float green, float blue, float alpha )
	{
		::GlEs30::clear_color( red, green, blue, alpha );
	}

	void GlClearDepthf( float d )
	{
		::GlEs30::clear_depthf( d );
	}

	void GlClearStencil( int32_t s )
	{
		::GlEs30::clear_stencil( s );
	}

	SyncStatus GlClientWaitSync( Black::GlSyncHandle sync, SyncObjectMask flags, uint64_t timeout )
	{
		return SyncStatus{ ::GlEs30::client_wait_sync( static_cast<GLsync>( sync ), static_cast<GLbitfield>( flags ), timeout ) };
	}

	void GlColorMask( bool red, bool green, bool blue, bool alpha )
	{
		::GlEs30::color_mask( red, green, blue, alpha );
	}

	void GlCompileShader( Black::GlShader shader )
	{
		::GlEs30::compile_shader( static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlCompressedTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t border, int32_t image_size, const void * data )
	{
		::GlEs30::compressed_tex_image2d( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, border, image_size, data );
	}

	void GlCompressedTexImage3D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, int32_t image_size, const void * data )
	{
		::GlEs30::compressed_tex_image3d( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, depth, border, image_size, data );
	}

	void GlCompressedTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, InternalFormat format, int32_t image_size, const void * data )
	{
		::GlEs30::compressed_tex_sub_image2d( Black::GetEnumValue( target ), level, xoffset, yoffset, width, height, Black::GetEnumValue( format ), image_size, data );
	}

	void GlCompressedTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, InternalFormat format, int32_t image_size, const void * data )
	{
		::GlEs30::compressed_tex_sub_image3d( Black::GetEnumValue( target ), level, xoffset, yoffset, zoffset, width, height, depth, Black::GetEnumValue( format ), image_size, data );
	}

	void GlCopyBufferSubData( CopyBufferSubDataTarget read_target, CopyBufferSubDataTarget write_target, intptr_t read_offset, intptr_t write_offset, ptrdiff_t size )
	{
		::GlEs30::copy_buffer_sub_data( Black::GetEnumValue( read_target ), Black::GetEnumValue( write_target ), read_offset, write_offset, size );
	}

	void GlCopyTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t x, int32_t y, int32_t width, int32_t height, int32_t border )
	{
		::GlEs30::copy_tex_image2d( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), x, y, width, height, border );
	}

	void GlCopyTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t x, int32_t y, int32_t width, int32_t height )
	{
		::GlEs30::copy_tex_sub_image2d( Black::GetEnumValue( target ), level, xoffset, yoffset, x, y, width, height );
	}

	void GlCopyTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t x, int32_t y, int32_t width, int32_t height )
	{
		::GlEs30::copy_tex_sub_image3d( Black::GetEnumValue( target ), level, xoffset, yoffset, zoffset, x, y, width, height );
	}

	Black::GlProgram GlCreateProgram()
	{
		return Black::GlProgram{ ::GlEs30::create_program() };
	}

	Black::GlShader GlCreateShader( ShaderType type )
	{
		return Black::GlShader{ ::GlEs30::create_shader( Black::GetEnumValue( type ) ) };
	}

	void GlCullFace( CullFaceMode mode )
	{
		::GlEs30::cull_face( Black::GetEnumValue( mode ) );
	}

	void GlDeleteBuffers( int32_t n, const Black::GlBuffer * buffers )
	{
		::GlEs30::delete_buffers( n, reinterpret_cast<const GLuint *>( buffers ) );
	}

	void GlDeleteFramebuffers( int32_t n, const Black::GlFrameBuffer * framebuffers )
	{
		::GlEs30::delete_framebuffers( n, reinterpret_cast<const GLuint *>( framebuffers ) );
	}

	void GlDeleteProgram( Black::GlProgram program )
	{
		::GlEs30::delete_program( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void GlDeleteQueries( int32_t n, const Black::GlQuery * ids )
	{
		::GlEs30::delete_queries( n, reinterpret_cast<const GLuint *>( ids ) );
	}

	void GlDeleteRenderbuffers( int32_t n, const Black::GlRenderBuffer * renderbuffers )
	{
		::GlEs30::delete_renderbuffers( n, reinterpret_cast<const GLuint *>( renderbuffers ) );
	}

	void GlDeleteSamplers( int32_t count, const Black::GlSampler * samplers )
	{
		::GlEs30::delete_samplers( count, reinterpret_cast<const GLuint *>( samplers ) );
	}

	void GlDeleteShader( Black::GlShader shader )
	{
		::GlEs30::delete_shader( static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlDeleteSync( Black::GlSyncHandle sync )
	{
		::GlEs30::delete_sync( static_cast<GLsync>( sync ) );
	}

	void GlDeleteTextures( int32_t n, const Black::GlTexture * textures )
	{
		::GlEs30::delete_textures( n, reinterpret_cast<const GLuint *>( textures ) );
	}

	void GlDeleteTransformFeedbacks( int32_t n, const Black::GlTransformFeedback * ids )
	{
		::GlEs30::delete_transform_feedbacks( n, reinterpret_cast<const GLuint *>( ids ) );
	}

	void GlDeleteVertexArrays( int32_t n, const Black::GlBuffer * arrays )
	{
		::GlEs30::delete_vertex_arrays( n, reinterpret_cast<const GLuint *>( arrays ) );
	}

	void GlDepthFunc( DepthFunction func )
	{
		::GlEs30::depth_func( Black::GetEnumValue( func ) );
	}

	void GlDepthMask( bool flag )
	{
		::GlEs30::depth_mask( flag );
	}

	void GlDepthRangef( float n, float f )
	{
		::GlEs30::depth_rangef( n, f );
	}

	void GlDetachShader( Black::GlProgram program, Black::GlShader shader )
	{
		::GlEs30::detach_shader( static_cast<GLuint>( Black::GetEnumValue( program ) ), static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlDisable( EnableCap cap )
	{
		::GlEs30::disable( Black::GetEnumValue( cap ) );
	}

	void GlDisableVertexAttribArray( uint32_t index )
	{
		::GlEs30::disable_vertex_attrib_array( index );
	}

	void GlDrawArrays( PrimitiveType mode, int32_t first, int32_t count )
	{
		::GlEs30::draw_arrays( Black::GetEnumValue( mode ), first, count );
	}

	void GlDrawArraysInstanced( PrimitiveType mode, int32_t first, int32_t count, int32_t instancecount )
	{
		::GlEs30::draw_arrays_instanced( Black::GetEnumValue( mode ), first, count, instancecount );
	}

	void GlDrawBuffers( int32_t n, const DrawBufferMode * bufs )
	{
		::GlEs30::draw_buffers( n, reinterpret_cast<const GLenum *>( bufs ) );
	}

	void GlDrawElements( PrimitiveType mode, int32_t count, DrawElementsType type, const void * indices )
	{
		::GlEs30::draw_elements( Black::GetEnumValue( mode ), count, Black::GetEnumValue( type ), indices );
	}

	void GlDrawElementsInstanced( PrimitiveType mode, int32_t count, DrawElementsType type, const void * indices, int32_t instancecount )
	{
		::GlEs30::draw_elements_instanced( Black::GetEnumValue( mode ), count, Black::GetEnumValue( type ), indices, instancecount );
	}

	void GlDrawRangeElements( PrimitiveType mode, uint32_t start, uint32_t end, int32_t count, DrawElementsType type, const void * indices )
	{
		::GlEs30::draw_range_elements( Black::GetEnumValue( mode ), start, end, count, Black::GetEnumValue( type ), indices );
	}

	void GlEnable( EnableCap cap )
	{
		::GlEs30::enable( Black::GetEnumValue( cap ) );
	}

	void GlEnableVertexAttribArray( uint32_t index )
	{
		::GlEs30::enable_vertex_attrib_array( index );
	}

	void GlEndQuery( QueryTarget target )
	{
		::GlEs30::end_query( Black::GetEnumValue( target ) );
	}

	void GlEndTransformFeedback()
	{
		::GlEs30::end_transform_feedback();
	}

	Black::GlSyncHandle GlFenceSync( SyncCondition condition, SyncBehaviorFlags flags )
	{
		return Black::GlSyncHandle{ ::GlEs30::fence_sync( Black::GetEnumValue( condition ), Black::GetEnumValue( flags ) ) };
	}

	void GlFinish()
	{
		::GlEs30::finish();
	}

	void GlFlush()
	{
		::GlEs30::flush();
	}

	void GlFlushMappedBufferRange( BufferTargetARB target, intptr_t offset, ptrdiff_t length )
	{
		::GlEs30::flush_mapped_buffer_range( Black::GetEnumValue( target ), offset, length );
	}

	void GlFramebufferRenderbuffer( FramebufferTarget target, FramebufferAttachment attachment, RenderbufferTarget renderbuffertarget, Black::GlRenderBuffer renderbuffer )
	{
		::GlEs30::framebuffer_renderbuffer( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), Black::GetEnumValue( renderbuffertarget ), static_cast<GLuint>( Black::GetEnumValue( renderbuffer ) ) );
	}

	void GlFramebufferTexture2D( FramebufferTarget target, FramebufferAttachment attachment, TextureTarget textarget, Black::GlTexture texture, int32_t level )
	{
		::GlEs30::framebuffer_texture2d( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), Black::GetEnumValue( textarget ), static_cast<GLuint>( Black::GetEnumValue( texture ) ), level );
	}

	void GlFramebufferTextureLayer( FramebufferTarget target, FramebufferAttachment attachment, Black::GlTexture texture, int32_t level, int32_t layer )
	{
		::GlEs30::framebuffer_texture_layer( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), static_cast<GLuint>( Black::GetEnumValue( texture ) ), level, layer );
	}

	void GlFrontFace( FrontFaceDirection mode )
	{
		::GlEs30::front_face( Black::GetEnumValue( mode ) );
	}

	void GlGenBuffers( int32_t n, Black::GlBuffer * buffers )
	{
		::GlEs30::gen_buffers( n, reinterpret_cast<GLuint *>( buffers ) );
	}

	void GlGenFramebuffers( int32_t n, Black::GlFrameBuffer * framebuffers )
	{
		::GlEs30::gen_framebuffers( n, reinterpret_cast<GLuint *>( framebuffers ) );
	}

	void GlGenQueries( int32_t n, Black::GlQuery * ids )
	{
		::GlEs30::gen_queries( n, reinterpret_cast<GLuint *>( ids ) );
	}

	void GlGenRenderbuffers( int32_t n, Black::GlRenderBuffer * renderbuffers )
	{
		::GlEs30::gen_renderbuffers( n, reinterpret_cast<GLuint *>( renderbuffers ) );
	}

	void GlGenSamplers( int32_t count, Black::GlSampler * samplers )
	{
		::GlEs30::gen_samplers( count, reinterpret_cast<GLuint *>( samplers ) );
	}

	void GlGenTextures( int32_t n, Black::GlTexture * textures )
	{
		::GlEs30::gen_textures( n, reinterpret_cast<GLuint *>( textures ) );
	}

	void GlGenTransformFeedbacks( int32_t n, Black::GlTransformFeedback * ids )
	{
		::GlEs30::gen_transform_feedbacks( n, reinterpret_cast<GLuint *>( ids ) );
	}

	void GlGenVertexArrays( int32_t n, Black::GlBuffer * arrays )
	{
		::GlEs30::gen_vertex_arrays( n, reinterpret_cast<GLuint *>( arrays ) );
	}

	void GlGenerateMipmap( TextureTarget target )
	{
		::GlEs30::generate_mipmap( Black::GetEnumValue( target ) );
	}

	void GlGetActiveAttrib( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, AttributeType * type, char * name )
	{
		::GlEs30::get_active_attrib( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLint *>( size ), reinterpret_cast<GLenum *>( type ), reinterpret_cast<GLchar *>( name ) );
	}

	void GlGetActiveUniform( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, UniformType * type, char * name )
	{
		::GlEs30::get_active_uniform( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLint *>( size ), reinterpret_cast<GLenum *>( type ), reinterpret_cast<GLchar *>( name ) );
	}

	void GlGetActiveUniformBlockName( Black::GlProgram program, uint32_t uniform_block_index, int32_t buf_size, int32_t * length, char * uniform_block_name )
	{
		::GlEs30::get_active_uniform_block_name( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_block_index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( uniform_block_name ) );
	}

	void GlGetActiveUniformBlockiv( Black::GlProgram program, uint32_t uniform_block_index, UniformBlockPName pname, int32_t * params )
	{
		::GlEs30::get_active_uniform_blockiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_block_index, Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetActiveUniformsiv( Black::GlProgram program, int32_t uniform_count, const uint32_t * uniform_indices, UniformPName pname, int32_t * params )
	{
		::GlEs30::get_active_uniformsiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_count, reinterpret_cast<const GLuint *>( uniform_indices ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetAttachedShaders( Black::GlProgram program, int32_t max_count, int32_t * count, Black::GlShader * shaders )
	{
		::GlEs30::get_attached_shaders( static_cast<GLuint>( Black::GetEnumValue( program ) ), max_count, reinterpret_cast<GLsizei *>( count ), reinterpret_cast<GLuint *>( shaders ) );
	}

	int32_t GlGetAttribLocation( Black::GlProgram program, const char * name )
	{
		return ::GlEs30::get_attrib_location( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( name ) );
	}

	void GlGetBooleanv( GetPName pname, bool * data )
	{
		::GlEs30::get_booleanv( Black::GetEnumValue( pname ), reinterpret_cast<GLboolean *>( data ) );
	}

	void GlGetBufferParameteri64v( BufferTargetARB target, BufferPNameARB pname, int64_t * params )
	{
		::GlEs30::get_buffer_parameteri64v( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint64 *>( params ) );
	}

	void GlGetBufferParameteriv( BufferTargetARB target, BufferPNameARB pname, int32_t * params )
	{
		::GlEs30::get_buffer_parameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetBufferPointerv( BufferTargetARB target, BufferPointerNameARB pname, void ** params )
	{
		::GlEs30::get_buffer_pointerv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), params );
	}

	ErrorCode GlGetError()
	{
		return ErrorCode{ ::GlEs30::get_error() };
	}

	void GlGetFloatv( GetPName pname, float * data )
	{
		::GlEs30::get_floatv( Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( data ) );
	}

	int32_t GlGetFragDataLocation( Black::GlProgram program, const char * name )
	{
		return ::GlEs30::get_frag_data_location( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( name ) );
	}

	void GlGetFramebufferAttachmentParameteriv( FramebufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameterName pname, int32_t * params )
	{
		::GlEs30::get_framebuffer_attachment_parameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetInteger64i_v( GetPName target, uint32_t index, int64_t * data )
	{
		::GlEs30::get_integer64i_v( Black::GetEnumValue( target ), index, reinterpret_cast<GLint64 *>( data ) );
	}

	void GlGetInteger64v( GetPName pname, int64_t * data )
	{
		::GlEs30::get_integer64v( Black::GetEnumValue( pname ), reinterpret_cast<GLint64 *>( data ) );
	}

	void GlGetIntegeri_v( GetPName target, uint32_t index, int32_t * data )
	{
		::GlEs30::get_integeri_v( Black::GetEnumValue( target ), index, reinterpret_cast<GLint *>( data ) );
	}

	void GlGetIntegerv( GetPName pname, int32_t * data )
	{
		::GlEs30::get_integerv( Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( data ) );
	}

	void GlGetInternalformativ( TextureTarget target, InternalFormat internalformat, InternalFormatPName pname, int32_t count, int32_t * params )
	{
		::GlEs30::get_internalformativ( Black::GetEnumValue( target ), Black::GetEnumValue( internalformat ), Black::GetEnumValue( pname ), count, reinterpret_cast<GLint *>( params ) );
	}

	void GlGetProgramBinary( Black::GlProgram program, int32_t buf_size, int32_t * length, uint32_t * binary_format, void * binary )
	{
		::GlEs30::get_program_binary( static_cast<GLuint>( Black::GetEnumValue( program ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLenum *>( binary_format ), binary );
	}

	void GlGetProgramInfoLog( Black::GlProgram program, int32_t buf_size, int32_t * length, char * info_log )
	{
		::GlEs30::get_program_info_log( static_cast<GLuint>( Black::GetEnumValue( program ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( info_log ) );
	}

	void GlGetProgramiv( Black::GlProgram program, ProgramPropertyARB pname, int32_t * params )
	{
		::GlEs30::get_programiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetQueryObjectuiv( Black::GlQuery id, QueryObjectParameterName pname, uint32_t * params )
	{
		::GlEs30::get_query_objectuiv( static_cast<GLuint>( Black::GetEnumValue( id ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLuint *>( params ) );
	}

	void GlGetQueryiv( QueryTarget target, QueryParameterName pname, int32_t * params )
	{
		::GlEs30::get_queryiv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetRenderbufferParameteriv( RenderbufferTarget target, RenderbufferParameterName pname, int32_t * params )
	{
		::GlEs30::get_renderbuffer_parameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetSamplerParameterfv( Black::GlSampler sampler, SamplerParameterF pname, float * params )
	{
		::GlEs30::get_sampler_parameterfv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetSamplerParameteriv( Black::GlSampler sampler, SamplerParameterI pname, int32_t * params )
	{
		::GlEs30::get_sampler_parameteriv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetShaderInfoLog( Black::GlShader shader, int32_t buf_size, int32_t * length, char * info_log )
	{
		::GlEs30::get_shader_info_log( static_cast<GLuint>( Black::GetEnumValue( shader ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( info_log ) );
	}

	void GlGetShaderPrecisionFormat( ShaderType shadertype, PrecisionType precisiontype, int32_t * range, int32_t * precision )
	{
		::GlEs30::get_shader_precision_format( Black::GetEnumValue( shadertype ), Black::GetEnumValue( precisiontype ), reinterpret_cast<GLint *>( range ), reinterpret_cast<GLint *>( precision ) );
	}

	void GlGetShaderSource( Black::GlShader shader, int32_t buf_size, int32_t * length, char * source )
	{
		::GlEs30::get_shader_source( static_cast<GLuint>( Black::GetEnumValue( shader ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( source ) );
	}

	void GlGetShaderiv( Black::GlShader shader, ShaderParameterName pname, int32_t * params )
	{
		::GlEs30::get_shaderiv( static_cast<GLuint>( Black::GetEnumValue( shader ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	const uint8_t * GlGetString( StringName name )
	{
		return ::GlEs30::get_string( Black::GetEnumValue( name ) );
	}

	const uint8_t * GlGetStringi( StringName name, uint32_t index )
	{
		return ::GlEs30::get_stringi( Black::GetEnumValue( name ), index );
	}

	void GlGetSynciv( Black::GlSyncHandle sync, SyncParameterName pname, int32_t count, int32_t * length, int32_t * values )
	{
		::GlEs30::get_synciv( static_cast<GLsync>( sync ), Black::GetEnumValue( pname ), count, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLint *>( values ) );
	}

	void GlGetTexParameterfv( TextureTarget target, GetTextureParameter pname, float * params )
	{
		::GlEs30::get_tex_parameterfv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetTexParameteriv( TextureTarget target, GetTextureParameter pname, int32_t * params )
	{
		::GlEs30::get_tex_parameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetTransformFeedbackVarying( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, AttributeType * type, char * name )
	{
		::GlEs30::get_transform_feedback_varying( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLsizei *>( size ), reinterpret_cast<GLenum *>( type ), reinterpret_cast<GLchar *>( name ) );
	}

	uint32_t GlGetUniformBlockIndex( Black::GlProgram program, const char * uniform_block_name )
	{
		return ::GlEs30::get_uniform_block_index( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( uniform_block_name ) );
	}

	void GlGetUniformIndices( Black::GlProgram program, int32_t uniform_count, const char *const* uniform_names, uint32_t * uniform_indices )
	{
		::GlEs30::get_uniform_indices( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_count, reinterpret_cast<const GLchar *const*>( uniform_names ), reinterpret_cast<GLuint *>( uniform_indices ) );
	}

	int32_t GlGetUniformLocation( Black::GlProgram program, const char * name )
	{
		return ::GlEs30::get_uniform_location( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( name ) );
	}

	void GlGetUniformfv( Black::GlProgram program, int32_t location, float * params )
	{
		::GlEs30::get_uniformfv( static_cast<GLuint>( Black::GetEnumValue( program ) ), location, reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetUniformiv( Black::GlProgram program, int32_t location, int32_t * params )
	{
		::GlEs30::get_uniformiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), location, reinterpret_cast<GLint *>( params ) );
	}

	void GlGetUniformuiv( Black::GlProgram program, int32_t location, uint32_t * params )
	{
		::GlEs30::get_uniformuiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), location, reinterpret_cast<GLuint *>( params ) );
	}

	void GlGetVertexAttribIiv( uint32_t index, VertexAttribEnum pname, int32_t * params )
	{
		::GlEs30::get_vertex_attrib_iiv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetVertexAttribIuiv( uint32_t index, VertexAttribEnum pname, uint32_t * params )
	{
		::GlEs30::get_vertex_attrib_iuiv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLuint *>( params ) );
	}

	void GlGetVertexAttribPointerv( uint32_t index, VertexAttribPointerPropertyARB pname, void ** pointer )
	{
		::GlEs30::get_vertex_attrib_pointerv( index, Black::GetEnumValue( pname ), pointer );
	}

	void GlGetVertexAttribfv( uint32_t index, VertexAttribPropertyARB pname, float * params )
	{
		::GlEs30::get_vertex_attribfv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetVertexAttribiv( uint32_t index, VertexAttribPropertyARB pname, int32_t * params )
	{
		::GlEs30::get_vertex_attribiv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlHint( HintTarget target, HintMode mode )
	{
		::GlEs30::hint( Black::GetEnumValue( target ), Black::GetEnumValue( mode ) );
	}

	void GlInvalidateFramebuffer( FramebufferTarget target, int32_t num_attachments, const InvalidateFramebufferAttachment * attachments )
	{
		::GlEs30::invalidate_framebuffer( Black::GetEnumValue( target ), num_attachments, reinterpret_cast<const GLenum *>( attachments ) );
	}

	void GlInvalidateSubFramebuffer( FramebufferTarget target, int32_t num_attachments, const InvalidateFramebufferAttachment * attachments, int32_t x, int32_t y, int32_t width, int32_t height )
	{
		::GlEs30::invalidate_sub_framebuffer( Black::GetEnumValue( target ), num_attachments, reinterpret_cast<const GLenum *>( attachments ), x, y, width, height );
	}

	bool GlIsBuffer( Black::GlBuffer buffer )
	{
		return ::GlEs30::is_buffer( static_cast<GLuint>( Black::GetEnumValue( buffer ) ) );
	}

	bool GlIsEnabled( EnableCap cap )
	{
		return ::GlEs30::is_enabled( Black::GetEnumValue( cap ) );
	}

	bool GlIsFramebuffer( Black::GlFrameBuffer framebuffer )
	{
		return ::GlEs30::is_framebuffer( static_cast<GLuint>( Black::GetEnumValue( framebuffer ) ) );
	}

	bool GlIsProgram( Black::GlProgram program )
	{
		return ::GlEs30::is_program( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	bool GlIsQuery( Black::GlQuery id )
	{
		return ::GlEs30::is_query( static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	bool GlIsRenderbuffer( Black::GlRenderBuffer renderbuffer )
	{
		return ::GlEs30::is_renderbuffer( static_cast<GLuint>( Black::GetEnumValue( renderbuffer ) ) );
	}

	bool GlIsSampler( Black::GlSampler sampler )
	{
		return ::GlEs30::is_sampler( static_cast<GLuint>( Black::GetEnumValue( sampler ) ) );
	}

	bool GlIsShader( Black::GlShader shader )
	{
		return ::GlEs30::is_shader( static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	bool GlIsSync( Black::GlSyncHandle sync )
	{
		return ::GlEs30::is_sync( static_cast<GLsync>( sync ) );
	}

	bool GlIsTexture( Black::GlTexture texture )
	{
		return ::GlEs30::is_texture( static_cast<GLuint>( Black::GetEnumValue( texture ) ) );
	}

	bool GlIsTransformFeedback( Black::GlTransformFeedback id )
	{
		return ::GlEs30::is_transform_feedback( static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	bool GlIsVertexArray( Black::GlBuffer array )
	{
		return ::GlEs30::is_vertex_array( static_cast<GLuint>( Black::GetEnumValue( array ) ) );
	}

	void GlLineWidth( float width )
	{
		::GlEs30::line_width( width );
	}

	void GlLinkProgram( Black::GlProgram program )
	{
		::GlEs30::link_program( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void * GlMapBufferRange( BufferTargetARB target, intptr_t offset, ptrdiff_t length, MapBufferAccessMask access )
	{
		return ::GlEs30::map_buffer_range( Black::GetEnumValue( target ), offset, length, static_cast<GLbitfield>( access ) );
	}

	void GlPauseTransformFeedback()
	{
		::GlEs30::pause_transform_feedback();
	}

	void GlPixelStorei( PixelStoreParameter pname, int32_t param )
	{
		::GlEs30::pixel_storei( Black::GetEnumValue( pname ), param );
	}

	void GlPolygonOffset( float factor, float units )
	{
		::GlEs30::polygon_offset( factor, units );
	}

	void GlProgramBinary( Black::GlProgram program, uint32_t binary_format, const void * binary, int32_t length )
	{
		::GlEs30::program_binary( static_cast<GLuint>( Black::GetEnumValue( program ) ), binary_format, binary, length );
	}

	void GlProgramParameteri( Black::GlProgram program, ProgramParameterPName pname, int32_t value )
	{
		::GlEs30::program_parameteri( static_cast<GLuint>( Black::GetEnumValue( program ) ), Black::GetEnumValue( pname ), value );
	}

	void GlReadBuffer( ReadBufferMode src )
	{
		::GlEs30::read_buffer( Black::GetEnumValue( src ) );
	}

	void GlReadPixels( int32_t x, int32_t y, int32_t width, int32_t height, PixelFormat format, PixelType type, void * pixels )
	{
		::GlEs30::read_pixels( x, y, width, height, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlReleaseShaderCompiler()
	{
		::GlEs30::release_shader_compiler();
	}

	void GlRenderbufferStorage( RenderbufferTarget target, InternalFormat internalformat, int32_t width, int32_t height )
	{
		::GlEs30::renderbuffer_storage( Black::GetEnumValue( target ), Black::GetEnumValue( internalformat ), width, height );
	}

	void GlRenderbufferStorageMultisample( RenderbufferTarget target, int32_t samples, InternalFormat internalformat, int32_t width, int32_t height )
	{
		::GlEs30::renderbuffer_storage_multisample( Black::GetEnumValue( target ), samples, Black::GetEnumValue( internalformat ), width, height );
	}

	void GlResumeTransformFeedback()
	{
		::GlEs30::resume_transform_feedback();
	}

	void GlSampleCoverage( float value, bool invert )
	{
		::GlEs30::sample_coverage( value, invert );
	}

	void GlSamplerParameterf( Black::GlSampler sampler, SamplerParameterF pname, float param )
	{
		::GlEs30::sampler_parameterf( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), param );
	}

	void GlSamplerParameterfv( Black::GlSampler sampler, SamplerParameterF pname, const float * param )
	{
		::GlEs30::sampler_parameterfv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<const GLfloat *>( param ) );
	}

	void GlSamplerParameteri( Black::GlSampler sampler, SamplerParameterI pname, int32_t param )
	{
		::GlEs30::sampler_parameteri( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), param );
	}

	void GlSamplerParameteriv( Black::GlSampler sampler, SamplerParameterI pname, const int32_t * param )
	{
		::GlEs30::sampler_parameteriv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<const GLint *>( param ) );
	}

	void GlScissor( int32_t x, int32_t y, int32_t width, int32_t height )
	{
		::GlEs30::scissor( x, y, width, height );
	}

	void GlShaderBinary( int32_t count, const Black::GlShader * shaders, ShaderBinaryFormat binary_format, const void * binary, int32_t length )
	{
		::GlEs30::shader_binary( count, reinterpret_cast<const GLuint *>( shaders ), Black::GetEnumValue( binary_format ), binary, length );
	}

	void GlShaderSource( Black::GlShader shader, int32_t count, const char *const* string, const int32_t * length )
	{
		::GlEs30::shader_source( static_cast<GLuint>( Black::GetEnumValue( shader ) ), count, reinterpret_cast<const GLchar *const*>( string ), reinterpret_cast<const GLint *>( length ) );
	}

	void GlStencilFunc( StencilFunction func, int32_t ref, uint32_t mask )
	{
		::GlEs30::stencil_func( Black::GetEnumValue( func ), ref, mask );
	}

	void GlStencilFuncSeparate( StencilFaceDirection face, StencilFunction func, int32_t ref, uint32_t mask )
	{
		::GlEs30::stencil_func_separate( Black::GetEnumValue( face ), Black::GetEnumValue( func ), ref, mask );
	}

	void GlStencilMask( uint32_t mask )
	{
		::GlEs30::stencil_mask( mask );
	}

	void GlStencilMaskSeparate( StencilFaceDirection face, uint32_t mask )
	{
		::GlEs30::stencil_mask_separate( Black::GetEnumValue( face ), mask );
	}

	void GlStencilOp( StencilOp fail, StencilOp zfail, StencilOp zpass )
	{
		::GlEs30::stencil_op( Black::GetEnumValue( fail ), Black::GetEnumValue( zfail ), Black::GetEnumValue( zpass ) );
	}

	void GlStencilOpSeparate( StencilFaceDirection face, StencilOp sfail, StencilOp dpfail, StencilOp dppass )
	{
		::GlEs30::stencil_op_separate( Black::GetEnumValue( face ), Black::GetEnumValue( sfail ), Black::GetEnumValue( dpfail ), Black::GetEnumValue( dppass ) );
	}

	void GlTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t border, PixelFormat format, PixelType type, const void * pixels )
	{
		::GlEs30::tex_image2_d( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, border, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTexImage3D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, PixelFormat format, PixelType type, const void * pixels )
	{
		::GlEs30::tex_image3_d( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, depth, border, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTexParameterf( TextureTarget target, TextureParameterName pname, float param )
	{
		::GlEs30::tex_parameterf( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), param );
	}

	void GlTexParameterfv( TextureTarget target, TextureParameterName pname, const float * params )
	{
		::GlEs30::tex_parameterfv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<const GLfloat *>( params ) );
	}

	void GlTexParameteri( TextureTarget target, TextureParameterName pname, int32_t param )
	{
		::GlEs30::tex_parameteri( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), param );
	}

	void GlTexParameteriv( TextureTarget target, TextureParameterName pname, const int32_t * params )
	{
		::GlEs30::tex_parameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<const GLint *>( params ) );
	}

	void GlTexStorage2D( TextureTarget target, int32_t levels, SizedInternalFormat internalformat, int32_t width, int32_t height )
	{
		::GlEs30::tex_storage2_d( Black::GetEnumValue( target ), levels, Black::GetEnumValue( internalformat ), width, height );
	}

	void GlTexStorage3D( TextureTarget target, int32_t levels, SizedInternalFormat internalformat, int32_t width, int32_t height, int32_t depth )
	{
		::GlEs30::tex_storage3_d( Black::GetEnumValue( target ), levels, Black::GetEnumValue( internalformat ), width, height, depth );
	}

	void GlTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, PixelFormat format, PixelType type, const void * pixels )
	{
		::GlEs30::tex_sub_image2_d( Black::GetEnumValue( target ), level, xoffset, yoffset, width, height, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, PixelFormat format, PixelType type, const void * pixels )
	{
		::GlEs30::tex_sub_image3_d( Black::GetEnumValue( target ), level, xoffset, yoffset, zoffset, width, height, depth, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTransformFeedbackVaryings( Black::GlProgram program, int32_t count, const char *const* varyings, TransformFeedbackBufferMode buffer_mode )
	{
		::GlEs30::transform_feedback_varyings( static_cast<GLuint>( Black::GetEnumValue( program ) ), count, reinterpret_cast<const GLchar *const*>( varyings ), Black::GetEnumValue( buffer_mode ) );
	}

	void GlUniform1f( int32_t location, float v0 )
	{
		::GlEs30::uniform1f( location, v0 );
	}

	void GlUniform1fv( int32_t location, int32_t count, const float * value )
	{
		::GlEs30::uniform1fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform1i( int32_t location, int32_t v0 )
	{
		::GlEs30::uniform1i( location, v0 );
	}

	void GlUniform1iv( int32_t location, int32_t count, const int32_t * value )
	{
		::GlEs30::uniform1iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform1ui( int32_t location, uint32_t v0 )
	{
		::GlEs30::uniform1ui( location, v0 );
	}

	void GlUniform1uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		::GlEs30::uniform1uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniform2f( int32_t location, float v0, float v1 )
	{
		::GlEs30::uniform2f( location, v0, v1 );
	}

	void GlUniform2fv( int32_t location, int32_t count, const float * value )
	{
		::GlEs30::uniform2fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform2i( int32_t location, int32_t v0, int32_t v1 )
	{
		::GlEs30::uniform2i( location, v0, v1 );
	}

	void GlUniform2iv( int32_t location, int32_t count, const int32_t * value )
	{
		::GlEs30::uniform2iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform2ui( int32_t location, uint32_t v0, uint32_t v1 )
	{
		::GlEs30::uniform2ui( location, v0, v1 );
	}

	void GlUniform2uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		::GlEs30::uniform2uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniform3f( int32_t location, float v0, float v1, float v2 )
	{
		::GlEs30::uniform3f( location, v0, v1, v2 );
	}

	void GlUniform3fv( int32_t location, int32_t count, const float * value )
	{
		::GlEs30::uniform3fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform3i( int32_t location, int32_t v0, int32_t v1, int32_t v2 )
	{
		::GlEs30::uniform3i( location, v0, v1, v2 );
	}

	void GlUniform3iv( int32_t location, int32_t count, const int32_t * value )
	{
		::GlEs30::uniform3iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform3ui( int32_t location, uint32_t v0, uint32_t v1, uint32_t v2 )
	{
		::GlEs30::uniform3ui( location, v0, v1, v2 );
	}

	void GlUniform3uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		::GlEs30::uniform3uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniform4f( int32_t location, float v0, float v1, float v2, float v3 )
	{
		::GlEs30::uniform4f( location, v0, v1, v2, v3 );
	}

	void GlUniform4fv( int32_t location, int32_t count, const float * value )
	{
		::GlEs30::uniform4fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform4i( int32_t location, int32_t v0, int32_t v1, int32_t v2, int32_t v3 )
	{
		::GlEs30::uniform4i( location, v0, v1, v2, v3 );
	}

	void GlUniform4iv( int32_t location, int32_t count, const int32_t * value )
	{
		::GlEs30::uniform4iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform4ui( int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3 )
	{
		::GlEs30::uniform4ui( location, v0, v1, v2, v3 );
	}

	void GlUniform4uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		::GlEs30::uniform4uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniformBlockBinding( Black::GlProgram program, uint32_t uniform_block_index, uint32_t uniform_block_binding )
	{
		::GlEs30::uniform_block_binding( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_block_index, uniform_block_binding );
	}

	void GlUniformMatrix2fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix2fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix2x3fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix2x3fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix2x4fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix2x4fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix3fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix3fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix3x2fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix3x2fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix3x4fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix3x4fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix4fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix4fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix4x2fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix4x2fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix4x3fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		::GlEs30::uniform_matrix4x3fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	bool GlUnmapBuffer( BufferTargetARB target )
	{
		return ::GlEs30::unmap_buffer( Black::GetEnumValue( target ) );
	}

	void GlUseProgram( Black::GlProgram program )
	{
		::GlEs30::use_program( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void GlValidateProgram( Black::GlProgram program )
	{
		::GlEs30::validate_program( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void GlVertexAttrib1f( uint32_t index, float x )
	{
		::GlEs30::vertex_attrib1f( index, x );
	}

	void GlVertexAttrib1fv( uint32_t index, const float * v )
	{
		::GlEs30::vertex_attrib1fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttrib2f( uint32_t index, float x, float y )
	{
		::GlEs30::vertex_attrib2f( index, x, y );
	}

	void GlVertexAttrib2fv( uint32_t index, const float * v )
	{
		::GlEs30::vertex_attrib2fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttrib3f( uint32_t index, float x, float y, float z )
	{
		::GlEs30::vertex_attrib3f( index, x, y, z );
	}

	void GlVertexAttrib3fv( uint32_t index, const float * v )
	{
		::GlEs30::vertex_attrib3fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttrib4f( uint32_t index, float x, float y, float z, float w )
	{
		::GlEs30::vertex_attrib4f( index, x, y, z, w );
	}

	void GlVertexAttrib4fv( uint32_t index, const float * v )
	{
		::GlEs30::vertex_attrib4fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttribDivisor( uint32_t index, uint32_t divisor )
	{
		::GlEs30::vertex_attrib_divisor( index, divisor );
	}

	void GlVertexAttribI4i( uint32_t index, int32_t x, int32_t y, int32_t z, int32_t w )
	{
		::GlEs30::vertex_attrib_i4i( index, x, y, z, w );
	}

	void GlVertexAttribI4iv( uint32_t index, const int32_t * v )
	{
		::GlEs30::vertex_attrib_i4iv( index, reinterpret_cast<const GLint *>( v ) );
	}

	void GlVertexAttribI4ui( uint32_t index, uint32_t x, uint32_t y, uint32_t z, uint32_t w )
	{
		::GlEs30::vertex_attrib_i4ui( index, x, y, z, w );
	}

	void GlVertexAttribI4uiv( uint32_t index, const uint32_t * v )
	{
		::GlEs30::vertex_attrib_i4uiv( index, reinterpret_cast<const GLuint *>( v ) );
	}

	void GlVertexAttribIPointer( uint32_t index, int32_t size, VertexAttribIType type, int32_t stride, const void * pointer )
	{
		::GlEs30::vertex_attrib_i_pointer( index, size, Black::GetEnumValue( type ), stride, pointer );
	}

	void GlVertexAttribPointer( uint32_t index, int32_t size, VertexAttribPointerType type, bool normalized, int32_t stride, const void * pointer )
	{
		::GlEs30::vertex_attrib_pointer( index, size, Black::GetEnumValue( type ), normalized, stride, pointer );
	}

	void GlViewport( int32_t x, int32_t y, int32_t width, int32_t height )
	{
		::GlEs30::viewport( x, y, width, height );
	}

	void GlWaitSync( Black::GlSyncHandle sync, SyncBehaviorFlags flags, uint64_t timeout )
	{
		::GlEs30::wait_sync( static_cast<GLsync>( sync ), Black::GetEnumValue( flags ), timeout );
	}

}
}
}
