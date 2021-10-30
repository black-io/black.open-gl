#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Global
{
inline namespace Types
{
	/**
		@brief	ID of regular OpenGL buffer object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify the VBO, VAO, UBO and other buffer objects.
	*/
	enum class GlBuffer : uint32_t;

	/**
		@brief	ID of regular OpenGL texture object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only texture objects.
	*/
	enum class GlTexture : uint32_t;

	/**
		@brief	ID of regular OpenGL shader object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only shader objects.
	*/
	enum class GlShader : uint32_t;

	/**
		@brief	ID of regular OpenGL program object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only program objects.
	*/
	enum class GlProgram : uint32_t;

	/**
		@brief	ID of regular OpenGL query object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only query objects.
	*/
	enum class GlQuery : uint32_t;

	/**
		@brief	ID of regular OpenGL frame buffer object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only frame buffer objects.
	*/
	enum class GlFrameBuffer : uint32_t;

	/**
		@brief	ID of regular OpenGL render buffer object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only render buffer objects.
	*/
	enum class GlRenderBuffer : uint32_t;

	/**
		@brief	ID of regular OpenGL sampler object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only sampler objects.
	*/
	enum class GlSampler : uint32_t;

	/**
		@brief	ID of regular OpenGL transform feedback object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only transform feedback objects.
	*/
	enum class GlTransformFeedback : uint32_t;

	/**
		@brief	ID of regular OpenGL pipeline object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only pipeline objects.
	*/
	enum class GlPipeline : uint32_t;

	/**
		@brief	ID of regular OpenGL display list object.
		Original type is `GLuint`. Aliased type is `uint32_t`.

		Ids of this type used to identify only display list objects.
	*/
	enum class GlDisplayList : uint32_t;

	/**
		@brief	ID of regular OpenGL display synchronization object handle.
		Original type is `GLsync`. Aliased type is `void*` since the originally mapped type is `struct __GLsync *`.

		Ids of this type used to identify only display list objects.
	*/
	using GlSyncHandle = void*;
}
}
}
}
