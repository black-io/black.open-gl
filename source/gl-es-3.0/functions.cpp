#include <black/open-gl/gl-es-3.0.h>

#include "glad-es-3.0.h"


namespace Black
{
inline namespace OpenGl
{
inline namespace GlEs30
{
	void GlActiveTexture( TextureUnit texture )
	{
		glad_es_30_glActiveTexture( Black::GetEnumValue( texture ) );
	}

	void GlAttachShader( Black::GlProgram program, Black::GlShader shader )
	{
		glad_es_30_glAttachShader( static_cast<GLuint>( Black::GetEnumValue( program ) ), static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlBeginQuery( QueryTarget target, Black::GlQuery id )
	{
		glad_es_30_glBeginQuery( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	void GlBeginTransformFeedback( PrimitiveType primitive_mode )
	{
		glad_es_30_glBeginTransformFeedback( Black::GetEnumValue( primitive_mode ) );
	}

	void GlBindAttribLocation( Black::GlProgram program, uint32_t index, const char * name )
	{
		glad_es_30_glBindAttribLocation( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, reinterpret_cast<const GLchar *>( name ) );
	}

	void GlBindBuffer( BufferTargetARB target, Black::GlBuffer buffer )
	{
		glad_es_30_glBindBuffer( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( buffer ) ) );
	}

	void GlBindBufferBase( BufferTargetARB target, uint32_t index, Black::GlBuffer buffer )
	{
		glad_es_30_glBindBufferBase( Black::GetEnumValue( target ), index, static_cast<GLuint>( Black::GetEnumValue( buffer ) ) );
	}

	void GlBindBufferRange( BufferTargetARB target, uint32_t index, Black::GlBuffer buffer, intptr_t offset, ptrdiff_t size )
	{
		glad_es_30_glBindBufferRange( Black::GetEnumValue( target ), index, static_cast<GLuint>( Black::GetEnumValue( buffer ) ), offset, size );
	}

	void GlBindFramebuffer( FramebufferTarget target, Black::GlFrameBuffer framebuffer )
	{
		glad_es_30_glBindFramebuffer( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( framebuffer ) ) );
	}

	void GlBindRenderbuffer( RenderbufferTarget target, Black::GlRenderBuffer renderbuffer )
	{
		glad_es_30_glBindRenderbuffer( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( renderbuffer ) ) );
	}

	void GlBindSampler( uint32_t unit, Black::GlSampler sampler )
	{
		glad_es_30_glBindSampler( unit, static_cast<GLuint>( Black::GetEnumValue( sampler ) ) );
	}

	void GlBindTexture( TextureTarget target, Black::GlTexture texture )
	{
		glad_es_30_glBindTexture( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( texture ) ) );
	}

	void GlBindTransformFeedback( BindTransformFeedbackTarget target, Black::GlTransformFeedback id )
	{
		glad_es_30_glBindTransformFeedback( Black::GetEnumValue( target ), static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	void GlBindVertexArray( Black::GlBuffer array )
	{
		glad_es_30_glBindVertexArray( static_cast<GLuint>( Black::GetEnumValue( array ) ) );
	}

	void GlBlendColor( float red, float green, float blue, float alpha )
	{
		glad_es_30_glBlendColor( red, green, blue, alpha );
	}

	void GlBlendEquation( BlendEquationModeEXT mode )
	{
		glad_es_30_glBlendEquation( Black::GetEnumValue( mode ) );
	}

	void GlBlendEquationSeparate( BlendEquationModeEXT mode_r_g_b, BlendEquationModeEXT mode_alpha )
	{
		glad_es_30_glBlendEquationSeparate( Black::GetEnumValue( mode_r_g_b ), Black::GetEnumValue( mode_alpha ) );
	}

	void GlBlendFunc( BlendingFactor sfactor, BlendingFactor dfactor )
	{
		glad_es_30_glBlendFunc( Black::GetEnumValue( sfactor ), Black::GetEnumValue( dfactor ) );
	}

	void GlBlendFuncSeparate( BlendingFactor sfactor_r_g_b, BlendingFactor dfactor_r_g_b, BlendingFactor sfactor_alpha, BlendingFactor dfactor_alpha )
	{
		glad_es_30_glBlendFuncSeparate( Black::GetEnumValue( sfactor_r_g_b ), Black::GetEnumValue( dfactor_r_g_b ), Black::GetEnumValue( sfactor_alpha ), Black::GetEnumValue( dfactor_alpha ) );
	}

	void GlBlitFramebuffer( int32_t src_x0, int32_t src_y0, int32_t src_x1, int32_t src_y1, int32_t dst_x0, int32_t dst_y0, int32_t dst_x1, int32_t dst_y1, ClearBufferMask mask, BlitFramebufferFilter filter )
	{
		glad_es_30_glBlitFramebuffer( src_x0, src_y0, src_x1, src_y1, dst_x0, dst_y0, dst_x1, dst_y1, static_cast<GLbitfield>( mask ), Black::GetEnumValue( filter ) );
	}

	void GlBufferData( BufferTargetARB target, ptrdiff_t size, const void * data, BufferUsageARB usage )
	{
		glad_es_30_glBufferData( Black::GetEnumValue( target ), size, data, Black::GetEnumValue( usage ) );
	}

	void GlBufferSubData( BufferTargetARB target, intptr_t offset, ptrdiff_t size, const void * data )
	{
		glad_es_30_glBufferSubData( Black::GetEnumValue( target ), offset, size, data );
	}

	FramebufferStatus GlCheckFramebufferStatus( FramebufferTarget target )
	{
		return FramebufferStatus{ glad_es_30_glCheckFramebufferStatus( Black::GetEnumValue( target ) ) };
	}

	void GlClear( ClearBufferMask mask )
	{
		glad_es_30_glClear( static_cast<GLbitfield>( mask ) );
	}

	void GlClearBufferfi( Buffer buffer, int32_t drawbuffer, float depth, int32_t stencil )
	{
		glad_es_30_glClearBufferfi( Black::GetEnumValue( buffer ), drawbuffer, depth, stencil );
	}

	void GlClearBufferfv( Buffer buffer, int32_t drawbuffer, const float * value )
	{
		glad_es_30_glClearBufferfv( Black::GetEnumValue( buffer ), drawbuffer, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlClearBufferiv( Buffer buffer, int32_t drawbuffer, const int32_t * value )
	{
		glad_es_30_glClearBufferiv( Black::GetEnumValue( buffer ), drawbuffer, reinterpret_cast<const GLint *>( value ) );
	}

	void GlClearBufferuiv( Buffer buffer, int32_t drawbuffer, const uint32_t * value )
	{
		glad_es_30_glClearBufferuiv( Black::GetEnumValue( buffer ), drawbuffer, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlClearColor( float red, float green, float blue, float alpha )
	{
		glad_es_30_glClearColor( red, green, blue, alpha );
	}

	void GlClearDepthf( float d )
	{
		glad_es_30_glClearDepthf( d );
	}

	void GlClearStencil( int32_t s )
	{
		glad_es_30_glClearStencil( s );
	}

	SyncStatus GlClientWaitSync( Black::GlSyncHandle sync, SyncObjectMask flags, uint64_t timeout )
	{
		return SyncStatus{ glad_es_30_glClientWaitSync( static_cast<GLsync>( sync ), static_cast<GLbitfield>( flags ), timeout ) };
	}

	void GlColorMask( bool red, bool green, bool blue, bool alpha )
	{
		glad_es_30_glColorMask( red, green, blue, alpha );
	}

	void GlCompileShader( Black::GlShader shader )
	{
		glad_es_30_glCompileShader( static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlCompressedTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t border, int32_t image_size, const void * data )
	{
		glad_es_30_glCompressedTexImage2D( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, border, image_size, data );
	}

	void GlCompressedTexImage3D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, int32_t image_size, const void * data )
	{
		glad_es_30_glCompressedTexImage3D( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, depth, border, image_size, data );
	}

	void GlCompressedTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, InternalFormat format, int32_t image_size, const void * data )
	{
		glad_es_30_glCompressedTexSubImage2D( Black::GetEnumValue( target ), level, xoffset, yoffset, width, height, Black::GetEnumValue( format ), image_size, data );
	}

	void GlCompressedTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, InternalFormat format, int32_t image_size, const void * data )
	{
		glad_es_30_glCompressedTexSubImage3D( Black::GetEnumValue( target ), level, xoffset, yoffset, zoffset, width, height, depth, Black::GetEnumValue( format ), image_size, data );
	}

	void GlCopyBufferSubData( CopyBufferSubDataTarget read_target, CopyBufferSubDataTarget write_target, intptr_t read_offset, intptr_t write_offset, ptrdiff_t size )
	{
		glad_es_30_glCopyBufferSubData( Black::GetEnumValue( read_target ), Black::GetEnumValue( write_target ), read_offset, write_offset, size );
	}

	void GlCopyTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t x, int32_t y, int32_t width, int32_t height, int32_t border )
	{
		glad_es_30_glCopyTexImage2D( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), x, y, width, height, border );
	}

	void GlCopyTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t x, int32_t y, int32_t width, int32_t height )
	{
		glad_es_30_glCopyTexSubImage2D( Black::GetEnumValue( target ), level, xoffset, yoffset, x, y, width, height );
	}

	void GlCopyTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t x, int32_t y, int32_t width, int32_t height )
	{
		glad_es_30_glCopyTexSubImage3D( Black::GetEnumValue( target ), level, xoffset, yoffset, zoffset, x, y, width, height );
	}

	Black::GlProgram GlCreateProgram()
	{
		return Black::GlProgram{ glad_es_30_glCreateProgram() };
	}

	Black::GlShader GlCreateShader( ShaderType type )
	{
		return Black::GlShader{ glad_es_30_glCreateShader( Black::GetEnumValue( type ) ) };
	}

	void GlCullFace( CullFaceMode mode )
	{
		glad_es_30_glCullFace( Black::GetEnumValue( mode ) );
	}

	void GlDeleteBuffers( int32_t n, const Black::GlBuffer * buffers )
	{
		glad_es_30_glDeleteBuffers( n, reinterpret_cast<const GLuint *>( buffers ) );
	}

	void GlDeleteFramebuffers( int32_t n, const Black::GlFrameBuffer * framebuffers )
	{
		glad_es_30_glDeleteFramebuffers( n, reinterpret_cast<const GLuint *>( framebuffers ) );
	}

	void GlDeleteProgram( Black::GlProgram program )
	{
		glad_es_30_glDeleteProgram( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void GlDeleteQueries( int32_t n, const Black::GlQuery * ids )
	{
		glad_es_30_glDeleteQueries( n, reinterpret_cast<const GLuint *>( ids ) );
	}

	void GlDeleteRenderbuffers( int32_t n, const Black::GlRenderBuffer * renderbuffers )
	{
		glad_es_30_glDeleteRenderbuffers( n, reinterpret_cast<const GLuint *>( renderbuffers ) );
	}

	void GlDeleteSamplers( int32_t count, const Black::GlSampler * samplers )
	{
		glad_es_30_glDeleteSamplers( count, reinterpret_cast<const GLuint *>( samplers ) );
	}

	void GlDeleteShader( Black::GlShader shader )
	{
		glad_es_30_glDeleteShader( static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlDeleteSync( Black::GlSyncHandle sync )
	{
		glad_es_30_glDeleteSync( static_cast<GLsync>( sync ) );
	}

	void GlDeleteTextures( int32_t n, const Black::GlTexture * textures )
	{
		glad_es_30_glDeleteTextures( n, reinterpret_cast<const GLuint *>( textures ) );
	}

	void GlDeleteTransformFeedbacks( int32_t n, const Black::GlTransformFeedback * ids )
	{
		glad_es_30_glDeleteTransformFeedbacks( n, reinterpret_cast<const GLuint *>( ids ) );
	}

	void GlDeleteVertexArrays( int32_t n, const Black::GlBuffer * arrays )
	{
		glad_es_30_glDeleteVertexArrays( n, reinterpret_cast<const GLuint *>( arrays ) );
	}

	void GlDepthFunc( DepthFunction func )
	{
		glad_es_30_glDepthFunc( Black::GetEnumValue( func ) );
	}

	void GlDepthMask( bool flag )
	{
		glad_es_30_glDepthMask( flag );
	}

	void GlDepthRangef( float n, float f )
	{
		glad_es_30_glDepthRangef( n, f );
	}

	void GlDetachShader( Black::GlProgram program, Black::GlShader shader )
	{
		glad_es_30_glDetachShader( static_cast<GLuint>( Black::GetEnumValue( program ) ), static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	void GlDisable( EnableCap cap )
	{
		glad_es_30_glDisable( Black::GetEnumValue( cap ) );
	}

	void GlDisableVertexAttribArray( uint32_t index )
	{
		glad_es_30_glDisableVertexAttribArray( index );
	}

	void GlDrawArrays( PrimitiveType mode, int32_t first, int32_t count )
	{
		glad_es_30_glDrawArrays( Black::GetEnumValue( mode ), first, count );
	}

	void GlDrawArraysInstanced( PrimitiveType mode, int32_t first, int32_t count, int32_t instancecount )
	{
		glad_es_30_glDrawArraysInstanced( Black::GetEnumValue( mode ), first, count, instancecount );
	}

	void GlDrawBuffers( int32_t n, const DrawBufferMode * bufs )
	{
		glad_es_30_glDrawBuffers( n, reinterpret_cast<const GLenum *>( bufs ) );
	}

	void GlDrawElements( PrimitiveType mode, int32_t count, DrawElementsType type, const void * indices )
	{
		glad_es_30_glDrawElements( Black::GetEnumValue( mode ), count, Black::GetEnumValue( type ), indices );
	}

	void GlDrawElementsInstanced( PrimitiveType mode, int32_t count, DrawElementsType type, const void * indices, int32_t instancecount )
	{
		glad_es_30_glDrawElementsInstanced( Black::GetEnumValue( mode ), count, Black::GetEnumValue( type ), indices, instancecount );
	}

	void GlDrawRangeElements( PrimitiveType mode, uint32_t start, uint32_t end, int32_t count, DrawElementsType type, const void * indices )
	{
		glad_es_30_glDrawRangeElements( Black::GetEnumValue( mode ), start, end, count, Black::GetEnumValue( type ), indices );
	}

	void GlEnable( EnableCap cap )
	{
		glad_es_30_glEnable( Black::GetEnumValue( cap ) );
	}

	void GlEnableVertexAttribArray( uint32_t index )
	{
		glad_es_30_glEnableVertexAttribArray( index );
	}

	void GlEndQuery( QueryTarget target )
	{
		glad_es_30_glEndQuery( Black::GetEnumValue( target ) );
	}

	void GlEndTransformFeedback()
	{
		glad_es_30_glEndTransformFeedback();
	}

	Black::GlSyncHandle GlFenceSync( SyncCondition condition, SyncBehaviorFlags flags )
	{
		return Black::GlSyncHandle{ glad_es_30_glFenceSync( Black::GetEnumValue( condition ), Black::GetEnumValue( flags ) ) };
	}

	void GlFinish()
	{
		glad_es_30_glFinish();
	}

	void GlFlush()
	{
		glad_es_30_glFlush();
	}

	void GlFlushMappedBufferRange( BufferTargetARB target, intptr_t offset, ptrdiff_t length )
	{
		glad_es_30_glFlushMappedBufferRange( Black::GetEnumValue( target ), offset, length );
	}

	void GlFramebufferRenderbuffer( FramebufferTarget target, FramebufferAttachment attachment, RenderbufferTarget renderbuffertarget, Black::GlRenderBuffer renderbuffer )
	{
		glad_es_30_glFramebufferRenderbuffer( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), Black::GetEnumValue( renderbuffertarget ), static_cast<GLuint>( Black::GetEnumValue( renderbuffer ) ) );
	}

	void GlFramebufferTexture2D( FramebufferTarget target, FramebufferAttachment attachment, TextureTarget textarget, Black::GlTexture texture, int32_t level )
	{
		glad_es_30_glFramebufferTexture2D( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), Black::GetEnumValue( textarget ), static_cast<GLuint>( Black::GetEnumValue( texture ) ), level );
	}

	void GlFramebufferTextureLayer( FramebufferTarget target, FramebufferAttachment attachment, Black::GlTexture texture, int32_t level, int32_t layer )
	{
		glad_es_30_glFramebufferTextureLayer( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), static_cast<GLuint>( Black::GetEnumValue( texture ) ), level, layer );
	}

	void GlFrontFace( FrontFaceDirection mode )
	{
		glad_es_30_glFrontFace( Black::GetEnumValue( mode ) );
	}

	void GlGenBuffers( int32_t n, Black::GlBuffer * buffers )
	{
		glad_es_30_glGenBuffers( n, reinterpret_cast<GLuint *>( buffers ) );
	}

	void GlGenFramebuffers( int32_t n, Black::GlFrameBuffer * framebuffers )
	{
		glad_es_30_glGenFramebuffers( n, reinterpret_cast<GLuint *>( framebuffers ) );
	}

	void GlGenQueries( int32_t n, Black::GlQuery * ids )
	{
		glad_es_30_glGenQueries( n, reinterpret_cast<GLuint *>( ids ) );
	}

	void GlGenRenderbuffers( int32_t n, Black::GlRenderBuffer * renderbuffers )
	{
		glad_es_30_glGenRenderbuffers( n, reinterpret_cast<GLuint *>( renderbuffers ) );
	}

	void GlGenSamplers( int32_t count, Black::GlSampler * samplers )
	{
		glad_es_30_glGenSamplers( count, reinterpret_cast<GLuint *>( samplers ) );
	}

	void GlGenTextures( int32_t n, Black::GlTexture * textures )
	{
		glad_es_30_glGenTextures( n, reinterpret_cast<GLuint *>( textures ) );
	}

	void GlGenTransformFeedbacks( int32_t n, Black::GlTransformFeedback * ids )
	{
		glad_es_30_glGenTransformFeedbacks( n, reinterpret_cast<GLuint *>( ids ) );
	}

	void GlGenVertexArrays( int32_t n, Black::GlBuffer * arrays )
	{
		glad_es_30_glGenVertexArrays( n, reinterpret_cast<GLuint *>( arrays ) );
	}

	void GlGenerateMipmap( TextureTarget target )
	{
		glad_es_30_glGenerateMipmap( Black::GetEnumValue( target ) );
	}

	void GlGetActiveAttrib( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, AttributeType * type, char * name )
	{
		glad_es_30_glGetActiveAttrib( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLint *>( size ), reinterpret_cast<GLenum *>( type ), reinterpret_cast<GLchar *>( name ) );
	}

	void GlGetActiveUniform( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, UniformType * type, char * name )
	{
		glad_es_30_glGetActiveUniform( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLint *>( size ), reinterpret_cast<GLenum *>( type ), reinterpret_cast<GLchar *>( name ) );
	}

	void GlGetActiveUniformBlockName( Black::GlProgram program, uint32_t uniform_block_index, int32_t buf_size, int32_t * length, char * uniform_block_name )
	{
		glad_es_30_glGetActiveUniformBlockName( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_block_index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( uniform_block_name ) );
	}

	void GlGetActiveUniformBlockiv( Black::GlProgram program, uint32_t uniform_block_index, UniformBlockPName pname, int32_t * params )
	{
		glad_es_30_glGetActiveUniformBlockiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_block_index, Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetActiveUniformsiv( Black::GlProgram program, int32_t uniform_count, const uint32_t * uniform_indices, UniformPName pname, int32_t * params )
	{
		glad_es_30_glGetActiveUniformsiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_count, reinterpret_cast<const GLuint *>( uniform_indices ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetAttachedShaders( Black::GlProgram program, int32_t max_count, int32_t * count, Black::GlShader * shaders )
	{
		glad_es_30_glGetAttachedShaders( static_cast<GLuint>( Black::GetEnumValue( program ) ), max_count, reinterpret_cast<GLsizei *>( count ), reinterpret_cast<GLuint *>( shaders ) );
	}

	int32_t GlGetAttribLocation( Black::GlProgram program, const char * name )
	{
		return glad_es_30_glGetAttribLocation( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( name ) );
	}

	void GlGetBooleanv( GetPName pname, bool * data )
	{
		glad_es_30_glGetBooleanv( Black::GetEnumValue( pname ), reinterpret_cast<GLboolean *>( data ) );
	}

	void GlGetBufferParameteri64v( BufferTargetARB target, BufferPNameARB pname, int64_t * params )
	{
		glad_es_30_glGetBufferParameteri64v( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint64 *>( params ) );
	}

	void GlGetBufferParameteriv( BufferTargetARB target, BufferPNameARB pname, int32_t * params )
	{
		glad_es_30_glGetBufferParameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetBufferPointerv( BufferTargetARB target, BufferPointerNameARB pname, void ** params )
	{
		glad_es_30_glGetBufferPointerv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), params );
	}

	ErrorCode GlGetError()
	{
		return ErrorCode{ glad_es_30_glGetError() };
	}

	void GlGetFloatv( GetPName pname, float * data )
	{
		glad_es_30_glGetFloatv( Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( data ) );
	}

	int32_t GlGetFragDataLocation( Black::GlProgram program, const char * name )
	{
		return glad_es_30_glGetFragDataLocation( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( name ) );
	}

	void GlGetFramebufferAttachmentParameteriv( FramebufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameterName pname, int32_t * params )
	{
		glad_es_30_glGetFramebufferAttachmentParameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( attachment ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetInteger64i_v( GetPName target, uint32_t index, int64_t * data )
	{
		glad_es_30_glGetInteger64i_v( Black::GetEnumValue( target ), index, reinterpret_cast<GLint64 *>( data ) );
	}

	void GlGetInteger64v( GetPName pname, int64_t * data )
	{
		glad_es_30_glGetInteger64v( Black::GetEnumValue( pname ), reinterpret_cast<GLint64 *>( data ) );
	}

	void GlGetIntegeri_v( GetPName target, uint32_t index, int32_t * data )
	{
		glad_es_30_glGetIntegeri_v( Black::GetEnumValue( target ), index, reinterpret_cast<GLint *>( data ) );
	}

	void GlGetIntegerv( GetPName pname, int32_t * data )
	{
		glad_es_30_glGetIntegerv( Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( data ) );
	}

	void GlGetInternalformativ( TextureTarget target, InternalFormat internalformat, InternalFormatPName pname, int32_t count, int32_t * params )
	{
		glad_es_30_glGetInternalformativ( Black::GetEnumValue( target ), Black::GetEnumValue( internalformat ), Black::GetEnumValue( pname ), count, reinterpret_cast<GLint *>( params ) );
	}

	void GlGetProgramBinary( Black::GlProgram program, int32_t buf_size, int32_t * length, uint32_t * binary_format, void * binary )
	{
		glad_es_30_glGetProgramBinary( static_cast<GLuint>( Black::GetEnumValue( program ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLenum *>( binary_format ), binary );
	}

	void GlGetProgramInfoLog( Black::GlProgram program, int32_t buf_size, int32_t * length, char * info_log )
	{
		glad_es_30_glGetProgramInfoLog( static_cast<GLuint>( Black::GetEnumValue( program ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( info_log ) );
	}

	void GlGetProgramiv( Black::GlProgram program, ProgramPropertyARB pname, int32_t * params )
	{
		glad_es_30_glGetProgramiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetQueryObjectuiv( Black::GlQuery id, QueryObjectParameterName pname, uint32_t * params )
	{
		glad_es_30_glGetQueryObjectuiv( static_cast<GLuint>( Black::GetEnumValue( id ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLuint *>( params ) );
	}

	void GlGetQueryiv( QueryTarget target, QueryParameterName pname, int32_t * params )
	{
		glad_es_30_glGetQueryiv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetRenderbufferParameteriv( RenderbufferTarget target, RenderbufferParameterName pname, int32_t * params )
	{
		glad_es_30_glGetRenderbufferParameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetSamplerParameterfv( Black::GlSampler sampler, SamplerParameterF pname, float * params )
	{
		glad_es_30_glGetSamplerParameterfv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetSamplerParameteriv( Black::GlSampler sampler, SamplerParameterI pname, int32_t * params )
	{
		glad_es_30_glGetSamplerParameteriv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetShaderInfoLog( Black::GlShader shader, int32_t buf_size, int32_t * length, char * info_log )
	{
		glad_es_30_glGetShaderInfoLog( static_cast<GLuint>( Black::GetEnumValue( shader ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( info_log ) );
	}

	void GlGetShaderPrecisionFormat( ShaderType shadertype, PrecisionType precisiontype, int32_t * range, int32_t * precision )
	{
		glad_es_30_glGetShaderPrecisionFormat( Black::GetEnumValue( shadertype ), Black::GetEnumValue( precisiontype ), reinterpret_cast<GLint *>( range ), reinterpret_cast<GLint *>( precision ) );
	}

	void GlGetShaderSource( Black::GlShader shader, int32_t buf_size, int32_t * length, char * source )
	{
		glad_es_30_glGetShaderSource( static_cast<GLuint>( Black::GetEnumValue( shader ) ), buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLchar *>( source ) );
	}

	void GlGetShaderiv( Black::GlShader shader, ShaderParameterName pname, int32_t * params )
	{
		glad_es_30_glGetShaderiv( static_cast<GLuint>( Black::GetEnumValue( shader ) ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	const uint8_t * GlGetString( StringName name )
	{
		return glad_es_30_glGetString( Black::GetEnumValue( name ) );
	}

	const uint8_t * GlGetStringi( StringName name, uint32_t index )
	{
		return glad_es_30_glGetStringi( Black::GetEnumValue( name ), index );
	}

	void GlGetSynciv( Black::GlSyncHandle sync, SyncParameterName pname, int32_t count, int32_t * length, int32_t * values )
	{
		glad_es_30_glGetSynciv( static_cast<GLsync>( sync ), Black::GetEnumValue( pname ), count, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLint *>( values ) );
	}

	void GlGetTexParameterfv( TextureTarget target, GetTextureParameter pname, float * params )
	{
		glad_es_30_glGetTexParameterfv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetTexParameteriv( TextureTarget target, GetTextureParameter pname, int32_t * params )
	{
		glad_es_30_glGetTexParameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetTransformFeedbackVarying( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, AttributeType * type, char * name )
	{
		glad_es_30_glGetTransformFeedbackVarying( static_cast<GLuint>( Black::GetEnumValue( program ) ), index, buf_size, reinterpret_cast<GLsizei *>( length ), reinterpret_cast<GLsizei *>( size ), reinterpret_cast<GLenum *>( type ), reinterpret_cast<GLchar *>( name ) );
	}

	uint32_t GlGetUniformBlockIndex( Black::GlProgram program, const char * uniform_block_name )
	{
		return glad_es_30_glGetUniformBlockIndex( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( uniform_block_name ) );
	}

	void GlGetUniformIndices( Black::GlProgram program, int32_t uniform_count, const char *const* uniform_names, uint32_t * uniform_indices )
	{
		glad_es_30_glGetUniformIndices( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_count, reinterpret_cast<const GLchar *const*>( uniform_names ), reinterpret_cast<GLuint *>( uniform_indices ) );
	}

	int32_t GlGetUniformLocation( Black::GlProgram program, const char * name )
	{
		return glad_es_30_glGetUniformLocation( static_cast<GLuint>( Black::GetEnumValue( program ) ), reinterpret_cast<const GLchar *>( name ) );
	}

	void GlGetUniformfv( Black::GlProgram program, int32_t location, float * params )
	{
		glad_es_30_glGetUniformfv( static_cast<GLuint>( Black::GetEnumValue( program ) ), location, reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetUniformiv( Black::GlProgram program, int32_t location, int32_t * params )
	{
		glad_es_30_glGetUniformiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), location, reinterpret_cast<GLint *>( params ) );
	}

	void GlGetUniformuiv( Black::GlProgram program, int32_t location, uint32_t * params )
	{
		glad_es_30_glGetUniformuiv( static_cast<GLuint>( Black::GetEnumValue( program ) ), location, reinterpret_cast<GLuint *>( params ) );
	}

	void GlGetVertexAttribIiv( uint32_t index, VertexAttribEnum pname, int32_t * params )
	{
		glad_es_30_glGetVertexAttribIiv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlGetVertexAttribIuiv( uint32_t index, VertexAttribEnum pname, uint32_t * params )
	{
		glad_es_30_glGetVertexAttribIuiv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLuint *>( params ) );
	}

	void GlGetVertexAttribPointerv( uint32_t index, VertexAttribPointerPropertyARB pname, void ** pointer )
	{
		glad_es_30_glGetVertexAttribPointerv( index, Black::GetEnumValue( pname ), pointer );
	}

	void GlGetVertexAttribfv( uint32_t index, VertexAttribPropertyARB pname, float * params )
	{
		glad_es_30_glGetVertexAttribfv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLfloat *>( params ) );
	}

	void GlGetVertexAttribiv( uint32_t index, VertexAttribPropertyARB pname, int32_t * params )
	{
		glad_es_30_glGetVertexAttribiv( index, Black::GetEnumValue( pname ), reinterpret_cast<GLint *>( params ) );
	}

	void GlHint( HintTarget target, HintMode mode )
	{
		glad_es_30_glHint( Black::GetEnumValue( target ), Black::GetEnumValue( mode ) );
	}

	void GlInvalidateFramebuffer( FramebufferTarget target, int32_t num_attachments, const InvalidateFramebufferAttachment * attachments )
	{
		glad_es_30_glInvalidateFramebuffer( Black::GetEnumValue( target ), num_attachments, reinterpret_cast<const GLenum *>( attachments ) );
	}

	void GlInvalidateSubFramebuffer( FramebufferTarget target, int32_t num_attachments, const InvalidateFramebufferAttachment * attachments, int32_t x, int32_t y, int32_t width, int32_t height )
	{
		glad_es_30_glInvalidateSubFramebuffer( Black::GetEnumValue( target ), num_attachments, reinterpret_cast<const GLenum *>( attachments ), x, y, width, height );
	}

	bool GlIsBuffer( Black::GlBuffer buffer )
	{
		return glad_es_30_glIsBuffer( static_cast<GLuint>( Black::GetEnumValue( buffer ) ) );
	}

	bool GlIsEnabled( EnableCap cap )
	{
		return glad_es_30_glIsEnabled( Black::GetEnumValue( cap ) );
	}

	bool GlIsFramebuffer( Black::GlFrameBuffer framebuffer )
	{
		return glad_es_30_glIsFramebuffer( static_cast<GLuint>( Black::GetEnumValue( framebuffer ) ) );
	}

	bool GlIsProgram( Black::GlProgram program )
	{
		return glad_es_30_glIsProgram( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	bool GlIsQuery( Black::GlQuery id )
	{
		return glad_es_30_glIsQuery( static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	bool GlIsRenderbuffer( Black::GlRenderBuffer renderbuffer )
	{
		return glad_es_30_glIsRenderbuffer( static_cast<GLuint>( Black::GetEnumValue( renderbuffer ) ) );
	}

	bool GlIsSampler( Black::GlSampler sampler )
	{
		return glad_es_30_glIsSampler( static_cast<GLuint>( Black::GetEnumValue( sampler ) ) );
	}

	bool GlIsShader( Black::GlShader shader )
	{
		return glad_es_30_glIsShader( static_cast<GLuint>( Black::GetEnumValue( shader ) ) );
	}

	bool GlIsSync( Black::GlSyncHandle sync )
	{
		return glad_es_30_glIsSync( static_cast<GLsync>( sync ) );
	}

	bool GlIsTexture( Black::GlTexture texture )
	{
		return glad_es_30_glIsTexture( static_cast<GLuint>( Black::GetEnumValue( texture ) ) );
	}

	bool GlIsTransformFeedback( Black::GlTransformFeedback id )
	{
		return glad_es_30_glIsTransformFeedback( static_cast<GLuint>( Black::GetEnumValue( id ) ) );
	}

	bool GlIsVertexArray( Black::GlBuffer array )
	{
		return glad_es_30_glIsVertexArray( static_cast<GLuint>( Black::GetEnumValue( array ) ) );
	}

	void GlLineWidth( float width )
	{
		glad_es_30_glLineWidth( width );
	}

	void GlLinkProgram( Black::GlProgram program )
	{
		glad_es_30_glLinkProgram( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void * GlMapBufferRange( BufferTargetARB target, intptr_t offset, ptrdiff_t length, MapBufferAccessMask access )
	{
		return glad_es_30_glMapBufferRange( Black::GetEnumValue( target ), offset, length, static_cast<GLbitfield>( access ) );
	}

	void GlPauseTransformFeedback()
	{
		glad_es_30_glPauseTransformFeedback();
	}

	void GlPixelStorei( PixelStoreParameter pname, int32_t param )
	{
		glad_es_30_glPixelStorei( Black::GetEnumValue( pname ), param );
	}

	void GlPolygonOffset( float factor, float units )
	{
		glad_es_30_glPolygonOffset( factor, units );
	}

	void GlProgramBinary( Black::GlProgram program, uint32_t binary_format, const void * binary, int32_t length )
	{
		glad_es_30_glProgramBinary( static_cast<GLuint>( Black::GetEnumValue( program ) ), binary_format, binary, length );
	}

	void GlProgramParameteri( Black::GlProgram program, ProgramParameterPName pname, int32_t value )
	{
		glad_es_30_glProgramParameteri( static_cast<GLuint>( Black::GetEnumValue( program ) ), Black::GetEnumValue( pname ), value );
	}

	void GlReadBuffer( ReadBufferMode src )
	{
		glad_es_30_glReadBuffer( Black::GetEnumValue( src ) );
	}

	void GlReadPixels( int32_t x, int32_t y, int32_t width, int32_t height, PixelFormat format, PixelType type, void * pixels )
	{
		glad_es_30_glReadPixels( x, y, width, height, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlReleaseShaderCompiler()
	{
		glad_es_30_glReleaseShaderCompiler();
	}

	void GlRenderbufferStorage( RenderbufferTarget target, InternalFormat internalformat, int32_t width, int32_t height )
	{
		glad_es_30_glRenderbufferStorage( Black::GetEnumValue( target ), Black::GetEnumValue( internalformat ), width, height );
	}

	void GlRenderbufferStorageMultisample( RenderbufferTarget target, int32_t samples, InternalFormat internalformat, int32_t width, int32_t height )
	{
		glad_es_30_glRenderbufferStorageMultisample( Black::GetEnumValue( target ), samples, Black::GetEnumValue( internalformat ), width, height );
	}

	void GlResumeTransformFeedback()
	{
		glad_es_30_glResumeTransformFeedback();
	}

	void GlSampleCoverage( float value, bool invert )
	{
		glad_es_30_glSampleCoverage( value, invert );
	}

	void GlSamplerParameterf( Black::GlSampler sampler, SamplerParameterF pname, float param )
	{
		glad_es_30_glSamplerParameterf( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), param );
	}

	void GlSamplerParameterfv( Black::GlSampler sampler, SamplerParameterF pname, const float * param )
	{
		glad_es_30_glSamplerParameterfv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<const GLfloat *>( param ) );
	}

	void GlSamplerParameteri( Black::GlSampler sampler, SamplerParameterI pname, int32_t param )
	{
		glad_es_30_glSamplerParameteri( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), param );
	}

	void GlSamplerParameteriv( Black::GlSampler sampler, SamplerParameterI pname, const int32_t * param )
	{
		glad_es_30_glSamplerParameteriv( static_cast<GLuint>( Black::GetEnumValue( sampler ) ), Black::GetEnumValue( pname ), reinterpret_cast<const GLint *>( param ) );
	}

	void GlScissor( int32_t x, int32_t y, int32_t width, int32_t height )
	{
		glad_es_30_glScissor( x, y, width, height );
	}

	void GlShaderBinary( int32_t count, const Black::GlShader * shaders, ShaderBinaryFormat binary_format, const void * binary, int32_t length )
	{
		glad_es_30_glShaderBinary( count, reinterpret_cast<const GLuint *>( shaders ), Black::GetEnumValue( binary_format ), binary, length );
	}

	void GlShaderSource( Black::GlShader shader, int32_t count, const char *const* string, const int32_t * length )
	{
		glad_es_30_glShaderSource( static_cast<GLuint>( Black::GetEnumValue( shader ) ), count, reinterpret_cast<const GLchar *const*>( string ), reinterpret_cast<const GLint *>( length ) );
	}

	void GlStencilFunc( StencilFunction func, int32_t ref, uint32_t mask )
	{
		glad_es_30_glStencilFunc( Black::GetEnumValue( func ), ref, mask );
	}

	void GlStencilFuncSeparate( StencilFaceDirection face, StencilFunction func, int32_t ref, uint32_t mask )
	{
		glad_es_30_glStencilFuncSeparate( Black::GetEnumValue( face ), Black::GetEnumValue( func ), ref, mask );
	}

	void GlStencilMask( uint32_t mask )
	{
		glad_es_30_glStencilMask( mask );
	}

	void GlStencilMaskSeparate( StencilFaceDirection face, uint32_t mask )
	{
		glad_es_30_glStencilMaskSeparate( Black::GetEnumValue( face ), mask );
	}

	void GlStencilOp( StencilOp fail, StencilOp zfail, StencilOp zpass )
	{
		glad_es_30_glStencilOp( Black::GetEnumValue( fail ), Black::GetEnumValue( zfail ), Black::GetEnumValue( zpass ) );
	}

	void GlStencilOpSeparate( StencilFaceDirection face, StencilOp sfail, StencilOp dpfail, StencilOp dppass )
	{
		glad_es_30_glStencilOpSeparate( Black::GetEnumValue( face ), Black::GetEnumValue( sfail ), Black::GetEnumValue( dpfail ), Black::GetEnumValue( dppass ) );
	}

	void GlTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t border, PixelFormat format, PixelType type, const void * pixels )
	{
		glad_es_30_glTexImage2D( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, border, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTexImage3D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, PixelFormat format, PixelType type, const void * pixels )
	{
		glad_es_30_glTexImage3D( Black::GetEnumValue( target ), level, Black::GetEnumValue( internalformat ), width, height, depth, border, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTexParameterf( TextureTarget target, TextureParameterName pname, float param )
	{
		glad_es_30_glTexParameterf( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), param );
	}

	void GlTexParameterfv( TextureTarget target, TextureParameterName pname, const float * params )
	{
		glad_es_30_glTexParameterfv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<const GLfloat *>( params ) );
	}

	void GlTexParameteri( TextureTarget target, TextureParameterName pname, int32_t param )
	{
		glad_es_30_glTexParameteri( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), param );
	}

	void GlTexParameteriv( TextureTarget target, TextureParameterName pname, const int32_t * params )
	{
		glad_es_30_glTexParameteriv( Black::GetEnumValue( target ), Black::GetEnumValue( pname ), reinterpret_cast<const GLint *>( params ) );
	}

	void GlTexStorage2D( TextureTarget target, int32_t levels, SizedInternalFormat internalformat, int32_t width, int32_t height )
	{
		glad_es_30_glTexStorage2D( Black::GetEnumValue( target ), levels, Black::GetEnumValue( internalformat ), width, height );
	}

	void GlTexStorage3D( TextureTarget target, int32_t levels, SizedInternalFormat internalformat, int32_t width, int32_t height, int32_t depth )
	{
		glad_es_30_glTexStorage3D( Black::GetEnumValue( target ), levels, Black::GetEnumValue( internalformat ), width, height, depth );
	}

	void GlTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, PixelFormat format, PixelType type, const void * pixels )
	{
		glad_es_30_glTexSubImage2D( Black::GetEnumValue( target ), level, xoffset, yoffset, width, height, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, PixelFormat format, PixelType type, const void * pixels )
	{
		glad_es_30_glTexSubImage3D( Black::GetEnumValue( target ), level, xoffset, yoffset, zoffset, width, height, depth, Black::GetEnumValue( format ), Black::GetEnumValue( type ), pixels );
	}

	void GlTransformFeedbackVaryings( Black::GlProgram program, int32_t count, const char *const* varyings, TransformFeedbackBufferMode buffer_mode )
	{
		glad_es_30_glTransformFeedbackVaryings( static_cast<GLuint>( Black::GetEnumValue( program ) ), count, reinterpret_cast<const GLchar *const*>( varyings ), Black::GetEnumValue( buffer_mode ) );
	}

	void GlUniform1f( int32_t location, float v0 )
	{
		glad_es_30_glUniform1f( location, v0 );
	}

	void GlUniform1fv( int32_t location, int32_t count, const float * value )
	{
		glad_es_30_glUniform1fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform1i( int32_t location, int32_t v0 )
	{
		glad_es_30_glUniform1i( location, v0 );
	}

	void GlUniform1iv( int32_t location, int32_t count, const int32_t * value )
	{
		glad_es_30_glUniform1iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform1ui( int32_t location, uint32_t v0 )
	{
		glad_es_30_glUniform1ui( location, v0 );
	}

	void GlUniform1uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		glad_es_30_glUniform1uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniform2f( int32_t location, float v0, float v1 )
	{
		glad_es_30_glUniform2f( location, v0, v1 );
	}

	void GlUniform2fv( int32_t location, int32_t count, const float * value )
	{
		glad_es_30_glUniform2fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform2i( int32_t location, int32_t v0, int32_t v1 )
	{
		glad_es_30_glUniform2i( location, v0, v1 );
	}

	void GlUniform2iv( int32_t location, int32_t count, const int32_t * value )
	{
		glad_es_30_glUniform2iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform2ui( int32_t location, uint32_t v0, uint32_t v1 )
	{
		glad_es_30_glUniform2ui( location, v0, v1 );
	}

	void GlUniform2uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		glad_es_30_glUniform2uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniform3f( int32_t location, float v0, float v1, float v2 )
	{
		glad_es_30_glUniform3f( location, v0, v1, v2 );
	}

	void GlUniform3fv( int32_t location, int32_t count, const float * value )
	{
		glad_es_30_glUniform3fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform3i( int32_t location, int32_t v0, int32_t v1, int32_t v2 )
	{
		glad_es_30_glUniform3i( location, v0, v1, v2 );
	}

	void GlUniform3iv( int32_t location, int32_t count, const int32_t * value )
	{
		glad_es_30_glUniform3iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform3ui( int32_t location, uint32_t v0, uint32_t v1, uint32_t v2 )
	{
		glad_es_30_glUniform3ui( location, v0, v1, v2 );
	}

	void GlUniform3uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		glad_es_30_glUniform3uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniform4f( int32_t location, float v0, float v1, float v2, float v3 )
	{
		glad_es_30_glUniform4f( location, v0, v1, v2, v3 );
	}

	void GlUniform4fv( int32_t location, int32_t count, const float * value )
	{
		glad_es_30_glUniform4fv( location, count, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniform4i( int32_t location, int32_t v0, int32_t v1, int32_t v2, int32_t v3 )
	{
		glad_es_30_glUniform4i( location, v0, v1, v2, v3 );
	}

	void GlUniform4iv( int32_t location, int32_t count, const int32_t * value )
	{
		glad_es_30_glUniform4iv( location, count, reinterpret_cast<const GLint *>( value ) );
	}

	void GlUniform4ui( int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3 )
	{
		glad_es_30_glUniform4ui( location, v0, v1, v2, v3 );
	}

	void GlUniform4uiv( int32_t location, int32_t count, const uint32_t * value )
	{
		glad_es_30_glUniform4uiv( location, count, reinterpret_cast<const GLuint *>( value ) );
	}

	void GlUniformBlockBinding( Black::GlProgram program, uint32_t uniform_block_index, uint32_t uniform_block_binding )
	{
		glad_es_30_glUniformBlockBinding( static_cast<GLuint>( Black::GetEnumValue( program ) ), uniform_block_index, uniform_block_binding );
	}

	void GlUniformMatrix2fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix2fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix2x3fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix2x3fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix2x4fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix2x4fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix3fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix3fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix3x2fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix3x2fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix3x4fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix3x4fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix4fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix4fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix4x2fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix4x2fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	void GlUniformMatrix4x3fv( int32_t location, int32_t count, bool transpose, const float * value )
	{
		glad_es_30_glUniformMatrix4x3fv( location, count, transpose, reinterpret_cast<const GLfloat *>( value ) );
	}

	bool GlUnmapBuffer( BufferTargetARB target )
	{
		return glad_es_30_glUnmapBuffer( Black::GetEnumValue( target ) );
	}

	void GlUseProgram( Black::GlProgram program )
	{
		glad_es_30_glUseProgram( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void GlValidateProgram( Black::GlProgram program )
	{
		glad_es_30_glValidateProgram( static_cast<GLuint>( Black::GetEnumValue( program ) ) );
	}

	void GlVertexAttrib1f( uint32_t index, float x )
	{
		glad_es_30_glVertexAttrib1f( index, x );
	}

	void GlVertexAttrib1fv( uint32_t index, const float * v )
	{
		glad_es_30_glVertexAttrib1fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttrib2f( uint32_t index, float x, float y )
	{
		glad_es_30_glVertexAttrib2f( index, x, y );
	}

	void GlVertexAttrib2fv( uint32_t index, const float * v )
	{
		glad_es_30_glVertexAttrib2fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttrib3f( uint32_t index, float x, float y, float z )
	{
		glad_es_30_glVertexAttrib3f( index, x, y, z );
	}

	void GlVertexAttrib3fv( uint32_t index, const float * v )
	{
		glad_es_30_glVertexAttrib3fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttrib4f( uint32_t index, float x, float y, float z, float w )
	{
		glad_es_30_glVertexAttrib4f( index, x, y, z, w );
	}

	void GlVertexAttrib4fv( uint32_t index, const float * v )
	{
		glad_es_30_glVertexAttrib4fv( index, reinterpret_cast<const GLfloat *>( v ) );
	}

	void GlVertexAttribDivisor( uint32_t index, uint32_t divisor )
	{
		glad_es_30_glVertexAttribDivisor( index, divisor );
	}

	void GlVertexAttribI4i( uint32_t index, int32_t x, int32_t y, int32_t z, int32_t w )
	{
		glad_es_30_glVertexAttribI4i( index, x, y, z, w );
	}

	void GlVertexAttribI4iv( uint32_t index, const int32_t * v )
	{
		glad_es_30_glVertexAttribI4iv( index, reinterpret_cast<const GLint *>( v ) );
	}

	void GlVertexAttribI4ui( uint32_t index, uint32_t x, uint32_t y, uint32_t z, uint32_t w )
	{
		glad_es_30_glVertexAttribI4ui( index, x, y, z, w );
	}

	void GlVertexAttribI4uiv( uint32_t index, const uint32_t * v )
	{
		glad_es_30_glVertexAttribI4uiv( index, reinterpret_cast<const GLuint *>( v ) );
	}

	void GlVertexAttribIPointer( uint32_t index, int32_t size, VertexAttribIType type, int32_t stride, const void * pointer )
	{
		glad_es_30_glVertexAttribIPointer( index, size, Black::GetEnumValue( type ), stride, pointer );
	}

	void GlVertexAttribPointer( uint32_t index, int32_t size, VertexAttribPointerType type, bool normalized, int32_t stride, const void * pointer )
	{
		glad_es_30_glVertexAttribPointer( index, size, Black::GetEnumValue( type ), normalized, stride, pointer );
	}

	void GlViewport( int32_t x, int32_t y, int32_t width, int32_t height )
	{
		glad_es_30_glViewport( x, y, width, height );
	}

	void GlWaitSync( Black::GlSyncHandle sync, SyncBehaviorFlags flags, uint64_t timeout )
	{
		glad_es_30_glWaitSync( static_cast<GLsync>( sync ), Black::GetEnumValue( flags ), timeout );
	}

}
}
}
