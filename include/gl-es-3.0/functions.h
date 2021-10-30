#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace GlEs30
{
	// void glActiveTexture(GLenum texture)
	void GlActiveTexture( TextureUnit texture );

	// void glAttachShader(GLuint program, GLuint shader)
	void GlAttachShader( Black::GlProgram program, Black::GlShader shader );

	// void glBeginQuery(GLenum target, GLuint id)
	void GlBeginQuery( QueryTarget target, Black::GlQuery id );

	// void glBeginTransformFeedback(GLenum primitiveMode)
	void GlBeginTransformFeedback( PrimitiveType primitive_mode );

	// void glBindAttribLocation(GLuint program, GLuint index, GLchar name)
	void GlBindAttribLocation( Black::GlProgram program, uint32_t index, const char * name );

	// void glBindBuffer(GLenum target, GLuint buffer)
	void GlBindBuffer( BufferTargetARB target, Black::GlBuffer buffer );

	// void glBindBufferBase(GLenum target, GLuint index, GLuint buffer)
	void GlBindBufferBase( BufferTargetARB target, uint32_t index, Black::GlBuffer buffer );

	// void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size)
	void GlBindBufferRange( BufferTargetARB target, uint32_t index, Black::GlBuffer buffer, intptr_t offset, ptrdiff_t size );

	// void glBindFramebuffer(GLenum target, GLuint framebuffer)
	void GlBindFramebuffer( FramebufferTarget target, Black::GlFrameBuffer framebuffer );

	// void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
	void GlBindRenderbuffer( RenderbufferTarget target, Black::GlRenderBuffer renderbuffer );

	// void glBindSampler(GLuint unit, GLuint sampler)
	void GlBindSampler( uint32_t unit, Black::GlSampler sampler );

	// void glBindTexture(GLenum target, GLuint texture)
	void GlBindTexture( TextureTarget target, Black::GlTexture texture );

	// void glBindTransformFeedback(GLenum target, GLuint id)
	void GlBindTransformFeedback( BindTransformFeedbackTarget target, Black::GlTransformFeedback id );

	// void glBindVertexArray(GLuint array)
	void GlBindVertexArray( Black::GlBuffer array );

	// void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	void GlBlendColor( float red, float green, float blue, float alpha );

	// void glBlendEquation(GLenum mode)
	void GlBlendEquation( BlendEquationModeEXT mode );

	// void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
	void GlBlendEquationSeparate( BlendEquationModeEXT mode_r_g_b, BlendEquationModeEXT mode_alpha );

	// void glBlendFunc(GLenum sfactor, GLenum dfactor)
	void GlBlendFunc( BlendingFactor sfactor, BlendingFactor dfactor );

	// void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
	void GlBlendFuncSeparate( BlendingFactor sfactor_r_g_b, BlendingFactor dfactor_r_g_b, BlendingFactor sfactor_alpha, BlendingFactor dfactor_alpha );

	// void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter)
	void GlBlitFramebuffer( int32_t src_x0, int32_t src_y0, int32_t src_x1, int32_t src_y1, int32_t dst_x0, int32_t dst_y0, int32_t dst_x1, int32_t dst_y1, ClearBufferMask mask, BlitFramebufferFilter filter );

	// void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage)
	void GlBufferData( BufferTargetARB target, ptrdiff_t size, const void * data, BufferUsageARB usage );

	// void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data)
	void GlBufferSubData( BufferTargetARB target, intptr_t offset, ptrdiff_t size, const void * data );

	// GLenum glCheckFramebufferStatus(GLenum target)
	FramebufferStatus GlCheckFramebufferStatus( FramebufferTarget target );

	// void glClear(GLbitfield mask)
	void GlClear( ClearBufferMask mask );

	// void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil)
	void GlClearBufferfi( Buffer buffer, int32_t drawbuffer, float depth, int32_t stencil );

	// void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat value)
	void GlClearBufferfv( Buffer buffer, int32_t drawbuffer, const float * value );

	// void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint value)
	void GlClearBufferiv( Buffer buffer, int32_t drawbuffer, const int32_t * value );

	// void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint value)
	void GlClearBufferuiv( Buffer buffer, int32_t drawbuffer, const uint32_t * value );

	// void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
	void GlClearColor( float red, float green, float blue, float alpha );

	// void glClearDepthf(GLfloat d)
	void GlClearDepthf( float d );

	// void glClearStencil(GLint s)
	void GlClearStencil( int32_t s );

	// GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
	SyncStatus GlClientWaitSync( Black::GlSyncHandle sync, SyncObjectMask flags, uint64_t timeout );

	// void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
	void GlColorMask( bool red, bool green, bool blue, bool alpha );

	// void glCompileShader(GLuint shader)
	void GlCompileShader( Black::GlShader shader );

	// void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data)
	void GlCompressedTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t border, int32_t image_size, const void * data );

	// void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data)
	void GlCompressedTexImage3D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, int32_t image_size, const void * data );

	// void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data)
	void GlCompressedTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, InternalFormat format, int32_t image_size, const void * data );

	// void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data)
	void GlCompressedTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, InternalFormat format, int32_t image_size, const void * data );

	// void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size)
	void GlCopyBufferSubData( CopyBufferSubDataTarget read_target, CopyBufferSubDataTarget write_target, intptr_t read_offset, intptr_t write_offset, ptrdiff_t size );

	// void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
	void GlCopyTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t x, int32_t y, int32_t width, int32_t height, int32_t border );

	// void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	void GlCopyTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t x, int32_t y, int32_t width, int32_t height );

	// void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height)
	void GlCopyTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t x, int32_t y, int32_t width, int32_t height );

	// GLuint glCreateProgram()
	Black::GlProgram GlCreateProgram();

	// GLuint glCreateShader(GLenum type)
	Black::GlShader GlCreateShader( ShaderType type );

	// void glCullFace(GLenum mode)
	void GlCullFace( CullFaceMode mode );

	// void glDeleteBuffers(GLsizei n, GLuint buffers)
	void GlDeleteBuffers( int32_t n, const Black::GlBuffer * buffers );

	// void glDeleteFramebuffers(GLsizei n, GLuint framebuffers)
	void GlDeleteFramebuffers( int32_t n, const Black::GlFrameBuffer * framebuffers );

	// void glDeleteProgram(GLuint program)
	void GlDeleteProgram( Black::GlProgram program );

	// void glDeleteQueries(GLsizei n, GLuint ids)
	void GlDeleteQueries( int32_t n, const Black::GlQuery * ids );

	// void glDeleteRenderbuffers(GLsizei n, GLuint renderbuffers)
	void GlDeleteRenderbuffers( int32_t n, const Black::GlRenderBuffer * renderbuffers );

	// void glDeleteSamplers(GLsizei count, GLuint samplers)
	void GlDeleteSamplers( int32_t count, const Black::GlSampler * samplers );

	// void glDeleteShader(GLuint shader)
	void GlDeleteShader( Black::GlShader shader );

	// void glDeleteSync(GLsync sync)
	void GlDeleteSync( Black::GlSyncHandle sync );

	// void glDeleteTextures(GLsizei n, GLuint textures)
	void GlDeleteTextures( int32_t n, const Black::GlTexture * textures );

	// void glDeleteTransformFeedbacks(GLsizei n, GLuint ids)
	void GlDeleteTransformFeedbacks( int32_t n, const Black::GlTransformFeedback * ids );

	// void glDeleteVertexArrays(GLsizei n, GLuint arrays)
	void GlDeleteVertexArrays( int32_t n, const Black::GlBuffer * arrays );

	// void glDepthFunc(GLenum func)
	void GlDepthFunc( DepthFunction func );

	// void glDepthMask(GLboolean flag)
	void GlDepthMask( bool flag );

	// void glDepthRangef(GLfloat n, GLfloat f)
	void GlDepthRangef( float n, float f );

	// void glDetachShader(GLuint program, GLuint shader)
	void GlDetachShader( Black::GlProgram program, Black::GlShader shader );

	// void glDisable(GLenum cap)
	void GlDisable( EnableCap cap );

	// void glDisableVertexAttribArray(GLuint index)
	void GlDisableVertexAttribArray( uint32_t index );

	// void glDrawArrays(GLenum mode, GLint first, GLsizei count)
	void GlDrawArrays( PrimitiveType mode, int32_t first, int32_t count );

	// void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount)
	void GlDrawArraysInstanced( PrimitiveType mode, int32_t first, int32_t count, int32_t instancecount );

	// void glDrawBuffers(GLsizei n, GLenum bufs)
	void GlDrawBuffers( int32_t n, const DrawBufferMode * bufs );

	// void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices)
	void GlDrawElements( PrimitiveType mode, int32_t count, DrawElementsType type, const void * indices );

	// void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount)
	void GlDrawElementsInstanced( PrimitiveType mode, int32_t count, DrawElementsType type, const void * indices, int32_t instancecount );

	// void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices)
	void GlDrawRangeElements( PrimitiveType mode, uint32_t start, uint32_t end, int32_t count, DrawElementsType type, const void * indices );

	// void glEnable(GLenum cap)
	void GlEnable( EnableCap cap );

	// void glEnableVertexAttribArray(GLuint index)
	void GlEnableVertexAttribArray( uint32_t index );

	// void glEndQuery(GLenum target)
	void GlEndQuery( QueryTarget target );

	// void glEndTransformFeedback()
	void GlEndTransformFeedback();

	// GLsync glFenceSync(GLenum condition, GLbitfield flags)
	Black::GlSyncHandle GlFenceSync( SyncCondition condition, SyncBehaviorFlags flags );

	// void glFinish()
	void GlFinish();

	// void glFlush()
	void GlFlush();

	// void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length)
	void GlFlushMappedBufferRange( BufferTargetARB target, intptr_t offset, ptrdiff_t length );

	// void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
	void GlFramebufferRenderbuffer( FramebufferTarget target, FramebufferAttachment attachment, RenderbufferTarget renderbuffertarget, Black::GlRenderBuffer renderbuffer );

	// void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
	void GlFramebufferTexture2D( FramebufferTarget target, FramebufferAttachment attachment, TextureTarget textarget, Black::GlTexture texture, int32_t level );

	// void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer)
	void GlFramebufferTextureLayer( FramebufferTarget target, FramebufferAttachment attachment, Black::GlTexture texture, int32_t level, int32_t layer );

	// void glFrontFace(GLenum mode)
	void GlFrontFace( FrontFaceDirection mode );

	// void glGenBuffers(GLsizei n, GLuint buffers)
	void GlGenBuffers( int32_t n, Black::GlBuffer * buffers );

	// void glGenFramebuffers(GLsizei n, GLuint framebuffers)
	void GlGenFramebuffers( int32_t n, Black::GlFrameBuffer * framebuffers );

	// void glGenQueries(GLsizei n, GLuint ids)
	void GlGenQueries( int32_t n, Black::GlQuery * ids );

	// void glGenRenderbuffers(GLsizei n, GLuint renderbuffers)
	void GlGenRenderbuffers( int32_t n, Black::GlRenderBuffer * renderbuffers );

	// void glGenSamplers(GLsizei count, GLuint samplers)
	void GlGenSamplers( int32_t count, Black::GlSampler * samplers );

	// void glGenTextures(GLsizei n, GLuint textures)
	void GlGenTextures( int32_t n, Black::GlTexture * textures );

	// void glGenTransformFeedbacks(GLsizei n, GLuint ids)
	void GlGenTransformFeedbacks( int32_t n, Black::GlTransformFeedback * ids );

	// void glGenVertexArrays(GLsizei n, GLuint arrays)
	void GlGenVertexArrays( int32_t n, Black::GlBuffer * arrays );

	// void glGenerateMipmap(GLenum target)
	void GlGenerateMipmap( TextureTarget target );

	// void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name)
	void GlGetActiveAttrib( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, AttributeType * type, char * name );

	// void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name)
	void GlGetActiveUniform( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, UniformType * type, char * name );

	// void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLchar uniformBlockName)
	void GlGetActiveUniformBlockName( Black::GlProgram program, uint32_t uniform_block_index, int32_t buf_size, int32_t * length, char * uniform_block_name );

	// void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint params)
	void GlGetActiveUniformBlockiv( Black::GlProgram program, uint32_t uniform_block_index, UniformBlockPName pname, int32_t * params );

	// void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint uniformIndices, GLenum pname, GLint params)
	void GlGetActiveUniformsiv( Black::GlProgram program, int32_t uniform_count, const uint32_t * uniform_indices, UniformPName pname, int32_t * params );

	// void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei count, GLuint shaders)
	void GlGetAttachedShaders( Black::GlProgram program, int32_t max_count, int32_t * count, Black::GlShader * shaders );

	// GLint glGetAttribLocation(GLuint program, GLchar name)
	int32_t GlGetAttribLocation( Black::GlProgram program, const char * name );

	// void glGetBooleanv(GLenum pname, GLboolean data)
	void GlGetBooleanv( GetPName pname, bool * data );

	// void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 params)
	void GlGetBufferParameteri64v( BufferTargetARB target, BufferPNameARB pname, int64_t * params );

	// void glGetBufferParameteriv(GLenum target, GLenum pname, GLint params)
	void GlGetBufferParameteriv( BufferTargetARB target, BufferPNameARB pname, int32_t * params );

	// void glGetBufferPointerv(GLenum target, GLenum pname, void ** params)
	void GlGetBufferPointerv( BufferTargetARB target, BufferPointerNameARB pname, void ** params );

	// GLenum glGetError()
	ErrorCode GlGetError();

	// void glGetFloatv(GLenum pname, GLfloat data)
	void GlGetFloatv( GetPName pname, float * data );

	// GLint glGetFragDataLocation(GLuint program, GLchar name)
	int32_t GlGetFragDataLocation( Black::GlProgram program, const char * name );

	// void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint params)
	void GlGetFramebufferAttachmentParameteriv( FramebufferTarget target, FramebufferAttachment attachment, FramebufferAttachmentParameterName pname, int32_t * params );

	// void glGetInteger64i_v(GLenum target, GLuint index, GLint64 data)
	void GlGetInteger64i_v( GetPName target, uint32_t index, int64_t * data );

	// void glGetInteger64v(GLenum pname, GLint64 data)
	void GlGetInteger64v( GetPName pname, int64_t * data );

	// void glGetIntegeri_v(GLenum target, GLuint index, GLint data)
	void GlGetIntegeri_v( GetPName target, uint32_t index, int32_t * data );

	// void glGetIntegerv(GLenum pname, GLint data)
	void GlGetIntegerv( GetPName pname, int32_t * data );

	// void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint params)
	void GlGetInternalformativ( TextureTarget target, InternalFormat internalformat, InternalFormatPName pname, int32_t count, int32_t * params );

	// void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenum binaryFormat, void * binary)
	void GlGetProgramBinary( Black::GlProgram program, int32_t buf_size, int32_t * length, uint32_t * binary_format, void * binary );

	// void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLchar infoLog)
	void GlGetProgramInfoLog( Black::GlProgram program, int32_t buf_size, int32_t * length, char * info_log );

	// void glGetProgramiv(GLuint program, GLenum pname, GLint params)
	void GlGetProgramiv( Black::GlProgram program, ProgramPropertyARB pname, int32_t * params );

	// void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint params)
	void GlGetQueryObjectuiv( Black::GlQuery id, QueryObjectParameterName pname, uint32_t * params );

	// void glGetQueryiv(GLenum target, GLenum pname, GLint params)
	void GlGetQueryiv( QueryTarget target, QueryParameterName pname, int32_t * params );

	// void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint params)
	void GlGetRenderbufferParameteriv( RenderbufferTarget target, RenderbufferParameterName pname, int32_t * params );

	// void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat params)
	void GlGetSamplerParameterfv( Black::GlSampler sampler, SamplerParameterF pname, float * params );

	// void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint params)
	void GlGetSamplerParameteriv( Black::GlSampler sampler, SamplerParameterI pname, int32_t * params );

	// void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLchar infoLog)
	void GlGetShaderInfoLog( Black::GlShader shader, int32_t buf_size, int32_t * length, char * info_log );

	// void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint range, GLint precision)
	void GlGetShaderPrecisionFormat( ShaderType shadertype, PrecisionType precisiontype, int32_t * range, int32_t * precision );

	// void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLchar source)
	void GlGetShaderSource( Black::GlShader shader, int32_t buf_size, int32_t * length, char * source );

	// void glGetShaderiv(GLuint shader, GLenum pname, GLint params)
	void GlGetShaderiv( Black::GlShader shader, ShaderParameterName pname, int32_t * params );

	// GLubyte glGetString(GLenum name)
	const uint8_t * GlGetString( StringName name );

	// GLubyte glGetStringi(GLenum name, GLuint index)
	const uint8_t * GlGetStringi( StringName name, uint32_t index );

	// void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei length, GLint values)
	void GlGetSynciv( Black::GlSyncHandle sync, SyncParameterName pname, int32_t count, int32_t * length, int32_t * values );

	// void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat params)
	void GlGetTexParameterfv( TextureTarget target, GetTextureParameter pname, float * params );

	// void glGetTexParameteriv(GLenum target, GLenum pname, GLint params)
	void GlGetTexParameteriv( TextureTarget target, GetTextureParameter pname, int32_t * params );

	// void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name)
	void GlGetTransformFeedbackVarying( Black::GlProgram program, uint32_t index, int32_t buf_size, int32_t * length, int32_t * size, AttributeType * type, char * name );

	// GLuint glGetUniformBlockIndex(GLuint program, GLchar uniformBlockName)
	uint32_t GlGetUniformBlockIndex( Black::GlProgram program, const char * uniform_block_name );

	// void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar uniformNames, GLuint uniformIndices)
	void GlGetUniformIndices( Black::GlProgram program, int32_t uniform_count, const char *const* uniform_names, uint32_t * uniform_indices );

	// GLint glGetUniformLocation(GLuint program, GLchar name)
	int32_t GlGetUniformLocation( Black::GlProgram program, const char * name );

	// void glGetUniformfv(GLuint program, GLint location, GLfloat params)
	void GlGetUniformfv( Black::GlProgram program, int32_t location, float * params );

	// void glGetUniformiv(GLuint program, GLint location, GLint params)
	void GlGetUniformiv( Black::GlProgram program, int32_t location, int32_t * params );

	// void glGetUniformuiv(GLuint program, GLint location, GLuint params)
	void GlGetUniformuiv( Black::GlProgram program, int32_t location, uint32_t * params );

	// void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint params)
	void GlGetVertexAttribIiv( uint32_t index, VertexAttribEnum pname, int32_t * params );

	// void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint params)
	void GlGetVertexAttribIuiv( uint32_t index, VertexAttribEnum pname, uint32_t * params );

	// void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer)
	void GlGetVertexAttribPointerv( uint32_t index, VertexAttribPointerPropertyARB pname, void ** pointer );

	// void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat params)
	void GlGetVertexAttribfv( uint32_t index, VertexAttribPropertyARB pname, float * params );

	// void glGetVertexAttribiv(GLuint index, GLenum pname, GLint params)
	void GlGetVertexAttribiv( uint32_t index, VertexAttribPropertyARB pname, int32_t * params );

	// void glHint(GLenum target, GLenum mode)
	void GlHint( HintTarget target, HintMode mode );

	// void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments)
	void GlInvalidateFramebuffer( FramebufferTarget target, int32_t num_attachments, const InvalidateFramebufferAttachment * attachments );

	// void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments, GLint x, GLint y, GLsizei width, GLsizei height)
	void GlInvalidateSubFramebuffer( FramebufferTarget target, int32_t num_attachments, const InvalidateFramebufferAttachment * attachments, int32_t x, int32_t y, int32_t width, int32_t height );

	// GLboolean glIsBuffer(GLuint buffer)
	bool GlIsBuffer( Black::GlBuffer buffer );

	// GLboolean glIsEnabled(GLenum cap)
	bool GlIsEnabled( EnableCap cap );

	// GLboolean glIsFramebuffer(GLuint framebuffer)
	bool GlIsFramebuffer( Black::GlFrameBuffer framebuffer );

	// GLboolean glIsProgram(GLuint program)
	bool GlIsProgram( Black::GlProgram program );

	// GLboolean glIsQuery(GLuint id)
	bool GlIsQuery( Black::GlQuery id );

	// GLboolean glIsRenderbuffer(GLuint renderbuffer)
	bool GlIsRenderbuffer( Black::GlRenderBuffer renderbuffer );

	// GLboolean glIsSampler(GLuint sampler)
	bool GlIsSampler( Black::GlSampler sampler );

	// GLboolean glIsShader(GLuint shader)
	bool GlIsShader( Black::GlShader shader );

	// GLboolean glIsSync(GLsync sync)
	bool GlIsSync( Black::GlSyncHandle sync );

	// GLboolean glIsTexture(GLuint texture)
	bool GlIsTexture( Black::GlTexture texture );

	// GLboolean glIsTransformFeedback(GLuint id)
	bool GlIsTransformFeedback( Black::GlTransformFeedback id );

	// GLboolean glIsVertexArray(GLuint array)
	bool GlIsVertexArray( Black::GlBuffer array );

	// void glLineWidth(GLfloat width)
	void GlLineWidth( float width );

	// void glLinkProgram(GLuint program)
	void GlLinkProgram( Black::GlProgram program );

	// void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access)
	void * GlMapBufferRange( BufferTargetARB target, intptr_t offset, ptrdiff_t length, MapBufferAccessMask access );

	// void glPauseTransformFeedback()
	void GlPauseTransformFeedback();

	// void glPixelStorei(GLenum pname, GLint param)
	void GlPixelStorei( PixelStoreParameter pname, int32_t param );

	// void glPolygonOffset(GLfloat factor, GLfloat units)
	void GlPolygonOffset( float factor, float units );

	// void glProgramBinary(GLuint program, GLenum binaryFormat, const void * binary, GLsizei length)
	void GlProgramBinary( Black::GlProgram program, uint32_t binary_format, const void * binary, int32_t length );

	// void glProgramParameteri(GLuint program, GLenum pname, GLint value)
	void GlProgramParameteri( Black::GlProgram program, ProgramParameterPName pname, int32_t value );

	// void glReadBuffer(GLenum src)
	void GlReadBuffer( ReadBufferMode src );

	// void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels)
	void GlReadPixels( int32_t x, int32_t y, int32_t width, int32_t height, PixelFormat format, PixelType type, void * pixels );

	// void glReleaseShaderCompiler()
	void GlReleaseShaderCompiler();

	// void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
	void GlRenderbufferStorage( RenderbufferTarget target, InternalFormat internalformat, int32_t width, int32_t height );

	// void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height)
	void GlRenderbufferStorageMultisample( RenderbufferTarget target, int32_t samples, InternalFormat internalformat, int32_t width, int32_t height );

	// void glResumeTransformFeedback()
	void GlResumeTransformFeedback();

	// void glSampleCoverage(GLfloat value, GLboolean invert)
	void GlSampleCoverage( float value, bool invert );

	// void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param)
	void GlSamplerParameterf( Black::GlSampler sampler, SamplerParameterF pname, float param );

	// void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat param)
	void GlSamplerParameterfv( Black::GlSampler sampler, SamplerParameterF pname, const float * param );

	// void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param)
	void GlSamplerParameteri( Black::GlSampler sampler, SamplerParameterI pname, int32_t param );

	// void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint param)
	void GlSamplerParameteriv( Black::GlSampler sampler, SamplerParameterI pname, const int32_t * param );

	// void glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
	void GlScissor( int32_t x, int32_t y, int32_t width, int32_t height );

	// void glShaderBinary(GLsizei count, GLuint shaders, GLenum binaryFormat, const void * binary, GLsizei length)
	void GlShaderBinary( int32_t count, const Black::GlShader * shaders, ShaderBinaryFormat binary_format, const void * binary, int32_t length );

	// void glShaderSource(GLuint shader, GLsizei count, GLchar string, GLint length)
	void GlShaderSource( Black::GlShader shader, int32_t count, const char *const* string, const int32_t * length );

	// void glStencilFunc(GLenum func, GLint ref, GLuint mask)
	void GlStencilFunc( StencilFunction func, int32_t ref, uint32_t mask );

	// void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
	void GlStencilFuncSeparate( StencilFaceDirection face, StencilFunction func, int32_t ref, uint32_t mask );

	// void glStencilMask(GLuint mask)
	void GlStencilMask( uint32_t mask );

	// void glStencilMaskSeparate(GLenum face, GLuint mask)
	void GlStencilMaskSeparate( StencilFaceDirection face, uint32_t mask );

	// void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
	void GlStencilOp( StencilOp fail, StencilOp zfail, StencilOp zpass );

	// void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
	void GlStencilOpSeparate( StencilFaceDirection face, StencilOp sfail, StencilOp dpfail, StencilOp dppass );

	// void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels)
	void GlTexImage2D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t border, PixelFormat format, PixelType type, const void * pixels );

	// void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels)
	void GlTexImage3D( TextureTarget target, int32_t level, InternalFormat internalformat, int32_t width, int32_t height, int32_t depth, int32_t border, PixelFormat format, PixelType type, const void * pixels );

	// void glTexParameterf(GLenum target, GLenum pname, GLfloat param)
	void GlTexParameterf( TextureTarget target, TextureParameterName pname, float param );

	// void glTexParameterfv(GLenum target, GLenum pname, GLfloat params)
	void GlTexParameterfv( TextureTarget target, TextureParameterName pname, const float * params );

	// void glTexParameteri(GLenum target, GLenum pname, GLint param)
	void GlTexParameteri( TextureTarget target, TextureParameterName pname, int32_t param );

	// void glTexParameteriv(GLenum target, GLenum pname, GLint params)
	void GlTexParameteriv( TextureTarget target, TextureParameterName pname, const int32_t * params );

	// void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height)
	void GlTexStorage2D( TextureTarget target, int32_t levels, SizedInternalFormat internalformat, int32_t width, int32_t height );

	// void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth)
	void GlTexStorage3D( TextureTarget target, int32_t levels, SizedInternalFormat internalformat, int32_t width, int32_t height, int32_t depth );

	// void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels)
	void GlTexSubImage2D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, PixelFormat format, PixelType type, const void * pixels );

	// void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels)
	void GlTexSubImage3D( TextureTarget target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, PixelFormat format, PixelType type, const void * pixels );

	// void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar varyings, GLenum bufferMode)
	void GlTransformFeedbackVaryings( Black::GlProgram program, int32_t count, const char *const* varyings, TransformFeedbackBufferMode buffer_mode );

	// void glUniform1f(GLint location, GLfloat v0)
	void GlUniform1f( int32_t location, float v0 );

	// void glUniform1fv(GLint location, GLsizei count, GLfloat value)
	void GlUniform1fv( int32_t location, int32_t count, const float * value );

	// void glUniform1i(GLint location, GLint v0)
	void GlUniform1i( int32_t location, int32_t v0 );

	// void glUniform1iv(GLint location, GLsizei count, GLint value)
	void GlUniform1iv( int32_t location, int32_t count, const int32_t * value );

	// void glUniform1ui(GLint location, GLuint v0)
	void GlUniform1ui( int32_t location, uint32_t v0 );

	// void glUniform1uiv(GLint location, GLsizei count, GLuint value)
	void GlUniform1uiv( int32_t location, int32_t count, const uint32_t * value );

	// void glUniform2f(GLint location, GLfloat v0, GLfloat v1)
	void GlUniform2f( int32_t location, float v0, float v1 );

	// void glUniform2fv(GLint location, GLsizei count, GLfloat value)
	void GlUniform2fv( int32_t location, int32_t count, const float * value );

	// void glUniform2i(GLint location, GLint v0, GLint v1)
	void GlUniform2i( int32_t location, int32_t v0, int32_t v1 );

	// void glUniform2iv(GLint location, GLsizei count, GLint value)
	void GlUniform2iv( int32_t location, int32_t count, const int32_t * value );

	// void glUniform2ui(GLint location, GLuint v0, GLuint v1)
	void GlUniform2ui( int32_t location, uint32_t v0, uint32_t v1 );

	// void glUniform2uiv(GLint location, GLsizei count, GLuint value)
	void GlUniform2uiv( int32_t location, int32_t count, const uint32_t * value );

	// void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
	void GlUniform3f( int32_t location, float v0, float v1, float v2 );

	// void glUniform3fv(GLint location, GLsizei count, GLfloat value)
	void GlUniform3fv( int32_t location, int32_t count, const float * value );

	// void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2)
	void GlUniform3i( int32_t location, int32_t v0, int32_t v1, int32_t v2 );

	// void glUniform3iv(GLint location, GLsizei count, GLint value)
	void GlUniform3iv( int32_t location, int32_t count, const int32_t * value );

	// void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2)
	void GlUniform3ui( int32_t location, uint32_t v0, uint32_t v1, uint32_t v2 );

	// void glUniform3uiv(GLint location, GLsizei count, GLuint value)
	void GlUniform3uiv( int32_t location, int32_t count, const uint32_t * value );

	// void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
	void GlUniform4f( int32_t location, float v0, float v1, float v2, float v3 );

	// void glUniform4fv(GLint location, GLsizei count, GLfloat value)
	void GlUniform4fv( int32_t location, int32_t count, const float * value );

	// void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
	void GlUniform4i( int32_t location, int32_t v0, int32_t v1, int32_t v2, int32_t v3 );

	// void glUniform4iv(GLint location, GLsizei count, GLint value)
	void GlUniform4iv( int32_t location, int32_t count, const int32_t * value );

	// void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3)
	void GlUniform4ui( int32_t location, uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3 );

	// void glUniform4uiv(GLint location, GLsizei count, GLuint value)
	void GlUniform4uiv( int32_t location, int32_t count, const uint32_t * value );

	// void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding)
	void GlUniformBlockBinding( Black::GlProgram program, uint32_t uniform_block_index, uint32_t uniform_block_binding );

	// void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix2fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix2x3fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix2x4fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix3fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix3x2fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix3x4fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix4fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix4x2fv( int32_t location, int32_t count, bool transpose, const float * value );

	// void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value)
	void GlUniformMatrix4x3fv( int32_t location, int32_t count, bool transpose, const float * value );

	// GLboolean glUnmapBuffer(GLenum target)
	bool GlUnmapBuffer( BufferTargetARB target );

	// void glUseProgram(GLuint program)
	void GlUseProgram( Black::GlProgram program );

	// void glValidateProgram(GLuint program)
	void GlValidateProgram( Black::GlProgram program );

	// void glVertexAttrib1f(GLuint index, GLfloat x)
	void GlVertexAttrib1f( uint32_t index, float x );

	// void glVertexAttrib1fv(GLuint index, GLfloat v)
	void GlVertexAttrib1fv( uint32_t index, const float * v );

	// void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y)
	void GlVertexAttrib2f( uint32_t index, float x, float y );

	// void glVertexAttrib2fv(GLuint index, GLfloat v)
	void GlVertexAttrib2fv( uint32_t index, const float * v );

	// void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z)
	void GlVertexAttrib3f( uint32_t index, float x, float y, float z );

	// void glVertexAttrib3fv(GLuint index, GLfloat v)
	void GlVertexAttrib3fv( uint32_t index, const float * v );

	// void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
	void GlVertexAttrib4f( uint32_t index, float x, float y, float z, float w );

	// void glVertexAttrib4fv(GLuint index, GLfloat v)
	void GlVertexAttrib4fv( uint32_t index, const float * v );

	// void glVertexAttribDivisor(GLuint index, GLuint divisor)
	void GlVertexAttribDivisor( uint32_t index, uint32_t divisor );

	// void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w)
	void GlVertexAttribI4i( uint32_t index, int32_t x, int32_t y, int32_t z, int32_t w );

	// void glVertexAttribI4iv(GLuint index, GLint v)
	void GlVertexAttribI4iv( uint32_t index, const int32_t * v );

	// void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w)
	void GlVertexAttribI4ui( uint32_t index, uint32_t x, uint32_t y, uint32_t z, uint32_t w );

	// void glVertexAttribI4uiv(GLuint index, GLuint v)
	void GlVertexAttribI4uiv( uint32_t index, const uint32_t * v );

	// void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer)
	void GlVertexAttribIPointer( uint32_t index, int32_t size, VertexAttribIType type, int32_t stride, const void * pointer );

	// void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer)
	void GlVertexAttribPointer( uint32_t index, int32_t size, VertexAttribPointerType type, bool normalized, int32_t stride, const void * pointer );

	// void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
	void GlViewport( int32_t x, int32_t y, int32_t width, int32_t height );

	// void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout)
	void GlWaitSync( Black::GlSyncHandle sync, SyncBehaviorFlags flags, uint64_t timeout );

}
}
}
