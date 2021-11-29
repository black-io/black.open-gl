#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace GlEs30
{
	// GL_BLEND_EQUATION
	inline constexpr int32_t BLEND_EQUATION = 0x8009;

	// GL_FRAMEBUFFER_DEFAULT
	inline constexpr int32_t FRAMEBUFFER_DEFAULT = 0x8218;

	// GL_TEXTURE_IMMUTABLE_LEVELS
	inline constexpr int32_t TEXTURE_IMMUTABLE_LEVELS = 0x82DF;

	// GL_UNSIGNED_SHORT_5_6_5
	inline constexpr int32_t UNSIGNED_SHORT_5_6_5 = 0x8363;

	// GL_UNSIGNED_INT_24_8
	inline constexpr int32_t UNSIGNED_INT_24_8 = 0x84FA;

	// GL_DRAW_BUFFER0
	inline constexpr int32_t DRAW_BUFFER0 = 0x8825;

	// GL_DRAW_BUFFER1
	inline constexpr int32_t DRAW_BUFFER1 = 0x8826;

	// GL_DRAW_BUFFER2
	inline constexpr int32_t DRAW_BUFFER2 = 0x8827;

	// GL_DRAW_BUFFER3
	inline constexpr int32_t DRAW_BUFFER3 = 0x8828;

	// GL_DRAW_BUFFER4
	inline constexpr int32_t DRAW_BUFFER4 = 0x8829;

	// GL_DRAW_BUFFER5
	inline constexpr int32_t DRAW_BUFFER5 = 0x882A;

	// GL_DRAW_BUFFER6
	inline constexpr int32_t DRAW_BUFFER6 = 0x882B;

	// GL_DRAW_BUFFER7
	inline constexpr int32_t DRAW_BUFFER7 = 0x882C;

	// GL_DRAW_BUFFER8
	inline constexpr int32_t DRAW_BUFFER8 = 0x882D;

	// GL_DRAW_BUFFER9
	inline constexpr int32_t DRAW_BUFFER9 = 0x882E;

	// GL_DRAW_BUFFER10
	inline constexpr int32_t DRAW_BUFFER10 = 0x882F;

	// GL_DRAW_BUFFER11
	inline constexpr int32_t DRAW_BUFFER11 = 0x8830;

	// GL_DRAW_BUFFER12
	inline constexpr int32_t DRAW_BUFFER12 = 0x8831;

	// GL_DRAW_BUFFER13
	inline constexpr int32_t DRAW_BUFFER13 = 0x8832;

	// GL_DRAW_BUFFER14
	inline constexpr int32_t DRAW_BUFFER14 = 0x8833;

	// GL_DRAW_BUFFER15
	inline constexpr int32_t DRAW_BUFFER15 = 0x8834;

	// GL_UNSIGNED_NORMALIZED
	inline constexpr int32_t UNSIGNED_NORMALIZED = 0x8C17;

	// GL_UNSIGNED_INT_5_9_9_9_REV
	inline constexpr int32_t UNSIGNED_INT_5_9_9_9_REV = 0x8C3E;

	// GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	inline constexpr int32_t MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80;

	// GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	inline constexpr int32_t MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A;

	// GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	inline constexpr int32_t MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B;

	// GL_FRAMEBUFFER_BINDING
	inline constexpr int32_t FRAMEBUFFER_BINDING = 0x8CA6;

	// GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS
	inline constexpr int32_t FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9;

	// GL_MAX_COLOR_ATTACHMENTS
	inline constexpr int32_t MAX_COLOR_ATTACHMENTS = 0x8CDF;

	// GL_MAX_SAMPLES
	inline constexpr int32_t MAX_SAMPLES = 0x8D57;

	// GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	inline constexpr int32_t FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD;

	// GL_TRANSFORM_FEEDBACK_BINDING
	inline constexpr int32_t TRANSFORM_FEEDBACK_BINDING = 0x8E25;

	// GL_COPY_READ_BUFFER_BINDING
	inline constexpr int32_t COPY_READ_BUFFER_BINDING = 0x8F36;

	// GL_COPY_WRITE_BUFFER_BINDING
	inline constexpr int32_t COPY_WRITE_BUFFER_BINDING = 0x8F37;

	// GL_SIGNED_NORMALIZED
	inline constexpr int32_t SIGNED_NORMALIZED = 0x8F9C;

	// GL_SYNC_FENCE
	inline constexpr int32_t SYNC_FENCE = 0x9116;

	// GL_UNSIGNALED
	inline constexpr int32_t UNSIGNALED = 0x9118;

	// GL_SIGNALED
	inline constexpr int32_t SIGNALED = 0x9119;

	// GL_TEXTURE_IMMUTABLE_FORMAT
	inline constexpr int32_t TEXTURE_IMMUTABLE_FORMAT = 0x912F;

	// AlphaFunction; bitmask: False.
	enum class AlphaFunction : uint32_t
	{
		Never = 0x0200, // GL_NEVER.
		Less = 0x0201, // GL_LESS.
		Equal = 0x0202, // GL_EQUAL.
		Lequal = 0x0203, // GL_LEQUAL.
		Greater = 0x0204, // GL_GREATER.
		Notequal = 0x0205, // GL_NOTEQUAL.
		Gequal = 0x0206, // GL_GEQUAL.
		Always = 0x0207, // GL_ALWAYS.
	};

	// AttribMask; bitmask: True.
	enum class Attrib : uint32_t
	{
		DepthBuffer = 0x00000100, // GL_DEPTH_BUFFER_BIT.
		StencilBuffer = 0x00000400, // GL_STENCIL_BUFFER_BIT.
		ColorBuffer = 0x00004000, // GL_COLOR_BUFFER_BIT.
	};

	// AttributeType; bitmask: False.
	enum class AttributeType : uint32_t
	{
		FloatVec2 = 0x8B50, // GL_FLOAT_VEC2.
		FloatVec3 = 0x8B51, // GL_FLOAT_VEC3.
		FloatVec4 = 0x8B52, // GL_FLOAT_VEC4.
		IntVec2 = 0x8B53, // GL_INT_VEC2.
		IntVec3 = 0x8B54, // GL_INT_VEC3.
		IntVec4 = 0x8B55, // GL_INT_VEC4.
		Bool = 0x8B56, // GL_BOOL.
		BoolVec2 = 0x8B57, // GL_BOOL_VEC2.
		BoolVec3 = 0x8B58, // GL_BOOL_VEC3.
		BoolVec4 = 0x8B59, // GL_BOOL_VEC4.
		FloatMat2 = 0x8B5A, // GL_FLOAT_MAT2.
		FloatMat3 = 0x8B5B, // GL_FLOAT_MAT3.
		FloatMat4 = 0x8B5C, // GL_FLOAT_MAT4.
		Sampler2d = 0x8B5E, // GL_SAMPLER_2D.
		Sampler3d = 0x8B5F, // GL_SAMPLER_3D.
		SamplerCube = 0x8B60, // GL_SAMPLER_CUBE.
		Sampler2dShadow = 0x8B62, // GL_SAMPLER_2D_SHADOW.
		FloatMat2x3 = 0x8B65, // GL_FLOAT_MAT2x3.
		FloatMat2x4 = 0x8B66, // GL_FLOAT_MAT2x4.
		FloatMat3x2 = 0x8B67, // GL_FLOAT_MAT3x2.
		FloatMat3x4 = 0x8B68, // GL_FLOAT_MAT3x4.
		FloatMat4x2 = 0x8B69, // GL_FLOAT_MAT4x2.
		FloatMat4x3 = 0x8B6A, // GL_FLOAT_MAT4x3.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
		Int64 = 0x140E, // GL_INT64_NV.
		UnsignedInt64 = 0x140F, // GL_UNSIGNED_INT64_NV.
		Sampler2dArrayShadow = 0x8DC4, // GL_SAMPLER_2D_ARRAY_SHADOW.
		SamplerCubeShadow = 0x8DC5, // GL_SAMPLER_CUBE_SHADOW.
		UnsignedIntVec2 = 0x8DC6, // GL_UNSIGNED_INT_VEC2.
		UnsignedIntVec3 = 0x8DC7, // GL_UNSIGNED_INT_VEC3.
		UnsignedIntVec4 = 0x8DC8, // GL_UNSIGNED_INT_VEC4.
		IntSampler2d = 0x8DCA, // GL_INT_SAMPLER_2D.
		IntSampler3d = 0x8DCB, // GL_INT_SAMPLER_3D.
		IntSamplerCube = 0x8DCC, // GL_INT_SAMPLER_CUBE.
		IntSampler2dArray = 0x8DCF, // GL_INT_SAMPLER_2D_ARRAY.
		UnsignedIntSampler2d = 0x8DD2, // GL_UNSIGNED_INT_SAMPLER_2D.
		UnsignedIntSampler3d = 0x8DD3, // GL_UNSIGNED_INT_SAMPLER_3D.
		UnsignedIntSamplerCube = 0x8DD4, // GL_UNSIGNED_INT_SAMPLER_CUBE.
		UnsignedIntSampler2dArray = 0x8DD7, // GL_UNSIGNED_INT_SAMPLER_2D_ARRAY.
	};

	// BindTransformFeedbackTarget; bitmask: False.
	enum class BindTransformFeedbackTarget : uint32_t
	{
		TransformFeedback = 0x8E22, // GL_TRANSFORM_FEEDBACK.
	};

	// BinormalPointerTypeEXT; bitmask: False.
	enum class BinormalPointerTypeEXT : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// BlendEquationModeEXT; bitmask: False.
	enum class BlendEquationModeEXT : uint32_t
	{
		FuncAdd = 0x8006, // GL_FUNC_ADD.
		Min = 0x8007, // GL_MIN.
		Max = 0x8008, // GL_MAX.
		FuncSubtract = 0x800A, // GL_FUNC_SUBTRACT.
		FuncReverseSubtract = 0x800B, // GL_FUNC_REVERSE_SUBTRACT.
	};

	// BlendingFactor; bitmask: False.
	enum class BlendingFactor : uint32_t
	{
		Zero = 0, // GL_ZERO.
		One = 1, // GL_ONE.
		SrcColor = 0x0300, // GL_SRC_COLOR.
		OneMinusSrcColor = 0x0301, // GL_ONE_MINUS_SRC_COLOR.
		SrcAlpha = 0x0302, // GL_SRC_ALPHA.
		OneMinusSrcAlpha = 0x0303, // GL_ONE_MINUS_SRC_ALPHA.
		DstAlpha = 0x0304, // GL_DST_ALPHA.
		OneMinusDstAlpha = 0x0305, // GL_ONE_MINUS_DST_ALPHA.
		DstColor = 0x0306, // GL_DST_COLOR.
		OneMinusDstColor = 0x0307, // GL_ONE_MINUS_DST_COLOR.
		SrcAlphaSaturate = 0x0308, // GL_SRC_ALPHA_SATURATE.
		ConstantColor = 0x8001, // GL_CONSTANT_COLOR.
		OneMinusConstantColor = 0x8002, // GL_ONE_MINUS_CONSTANT_COLOR.
		ConstantAlpha = 0x8003, // GL_CONSTANT_ALPHA.
		OneMinusConstantAlpha = 0x8004, // GL_ONE_MINUS_CONSTANT_ALPHA.
	};

	// BlitFramebufferFilter; bitmask: False.
	enum class BlitFramebufferFilter : uint32_t
	{
		Nearest = 0x2600, // GL_NEAREST.
		Linear = 0x2601, // GL_LINEAR.
	};

	// Boolean; bitmask: False.
	enum class Boolean : uint32_t
	{
		False = 0, // GL_FALSE.
		True = 1, // GL_TRUE.
	};

	// Buffer; bitmask: False.
	enum class Buffer : uint32_t
	{
		Color = 0x1800, // GL_COLOR.
		Depth = 0x1801, // GL_DEPTH.
		Stencil = 0x1802, // GL_STENCIL.
	};

	// BufferPNameARB; bitmask: False.
	enum class BufferPNameARB : uint32_t
	{
		BufferSize = 0x8764, // GL_BUFFER_SIZE.
		BufferUsage = 0x8765, // GL_BUFFER_USAGE.
		BufferMapped = 0x88BC, // GL_BUFFER_MAPPED.
		BufferAccessFlags = 0x911F, // GL_BUFFER_ACCESS_FLAGS.
		BufferMapLength = 0x9120, // GL_BUFFER_MAP_LENGTH.
		BufferMapOffset = 0x9121, // GL_BUFFER_MAP_OFFSET.
	};

	// BufferPointerNameARB; bitmask: False.
	enum class BufferPointerNameARB : uint32_t
	{
		BufferMapPointer = 0x88BD, // GL_BUFFER_MAP_POINTER.
	};

	// BufferStorageMask; bitmask: True.
	enum class BufferStorage : uint32_t
	{
		DynamicStorage = 0x0100, // GL_DYNAMIC_STORAGE_BIT_EXT.
		MapRead = 0x0001, // GL_MAP_READ_BIT.
		MapWrite = 0x0002, // GL_MAP_WRITE_BIT.
		MapPersistent = 0x0040, // GL_MAP_PERSISTENT_BIT_EXT.
		MapCoherent = 0x0080, // GL_MAP_COHERENT_BIT_EXT.
	};

	// BufferStorageTarget; bitmask: False.
	enum class BufferStorageTarget : uint32_t
	{
		ArrayBuffer = 0x8892, // GL_ARRAY_BUFFER.
		ElementArrayBuffer = 0x8893, // GL_ELEMENT_ARRAY_BUFFER.
		PixelPackBuffer = 0x88EB, // GL_PIXEL_PACK_BUFFER.
		PixelUnpackBuffer = 0x88EC, // GL_PIXEL_UNPACK_BUFFER.
		UniformBuffer = 0x8A11, // GL_UNIFORM_BUFFER.
		TransformFeedbackBuffer = 0x8C8E, // GL_TRANSFORM_FEEDBACK_BUFFER.
		CopyReadBuffer = 0x8F36, // GL_COPY_READ_BUFFER.
		CopyWriteBuffer = 0x8F37, // GL_COPY_WRITE_BUFFER.
	};

	// BufferTargetARB; bitmask: False.
	enum class BufferTargetARB : uint32_t
	{
		ArrayBuffer = 0x8892, // GL_ARRAY_BUFFER.
		ElementArrayBuffer = 0x8893, // GL_ELEMENT_ARRAY_BUFFER.
		PixelPackBuffer = 0x88EB, // GL_PIXEL_PACK_BUFFER.
		PixelUnpackBuffer = 0x88EC, // GL_PIXEL_UNPACK_BUFFER.
		UniformBuffer = 0x8A11, // GL_UNIFORM_BUFFER.
		TransformFeedbackBuffer = 0x8C8E, // GL_TRANSFORM_FEEDBACK_BUFFER.
		CopyReadBuffer = 0x8F36, // GL_COPY_READ_BUFFER.
		CopyWriteBuffer = 0x8F37, // GL_COPY_WRITE_BUFFER.
	};

	// BufferUsageARB; bitmask: False.
	enum class BufferUsageARB : uint32_t
	{
		StreamDraw = 0x88E0, // GL_STREAM_DRAW.
		StreamRead = 0x88E1, // GL_STREAM_READ.
		StreamCopy = 0x88E2, // GL_STREAM_COPY.
		StaticDraw = 0x88E4, // GL_STATIC_DRAW.
		StaticRead = 0x88E5, // GL_STATIC_READ.
		StaticCopy = 0x88E6, // GL_STATIC_COPY.
		DynamicDraw = 0x88E8, // GL_DYNAMIC_DRAW.
		DynamicRead = 0x88E9, // GL_DYNAMIC_READ.
		DynamicCopy = 0x88EA, // GL_DYNAMIC_COPY.
	};

	// CheckFramebufferStatusTarget; bitmask: False.
	enum class CheckFramebufferStatusTarget : uint32_t
	{
		ReadFramebuffer = 0x8CA8, // GL_READ_FRAMEBUFFER.
		DrawFramebuffer = 0x8CA9, // GL_DRAW_FRAMEBUFFER.
		Framebuffer = 0x8D40, // GL_FRAMEBUFFER.
	};

	// ClampColorModeARB; bitmask: False.
	enum class ClampColorModeARB : uint32_t
	{
		False = 0, // GL_FALSE.
		True = 1, // GL_TRUE.
	};

	// ClearBufferMask; bitmask: True.
	enum class ClearBuffer : uint32_t
	{
		CoverageBuffer = 0x00008000, // GL_COVERAGE_BUFFER_BIT_NV.
		DepthBuffer = 0x00000100, // GL_DEPTH_BUFFER_BIT.
		StencilBuffer = 0x00000400, // GL_STENCIL_BUFFER_BIT.
		ColorBuffer = 0x00004000, // GL_COLOR_BUFFER_BIT.
	};

	// ColorBuffer; bitmask: False.
	enum class ColorBuffer : uint32_t
	{
		None = 0, // GL_NONE.
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		FrontAndBack = 0x0408, // GL_FRONT_AND_BACK.
		ColorAttachment0 = 0x8CE0, // GL_COLOR_ATTACHMENT0.
		ColorAttachment1 = 0x8CE1, // GL_COLOR_ATTACHMENT1.
		ColorAttachment2 = 0x8CE2, // GL_COLOR_ATTACHMENT2.
		ColorAttachment3 = 0x8CE3, // GL_COLOR_ATTACHMENT3.
		ColorAttachment4 = 0x8CE4, // GL_COLOR_ATTACHMENT4.
		ColorAttachment5 = 0x8CE5, // GL_COLOR_ATTACHMENT5.
		ColorAttachment6 = 0x8CE6, // GL_COLOR_ATTACHMENT6.
		ColorAttachment7 = 0x8CE7, // GL_COLOR_ATTACHMENT7.
		ColorAttachment8 = 0x8CE8, // GL_COLOR_ATTACHMENT8.
		ColorAttachment9 = 0x8CE9, // GL_COLOR_ATTACHMENT9.
		ColorAttachment10 = 0x8CEA, // GL_COLOR_ATTACHMENT10.
		ColorAttachment11 = 0x8CEB, // GL_COLOR_ATTACHMENT11.
		ColorAttachment12 = 0x8CEC, // GL_COLOR_ATTACHMENT12.
		ColorAttachment13 = 0x8CED, // GL_COLOR_ATTACHMENT13.
		ColorAttachment14 = 0x8CEE, // GL_COLOR_ATTACHMENT14.
		ColorAttachment15 = 0x8CEF, // GL_COLOR_ATTACHMENT15.
		ColorAttachment16 = 0x8CF0, // GL_COLOR_ATTACHMENT16.
		ColorAttachment17 = 0x8CF1, // GL_COLOR_ATTACHMENT17.
		ColorAttachment18 = 0x8CF2, // GL_COLOR_ATTACHMENT18.
		ColorAttachment19 = 0x8CF3, // GL_COLOR_ATTACHMENT19.
		ColorAttachment20 = 0x8CF4, // GL_COLOR_ATTACHMENT20.
		ColorAttachment21 = 0x8CF5, // GL_COLOR_ATTACHMENT21.
		ColorAttachment22 = 0x8CF6, // GL_COLOR_ATTACHMENT22.
		ColorAttachment23 = 0x8CF7, // GL_COLOR_ATTACHMENT23.
		ColorAttachment24 = 0x8CF8, // GL_COLOR_ATTACHMENT24.
		ColorAttachment25 = 0x8CF9, // GL_COLOR_ATTACHMENT25.
		ColorAttachment26 = 0x8CFA, // GL_COLOR_ATTACHMENT26.
		ColorAttachment27 = 0x8CFB, // GL_COLOR_ATTACHMENT27.
		ColorAttachment28 = 0x8CFC, // GL_COLOR_ATTACHMENT28.
		ColorAttachment29 = 0x8CFD, // GL_COLOR_ATTACHMENT29.
		ColorAttachment30 = 0x8CFE, // GL_COLOR_ATTACHMENT30.
		ColorAttachment31 = 0x8CFF, // GL_COLOR_ATTACHMENT31.
	};

	// ColorMaterialFace; bitmask: False.
	enum class ColorMaterialFace : uint32_t
	{
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		FrontAndBack = 0x0408, // GL_FRONT_AND_BACK.
	};

	// ColorPointerType; bitmask: False.
	enum class ColorPointerType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// CombinerBiasNV; bitmask: False.
	enum class CombinerBiasNV : uint32_t
	{
		None = 0, // GL_NONE.
	};

	// CombinerComponentUsageNV; bitmask: False.
	enum class CombinerComponentUsageNV : uint32_t
	{
		Blue = 0x1905, // GL_BLUE.
		Alpha = 0x1906, // GL_ALPHA.
		Rgb = 0x1907, // GL_RGB.
	};

	// CombinerPortionNV; bitmask: False.
	enum class CombinerPortionNV : uint32_t
	{
		Alpha = 0x1906, // GL_ALPHA.
		Rgb = 0x1907, // GL_RGB.
	};

	// CombinerScaleNV; bitmask: False.
	enum class CombinerScaleNV : uint32_t
	{
		None = 0, // GL_NONE.
	};

	// CopyBufferSubDataTarget; bitmask: False.
	enum class CopyBufferSubDataTarget : uint32_t
	{
		ArrayBuffer = 0x8892, // GL_ARRAY_BUFFER.
		ElementArrayBuffer = 0x8893, // GL_ELEMENT_ARRAY_BUFFER.
		PixelPackBuffer = 0x88EB, // GL_PIXEL_PACK_BUFFER.
		PixelUnpackBuffer = 0x88EC, // GL_PIXEL_UNPACK_BUFFER.
		UniformBuffer = 0x8A11, // GL_UNIFORM_BUFFER.
		TransformFeedbackBuffer = 0x8C8E, // GL_TRANSFORM_FEEDBACK_BUFFER.
		CopyReadBuffer = 0x8F36, // GL_COPY_READ_BUFFER.
		CopyWriteBuffer = 0x8F37, // GL_COPY_WRITE_BUFFER.
	};

	// CopyImageSubDataTarget; bitmask: False.
	enum class CopyImageSubDataTarget : uint32_t
	{
		Texture2d = 0x0DE1, // GL_TEXTURE_2D.
		Texture3d = 0x806F, // GL_TEXTURE_3D.
		TextureCubeMap = 0x8513, // GL_TEXTURE_CUBE_MAP.
		Texture2dArray = 0x8C1A, // GL_TEXTURE_2D_ARRAY.
		Renderbuffer = 0x8D41, // GL_RENDERBUFFER.
		Texture2dMultisample = 0x9100, // GL_TEXTURE_2D_MULTISAMPLE.
		Texture2dMultisampleArray = 0x9102, // GL_TEXTURE_2D_MULTISAMPLE_ARRAY.
	};

	// CullFaceMode; bitmask: False.
	enum class CullFaceMode : uint32_t
	{
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		FrontAndBack = 0x0408, // GL_FRONT_AND_BACK.
	};

	// DebugSeverity; bitmask: False.
	enum class DebugSeverity : uint32_t
	{
		DontCare = 0x1100, // GL_DONT_CARE.
		DebugSeverityNotification = 0x826B, // GL_DEBUG_SEVERITY_NOTIFICATION.
		DebugSeverityHigh = 0x9146, // GL_DEBUG_SEVERITY_HIGH.
		DebugSeverityMedium = 0x9147, // GL_DEBUG_SEVERITY_MEDIUM.
		DebugSeverityLow = 0x9148, // GL_DEBUG_SEVERITY_LOW.
	};

	// DebugSource; bitmask: False.
	enum class DebugSource : uint32_t
	{
		DontCare = 0x1100, // GL_DONT_CARE.
		DebugSourceApi = 0x8246, // GL_DEBUG_SOURCE_API.
		DebugSourceWindowSystem = 0x8247, // GL_DEBUG_SOURCE_WINDOW_SYSTEM.
		DebugSourceShaderCompiler = 0x8248, // GL_DEBUG_SOURCE_SHADER_COMPILER.
		DebugSourceThirdParty = 0x8249, // GL_DEBUG_SOURCE_THIRD_PARTY.
		DebugSourceApplication = 0x824A, // GL_DEBUG_SOURCE_APPLICATION.
		DebugSourceOther = 0x824B, // GL_DEBUG_SOURCE_OTHER.
	};

	// DebugType; bitmask: False.
	enum class DebugType : uint32_t
	{
		DontCare = 0x1100, // GL_DONT_CARE.
		DebugTypeError = 0x824C, // GL_DEBUG_TYPE_ERROR.
		DebugTypeDeprecatedBehavior = 0x824D, // GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR.
		DebugTypeUndefinedBehavior = 0x824E, // GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR.
		DebugTypePortability = 0x824F, // GL_DEBUG_TYPE_PORTABILITY.
		DebugTypePerformance = 0x8250, // GL_DEBUG_TYPE_PERFORMANCE.
		DebugTypeOther = 0x8251, // GL_DEBUG_TYPE_OTHER.
		DebugTypeMarker = 0x8268, // GL_DEBUG_TYPE_MARKER.
		DebugTypePushGroup = 0x8269, // GL_DEBUG_TYPE_PUSH_GROUP.
		DebugTypePopGroup = 0x826A, // GL_DEBUG_TYPE_POP_GROUP.
	};

	// DepthFunction; bitmask: False.
	enum class DepthFunction : uint32_t
	{
		Never = 0x0200, // GL_NEVER.
		Less = 0x0201, // GL_LESS.
		Equal = 0x0202, // GL_EQUAL.
		Lequal = 0x0203, // GL_LEQUAL.
		Greater = 0x0204, // GL_GREATER.
		Notequal = 0x0205, // GL_NOTEQUAL.
		Gequal = 0x0206, // GL_GEQUAL.
		Always = 0x0207, // GL_ALWAYS.
	};

	// DrawBufferMode; bitmask: False.
	enum class DrawBufferMode : uint32_t
	{
		None = 0, // GL_NONE.
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		FrontAndBack = 0x0408, // GL_FRONT_AND_BACK.
		ColorAttachment0 = 0x8CE0, // GL_COLOR_ATTACHMENT0.
		ColorAttachment1 = 0x8CE1, // GL_COLOR_ATTACHMENT1.
		ColorAttachment2 = 0x8CE2, // GL_COLOR_ATTACHMENT2.
		ColorAttachment3 = 0x8CE3, // GL_COLOR_ATTACHMENT3.
		ColorAttachment4 = 0x8CE4, // GL_COLOR_ATTACHMENT4.
		ColorAttachment5 = 0x8CE5, // GL_COLOR_ATTACHMENT5.
		ColorAttachment6 = 0x8CE6, // GL_COLOR_ATTACHMENT6.
		ColorAttachment7 = 0x8CE7, // GL_COLOR_ATTACHMENT7.
		ColorAttachment8 = 0x8CE8, // GL_COLOR_ATTACHMENT8.
		ColorAttachment9 = 0x8CE9, // GL_COLOR_ATTACHMENT9.
		ColorAttachment10 = 0x8CEA, // GL_COLOR_ATTACHMENT10.
		ColorAttachment11 = 0x8CEB, // GL_COLOR_ATTACHMENT11.
		ColorAttachment12 = 0x8CEC, // GL_COLOR_ATTACHMENT12.
		ColorAttachment13 = 0x8CED, // GL_COLOR_ATTACHMENT13.
		ColorAttachment14 = 0x8CEE, // GL_COLOR_ATTACHMENT14.
		ColorAttachment15 = 0x8CEF, // GL_COLOR_ATTACHMENT15.
		ColorAttachment16 = 0x8CF0, // GL_COLOR_ATTACHMENT16.
		ColorAttachment17 = 0x8CF1, // GL_COLOR_ATTACHMENT17.
		ColorAttachment18 = 0x8CF2, // GL_COLOR_ATTACHMENT18.
		ColorAttachment19 = 0x8CF3, // GL_COLOR_ATTACHMENT19.
		ColorAttachment20 = 0x8CF4, // GL_COLOR_ATTACHMENT20.
		ColorAttachment21 = 0x8CF5, // GL_COLOR_ATTACHMENT21.
		ColorAttachment22 = 0x8CF6, // GL_COLOR_ATTACHMENT22.
		ColorAttachment23 = 0x8CF7, // GL_COLOR_ATTACHMENT23.
		ColorAttachment24 = 0x8CF8, // GL_COLOR_ATTACHMENT24.
		ColorAttachment25 = 0x8CF9, // GL_COLOR_ATTACHMENT25.
		ColorAttachment26 = 0x8CFA, // GL_COLOR_ATTACHMENT26.
		ColorAttachment27 = 0x8CFB, // GL_COLOR_ATTACHMENT27.
		ColorAttachment28 = 0x8CFC, // GL_COLOR_ATTACHMENT28.
		ColorAttachment29 = 0x8CFD, // GL_COLOR_ATTACHMENT29.
		ColorAttachment30 = 0x8CFE, // GL_COLOR_ATTACHMENT30.
		ColorAttachment31 = 0x8CFF, // GL_COLOR_ATTACHMENT31.
	};

	// DrawElementsType; bitmask: False.
	enum class DrawElementsType : uint32_t
	{
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// ElementPointerTypeATI; bitmask: False.
	enum class ElementPointerTypeATI : uint32_t
	{
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// EnableCap; bitmask: False.
	enum class EnableCap : uint32_t
	{
		CullFace = 0x0B44, // GL_CULL_FACE.
		DepthTest = 0x0B71, // GL_DEPTH_TEST.
		StencilTest = 0x0B90, // GL_STENCIL_TEST.
		Dither = 0x0BD0, // GL_DITHER.
		Blend = 0x0BE2, // GL_BLEND.
		ScissorTest = 0x0C11, // GL_SCISSOR_TEST.
		Texture2d = 0x0DE1, // GL_TEXTURE_2D.
		PolygonOffsetFill = 0x8037, // GL_POLYGON_OFFSET_FILL.
		VertexArray = 0x8074, // GL_VERTEX_ARRAY.
		SampleAlphaToCoverage = 0x809E, // GL_SAMPLE_ALPHA_TO_COVERAGE.
		SampleCoverage = 0x80A0, // GL_SAMPLE_COVERAGE.
		DebugOutputSynchronous = 0x8242, // GL_DEBUG_OUTPUT_SYNCHRONOUS.
		RasterizerDiscard = 0x8C89, // GL_RASTERIZER_DISCARD.
		PrimitiveRestartFixedIndex = 0x8D69, // GL_PRIMITIVE_RESTART_FIXED_INDEX.
		FetchPerSampleArm = 0x8F65, // GL_FETCH_PER_SAMPLE_ARM.
		DebugOutput = 0x92E0, // GL_DEBUG_OUTPUT.
		ShadingRateImagePerPrimitive = 0x95B1, // GL_SHADING_RATE_IMAGE_PER_PRIMITIVE_NV.
		ShadingRatePreserveAspectRatio = 0x96A5, // GL_SHADING_RATE_PRESERVE_ASPECT_RATIO_QCOM.
	};

	// ErrorCode; bitmask: False.
	enum class ErrorCode : uint32_t
	{
		NoError = 0, // GL_NO_ERROR.
		InvalidEnum = 0x0500, // GL_INVALID_ENUM.
		InvalidValue = 0x0501, // GL_INVALID_VALUE.
		InvalidOperation = 0x0502, // GL_INVALID_OPERATION.
		StackOverflow = 0x0503, // GL_STACK_OVERFLOW.
		StackUnderflow = 0x0504, // GL_STACK_UNDERFLOW.
		OutOfMemory = 0x0505, // GL_OUT_OF_MEMORY.
		InvalidFramebufferOperation = 0x0506, // GL_INVALID_FRAMEBUFFER_OPERATION.
	};

	// FogCoordinatePointerType; bitmask: False.
	enum class FogCoordinatePointerType : uint32_t
	{
		Float = 0x1406, // GL_FLOAT.
	};

	// FogMode; bitmask: False.
	enum class FogMode : uint32_t
	{
		Linear = 0x2601, // GL_LINEAR.
	};

	// FogPointerTypeEXT; bitmask: False.
	enum class FogPointerTypeEXT : uint32_t
	{
		Float = 0x1406, // GL_FLOAT.
	};

	// FogPointerTypeIBM; bitmask: False.
	enum class FogPointerTypeIBM : uint32_t
	{
		Float = 0x1406, // GL_FLOAT.
	};

	// FramebufferAttachment; bitmask: False.
	enum class FramebufferAttachment : uint32_t
	{
		ColorAttachment0 = 0x8CE0, // GL_COLOR_ATTACHMENT0.
		ColorAttachment1 = 0x8CE1, // GL_COLOR_ATTACHMENT1.
		ColorAttachment2 = 0x8CE2, // GL_COLOR_ATTACHMENT2.
		ColorAttachment3 = 0x8CE3, // GL_COLOR_ATTACHMENT3.
		ColorAttachment4 = 0x8CE4, // GL_COLOR_ATTACHMENT4.
		ColorAttachment5 = 0x8CE5, // GL_COLOR_ATTACHMENT5.
		ColorAttachment6 = 0x8CE6, // GL_COLOR_ATTACHMENT6.
		ColorAttachment7 = 0x8CE7, // GL_COLOR_ATTACHMENT7.
		ColorAttachment8 = 0x8CE8, // GL_COLOR_ATTACHMENT8.
		ColorAttachment9 = 0x8CE9, // GL_COLOR_ATTACHMENT9.
		ColorAttachment10 = 0x8CEA, // GL_COLOR_ATTACHMENT10.
		ColorAttachment11 = 0x8CEB, // GL_COLOR_ATTACHMENT11.
		ColorAttachment12 = 0x8CEC, // GL_COLOR_ATTACHMENT12.
		ColorAttachment13 = 0x8CED, // GL_COLOR_ATTACHMENT13.
		ColorAttachment14 = 0x8CEE, // GL_COLOR_ATTACHMENT14.
		ColorAttachment15 = 0x8CEF, // GL_COLOR_ATTACHMENT15.
		ColorAttachment16 = 0x8CF0, // GL_COLOR_ATTACHMENT16.
		ColorAttachment17 = 0x8CF1, // GL_COLOR_ATTACHMENT17.
		ColorAttachment18 = 0x8CF2, // GL_COLOR_ATTACHMENT18.
		ColorAttachment19 = 0x8CF3, // GL_COLOR_ATTACHMENT19.
		ColorAttachment20 = 0x8CF4, // GL_COLOR_ATTACHMENT20.
		ColorAttachment21 = 0x8CF5, // GL_COLOR_ATTACHMENT21.
		ColorAttachment22 = 0x8CF6, // GL_COLOR_ATTACHMENT22.
		ColorAttachment23 = 0x8CF7, // GL_COLOR_ATTACHMENT23.
		ColorAttachment24 = 0x8CF8, // GL_COLOR_ATTACHMENT24.
		ColorAttachment25 = 0x8CF9, // GL_COLOR_ATTACHMENT25.
		ColorAttachment26 = 0x8CFA, // GL_COLOR_ATTACHMENT26.
		ColorAttachment27 = 0x8CFB, // GL_COLOR_ATTACHMENT27.
		ColorAttachment28 = 0x8CFC, // GL_COLOR_ATTACHMENT28.
		ColorAttachment29 = 0x8CFD, // GL_COLOR_ATTACHMENT29.
		ColorAttachment30 = 0x8CFE, // GL_COLOR_ATTACHMENT30.
		ColorAttachment31 = 0x8CFF, // GL_COLOR_ATTACHMENT31.
		DepthAttachment = 0x8D00, // GL_DEPTH_ATTACHMENT.
		StencilAttachment = 0x8D20, // GL_STENCIL_ATTACHMENT.
	};

	// FramebufferAttachmentParameterName; bitmask: False.
	enum class FramebufferAttachmentParameterName : uint32_t
	{
		FramebufferAttachmentColorEncoding = 0x8210, // GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING.
		FramebufferAttachmentComponentType = 0x8211, // GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE.
		FramebufferAttachmentRedSize = 0x8212, // GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE.
		FramebufferAttachmentGreenSize = 0x8213, // GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE.
		FramebufferAttachmentBlueSize = 0x8214, // GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE.
		FramebufferAttachmentAlphaSize = 0x8215, // GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE.
		FramebufferAttachmentDepthSize = 0x8216, // GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE.
		FramebufferAttachmentStencilSize = 0x8217, // GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE.
		FramebufferAttachmentObjectType = 0x8CD0, // GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE.
		FramebufferAttachmentObjectName = 0x8CD1, // GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME.
		FramebufferAttachmentTextureLevel = 0x8CD2, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL.
		FramebufferAttachmentTextureCubeMapFace = 0x8CD3, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE.
		FramebufferAttachmentTextureLayer = 0x8CD4, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER.
		FramebufferAttachmentTextureSamples = 0x8D6C, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_SAMPLES_EXT.
		FramebufferAttachmentLayered = 0x8DA7, // GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT.
		FramebufferAttachmentTextureScale = 0x913F, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_SCALE_IMG.
		FramebufferAttachmentTextureNumViewsOvr = 0x9630, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR.
		FramebufferAttachmentTextureBaseViewIndexOvr = 0x9632, // GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR.
	};

	// FramebufferStatus; bitmask: False.
	enum class FramebufferStatus : uint32_t
	{
		FramebufferUndefined = 0x8219, // GL_FRAMEBUFFER_UNDEFINED.
		FramebufferComplete = 0x8CD5, // GL_FRAMEBUFFER_COMPLETE.
		FramebufferIncompleteAttachment = 0x8CD6, // GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT.
		FramebufferIncompleteMissingAttachment = 0x8CD7, // GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT.
		FramebufferUnsupported = 0x8CDD, // GL_FRAMEBUFFER_UNSUPPORTED.
		FramebufferIncompleteMultisample = 0x8D56, // GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE.
	};

	// FramebufferTarget; bitmask: False.
	enum class FramebufferTarget : uint32_t
	{
		ReadFramebuffer = 0x8CA8, // GL_READ_FRAMEBUFFER.
		DrawFramebuffer = 0x8CA9, // GL_DRAW_FRAMEBUFFER.
		Framebuffer = 0x8D40, // GL_FRAMEBUFFER.
	};

	// FrontFaceDirection; bitmask: False.
	enum class FrontFaceDirection : uint32_t
	{
		Cw = 0x0900, // GL_CW.
		Ccw = 0x0901, // GL_CCW.
	};

	// GetFramebufferParameter; bitmask: False.
	enum class GetFramebufferParameter : uint32_t
	{
		SampleBuffers = 0x80A8, // GL_SAMPLE_BUFFERS.
		Samples = 0x80A9, // GL_SAMPLES.
		ImplementationColorReadType = 0x8B9A, // GL_IMPLEMENTATION_COLOR_READ_TYPE.
		ImplementationColorReadFormat = 0x8B9B, // GL_IMPLEMENTATION_COLOR_READ_FORMAT.
	};

	// GetPName; bitmask: False.
	enum class GetPName : uint32_t
	{
		LineWidth = 0x0B21, // GL_LINE_WIDTH.
		CullFace = 0x0B44, // GL_CULL_FACE.
		CullFaceMode = 0x0B45, // GL_CULL_FACE_MODE.
		FrontFace = 0x0B46, // GL_FRONT_FACE.
		DepthRange = 0x0B70, // GL_DEPTH_RANGE.
		DepthTest = 0x0B71, // GL_DEPTH_TEST.
		DepthWritemask = 0x0B72, // GL_DEPTH_WRITEMASK.
		DepthClearValue = 0x0B73, // GL_DEPTH_CLEAR_VALUE.
		DepthFunc = 0x0B74, // GL_DEPTH_FUNC.
		StencilTest = 0x0B90, // GL_STENCIL_TEST.
		StencilClearValue = 0x0B91, // GL_STENCIL_CLEAR_VALUE.
		StencilFunc = 0x0B92, // GL_STENCIL_FUNC.
		StencilValueMask = 0x0B93, // GL_STENCIL_VALUE_MASK.
		StencilFail = 0x0B94, // GL_STENCIL_FAIL.
		StencilPassDepthFail = 0x0B95, // GL_STENCIL_PASS_DEPTH_FAIL.
		StencilPassDepthPass = 0x0B96, // GL_STENCIL_PASS_DEPTH_PASS.
		StencilRef = 0x0B97, // GL_STENCIL_REF.
		StencilWritemask = 0x0B98, // GL_STENCIL_WRITEMASK.
		Viewport = 0x0BA2, // GL_VIEWPORT.
		AlphaTest = 0x0BC0, // GL_ALPHA_TEST_QCOM.
		AlphaTestFunc = 0x0BC1, // GL_ALPHA_TEST_FUNC_QCOM.
		AlphaTestRef = 0x0BC2, // GL_ALPHA_TEST_REF_QCOM.
		Dither = 0x0BD0, // GL_DITHER.
		Blend = 0x0BE2, // GL_BLEND.
		DrawBuffer = 0x0C01, // GL_DRAW_BUFFER_EXT.
		ReadBuffer = 0x0C02, // GL_READ_BUFFER.
		ScissorBox = 0x0C10, // GL_SCISSOR_BOX.
		ScissorTest = 0x0C11, // GL_SCISSOR_TEST.
		ColorClearValue = 0x0C22, // GL_COLOR_CLEAR_VALUE.
		ColorWritemask = 0x0C23, // GL_COLOR_WRITEMASK.
		UnpackRowLength = 0x0CF2, // GL_UNPACK_ROW_LENGTH.
		UnpackSkipRows = 0x0CF3, // GL_UNPACK_SKIP_ROWS.
		UnpackSkipPixels = 0x0CF4, // GL_UNPACK_SKIP_PIXELS.
		UnpackAlignment = 0x0CF5, // GL_UNPACK_ALIGNMENT.
		PackRowLength = 0x0D02, // GL_PACK_ROW_LENGTH.
		PackSkipRows = 0x0D03, // GL_PACK_SKIP_ROWS.
		PackSkipPixels = 0x0D04, // GL_PACK_SKIP_PIXELS.
		PackAlignment = 0x0D05, // GL_PACK_ALIGNMENT.
		MaxTextureSize = 0x0D33, // GL_MAX_TEXTURE_SIZE.
		MaxViewportDims = 0x0D3A, // GL_MAX_VIEWPORT_DIMS.
		SubpixelBits = 0x0D50, // GL_SUBPIXEL_BITS.
		RedBits = 0x0D52, // GL_RED_BITS.
		GreenBits = 0x0D53, // GL_GREEN_BITS.
		BlueBits = 0x0D54, // GL_BLUE_BITS.
		AlphaBits = 0x0D55, // GL_ALPHA_BITS.
		DepthBits = 0x0D56, // GL_DEPTH_BITS.
		StencilBits = 0x0D57, // GL_STENCIL_BITS.
		Texture2d = 0x0DE1, // GL_TEXTURE_2D.
		PolygonOffsetUnits = 0x2A00, // GL_POLYGON_OFFSET_UNITS.
		BlendColor = 0x8005, // GL_BLEND_COLOR.
		BlendEquationRgb = 0x8009, // GL_BLEND_EQUATION_RGB.
		PolygonOffsetFill = 0x8037, // GL_POLYGON_OFFSET_FILL.
		PolygonOffsetFactor = 0x8038, // GL_POLYGON_OFFSET_FACTOR.
		TextureBinding2d = 0x8069, // GL_TEXTURE_BINDING_2D.
		TextureBinding3d = 0x806A, // GL_TEXTURE_BINDING_3D.
		UnpackSkipImages = 0x806D, // GL_UNPACK_SKIP_IMAGES.
		UnpackImageHeight = 0x806E, // GL_UNPACK_IMAGE_HEIGHT.
		Max3dTextureSize = 0x8073, // GL_MAX_3D_TEXTURE_SIZE.
		VertexArray = 0x8074, // GL_VERTEX_ARRAY.
		SampleBuffers = 0x80A8, // GL_SAMPLE_BUFFERS.
		Samples = 0x80A9, // GL_SAMPLES.
		SampleCoverageValue = 0x80AA, // GL_SAMPLE_COVERAGE_VALUE.
		SampleCoverageInvert = 0x80AB, // GL_SAMPLE_COVERAGE_INVERT.
		BlendDstRgb = 0x80C8, // GL_BLEND_DST_RGB.
		BlendSrcRgb = 0x80C9, // GL_BLEND_SRC_RGB.
		BlendDstAlpha = 0x80CA, // GL_BLEND_DST_ALPHA.
		BlendSrcAlpha = 0x80CB, // GL_BLEND_SRC_ALPHA.
		MaxElementsVertices = 0x80E8, // GL_MAX_ELEMENTS_VERTICES.
		MaxElementsIndices = 0x80E9, // GL_MAX_ELEMENTS_INDICES.
		MajorVersion = 0x821B, // GL_MAJOR_VERSION.
		MinorVersion = 0x821C, // GL_MINOR_VERSION.
		NumExtensions = 0x821D, // GL_NUM_EXTENSIONS.
		MaxDebugGroupStackDepth = 0x826C, // GL_MAX_DEBUG_GROUP_STACK_DEPTH.
		DebugGroupStackDepth = 0x826D, // GL_DEBUG_GROUP_STACK_DEPTH.
		MaxLabelLength = 0x82E8, // GL_MAX_LABEL_LENGTH.
		AliasedPointSizeRange = 0x846D, // GL_ALIASED_POINT_SIZE_RANGE.
		AliasedLineWidthRange = 0x846E, // GL_ALIASED_LINE_WIDTH_RANGE.
		ActiveTexture = 0x84E0, // GL_ACTIVE_TEXTURE.
		MaxRenderbufferSize = 0x84E8, // GL_MAX_RENDERBUFFER_SIZE.
		MaxTextureLodBias = 0x84FD, // GL_MAX_TEXTURE_LOD_BIAS.
		TextureBindingCubeMap = 0x8514, // GL_TEXTURE_BINDING_CUBE_MAP.
		MaxCubeMapTextureSize = 0x851C, // GL_MAX_CUBE_MAP_TEXTURE_SIZE.
		VertexArrayBinding = 0x85B5, // GL_VERTEX_ARRAY_BINDING.
		NumCompressedTextureFormats = 0x86A2, // GL_NUM_COMPRESSED_TEXTURE_FORMATS.
		CompressedTextureFormats = 0x86A3, // GL_COMPRESSED_TEXTURE_FORMATS.
		NumProgramBinaryFormats = 0x87FE, // GL_NUM_PROGRAM_BINARY_FORMATS.
		ProgramBinaryFormats = 0x87FF, // GL_PROGRAM_BINARY_FORMATS.
		StencilBackFunc = 0x8800, // GL_STENCIL_BACK_FUNC.
		StencilBackFail = 0x8801, // GL_STENCIL_BACK_FAIL.
		StencilBackPassDepthFail = 0x8802, // GL_STENCIL_BACK_PASS_DEPTH_FAIL.
		StencilBackPassDepthPass = 0x8803, // GL_STENCIL_BACK_PASS_DEPTH_PASS.
		MaxDrawBuffers = 0x8824, // GL_MAX_DRAW_BUFFERS.
		BlendEquationAlpha = 0x883D, // GL_BLEND_EQUATION_ALPHA.
		MaxVertexAttribs = 0x8869, // GL_MAX_VERTEX_ATTRIBS.
		MaxTextureImageUnits = 0x8872, // GL_MAX_TEXTURE_IMAGE_UNITS.
		ArrayBufferBinding = 0x8894, // GL_ARRAY_BUFFER_BINDING.
		ElementArrayBufferBinding = 0x8895, // GL_ELEMENT_ARRAY_BUFFER_BINDING.
		PixelPackBufferBinding = 0x88ED, // GL_PIXEL_PACK_BUFFER_BINDING.
		PixelUnpackBufferBinding = 0x88EF, // GL_PIXEL_UNPACK_BUFFER_BINDING.
		MaxArrayTextureLayers = 0x88FF, // GL_MAX_ARRAY_TEXTURE_LAYERS.
		MinProgramTexelOffset = 0x8904, // GL_MIN_PROGRAM_TEXEL_OFFSET.
		MaxProgramTexelOffset = 0x8905, // GL_MAX_PROGRAM_TEXEL_OFFSET.
		SamplerBinding = 0x8919, // GL_SAMPLER_BINDING.
		UniformBufferBinding = 0x8A28, // GL_UNIFORM_BUFFER_BINDING.
		UniformBufferStart = 0x8A29, // GL_UNIFORM_BUFFER_START.
		UniformBufferSize = 0x8A2A, // GL_UNIFORM_BUFFER_SIZE.
		MaxVertexUniformBlocks = 0x8A2B, // GL_MAX_VERTEX_UNIFORM_BLOCKS.
		MaxFragmentUniformBlocks = 0x8A2D, // GL_MAX_FRAGMENT_UNIFORM_BLOCKS.
		MaxCombinedUniformBlocks = 0x8A2E, // GL_MAX_COMBINED_UNIFORM_BLOCKS.
		MaxUniformBufferBindings = 0x8A2F, // GL_MAX_UNIFORM_BUFFER_BINDINGS.
		MaxUniformBlockSize = 0x8A30, // GL_MAX_UNIFORM_BLOCK_SIZE.
		MaxCombinedVertexUniformComponents = 0x8A31, // GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS.
		MaxCombinedFragmentUniformComponents = 0x8A33, // GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS.
		UniformBufferOffsetAlignment = 0x8A34, // GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT.
		MaxFragmentUniformComponents = 0x8B49, // GL_MAX_FRAGMENT_UNIFORM_COMPONENTS.
		MaxVertexUniformComponents = 0x8B4A, // GL_MAX_VERTEX_UNIFORM_COMPONENTS.
		MaxVaryingComponents = 0x8B4B, // GL_MAX_VARYING_COMPONENTS.
		MaxVertexTextureImageUnits = 0x8B4C, // GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS.
		MaxCombinedTextureImageUnits = 0x8B4D, // GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS.
		FragmentShaderDerivativeHint = 0x8B8B, // GL_FRAGMENT_SHADER_DERIVATIVE_HINT.
		CurrentProgram = 0x8B8D, // GL_CURRENT_PROGRAM.
		ImplementationColorReadType = 0x8B9A, // GL_IMPLEMENTATION_COLOR_READ_TYPE.
		ImplementationColorReadFormat = 0x8B9B, // GL_IMPLEMENTATION_COLOR_READ_FORMAT.
		TextureBinding2dArray = 0x8C1D, // GL_TEXTURE_BINDING_2D_ARRAY.
		TransformFeedbackBufferStart = 0x8C84, // GL_TRANSFORM_FEEDBACK_BUFFER_START.
		TransformFeedbackBufferSize = 0x8C85, // GL_TRANSFORM_FEEDBACK_BUFFER_SIZE.
		TransformFeedbackBufferBinding = 0x8C8F, // GL_TRANSFORM_FEEDBACK_BUFFER_BINDING.
		MotionEstimationSearchBlockX = 0x8C90, // GL_MOTION_ESTIMATION_SEARCH_BLOCK_X_QCOM.
		MotionEstimationSearchBlockY = 0x8C91, // GL_MOTION_ESTIMATION_SEARCH_BLOCK_Y_QCOM.
		StencilBackRef = 0x8CA3, // GL_STENCIL_BACK_REF.
		StencilBackValueMask = 0x8CA4, // GL_STENCIL_BACK_VALUE_MASK.
		StencilBackWritemask = 0x8CA5, // GL_STENCIL_BACK_WRITEMASK.
		DrawFramebufferBinding = 0x8CA6, // GL_DRAW_FRAMEBUFFER_BINDING.
		RenderbufferBinding = 0x8CA7, // GL_RENDERBUFFER_BINDING.
		ReadFramebufferBinding = 0x8CAA, // GL_READ_FRAMEBUFFER_BINDING.
		MaxElementIndex = 0x8D6B, // GL_MAX_ELEMENT_INDEX.
		ShaderBinaryFormats = 0x8DF8, // GL_SHADER_BINARY_FORMATS.
		NumShaderBinaryFormats = 0x8DF9, // GL_NUM_SHADER_BINARY_FORMATS.
		ShaderCompiler = 0x8DFA, // GL_SHADER_COMPILER.
		MaxVertexUniformVectors = 0x8DFB, // GL_MAX_VERTEX_UNIFORM_VECTORS.
		MaxVaryingVectors = 0x8DFC, // GL_MAX_VARYING_VECTORS.
		MaxFragmentUniformVectors = 0x8DFD, // GL_MAX_FRAGMENT_UNIFORM_VECTORS.
		FetchPerSampleArm = 0x8F65, // GL_FETCH_PER_SAMPLE_ARM.
		FragmentShaderFramebufferFetchMrtArm = 0x8F66, // GL_FRAGMENT_SHADER_FRAMEBUFFER_FETCH_MRT_ARM.
		MaxServerWaitTimeout = 0x9111, // GL_MAX_SERVER_WAIT_TIMEOUT.
		MaxVertexOutputComponents = 0x9122, // GL_MAX_VERTEX_OUTPUT_COMPONENTS.
		MaxFragmentInputComponents = 0x9125, // GL_MAX_FRAGMENT_INPUT_COMPONENTS.
		NumDeviceUuids = 0x9596, // GL_NUM_DEVICE_UUIDS_EXT.
		DeviceUuid = 0x9597, // GL_DEVICE_UUID_EXT.
		DriverUuid = 0x9598, // GL_DRIVER_UUID_EXT.
		DeviceLuid = 0x9599, // GL_DEVICE_LUID_EXT.
		DeviceNodeMask = 0x959A, // GL_DEVICE_NODE_MASK_EXT.
		ShadingRateImagePerPrimitive = 0x95B1, // GL_SHADING_RATE_IMAGE_PER_PRIMITIVE_NV.
		ShadingRateImagePaletteCount = 0x95B2, // GL_SHADING_RATE_IMAGE_PALETTE_COUNT_NV.
		MaxTimelineSemaphoreValueDifference = 0x95B6, // GL_MAX_TIMELINE_SEMAPHORE_VALUE_DIFFERENCE_NV.
		ShadingRate = 0x96A4, // GL_SHADING_RATE_QCOM.
	};

	// GetTextureParameter; bitmask: False.
	enum class GetTextureParameter : uint32_t
	{
		TextureBorderColor = 0x1004, // GL_TEXTURE_BORDER_COLOR_NV.
		TextureMagFilter = 0x2800, // GL_TEXTURE_MAG_FILTER.
		TextureMinFilter = 0x2801, // GL_TEXTURE_MIN_FILTER.
		TextureWrapS = 0x2802, // GL_TEXTURE_WRAP_S.
		TextureWrapT = 0x2803, // GL_TEXTURE_WRAP_T.
		TextureUnnormalizedCoordinatesArm = 0x8F6A, // GL_TEXTURE_UNNORMALIZED_COORDINATES_ARM.
	};

	// GlslTypeToken; bitmask: False.
	enum class GlslTypeToken : uint32_t
	{
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
		FloatVec2 = 0x8B50, // GL_FLOAT_VEC2.
		FloatVec3 = 0x8B51, // GL_FLOAT_VEC3.
		FloatVec4 = 0x8B52, // GL_FLOAT_VEC4.
		IntVec2 = 0x8B53, // GL_INT_VEC2.
		IntVec3 = 0x8B54, // GL_INT_VEC3.
		IntVec4 = 0x8B55, // GL_INT_VEC4.
		Bool = 0x8B56, // GL_BOOL.
		BoolVec2 = 0x8B57, // GL_BOOL_VEC2.
		BoolVec3 = 0x8B58, // GL_BOOL_VEC3.
		BoolVec4 = 0x8B59, // GL_BOOL_VEC4.
		FloatMat2 = 0x8B5A, // GL_FLOAT_MAT2.
		FloatMat3 = 0x8B5B, // GL_FLOAT_MAT3.
		FloatMat4 = 0x8B5C, // GL_FLOAT_MAT4.
		Sampler2d = 0x8B5E, // GL_SAMPLER_2D.
		Sampler3d = 0x8B5F, // GL_SAMPLER_3D.
		SamplerCube = 0x8B60, // GL_SAMPLER_CUBE.
		Sampler2dShadow = 0x8B62, // GL_SAMPLER_2D_SHADOW.
		FloatMat2x3 = 0x8B65, // GL_FLOAT_MAT2x3.
		FloatMat2x4 = 0x8B66, // GL_FLOAT_MAT2x4.
		FloatMat3x2 = 0x8B67, // GL_FLOAT_MAT3x2.
		FloatMat3x4 = 0x8B68, // GL_FLOAT_MAT3x4.
		FloatMat4x2 = 0x8B69, // GL_FLOAT_MAT4x2.
		FloatMat4x3 = 0x8B6A, // GL_FLOAT_MAT4x3.
		Sampler2dArray = 0x8DC1, // GL_SAMPLER_2D_ARRAY.
		Sampler2dArrayShadow = 0x8DC4, // GL_SAMPLER_2D_ARRAY_SHADOW.
		SamplerCubeShadow = 0x8DC5, // GL_SAMPLER_CUBE_SHADOW.
		UnsignedIntVec2 = 0x8DC6, // GL_UNSIGNED_INT_VEC2.
		UnsignedIntVec3 = 0x8DC7, // GL_UNSIGNED_INT_VEC3.
		UnsignedIntVec4 = 0x8DC8, // GL_UNSIGNED_INT_VEC4.
		IntSampler2d = 0x8DCA, // GL_INT_SAMPLER_2D.
		IntSampler3d = 0x8DCB, // GL_INT_SAMPLER_3D.
		IntSamplerCube = 0x8DCC, // GL_INT_SAMPLER_CUBE.
		IntSampler2dArray = 0x8DCF, // GL_INT_SAMPLER_2D_ARRAY.
		UnsignedIntSampler2d = 0x8DD2, // GL_UNSIGNED_INT_SAMPLER_2D.
		UnsignedIntSampler3d = 0x8DD3, // GL_UNSIGNED_INT_SAMPLER_3D.
		UnsignedIntSamplerCube = 0x8DD4, // GL_UNSIGNED_INT_SAMPLER_CUBE.
		UnsignedIntSampler2dArray = 0x8DD7, // GL_UNSIGNED_INT_SAMPLER_2D_ARRAY.
	};

	// GraphicsResetStatus; bitmask: False.
	enum class GraphicsResetStatus : uint32_t
	{
		NoError = 0, // GL_NO_ERROR.
		GuiltyContextReset = 0x8253, // GL_GUILTY_CONTEXT_RESET.
		InnocentContextReset = 0x8254, // GL_INNOCENT_CONTEXT_RESET.
		UnknownContextReset = 0x8255, // GL_UNKNOWN_CONTEXT_RESET.
	};

	// HintMode; bitmask: False.
	enum class HintMode : uint32_t
	{
		DontCare = 0x1100, // GL_DONT_CARE.
		Fastest = 0x1101, // GL_FASTEST.
		Nicest = 0x1102, // GL_NICEST.
	};

	// HintTarget; bitmask: False.
	enum class HintTarget : uint32_t
	{
		GenerateMipmapHint = 0x8192, // GL_GENERATE_MIPMAP_HINT.
		ProgramBinaryRetrievableHint = 0x8257, // GL_PROGRAM_BINARY_RETRIEVABLE_HINT.
		FragmentShaderDerivativeHint = 0x8B8B, // GL_FRAGMENT_SHADER_DERIVATIVE_HINT.
		BinningControlHint = 0x8FB0, // GL_BINNING_CONTROL_HINT_QCOM.
	};

	// IndexFunctionEXT; bitmask: False.
	enum class IndexFunctionEXT : uint32_t
	{
		Never = 0x0200, // GL_NEVER.
		Less = 0x0201, // GL_LESS.
		Equal = 0x0202, // GL_EQUAL.
		Lequal = 0x0203, // GL_LEQUAL.
		Greater = 0x0204, // GL_GREATER.
		Notequal = 0x0205, // GL_NOTEQUAL.
		Gequal = 0x0206, // GL_GEQUAL.
		Always = 0x0207, // GL_ALWAYS.
	};

	// IndexPointerType; bitmask: False.
	enum class IndexPointerType : uint32_t
	{
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// InternalFormat; bitmask: False.
	enum class InternalFormat : uint32_t
	{
		StencilIndex = 0x1901, // GL_STENCIL_INDEX_OES.
		DepthComponent = 0x1902, // GL_DEPTH_COMPONENT.
		Red = 0x1903, // GL_RED.
		Rgb = 0x1907, // GL_RGB.
		Rgba = 0x1908, // GL_RGBA.
		Alpha8 = 0x803C, // GL_ALPHA8_EXT.
		Luminance8 = 0x8040, // GL_LUMINANCE8_EXT.
		Luminance4Alpha4 = 0x8043, // GL_LUMINANCE4_ALPHA4_OES.
		Luminance8Alpha8 = 0x8045, // GL_LUMINANCE8_ALPHA8_EXT.
		Rgb8 = 0x8051, // GL_RGB8.
		Rgb10 = 0x8052, // GL_RGB10_EXT.
		Rgb16 = 0x8054, // GL_RGB16_EXT.
		Rgba4 = 0x8056, // GL_RGBA4.
		Rgb5A1 = 0x8057, // GL_RGB5_A1.
		Rgba8 = 0x8058, // GL_RGBA8.
		Rgb10A2 = 0x8059, // GL_RGB10_A2.
		Rgba16 = 0x805B, // GL_RGBA16_EXT.
		Bgra = 0x80E1, // GL_BGRA_EXT.
		DepthComponent16 = 0x81A5, // GL_DEPTH_COMPONENT16.
		DepthComponent24 = 0x81A6, // GL_DEPTH_COMPONENT24.
		DepthComponent32 = 0x81A7, // GL_DEPTH_COMPONENT32_OES.
		Rg = 0x8227, // GL_RG.
		R8 = 0x8229, // GL_R8.
		R16 = 0x822A, // GL_R16_EXT.
		Rg8 = 0x822B, // GL_RG8.
		Rg16 = 0x822C, // GL_RG16_EXT.
		R16f = 0x822D, // GL_R16F.
		R32f = 0x822E, // GL_R32F.
		Rg16f = 0x822F, // GL_RG16F.
		Rg32f = 0x8230, // GL_RG32F.
		R8i = 0x8231, // GL_R8I.
		R8ui = 0x8232, // GL_R8UI.
		R16i = 0x8233, // GL_R16I.
		R16ui = 0x8234, // GL_R16UI.
		R32i = 0x8235, // GL_R32I.
		R32ui = 0x8236, // GL_R32UI.
		Rg8i = 0x8237, // GL_RG8I.
		Rg8ui = 0x8238, // GL_RG8UI.
		Rg16i = 0x8239, // GL_RG16I.
		Rg16ui = 0x823A, // GL_RG16UI.
		Rg32i = 0x823B, // GL_RG32I.
		Rg32ui = 0x823C, // GL_RG32UI.
		CompressedRgbS3tcDxt1 = 0x83F0, // GL_COMPRESSED_RGB_S3TC_DXT1_EXT.
		CompressedRgbaS3tcDxt1 = 0x83F1, // GL_COMPRESSED_RGBA_S3TC_DXT1_EXT.
		CompressedRgbaS3tcDxt3Angle = 0x83F2, // GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE.
		CompressedRgbaS3tcDxt5Angle = 0x83F3, // GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE.
		DepthStencil = 0x84F9, // GL_DEPTH_STENCIL.
		AtcRgbaInterpolatedAlpha = 0x87EE, // GL_ATC_RGBA_INTERPOLATED_ALPHA_AMD.
		Gl3dcX = 0x87F9, // GL_3DC_X_AMD.
		Gl3dcXy = 0x87FA, // GL_3DC_XY_AMD.
		Rgba32f = 0x8814, // GL_RGBA32F.
		Rgb32f = 0x8815, // GL_RGB32F.
		Rgba16f = 0x881A, // GL_RGBA16F.
		Rgb16f = 0x881B, // GL_RGB16F.
		Depth24Stencil8 = 0x88F0, // GL_DEPTH24_STENCIL8.
		CompressedRgbPvrtc4bppv1 = 0x8C00, // GL_COMPRESSED_RGB_PVRTC_4BPPV1_IMG.
		CompressedRgbPvrtc2bppv1 = 0x8C01, // GL_COMPRESSED_RGB_PVRTC_2BPPV1_IMG.
		CompressedRgbaPvrtc4bppv1 = 0x8C02, // GL_COMPRESSED_RGBA_PVRTC_4BPPV1_IMG.
		CompressedRgbaPvrtc2bppv1 = 0x8C03, // GL_COMPRESSED_RGBA_PVRTC_2BPPV1_IMG.
		R11fG11fB10f = 0x8C3A, // GL_R11F_G11F_B10F.
		Rgb9E5 = 0x8C3D, // GL_RGB9_E5.
		Srgb = 0x8C40, // GL_SRGB.
		Srgb8 = 0x8C41, // GL_SRGB8.
		SrgbAlpha = 0x8C42, // GL_SRGB_ALPHA_EXT.
		Srgb8Alpha8 = 0x8C43, // GL_SRGB8_ALPHA8.
		CompressedSrgbS3tcDxt1 = 0x8C4C, // GL_COMPRESSED_SRGB_S3TC_DXT1_EXT.
		CompressedSrgbAlphaS3tcDxt1 = 0x8C4D, // GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT.
		CompressedSrgbAlphaS3tcDxt3 = 0x8C4E, // GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT.
		CompressedSrgbAlphaS3tcDxt5 = 0x8C4F, // GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT.
		AtcRgb = 0x8C92, // GL_ATC_RGB_AMD.
		AtcRgbaExplicitAlpha = 0x8C93, // GL_ATC_RGBA_EXPLICIT_ALPHA_AMD.
		DepthComponent32f = 0x8CAC, // GL_DEPTH_COMPONENT32F.
		Depth32fStencil8 = 0x8CAD, // GL_DEPTH32F_STENCIL8.
		StencilIndex1 = 0x8D46, // GL_STENCIL_INDEX1_OES.
		StencilIndex4 = 0x8D47, // GL_STENCIL_INDEX4_OES.
		StencilIndex8 = 0x8D48, // GL_STENCIL_INDEX8.
		Rgb565 = 0x8D62, // GL_RGB565.
		Etc1Rgb8 = 0x8D64, // GL_ETC1_RGB8_OES.
		Rgba32ui = 0x8D70, // GL_RGBA32UI.
		Rgb32ui = 0x8D71, // GL_RGB32UI.
		Rgba16ui = 0x8D76, // GL_RGBA16UI.
		Rgb16ui = 0x8D77, // GL_RGB16UI.
		Rgba8ui = 0x8D7C, // GL_RGBA8UI.
		Rgb8ui = 0x8D7D, // GL_RGB8UI.
		Rgba32i = 0x8D82, // GL_RGBA32I.
		Rgb32i = 0x8D83, // GL_RGB32I.
		Rgba16i = 0x8D88, // GL_RGBA16I.
		Rgb16i = 0x8D89, // GL_RGB16I.
		Rgba8i = 0x8D8E, // GL_RGBA8I.
		Rgb8i = 0x8D8F, // GL_RGB8I.
		CompressedRedRgtc1 = 0x8DBB, // GL_COMPRESSED_RED_RGTC1_EXT.
		CompressedSignedRedRgtc1 = 0x8DBC, // GL_COMPRESSED_SIGNED_RED_RGTC1_EXT.
		CompressedRedGreenRgtc2 = 0x8DBD, // GL_COMPRESSED_RED_GREEN_RGTC2_EXT.
		CompressedSignedRedGreenRgtc2 = 0x8DBE, // GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT.
		CompressedRgbaBptcUnorm = 0x8E8C, // GL_COMPRESSED_RGBA_BPTC_UNORM_EXT.
		CompressedSrgbAlphaBptcUnorm = 0x8E8D, // GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_EXT.
		CompressedRgbBptcSignedFloat = 0x8E8E, // GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_EXT.
		CompressedRgbBptcUnsignedFloat = 0x8E8F, // GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_EXT.
		R8Snorm = 0x8F94, // GL_R8_SNORM.
		Rg8Snorm = 0x8F95, // GL_RG8_SNORM.
		Rgb8Snorm = 0x8F96, // GL_RGB8_SNORM.
		Rgba8Snorm = 0x8F97, // GL_RGBA8_SNORM.
		R16Snorm = 0x8F98, // GL_R16_SNORM_EXT.
		Rg16Snorm = 0x8F99, // GL_RG16_SNORM_EXT.
		Rgb16Snorm = 0x8F9A, // GL_RGB16_SNORM_EXT.
		Rgba16Snorm = 0x8F9B, // GL_RGBA16_SNORM_EXT.
		Sr8 = 0x8FBD, // GL_SR8_EXT.
		Srg8 = 0x8FBE, // GL_SRG8_EXT.
		Rgb10A2ui = 0x906F, // GL_RGB10_A2UI.
		CompressedRgbaPvrtc2bppv2 = 0x9137, // GL_COMPRESSED_RGBA_PVRTC_2BPPV2_IMG.
		CompressedRgbaPvrtc4bppv2 = 0x9138, // GL_COMPRESSED_RGBA_PVRTC_4BPPV2_IMG.
		CompressedR11Eac = 0x9270, // GL_COMPRESSED_R11_EAC.
		CompressedSignedR11Eac = 0x9271, // GL_COMPRESSED_SIGNED_R11_EAC.
		CompressedRg11Eac = 0x9272, // GL_COMPRESSED_RG11_EAC.
		CompressedSignedRg11Eac = 0x9273, // GL_COMPRESSED_SIGNED_RG11_EAC.
		CompressedRgb8Etc2 = 0x9274, // GL_COMPRESSED_RGB8_ETC2.
		CompressedSrgb8Etc2 = 0x9275, // GL_COMPRESSED_SRGB8_ETC2.
		CompressedRgb8PunchthroughAlpha1Etc2 = 0x9276, // GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2.
		CompressedSrgb8PunchthroughAlpha1Etc2 = 0x9277, // GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2.
		CompressedRgba8Etc2Eac = 0x9278, // GL_COMPRESSED_RGBA8_ETC2_EAC.
		CompressedSrgb8Alpha8Etc2Eac = 0x9279, // GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC.
		Bgra8 = 0x93A1, // GL_BGRA8_EXT.
		CompressedRgbaAstc4x4Khr = 0x93B0, // GL_COMPRESSED_RGBA_ASTC_4x4_KHR.
		CompressedRgbaAstc5x4Khr = 0x93B1, // GL_COMPRESSED_RGBA_ASTC_5x4_KHR.
		CompressedRgbaAstc5x5Khr = 0x93B2, // GL_COMPRESSED_RGBA_ASTC_5x5_KHR.
		CompressedRgbaAstc6x5Khr = 0x93B3, // GL_COMPRESSED_RGBA_ASTC_6x5_KHR.
		CompressedRgbaAstc6x6Khr = 0x93B4, // GL_COMPRESSED_RGBA_ASTC_6x6_KHR.
		CompressedRgbaAstc8x5Khr = 0x93B5, // GL_COMPRESSED_RGBA_ASTC_8x5_KHR.
		CompressedRgbaAstc8x6Khr = 0x93B6, // GL_COMPRESSED_RGBA_ASTC_8x6_KHR.
		CompressedRgbaAstc8x8Khr = 0x93B7, // GL_COMPRESSED_RGBA_ASTC_8x8_KHR.
		CompressedRgbaAstc10x5Khr = 0x93B8, // GL_COMPRESSED_RGBA_ASTC_10x5_KHR.
		CompressedRgbaAstc10x6Khr = 0x93B9, // GL_COMPRESSED_RGBA_ASTC_10x6_KHR.
		CompressedRgbaAstc10x8Khr = 0x93BA, // GL_COMPRESSED_RGBA_ASTC_10x8_KHR.
		CompressedRgbaAstc10x10Khr = 0x93BB, // GL_COMPRESSED_RGBA_ASTC_10x10_KHR.
		CompressedRgbaAstc12x10Khr = 0x93BC, // GL_COMPRESSED_RGBA_ASTC_12x10_KHR.
		CompressedRgbaAstc12x12Khr = 0x93BD, // GL_COMPRESSED_RGBA_ASTC_12x12_KHR.
		CompressedRgbaAstc3x3x3 = 0x93C0, // GL_COMPRESSED_RGBA_ASTC_3x3x3_OES.
		CompressedRgbaAstc4x3x3 = 0x93C1, // GL_COMPRESSED_RGBA_ASTC_4x3x3_OES.
		CompressedRgbaAstc4x4x3 = 0x93C2, // GL_COMPRESSED_RGBA_ASTC_4x4x3_OES.
		CompressedRgbaAstc4x4x4 = 0x93C3, // GL_COMPRESSED_RGBA_ASTC_4x4x4_OES.
		CompressedRgbaAstc5x4x4 = 0x93C4, // GL_COMPRESSED_RGBA_ASTC_5x4x4_OES.
		CompressedRgbaAstc5x5x4 = 0x93C5, // GL_COMPRESSED_RGBA_ASTC_5x5x4_OES.
		CompressedRgbaAstc5x5x5 = 0x93C6, // GL_COMPRESSED_RGBA_ASTC_5x5x5_OES.
		CompressedRgbaAstc6x5x5 = 0x93C7, // GL_COMPRESSED_RGBA_ASTC_6x5x5_OES.
		CompressedRgbaAstc6x6x5 = 0x93C8, // GL_COMPRESSED_RGBA_ASTC_6x6x5_OES.
		CompressedRgbaAstc6x6x6 = 0x93C9, // GL_COMPRESSED_RGBA_ASTC_6x6x6_OES.
		CompressedSrgb8Alpha8Astc4x4Khr = 0x93D0, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR.
		CompressedSrgb8Alpha8Astc5x4Khr = 0x93D1, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR.
		CompressedSrgb8Alpha8Astc5x5Khr = 0x93D2, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR.
		CompressedSrgb8Alpha8Astc6x5Khr = 0x93D3, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR.
		CompressedSrgb8Alpha8Astc6x6Khr = 0x93D4, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR.
		CompressedSrgb8Alpha8Astc8x5Khr = 0x93D5, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR.
		CompressedSrgb8Alpha8Astc8x6Khr = 0x93D6, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR.
		CompressedSrgb8Alpha8Astc8x8Khr = 0x93D7, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR.
		CompressedSrgb8Alpha8Astc10x5Khr = 0x93D8, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR.
		CompressedSrgb8Alpha8Astc10x6Khr = 0x93D9, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR.
		CompressedSrgb8Alpha8Astc10x8Khr = 0x93DA, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR.
		CompressedSrgb8Alpha8Astc10x10Khr = 0x93DB, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR.
		CompressedSrgb8Alpha8Astc12x10Khr = 0x93DC, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR.
		CompressedSrgb8Alpha8Astc12x12Khr = 0x93DD, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR.
		CompressedSrgb8Alpha8Astc3x3x3 = 0x93E0, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_3x3x3_OES.
		CompressedSrgb8Alpha8Astc4x3x3 = 0x93E1, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x3x3_OES.
		CompressedSrgb8Alpha8Astc4x4x3 = 0x93E2, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x3_OES.
		CompressedSrgb8Alpha8Astc4x4x4 = 0x93E3, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x4_OES.
		CompressedSrgb8Alpha8Astc5x4x4 = 0x93E4, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4x4_OES.
		CompressedSrgb8Alpha8Astc5x5x4 = 0x93E5, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x4_OES.
		CompressedSrgb8Alpha8Astc5x5x5 = 0x93E6, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x5_OES.
		CompressedSrgb8Alpha8Astc6x5x5 = 0x93E7, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5x5_OES.
		CompressedSrgb8Alpha8Astc6x6x5 = 0x93E8, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x5_OES.
		CompressedSrgb8Alpha8Astc6x6x6 = 0x93E9, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x6_OES.
	};

	// InternalFormatPName; bitmask: False.
	enum class InternalFormatPName : uint32_t
	{
		Samples = 0x80A9, // GL_SAMPLES.
		NumSampleCounts = 0x9380, // GL_NUM_SAMPLE_COUNTS.
	};

	// InvalidateFramebufferAttachment; bitmask: False.
	enum class InvalidateFramebufferAttachment : uint32_t
	{
		Color = 0x1800, // GL_COLOR.
		Depth = 0x1801, // GL_DEPTH.
		Stencil = 0x1802, // GL_STENCIL.
		DepthStencilAttachment = 0x821A, // GL_DEPTH_STENCIL_ATTACHMENT.
		ColorAttachment0 = 0x8CE0, // GL_COLOR_ATTACHMENT0.
		ColorAttachment1 = 0x8CE1, // GL_COLOR_ATTACHMENT1.
		ColorAttachment2 = 0x8CE2, // GL_COLOR_ATTACHMENT2.
		ColorAttachment3 = 0x8CE3, // GL_COLOR_ATTACHMENT3.
		ColorAttachment4 = 0x8CE4, // GL_COLOR_ATTACHMENT4.
		ColorAttachment5 = 0x8CE5, // GL_COLOR_ATTACHMENT5.
		ColorAttachment6 = 0x8CE6, // GL_COLOR_ATTACHMENT6.
		ColorAttachment7 = 0x8CE7, // GL_COLOR_ATTACHMENT7.
		ColorAttachment8 = 0x8CE8, // GL_COLOR_ATTACHMENT8.
		ColorAttachment9 = 0x8CE9, // GL_COLOR_ATTACHMENT9.
		ColorAttachment10 = 0x8CEA, // GL_COLOR_ATTACHMENT10.
		ColorAttachment11 = 0x8CEB, // GL_COLOR_ATTACHMENT11.
		ColorAttachment12 = 0x8CEC, // GL_COLOR_ATTACHMENT12.
		ColorAttachment13 = 0x8CED, // GL_COLOR_ATTACHMENT13.
		ColorAttachment14 = 0x8CEE, // GL_COLOR_ATTACHMENT14.
		ColorAttachment15 = 0x8CEF, // GL_COLOR_ATTACHMENT15.
		ColorAttachment16 = 0x8CF0, // GL_COLOR_ATTACHMENT16.
		ColorAttachment17 = 0x8CF1, // GL_COLOR_ATTACHMENT17.
		ColorAttachment18 = 0x8CF2, // GL_COLOR_ATTACHMENT18.
		ColorAttachment19 = 0x8CF3, // GL_COLOR_ATTACHMENT19.
		ColorAttachment20 = 0x8CF4, // GL_COLOR_ATTACHMENT20.
		ColorAttachment21 = 0x8CF5, // GL_COLOR_ATTACHMENT21.
		ColorAttachment22 = 0x8CF6, // GL_COLOR_ATTACHMENT22.
		ColorAttachment23 = 0x8CF7, // GL_COLOR_ATTACHMENT23.
		ColorAttachment24 = 0x8CF8, // GL_COLOR_ATTACHMENT24.
		ColorAttachment25 = 0x8CF9, // GL_COLOR_ATTACHMENT25.
		ColorAttachment26 = 0x8CFA, // GL_COLOR_ATTACHMENT26.
		ColorAttachment27 = 0x8CFB, // GL_COLOR_ATTACHMENT27.
		ColorAttachment28 = 0x8CFC, // GL_COLOR_ATTACHMENT28.
		ColorAttachment29 = 0x8CFD, // GL_COLOR_ATTACHMENT29.
		ColorAttachment30 = 0x8CFE, // GL_COLOR_ATTACHMENT30.
		ColorAttachment31 = 0x8CFF, // GL_COLOR_ATTACHMENT31.
		DepthAttachment = 0x8D00, // GL_DEPTH_ATTACHMENT.
	};

	// LightEnvModeSGIX; bitmask: False.
	enum class LightEnvModeSGIX : uint32_t
	{
		Replace = 0x1E01, // GL_REPLACE.
	};

	// ListNameType; bitmask: False.
	enum class ListNameType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		Short = 0x1402, // GL_SHORT.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// LogicOp; bitmask: False.
	enum class LogicOp : uint32_t
	{
		Invert = 0x150A, // GL_INVERT.
	};

	// MapBufferAccessMask; bitmask: True.
	enum class MapBufferAccess : uint32_t
	{
		MapRead = 0x0001, // GL_MAP_READ_BIT.
		MapWrite = 0x0002, // GL_MAP_WRITE_BIT.
		MapInvalidateRange = 0x0004, // GL_MAP_INVALIDATE_RANGE_BIT.
		MapInvalidateBuffer = 0x0008, // GL_MAP_INVALIDATE_BUFFER_BIT.
		MapFlushExplicit = 0x0010, // GL_MAP_FLUSH_EXPLICIT_BIT.
		MapUnsynchronized = 0x0020, // GL_MAP_UNSYNCHRONIZED_BIT.
		MapPersistent = 0x0040, // GL_MAP_PERSISTENT_BIT_EXT.
		MapCoherent = 0x0080, // GL_MAP_COHERENT_BIT_EXT.
	};

	// MapTypeNV; bitmask: False.
	enum class MapTypeNV : uint32_t
	{
		Float = 0x1406, // GL_FLOAT.
	};

	// MaterialFace; bitmask: False.
	enum class MaterialFace : uint32_t
	{
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		FrontAndBack = 0x0408, // GL_FRONT_AND_BACK.
	};

	// MatrixIndexPointerTypeARB; bitmask: False.
	enum class MatrixIndexPointerTypeARB : uint32_t
	{
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// MatrixMode; bitmask: False.
	enum class MatrixMode : uint32_t
	{
		Texture = 0x1702, // GL_TEXTURE.
	};

	// NormalPointerType; bitmask: False.
	enum class NormalPointerType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// ObjectIdentifier; bitmask: False.
	enum class ObjectIdentifier : uint32_t
	{
		Texture = 0x1702, // GL_TEXTURE.
		VertexArray = 0x8074, // GL_VERTEX_ARRAY.
		Buffer = 0x82E0, // GL_BUFFER.
		Shader = 0x82E1, // GL_SHADER.
		Program = 0x82E2, // GL_PROGRAM.
		Query = 0x82E3, // GL_QUERY.
		ProgramPipeline = 0x82E4, // GL_PROGRAM_PIPELINE.
		Sampler = 0x82E6, // GL_SAMPLER.
		Framebuffer = 0x8D40, // GL_FRAMEBUFFER.
		Renderbuffer = 0x8D41, // GL_RENDERBUFFER.
		TransformFeedback = 0x8E22, // GL_TRANSFORM_FEEDBACK.
	};

	// PathColorFormat; bitmask: False.
	enum class PathColorFormat : uint32_t
	{
		None = 0, // GL_NONE.
		Alpha = 0x1906, // GL_ALPHA.
		Rgb = 0x1907, // GL_RGB.
		Rgba = 0x1908, // GL_RGBA.
		Luminance = 0x1909, // GL_LUMINANCE.
		LuminanceAlpha = 0x190A, // GL_LUMINANCE_ALPHA.
	};

	// PathFillMode; bitmask: False.
	enum class PathFillMode : uint32_t
	{
		Invert = 0x150A, // GL_INVERT.
		PathFillMode = 0x9080, // GL_PATH_FILL_MODE_NV.
		CountUp = 0x9088, // GL_COUNT_UP_NV.
		CountDown = 0x9089, // GL_COUNT_DOWN_NV.
	};

	// PathFontStyle; bitmask: True.
	enum class PathFontStyle : uint32_t
	{
		Bold = 0x01, // GL_BOLD_BIT_NV.
		Italic = 0x02, // GL_ITALIC_BIT_NV.
		None = 0, // GL_NONE.
	};

	// PathGenMode; bitmask: False.
	enum class PathGenMode : uint32_t
	{
		None = 0, // GL_NONE.
		PathObjectBoundingBox = 0x908A, // GL_PATH_OBJECT_BOUNDING_BOX_NV.
	};

	// PathTransformType; bitmask: False.
	enum class PathTransformType : uint32_t
	{
		None = 0, // GL_NONE.
		TranslateX = 0x908E, // GL_TRANSLATE_X_NV.
		TranslateY = 0x908F, // GL_TRANSLATE_Y_NV.
		Translate2d = 0x9090, // GL_TRANSLATE_2D_NV.
		Translate3d = 0x9091, // GL_TRANSLATE_3D_NV.
		Affine2d = 0x9092, // GL_AFFINE_2D_NV.
		Affine3d = 0x9094, // GL_AFFINE_3D_NV.
		TransposeAffine2d = 0x9096, // GL_TRANSPOSE_AFFINE_2D_NV.
		TransposeAffine3d = 0x9098, // GL_TRANSPOSE_AFFINE_3D_NV.
	};

	// PipelineParameterName; bitmask: False.
	enum class PipelineParameterName : uint32_t
	{
		FragmentShader = 0x8B30, // GL_FRAGMENT_SHADER.
		VertexShader = 0x8B31, // GL_VERTEX_SHADER.
		InfoLogLength = 0x8B84, // GL_INFO_LOG_LENGTH.
	};

	// PixelCopyType; bitmask: False.
	enum class PixelCopyType : uint32_t
	{
		Color = 0x1800, // GL_COLOR.
		Depth = 0x1801, // GL_DEPTH.
		Stencil = 0x1802, // GL_STENCIL.
	};

	// PixelFormat; bitmask: False.
	enum class PixelFormat : uint32_t
	{
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		DepthComponent = 0x1902, // GL_DEPTH_COMPONENT.
		Red = 0x1903, // GL_RED.
		Green = 0x1904, // GL_GREEN.
		Blue = 0x1905, // GL_BLUE.
		Alpha = 0x1906, // GL_ALPHA.
		Rgb = 0x1907, // GL_RGB.
		Rgba = 0x1908, // GL_RGBA.
		Luminance = 0x1909, // GL_LUMINANCE.
		LuminanceAlpha = 0x190A, // GL_LUMINANCE_ALPHA.
		Rg = 0x8227, // GL_RG.
		RgInteger = 0x8228, // GL_RG_INTEGER.
		DepthStencil = 0x84F9, // GL_DEPTH_STENCIL.
		RedInteger = 0x8D94, // GL_RED_INTEGER.
		RgbInteger = 0x8D98, // GL_RGB_INTEGER.
		RgbaInteger = 0x8D99, // GL_RGBA_INTEGER.
	};

	// PixelStoreParameter; bitmask: False.
	enum class PixelStoreParameter : uint32_t
	{
		UnpackRowLength = 0x0CF2, // GL_UNPACK_ROW_LENGTH.
		UnpackSkipRows = 0x0CF3, // GL_UNPACK_SKIP_ROWS.
		UnpackSkipPixels = 0x0CF4, // GL_UNPACK_SKIP_PIXELS.
		UnpackAlignment = 0x0CF5, // GL_UNPACK_ALIGNMENT.
		PackRowLength = 0x0D02, // GL_PACK_ROW_LENGTH.
		PackSkipRows = 0x0D03, // GL_PACK_SKIP_ROWS.
		PackSkipPixels = 0x0D04, // GL_PACK_SKIP_PIXELS.
		PackAlignment = 0x0D05, // GL_PACK_ALIGNMENT.
		UnpackSkipImages = 0x806D, // GL_UNPACK_SKIP_IMAGES.
		UnpackImageHeight = 0x806E, // GL_UNPACK_IMAGE_HEIGHT.
	};

	// PixelTexGenMode; bitmask: False.
	enum class PixelTexGenMode : uint32_t
	{
		None = 0, // GL_NONE.
		Rgb = 0x1907, // GL_RGB.
		Rgba = 0x1908, // GL_RGBA.
		Luminance = 0x1909, // GL_LUMINANCE.
		LuminanceAlpha = 0x190A, // GL_LUMINANCE_ALPHA.
	};

	// PixelType; bitmask: False.
	enum class PixelType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		Short = 0x1402, // GL_SHORT.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
		UnsignedShort4444 = 0x8033, // GL_UNSIGNED_SHORT_4_4_4_4.
		UnsignedShort5551 = 0x8034, // GL_UNSIGNED_SHORT_5_5_5_1.
	};

	// PrecisionType; bitmask: False.
	enum class PrecisionType : uint32_t
	{
		LowFloat = 0x8DF0, // GL_LOW_FLOAT.
		MediumFloat = 0x8DF1, // GL_MEDIUM_FLOAT.
		HighFloat = 0x8DF2, // GL_HIGH_FLOAT.
		LowInt = 0x8DF3, // GL_LOW_INT.
		MediumInt = 0x8DF4, // GL_MEDIUM_INT.
		HighInt = 0x8DF5, // GL_HIGH_INT.
	};

	// PrimitiveType; bitmask: False.
	enum class PrimitiveType : uint32_t
	{
		Points = 0x0000, // GL_POINTS.
		Lines = 0x0001, // GL_LINES.
		LineLoop = 0x0002, // GL_LINE_LOOP.
		LineStrip = 0x0003, // GL_LINE_STRIP.
		Triangles = 0x0004, // GL_TRIANGLES.
		TriangleStrip = 0x0005, // GL_TRIANGLE_STRIP.
		TriangleFan = 0x0006, // GL_TRIANGLE_FAN.
		Quads = 0x0007, // GL_QUADS_EXT.
		LinesAdjacency = 0x000A, // GL_LINES_ADJACENCY_EXT.
		LineStripAdjacency = 0x000B, // GL_LINE_STRIP_ADJACENCY_EXT.
		TrianglesAdjacency = 0x000C, // GL_TRIANGLES_ADJACENCY_EXT.
		TriangleStripAdjacency = 0x000D, // GL_TRIANGLE_STRIP_ADJACENCY_EXT.
		Patches = 0x000E, // GL_PATCHES_EXT.
	};

	// ProgramInterface; bitmask: False.
	enum class ProgramInterface : uint32_t
	{
		TransformFeedbackBuffer = 0x8C8E, // GL_TRANSFORM_FEEDBACK_BUFFER.
	};

	// ProgramParameterPName; bitmask: False.
	enum class ProgramParameterPName : uint32_t
	{
		ProgramBinaryRetrievableHint = 0x8257, // GL_PROGRAM_BINARY_RETRIEVABLE_HINT.
	};

	// ProgramPropertyARB; bitmask: False.
	enum class ProgramPropertyARB : uint32_t
	{
		ProgramBinaryLength = 0x8741, // GL_PROGRAM_BINARY_LENGTH.
		ActiveUniformBlockMaxNameLength = 0x8A35, // GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH.
		ActiveUniformBlocks = 0x8A36, // GL_ACTIVE_UNIFORM_BLOCKS.
		DeleteStatus = 0x8B80, // GL_DELETE_STATUS.
		LinkStatus = 0x8B82, // GL_LINK_STATUS.
		ValidateStatus = 0x8B83, // GL_VALIDATE_STATUS.
		InfoLogLength = 0x8B84, // GL_INFO_LOG_LENGTH.
		AttachedShaders = 0x8B85, // GL_ATTACHED_SHADERS.
		ActiveUniforms = 0x8B86, // GL_ACTIVE_UNIFORMS.
		ActiveUniformMaxLength = 0x8B87, // GL_ACTIVE_UNIFORM_MAX_LENGTH.
		ActiveAttributes = 0x8B89, // GL_ACTIVE_ATTRIBUTES.
		ActiveAttributeMaxLength = 0x8B8A, // GL_ACTIVE_ATTRIBUTE_MAX_LENGTH.
		TransformFeedbackVaryingMaxLength = 0x8C76, // GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH.
		TransformFeedbackBufferMode = 0x8C7F, // GL_TRANSFORM_FEEDBACK_BUFFER_MODE.
		TransformFeedbackVaryings = 0x8C83, // GL_TRANSFORM_FEEDBACK_VARYINGS.
	};

	// QueryObjectParameterName; bitmask: False.
	enum class QueryObjectParameterName : uint32_t
	{
		QueryResult = 0x8866, // GL_QUERY_RESULT.
		QueryResultAvailable = 0x8867, // GL_QUERY_RESULT_AVAILABLE.
	};

	// QueryParameterName; bitmask: False.
	enum class QueryParameterName : uint32_t
	{
		CurrentQuery = 0x8865, // GL_CURRENT_QUERY.
	};

	// QueryTarget; bitmask: False.
	enum class QueryTarget : uint32_t
	{
		AnySamplesPassed = 0x8C2F, // GL_ANY_SAMPLES_PASSED.
		TransformFeedbackPrimitivesWritten = 0x8C88, // GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN.
		AnySamplesPassedConservative = 0x8D6A, // GL_ANY_SAMPLES_PASSED_CONSERVATIVE.
	};

	// ReadBufferMode; bitmask: False.
	enum class ReadBufferMode : uint32_t
	{
		None = 0, // GL_NONE.
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		ColorAttachment0 = 0x8CE0, // GL_COLOR_ATTACHMENT0.
		ColorAttachment1 = 0x8CE1, // GL_COLOR_ATTACHMENT1.
		ColorAttachment2 = 0x8CE2, // GL_COLOR_ATTACHMENT2.
		ColorAttachment3 = 0x8CE3, // GL_COLOR_ATTACHMENT3.
		ColorAttachment4 = 0x8CE4, // GL_COLOR_ATTACHMENT4.
		ColorAttachment5 = 0x8CE5, // GL_COLOR_ATTACHMENT5.
		ColorAttachment6 = 0x8CE6, // GL_COLOR_ATTACHMENT6.
		ColorAttachment7 = 0x8CE7, // GL_COLOR_ATTACHMENT7.
		ColorAttachment8 = 0x8CE8, // GL_COLOR_ATTACHMENT8.
		ColorAttachment9 = 0x8CE9, // GL_COLOR_ATTACHMENT9.
		ColorAttachment10 = 0x8CEA, // GL_COLOR_ATTACHMENT10.
		ColorAttachment11 = 0x8CEB, // GL_COLOR_ATTACHMENT11.
		ColorAttachment12 = 0x8CEC, // GL_COLOR_ATTACHMENT12.
		ColorAttachment13 = 0x8CED, // GL_COLOR_ATTACHMENT13.
		ColorAttachment14 = 0x8CEE, // GL_COLOR_ATTACHMENT14.
		ColorAttachment15 = 0x8CEF, // GL_COLOR_ATTACHMENT15.
	};

	// RenderbufferParameterName; bitmask: False.
	enum class RenderbufferParameterName : uint32_t
	{
		RenderbufferSamples = 0x8CAB, // GL_RENDERBUFFER_SAMPLES.
		RenderbufferWidth = 0x8D42, // GL_RENDERBUFFER_WIDTH.
		RenderbufferHeight = 0x8D43, // GL_RENDERBUFFER_HEIGHT.
		RenderbufferInternalFormat = 0x8D44, // GL_RENDERBUFFER_INTERNAL_FORMAT.
		RenderbufferRedSize = 0x8D50, // GL_RENDERBUFFER_RED_SIZE.
		RenderbufferGreenSize = 0x8D51, // GL_RENDERBUFFER_GREEN_SIZE.
		RenderbufferBlueSize = 0x8D52, // GL_RENDERBUFFER_BLUE_SIZE.
		RenderbufferAlphaSize = 0x8D53, // GL_RENDERBUFFER_ALPHA_SIZE.
		RenderbufferDepthSize = 0x8D54, // GL_RENDERBUFFER_DEPTH_SIZE.
		RenderbufferStencilSize = 0x8D55, // GL_RENDERBUFFER_STENCIL_SIZE.
		RenderbufferSamplesImg = 0x9133, // GL_RENDERBUFFER_SAMPLES_IMG.
		RenderbufferStorageSamples = 0x91B2, // GL_RENDERBUFFER_STORAGE_SAMPLES_AMD.
	};

	// RenderbufferTarget; bitmask: False.
	enum class RenderbufferTarget : uint32_t
	{
		Renderbuffer = 0x8D41, // GL_RENDERBUFFER.
	};

	// ReplacementCodeTypeSUN; bitmask: False.
	enum class ReplacementCodeTypeSUN : uint32_t
	{
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// SamplerParameterF; bitmask: False.
	enum class SamplerParameterF : uint32_t
	{
		TextureMinLod = 0x813A, // GL_TEXTURE_MIN_LOD.
		TextureMaxLod = 0x813B, // GL_TEXTURE_MAX_LOD.
		TextureUnnormalizedCoordinatesArm = 0x8F6A, // GL_TEXTURE_UNNORMALIZED_COORDINATES_ARM.
	};

	// SamplerParameterI; bitmask: False.
	enum class SamplerParameterI : uint32_t
	{
		TextureMagFilter = 0x2800, // GL_TEXTURE_MAG_FILTER.
		TextureMinFilter = 0x2801, // GL_TEXTURE_MIN_FILTER.
		TextureWrapS = 0x2802, // GL_TEXTURE_WRAP_S.
		TextureWrapT = 0x2803, // GL_TEXTURE_WRAP_T.
		TextureWrapR = 0x8072, // GL_TEXTURE_WRAP_R.
		TextureCompareMode = 0x884C, // GL_TEXTURE_COMPARE_MODE.
		TextureCompareFunc = 0x884D, // GL_TEXTURE_COMPARE_FUNC.
		TextureUnnormalizedCoordinatesArm = 0x8F6A, // GL_TEXTURE_UNNORMALIZED_COORDINATES_ARM.
	};

	// ScalarType; bitmask: False.
	enum class ScalarType : uint32_t
	{
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// SecondaryColorPointerTypeIBM; bitmask: False.
	enum class SecondaryColorPointerTypeIBM : uint32_t
	{
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// ShaderBinaryFormat; bitmask: False.
	enum class ShaderBinaryFormat : uint32_t
	{
		SgxBinary = 0x8C0A, // GL_SGX_BINARY_IMG.
		MaliShaderBinaryArm = 0x8F60, // GL_MALI_SHADER_BINARY_ARM.
		ShaderBinaryViv = 0x8FC4, // GL_SHADER_BINARY_VIV.
		ShaderBinaryDmp = 0x9250, // GL_SHADER_BINARY_DMP.
		GccsoShaderBinaryFj = 0x9260, // GL_GCCSO_SHADER_BINARY_FJ.
	};

	// ShaderParameterName; bitmask: False.
	enum class ShaderParameterName : uint32_t
	{
		ShaderType = 0x8B4F, // GL_SHADER_TYPE.
		DeleteStatus = 0x8B80, // GL_DELETE_STATUS.
		CompileStatus = 0x8B81, // GL_COMPILE_STATUS.
		InfoLogLength = 0x8B84, // GL_INFO_LOG_LENGTH.
		ShaderSourceLength = 0x8B88, // GL_SHADER_SOURCE_LENGTH.
	};

	// ShaderType; bitmask: False.
	enum class ShaderType : uint32_t
	{
		FragmentShader = 0x8B30, // GL_FRAGMENT_SHADER.
		VertexShader = 0x8B31, // GL_VERTEX_SHADER.
	};

	// SizedInternalFormat; bitmask: False.
	enum class SizedInternalFormat : uint32_t
	{
		Alpha8 = 0x803C, // GL_ALPHA8_EXT.
		Luminance8 = 0x8040, // GL_LUMINANCE8_EXT.
		Luminance4Alpha4 = 0x8043, // GL_LUMINANCE4_ALPHA4_OES.
		Luminance8Alpha8 = 0x8045, // GL_LUMINANCE8_ALPHA8_EXT.
		Rgb8 = 0x8051, // GL_RGB8.
		Rgb10 = 0x8052, // GL_RGB10_EXT.
		Rgb16 = 0x8054, // GL_RGB16_EXT.
		Rgba4 = 0x8056, // GL_RGBA4.
		Rgb5A1 = 0x8057, // GL_RGB5_A1.
		Rgba8 = 0x8058, // GL_RGBA8.
		Rgb10A2 = 0x8059, // GL_RGB10_A2.
		Rgba16 = 0x805B, // GL_RGBA16_EXT.
		DepthComponent16 = 0x81A5, // GL_DEPTH_COMPONENT16.
		DepthComponent24 = 0x81A6, // GL_DEPTH_COMPONENT24.
		DepthComponent32 = 0x81A7, // GL_DEPTH_COMPONENT32_OES.
		R8 = 0x8229, // GL_R8.
		R16 = 0x822A, // GL_R16_EXT.
		Rg8 = 0x822B, // GL_RG8.
		Rg16 = 0x822C, // GL_RG16_EXT.
		R16f = 0x822D, // GL_R16F.
		R32f = 0x822E, // GL_R32F.
		Rg16f = 0x822F, // GL_RG16F.
		Rg32f = 0x8230, // GL_RG32F.
		R8i = 0x8231, // GL_R8I.
		R8ui = 0x8232, // GL_R8UI.
		R16i = 0x8233, // GL_R16I.
		R16ui = 0x8234, // GL_R16UI.
		R32i = 0x8235, // GL_R32I.
		R32ui = 0x8236, // GL_R32UI.
		Rg8i = 0x8237, // GL_RG8I.
		Rg8ui = 0x8238, // GL_RG8UI.
		Rg16i = 0x8239, // GL_RG16I.
		Rg16ui = 0x823A, // GL_RG16UI.
		Rg32i = 0x823B, // GL_RG32I.
		Rg32ui = 0x823C, // GL_RG32UI.
		CompressedRgbS3tcDxt1 = 0x83F0, // GL_COMPRESSED_RGB_S3TC_DXT1_EXT.
		CompressedRgbaS3tcDxt1 = 0x83F1, // GL_COMPRESSED_RGBA_S3TC_DXT1_EXT.
		CompressedRgbaS3tcDxt3Angle = 0x83F2, // GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE.
		CompressedRgbaS3tcDxt5Angle = 0x83F3, // GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE.
		Rgba32f = 0x8814, // GL_RGBA32F.
		Rgb32f = 0x8815, // GL_RGB32F.
		Rgba16f = 0x881A, // GL_RGBA16F.
		Rgb16f = 0x881B, // GL_RGB16F.
		Depth24Stencil8 = 0x88F0, // GL_DEPTH24_STENCIL8.
		R11fG11fB10f = 0x8C3A, // GL_R11F_G11F_B10F.
		Rgb9E5 = 0x8C3D, // GL_RGB9_E5.
		Srgb8 = 0x8C41, // GL_SRGB8.
		Srgb8Alpha8 = 0x8C43, // GL_SRGB8_ALPHA8.
		CompressedSrgbS3tcDxt1 = 0x8C4C, // GL_COMPRESSED_SRGB_S3TC_DXT1_EXT.
		CompressedSrgbAlphaS3tcDxt1 = 0x8C4D, // GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT.
		CompressedSrgbAlphaS3tcDxt3 = 0x8C4E, // GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT.
		CompressedSrgbAlphaS3tcDxt5 = 0x8C4F, // GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT.
		DepthComponent32f = 0x8CAC, // GL_DEPTH_COMPONENT32F.
		Depth32fStencil8 = 0x8CAD, // GL_DEPTH32F_STENCIL8.
		StencilIndex1 = 0x8D46, // GL_STENCIL_INDEX1_OES.
		StencilIndex4 = 0x8D47, // GL_STENCIL_INDEX4_OES.
		StencilIndex8 = 0x8D48, // GL_STENCIL_INDEX8.
		Rgb565 = 0x8D62, // GL_RGB565.
		Etc1Rgb8 = 0x8D64, // GL_ETC1_RGB8_OES.
		Rgba32ui = 0x8D70, // GL_RGBA32UI.
		Rgb32ui = 0x8D71, // GL_RGB32UI.
		Rgba16ui = 0x8D76, // GL_RGBA16UI.
		Rgb16ui = 0x8D77, // GL_RGB16UI.
		Rgba8ui = 0x8D7C, // GL_RGBA8UI.
		Rgb8ui = 0x8D7D, // GL_RGB8UI.
		Rgba32i = 0x8D82, // GL_RGBA32I.
		Rgb32i = 0x8D83, // GL_RGB32I.
		Rgba16i = 0x8D88, // GL_RGBA16I.
		Rgb16i = 0x8D89, // GL_RGB16I.
		Rgba8i = 0x8D8E, // GL_RGBA8I.
		Rgb8i = 0x8D8F, // GL_RGB8I.
		CompressedRedRgtc1 = 0x8DBB, // GL_COMPRESSED_RED_RGTC1_EXT.
		CompressedSignedRedRgtc1 = 0x8DBC, // GL_COMPRESSED_SIGNED_RED_RGTC1_EXT.
		CompressedRedGreenRgtc2 = 0x8DBD, // GL_COMPRESSED_RED_GREEN_RGTC2_EXT.
		CompressedSignedRedGreenRgtc2 = 0x8DBE, // GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT.
		CompressedRgbaBptcUnorm = 0x8E8C, // GL_COMPRESSED_RGBA_BPTC_UNORM_EXT.
		CompressedSrgbAlphaBptcUnorm = 0x8E8D, // GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_EXT.
		CompressedRgbBptcSignedFloat = 0x8E8E, // GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_EXT.
		CompressedRgbBptcUnsignedFloat = 0x8E8F, // GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_EXT.
		R8Snorm = 0x8F94, // GL_R8_SNORM.
		Rg8Snorm = 0x8F95, // GL_RG8_SNORM.
		Rgb8Snorm = 0x8F96, // GL_RGB8_SNORM.
		Rgba8Snorm = 0x8F97, // GL_RGBA8_SNORM.
		R16Snorm = 0x8F98, // GL_R16_SNORM_EXT.
		Rg16Snorm = 0x8F99, // GL_RG16_SNORM_EXT.
		Rgb16Snorm = 0x8F9A, // GL_RGB16_SNORM_EXT.
		Rgba16Snorm = 0x8F9B, // GL_RGBA16_SNORM_EXT.
		Rgb10A2ui = 0x906F, // GL_RGB10_A2UI.
		CompressedR11Eac = 0x9270, // GL_COMPRESSED_R11_EAC.
		CompressedSignedR11Eac = 0x9271, // GL_COMPRESSED_SIGNED_R11_EAC.
		CompressedRg11Eac = 0x9272, // GL_COMPRESSED_RG11_EAC.
		CompressedSignedRg11Eac = 0x9273, // GL_COMPRESSED_SIGNED_RG11_EAC.
		CompressedRgb8Etc2 = 0x9274, // GL_COMPRESSED_RGB8_ETC2.
		CompressedSrgb8Etc2 = 0x9275, // GL_COMPRESSED_SRGB8_ETC2.
		CompressedRgb8PunchthroughAlpha1Etc2 = 0x9276, // GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2.
		CompressedSrgb8PunchthroughAlpha1Etc2 = 0x9277, // GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2.
		CompressedRgba8Etc2Eac = 0x9278, // GL_COMPRESSED_RGBA8_ETC2_EAC.
		CompressedSrgb8Alpha8Etc2Eac = 0x9279, // GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC.
		CompressedRgbaAstc4x4Khr = 0x93B0, // GL_COMPRESSED_RGBA_ASTC_4x4_KHR.
		CompressedRgbaAstc5x4Khr = 0x93B1, // GL_COMPRESSED_RGBA_ASTC_5x4_KHR.
		CompressedRgbaAstc5x5Khr = 0x93B2, // GL_COMPRESSED_RGBA_ASTC_5x5_KHR.
		CompressedRgbaAstc6x5Khr = 0x93B3, // GL_COMPRESSED_RGBA_ASTC_6x5_KHR.
		CompressedRgbaAstc6x6Khr = 0x93B4, // GL_COMPRESSED_RGBA_ASTC_6x6_KHR.
		CompressedRgbaAstc8x5Khr = 0x93B5, // GL_COMPRESSED_RGBA_ASTC_8x5_KHR.
		CompressedRgbaAstc8x6Khr = 0x93B6, // GL_COMPRESSED_RGBA_ASTC_8x6_KHR.
		CompressedRgbaAstc8x8Khr = 0x93B7, // GL_COMPRESSED_RGBA_ASTC_8x8_KHR.
		CompressedRgbaAstc10x5Khr = 0x93B8, // GL_COMPRESSED_RGBA_ASTC_10x5_KHR.
		CompressedRgbaAstc10x6Khr = 0x93B9, // GL_COMPRESSED_RGBA_ASTC_10x6_KHR.
		CompressedRgbaAstc10x8Khr = 0x93BA, // GL_COMPRESSED_RGBA_ASTC_10x8_KHR.
		CompressedRgbaAstc10x10Khr = 0x93BB, // GL_COMPRESSED_RGBA_ASTC_10x10_KHR.
		CompressedRgbaAstc12x10Khr = 0x93BC, // GL_COMPRESSED_RGBA_ASTC_12x10_KHR.
		CompressedRgbaAstc12x12Khr = 0x93BD, // GL_COMPRESSED_RGBA_ASTC_12x12_KHR.
		CompressedRgbaAstc3x3x3 = 0x93C0, // GL_COMPRESSED_RGBA_ASTC_3x3x3_OES.
		CompressedRgbaAstc4x3x3 = 0x93C1, // GL_COMPRESSED_RGBA_ASTC_4x3x3_OES.
		CompressedRgbaAstc4x4x3 = 0x93C2, // GL_COMPRESSED_RGBA_ASTC_4x4x3_OES.
		CompressedRgbaAstc4x4x4 = 0x93C3, // GL_COMPRESSED_RGBA_ASTC_4x4x4_OES.
		CompressedRgbaAstc5x4x4 = 0x93C4, // GL_COMPRESSED_RGBA_ASTC_5x4x4_OES.
		CompressedRgbaAstc5x5x4 = 0x93C5, // GL_COMPRESSED_RGBA_ASTC_5x5x4_OES.
		CompressedRgbaAstc5x5x5 = 0x93C6, // GL_COMPRESSED_RGBA_ASTC_5x5x5_OES.
		CompressedRgbaAstc6x5x5 = 0x93C7, // GL_COMPRESSED_RGBA_ASTC_6x5x5_OES.
		CompressedRgbaAstc6x6x5 = 0x93C8, // GL_COMPRESSED_RGBA_ASTC_6x6x5_OES.
		CompressedRgbaAstc6x6x6 = 0x93C9, // GL_COMPRESSED_RGBA_ASTC_6x6x6_OES.
		CompressedSrgb8Alpha8Astc4x4Khr = 0x93D0, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR.
		CompressedSrgb8Alpha8Astc5x4Khr = 0x93D1, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR.
		CompressedSrgb8Alpha8Astc5x5Khr = 0x93D2, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR.
		CompressedSrgb8Alpha8Astc6x5Khr = 0x93D3, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR.
		CompressedSrgb8Alpha8Astc6x6Khr = 0x93D4, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR.
		CompressedSrgb8Alpha8Astc8x5Khr = 0x93D5, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR.
		CompressedSrgb8Alpha8Astc8x6Khr = 0x93D6, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR.
		CompressedSrgb8Alpha8Astc8x8Khr = 0x93D7, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR.
		CompressedSrgb8Alpha8Astc10x5Khr = 0x93D8, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR.
		CompressedSrgb8Alpha8Astc10x6Khr = 0x93D9, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR.
		CompressedSrgb8Alpha8Astc10x8Khr = 0x93DA, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR.
		CompressedSrgb8Alpha8Astc10x10Khr = 0x93DB, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR.
		CompressedSrgb8Alpha8Astc12x10Khr = 0x93DC, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR.
		CompressedSrgb8Alpha8Astc12x12Khr = 0x93DD, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR.
		CompressedSrgb8Alpha8Astc3x3x3 = 0x93E0, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_3x3x3_OES.
		CompressedSrgb8Alpha8Astc4x3x3 = 0x93E1, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x3x3_OES.
		CompressedSrgb8Alpha8Astc4x4x3 = 0x93E2, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x3_OES.
		CompressedSrgb8Alpha8Astc4x4x4 = 0x93E3, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4x4_OES.
		CompressedSrgb8Alpha8Astc5x4x4 = 0x93E4, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4x4_OES.
		CompressedSrgb8Alpha8Astc5x5x4 = 0x93E5, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x4_OES.
		CompressedSrgb8Alpha8Astc5x5x5 = 0x93E6, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5x5_OES.
		CompressedSrgb8Alpha8Astc6x5x5 = 0x93E7, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5x5_OES.
		CompressedSrgb8Alpha8Astc6x6x5 = 0x93E8, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x5_OES.
		CompressedSrgb8Alpha8Astc6x6x6 = 0x93E9, // GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6x6_OES.
	};

	// StencilFaceDirection; bitmask: False.
	enum class StencilFaceDirection : uint32_t
	{
		Front = 0x0404, // GL_FRONT.
		Back = 0x0405, // GL_BACK.
		FrontAndBack = 0x0408, // GL_FRONT_AND_BACK.
	};

	// StencilFunction; bitmask: False.
	enum class StencilFunction : uint32_t
	{
		Never = 0x0200, // GL_NEVER.
		Less = 0x0201, // GL_LESS.
		Equal = 0x0202, // GL_EQUAL.
		Lequal = 0x0203, // GL_LEQUAL.
		Greater = 0x0204, // GL_GREATER.
		Notequal = 0x0205, // GL_NOTEQUAL.
		Gequal = 0x0206, // GL_GEQUAL.
		Always = 0x0207, // GL_ALWAYS.
	};

	// StencilOp; bitmask: False.
	enum class StencilOp : uint32_t
	{
		Zero = 0, // GL_ZERO.
		Invert = 0x150A, // GL_INVERT.
		Keep = 0x1E00, // GL_KEEP.
		Replace = 0x1E01, // GL_REPLACE.
		Incr = 0x1E02, // GL_INCR.
		Decr = 0x1E03, // GL_DECR.
		IncrWrap = 0x8507, // GL_INCR_WRAP.
		DecrWrap = 0x8508, // GL_DECR_WRAP.
	};

	// StringName; bitmask: False.
	enum class StringName : uint32_t
	{
		Vendor = 0x1F00, // GL_VENDOR.
		Renderer = 0x1F01, // GL_RENDERER.
		Version = 0x1F02, // GL_VERSION.
		Extensions = 0x1F03, // GL_EXTENSIONS.
		ShadingLanguageVersion = 0x8B8C, // GL_SHADING_LANGUAGE_VERSION.
	};

	// SubroutineParameterName; bitmask: False.
	enum class SubroutineParameterName : uint32_t
	{
		UniformSize = 0x8A38, // GL_UNIFORM_SIZE.
		UniformNameLength = 0x8A39, // GL_UNIFORM_NAME_LENGTH.
	};

	// SyncBehaviorFlags; bitmask: False.
	enum class SyncBehaviorFlags : uint32_t
	{
		None = 0, // GL_NONE.
	};

	// SyncCondition; bitmask: False.
	enum class SyncCondition : uint32_t
	{
		SyncGpuCommandsComplete = 0x9117, // GL_SYNC_GPU_COMMANDS_COMPLETE.
	};

	// SyncObjectMask; bitmask: True.
	enum class SyncObject : uint32_t
	{
		SyncFlushCommands = 0x00000001, // GL_SYNC_FLUSH_COMMANDS_BIT.
	};

	// SyncParameterName; bitmask: False.
	enum class SyncParameterName : uint32_t
	{
		ObjectType = 0x9112, // GL_OBJECT_TYPE.
		SyncCondition = 0x9113, // GL_SYNC_CONDITION.
		SyncStatus = 0x9114, // GL_SYNC_STATUS.
		SyncFlags = 0x9115, // GL_SYNC_FLAGS.
	};

	// SyncStatus; bitmask: False.
	enum class SyncStatus : uint32_t
	{
		AlreadySignaled = 0x911A, // GL_ALREADY_SIGNALED.
		TimeoutExpired = 0x911B, // GL_TIMEOUT_EXPIRED.
		ConditionSatisfied = 0x911C, // GL_CONDITION_SATISFIED.
		WaitFailed = 0x911D, // GL_WAIT_FAILED.
	};

	// TangentPointerTypeEXT; bitmask: False.
	enum class TangentPointerTypeEXT : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// TexCoordPointerType; bitmask: False.
	enum class TexCoordPointerType : uint32_t
	{
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// TextureCompareMode; bitmask: False.
	enum class TextureCompareMode : uint32_t
	{
		None = 0, // GL_NONE.
		CompareRefToTexture = 0x884E, // GL_COMPARE_REF_TO_TEXTURE.
	};

	// TextureEnvMode; bitmask: False.
	enum class TextureEnvMode : uint32_t
	{
		Blend = 0x0BE2, // GL_BLEND.
	};

	// TextureMagFilter; bitmask: False.
	enum class TextureMagFilter : uint32_t
	{
		Nearest = 0x2600, // GL_NEAREST.
		Linear = 0x2601, // GL_LINEAR.
	};

	// TextureMinFilter; bitmask: False.
	enum class TextureMinFilter : uint32_t
	{
		Nearest = 0x2600, // GL_NEAREST.
		Linear = 0x2601, // GL_LINEAR.
		NearestMipmapNearest = 0x2700, // GL_NEAREST_MIPMAP_NEAREST.
		LinearMipmapNearest = 0x2701, // GL_LINEAR_MIPMAP_NEAREST.
		NearestMipmapLinear = 0x2702, // GL_NEAREST_MIPMAP_LINEAR.
		LinearMipmapLinear = 0x2703, // GL_LINEAR_MIPMAP_LINEAR.
	};

	// TextureParameterName; bitmask: False.
	enum class TextureParameterName : uint32_t
	{
		TextureBorderColor = 0x1004, // GL_TEXTURE_BORDER_COLOR_NV.
		TextureMagFilter = 0x2800, // GL_TEXTURE_MAG_FILTER.
		TextureMinFilter = 0x2801, // GL_TEXTURE_MIN_FILTER.
		TextureWrapS = 0x2802, // GL_TEXTURE_WRAP_S.
		TextureWrapT = 0x2803, // GL_TEXTURE_WRAP_T.
		TextureWrapR = 0x8072, // GL_TEXTURE_WRAP_R.
		TextureMinLod = 0x813A, // GL_TEXTURE_MIN_LOD.
		TextureMaxLod = 0x813B, // GL_TEXTURE_MAX_LOD.
		TextureBaseLevel = 0x813C, // GL_TEXTURE_BASE_LEVEL.
		TextureMaxLevel = 0x813D, // GL_TEXTURE_MAX_LEVEL.
		TextureCompareMode = 0x884C, // GL_TEXTURE_COMPARE_MODE.
		TextureCompareFunc = 0x884D, // GL_TEXTURE_COMPARE_FUNC.
		TextureSwizzleR = 0x8E42, // GL_TEXTURE_SWIZZLE_R.
		TextureSwizzleG = 0x8E43, // GL_TEXTURE_SWIZZLE_G.
		TextureSwizzleB = 0x8E44, // GL_TEXTURE_SWIZZLE_B.
		TextureSwizzleA = 0x8E45, // GL_TEXTURE_SWIZZLE_A.
		TextureUnnormalizedCoordinatesArm = 0x8F6A, // GL_TEXTURE_UNNORMALIZED_COORDINATES_ARM.
		TextureTiling = 0x9580, // GL_TEXTURE_TILING_EXT.
		TextureFoveatedCutoffDensity = 0x96A0, // GL_TEXTURE_FOVEATED_CUTOFF_DENSITY_QCOM.
	};

	// TextureSwizzle; bitmask: False.
	enum class TextureSwizzle : uint32_t
	{
		Zero = 0, // GL_ZERO.
		One = 1, // GL_ONE.
		Red = 0x1903, // GL_RED.
		Green = 0x1904, // GL_GREEN.
		Blue = 0x1905, // GL_BLUE.
		Alpha = 0x1906, // GL_ALPHA.
	};

	// TextureTarget; bitmask: False.
	enum class TextureTarget : uint32_t
	{
		Texture2d = 0x0DE1, // GL_TEXTURE_2D.
		Texture3d = 0x806F, // GL_TEXTURE_3D.
		TextureCubeMap = 0x8513, // GL_TEXTURE_CUBE_MAP.
		TextureCubeMapPositiveX = 0x8515, // GL_TEXTURE_CUBE_MAP_POSITIVE_X.
		TextureCubeMapNegativeX = 0x8516, // GL_TEXTURE_CUBE_MAP_NEGATIVE_X.
		TextureCubeMapPositiveY = 0x8517, // GL_TEXTURE_CUBE_MAP_POSITIVE_Y.
		TextureCubeMapNegativeY = 0x8518, // GL_TEXTURE_CUBE_MAP_NEGATIVE_Y.
		TextureCubeMapPositiveZ = 0x8519, // GL_TEXTURE_CUBE_MAP_POSITIVE_Z.
		TextureCubeMapNegativeZ = 0x851A, // GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.
		Texture2dArray = 0x8C1A, // GL_TEXTURE_2D_ARRAY.
		Renderbuffer = 0x8D41, // GL_RENDERBUFFER.
		TextureCubeMapArray = 0x9009, // GL_TEXTURE_CUBE_MAP_ARRAY_OES.
		Texture2dMultisample = 0x9100, // GL_TEXTURE_2D_MULTISAMPLE.
		Texture2dMultisampleArray = 0x9102, // GL_TEXTURE_2D_MULTISAMPLE_ARRAY.
	};

	// TextureUnit; bitmask: False.
	enum class TextureUnit : uint32_t
	{
		Texture0 = 0x84C0, // GL_TEXTURE0.
		Texture1 = 0x84C1, // GL_TEXTURE1.
		Texture2 = 0x84C2, // GL_TEXTURE2.
		Texture3 = 0x84C3, // GL_TEXTURE3.
		Texture4 = 0x84C4, // GL_TEXTURE4.
		Texture5 = 0x84C5, // GL_TEXTURE5.
		Texture6 = 0x84C6, // GL_TEXTURE6.
		Texture7 = 0x84C7, // GL_TEXTURE7.
		Texture8 = 0x84C8, // GL_TEXTURE8.
		Texture9 = 0x84C9, // GL_TEXTURE9.
		Texture10 = 0x84CA, // GL_TEXTURE10.
		Texture11 = 0x84CB, // GL_TEXTURE11.
		Texture12 = 0x84CC, // GL_TEXTURE12.
		Texture13 = 0x84CD, // GL_TEXTURE13.
		Texture14 = 0x84CE, // GL_TEXTURE14.
		Texture15 = 0x84CF, // GL_TEXTURE15.
		Texture16 = 0x84D0, // GL_TEXTURE16.
		Texture17 = 0x84D1, // GL_TEXTURE17.
		Texture18 = 0x84D2, // GL_TEXTURE18.
		Texture19 = 0x84D3, // GL_TEXTURE19.
		Texture20 = 0x84D4, // GL_TEXTURE20.
		Texture21 = 0x84D5, // GL_TEXTURE21.
		Texture22 = 0x84D6, // GL_TEXTURE22.
		Texture23 = 0x84D7, // GL_TEXTURE23.
		Texture24 = 0x84D8, // GL_TEXTURE24.
		Texture25 = 0x84D9, // GL_TEXTURE25.
		Texture26 = 0x84DA, // GL_TEXTURE26.
		Texture27 = 0x84DB, // GL_TEXTURE27.
		Texture28 = 0x84DC, // GL_TEXTURE28.
		Texture29 = 0x84DD, // GL_TEXTURE29.
		Texture30 = 0x84DE, // GL_TEXTURE30.
		Texture31 = 0x84DF, // GL_TEXTURE31.
	};

	// TextureWrapMode; bitmask: False.
	enum class TextureWrapMode : uint32_t
	{
		LinearMipmapLinear = 0x2703, // GL_LINEAR_MIPMAP_LINEAR.
		Repeat = 0x2901, // GL_REPEAT.
		ClampToBorder = 0x812D, // GL_CLAMP_TO_BORDER_NV.
		ClampToEdge = 0x812F, // GL_CLAMP_TO_EDGE.
		MirroredRepeat = 0x8370, // GL_MIRRORED_REPEAT.
	};

	// TransformFeedbackBufferMode; bitmask: False.
	enum class TransformFeedbackBufferMode : uint32_t
	{
		InterleavedAttribs = 0x8C8C, // GL_INTERLEAVED_ATTRIBS.
		SeparateAttribs = 0x8C8D, // GL_SEPARATE_ATTRIBS.
	};

	// TransformFeedbackPName; bitmask: False.
	enum class TransformFeedbackPName : uint32_t
	{
		TransformFeedbackBufferStart = 0x8C84, // GL_TRANSFORM_FEEDBACK_BUFFER_START.
		TransformFeedbackBufferSize = 0x8C85, // GL_TRANSFORM_FEEDBACK_BUFFER_SIZE.
		TransformFeedbackBufferBinding = 0x8C8F, // GL_TRANSFORM_FEEDBACK_BUFFER_BINDING.
		TransformFeedbackPaused = 0x8E23, // GL_TRANSFORM_FEEDBACK_PAUSED.
		TransformFeedbackActive = 0x8E24, // GL_TRANSFORM_FEEDBACK_ACTIVE.
	};

	// UniformBlockPName; bitmask: False.
	enum class UniformBlockPName : uint32_t
	{
		UniformBlockBinding = 0x8A3F, // GL_UNIFORM_BLOCK_BINDING.
		UniformBlockDataSize = 0x8A40, // GL_UNIFORM_BLOCK_DATA_SIZE.
		UniformBlockNameLength = 0x8A41, // GL_UNIFORM_BLOCK_NAME_LENGTH.
		UniformBlockActiveUniforms = 0x8A42, // GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS.
		UniformBlockActiveUniformIndices = 0x8A43, // GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES.
		UniformBlockReferencedByVertexShader = 0x8A44, // GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER.
		UniformBlockReferencedByFragmentShader = 0x8A46, // GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER.
	};

	// UniformPName; bitmask: False.
	enum class UniformPName : uint32_t
	{
		UniformType = 0x8A37, // GL_UNIFORM_TYPE.
		UniformSize = 0x8A38, // GL_UNIFORM_SIZE.
		UniformNameLength = 0x8A39, // GL_UNIFORM_NAME_LENGTH.
		UniformBlockIndex = 0x8A3A, // GL_UNIFORM_BLOCK_INDEX.
		UniformOffset = 0x8A3B, // GL_UNIFORM_OFFSET.
		UniformArrayStride = 0x8A3C, // GL_UNIFORM_ARRAY_STRIDE.
		UniformMatrixStride = 0x8A3D, // GL_UNIFORM_MATRIX_STRIDE.
		UniformIsRowMajor = 0x8A3E, // GL_UNIFORM_IS_ROW_MAJOR.
	};

	// UniformType; bitmask: False.
	enum class UniformType : uint32_t
	{
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
		FloatVec2 = 0x8B50, // GL_FLOAT_VEC2.
		FloatVec3 = 0x8B51, // GL_FLOAT_VEC3.
		FloatVec4 = 0x8B52, // GL_FLOAT_VEC4.
		IntVec2 = 0x8B53, // GL_INT_VEC2.
		IntVec3 = 0x8B54, // GL_INT_VEC3.
		IntVec4 = 0x8B55, // GL_INT_VEC4.
		Bool = 0x8B56, // GL_BOOL.
		BoolVec2 = 0x8B57, // GL_BOOL_VEC2.
		BoolVec3 = 0x8B58, // GL_BOOL_VEC3.
		BoolVec4 = 0x8B59, // GL_BOOL_VEC4.
		FloatMat2 = 0x8B5A, // GL_FLOAT_MAT2.
		FloatMat3 = 0x8B5B, // GL_FLOAT_MAT3.
		FloatMat4 = 0x8B5C, // GL_FLOAT_MAT4.
		Sampler2d = 0x8B5E, // GL_SAMPLER_2D.
		Sampler3d = 0x8B5F, // GL_SAMPLER_3D.
		SamplerCube = 0x8B60, // GL_SAMPLER_CUBE.
		Sampler2dShadow = 0x8B62, // GL_SAMPLER_2D_SHADOW.
		FloatMat2x3 = 0x8B65, // GL_FLOAT_MAT2x3.
		FloatMat2x4 = 0x8B66, // GL_FLOAT_MAT2x4.
		FloatMat3x2 = 0x8B67, // GL_FLOAT_MAT3x2.
		FloatMat3x4 = 0x8B68, // GL_FLOAT_MAT3x4.
		FloatMat4x2 = 0x8B69, // GL_FLOAT_MAT4x2.
		FloatMat4x3 = 0x8B6A, // GL_FLOAT_MAT4x3.
		Sampler2dArray = 0x8DC1, // GL_SAMPLER_2D_ARRAY.
		Sampler2dArrayShadow = 0x8DC4, // GL_SAMPLER_2D_ARRAY_SHADOW.
		SamplerCubeShadow = 0x8DC5, // GL_SAMPLER_CUBE_SHADOW.
		UnsignedIntVec2 = 0x8DC6, // GL_UNSIGNED_INT_VEC2.
		UnsignedIntVec3 = 0x8DC7, // GL_UNSIGNED_INT_VEC3.
		UnsignedIntVec4 = 0x8DC8, // GL_UNSIGNED_INT_VEC4.
		IntSampler2d = 0x8DCA, // GL_INT_SAMPLER_2D.
		IntSampler3d = 0x8DCB, // GL_INT_SAMPLER_3D.
		IntSamplerCube = 0x8DCC, // GL_INT_SAMPLER_CUBE.
		IntSampler2dArray = 0x8DCF, // GL_INT_SAMPLER_2D_ARRAY.
		UnsignedIntSampler2d = 0x8DD2, // GL_UNSIGNED_INT_SAMPLER_2D.
		UnsignedIntSampler3d = 0x8DD3, // GL_UNSIGNED_INT_SAMPLER_3D.
		UnsignedIntSamplerCube = 0x8DD4, // GL_UNSIGNED_INT_SAMPLER_CUBE.
		UnsignedIntSampler2dArray = 0x8DD7, // GL_UNSIGNED_INT_SAMPLER_2D_ARRAY.
	};

	// VertexArrayPName; bitmask: False.
	enum class VertexArrayPName : uint32_t
	{
		VertexAttribArrayEnabled = 0x8622, // GL_VERTEX_ATTRIB_ARRAY_ENABLED.
		VertexAttribArraySize = 0x8623, // GL_VERTEX_ATTRIB_ARRAY_SIZE.
		VertexAttribArrayStride = 0x8624, // GL_VERTEX_ATTRIB_ARRAY_STRIDE.
		VertexAttribArrayType = 0x8625, // GL_VERTEX_ATTRIB_ARRAY_TYPE.
		VertexAttribArrayNormalized = 0x886A, // GL_VERTEX_ATTRIB_ARRAY_NORMALIZED.
		VertexAttribArrayInteger = 0x88FD, // GL_VERTEX_ATTRIB_ARRAY_INTEGER.
		VertexAttribArrayDivisor = 0x88FE, // GL_VERTEX_ATTRIB_ARRAY_DIVISOR.
	};

	// VertexAttribEnum; bitmask: False.
	enum class VertexAttribEnum : uint32_t
	{
		VertexAttribArrayEnabled = 0x8622, // GL_VERTEX_ATTRIB_ARRAY_ENABLED.
		VertexAttribArraySize = 0x8623, // GL_VERTEX_ATTRIB_ARRAY_SIZE.
		VertexAttribArrayStride = 0x8624, // GL_VERTEX_ATTRIB_ARRAY_STRIDE.
		VertexAttribArrayType = 0x8625, // GL_VERTEX_ATTRIB_ARRAY_TYPE.
		CurrentVertexAttrib = 0x8626, // GL_CURRENT_VERTEX_ATTRIB.
		VertexAttribArrayNormalized = 0x886A, // GL_VERTEX_ATTRIB_ARRAY_NORMALIZED.
		VertexAttribArrayBufferBinding = 0x889F, // GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING.
		VertexAttribArrayInteger = 0x88FD, // GL_VERTEX_ATTRIB_ARRAY_INTEGER.
		VertexAttribArrayDivisor = 0x88FE, // GL_VERTEX_ATTRIB_ARRAY_DIVISOR.
	};

	// VertexAttribIType; bitmask: False.
	enum class VertexAttribIType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		Short = 0x1402, // GL_SHORT.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
	};

	// VertexAttribPointerPropertyARB; bitmask: False.
	enum class VertexAttribPointerPropertyARB : uint32_t
	{
		VertexAttribArrayPointer = 0x8645, // GL_VERTEX_ATTRIB_ARRAY_POINTER.
	};

	// VertexAttribPointerType; bitmask: False.
	enum class VertexAttribPointerType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		Short = 0x1402, // GL_SHORT.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
		HalfFloat = 0x140B, // GL_HALF_FLOAT.
		Fixed = 0x140C, // GL_FIXED.
		Int64 = 0x140E, // GL_INT64_NV.
		UnsignedInt64 = 0x140F, // GL_UNSIGNED_INT64_NV.
		UnsignedInt2101010Rev = 0x8368, // GL_UNSIGNED_INT_2_10_10_10_REV.
		UnsignedInt10f11f11fRev = 0x8C3B, // GL_UNSIGNED_INT_10F_11F_11F_REV.
		Int2101010Rev = 0x8D9F, // GL_INT_2_10_10_10_REV.
	};

	// VertexAttribPropertyARB; bitmask: False.
	enum class VertexAttribPropertyARB : uint32_t
	{
		VertexAttribArrayEnabled = 0x8622, // GL_VERTEX_ATTRIB_ARRAY_ENABLED.
		VertexAttribArraySize = 0x8623, // GL_VERTEX_ATTRIB_ARRAY_SIZE.
		VertexAttribArrayStride = 0x8624, // GL_VERTEX_ATTRIB_ARRAY_STRIDE.
		VertexAttribArrayType = 0x8625, // GL_VERTEX_ATTRIB_ARRAY_TYPE.
		CurrentVertexAttrib = 0x8626, // GL_CURRENT_VERTEX_ATTRIB.
		VertexAttribArrayNormalized = 0x886A, // GL_VERTEX_ATTRIB_ARRAY_NORMALIZED.
		VertexAttribArrayBufferBinding = 0x889F, // GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING.
		VertexAttribArrayInteger = 0x88FD, // GL_VERTEX_ATTRIB_ARRAY_INTEGER.
		VertexAttribArrayDivisor = 0x88FE, // GL_VERTEX_ATTRIB_ARRAY_DIVISOR.
	};

	// VertexAttribType; bitmask: False.
	enum class VertexAttribType : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		Short = 0x1402, // GL_SHORT.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
		HalfFloat = 0x140B, // GL_HALF_FLOAT.
		Fixed = 0x140C, // GL_FIXED.
		UnsignedInt2101010Rev = 0x8368, // GL_UNSIGNED_INT_2_10_10_10_REV.
		UnsignedInt10f11f11fRev = 0x8C3B, // GL_UNSIGNED_INT_10F_11F_11F_REV.
		Int2101010Rev = 0x8D9F, // GL_INT_2_10_10_10_REV.
	};

	// VertexBufferObjectParameter; bitmask: False.
	enum class VertexBufferObjectParameter : uint32_t
	{
		BufferSize = 0x8764, // GL_BUFFER_SIZE.
		BufferUsage = 0x8765, // GL_BUFFER_USAGE.
		BufferMapped = 0x88BC, // GL_BUFFER_MAPPED.
		BufferAccessFlags = 0x911F, // GL_BUFFER_ACCESS_FLAGS.
		BufferMapLength = 0x9120, // GL_BUFFER_MAP_LENGTH.
		BufferMapOffset = 0x9121, // GL_BUFFER_MAP_OFFSET.
	};

	// VertexBufferObjectUsage; bitmask: False.
	enum class VertexBufferObjectUsage : uint32_t
	{
		StreamDraw = 0x88E0, // GL_STREAM_DRAW.
		StreamRead = 0x88E1, // GL_STREAM_READ.
		StreamCopy = 0x88E2, // GL_STREAM_COPY.
		StaticDraw = 0x88E4, // GL_STATIC_DRAW.
		StaticRead = 0x88E5, // GL_STATIC_READ.
		StaticCopy = 0x88E6, // GL_STATIC_COPY.
		DynamicDraw = 0x88E8, // GL_DYNAMIC_DRAW.
		DynamicRead = 0x88E9, // GL_DYNAMIC_READ.
		DynamicCopy = 0x88EA, // GL_DYNAMIC_COPY.
	};

	// VertexPointerType; bitmask: False.
	enum class VertexPointerType : uint32_t
	{
		Short = 0x1402, // GL_SHORT.
		Int = 0x1404, // GL_INT.
		Float = 0x1406, // GL_FLOAT.
	};

	// VertexShaderWriteMaskEXT; bitmask: False.
	enum class VertexShaderWriteEXT : uint32_t
	{
		False = 0, // GL_FALSE.
		True = 1, // GL_TRUE.
	};

	// VertexWeightPointerTypeEXT; bitmask: False.
	enum class VertexWeightPointerTypeEXT : uint32_t
	{
		Float = 0x1406, // GL_FLOAT.
	};

	// WeightPointerTypeARB; bitmask: False.
	enum class WeightPointerTypeARB : uint32_t
	{
		Byte = 0x1400, // GL_BYTE.
		UnsignedByte = 0x1401, // GL_UNSIGNED_BYTE.
		Short = 0x1402, // GL_SHORT.
		UnsignedShort = 0x1403, // GL_UNSIGNED_SHORT.
		Int = 0x1404, // GL_INT.
		UnsignedInt = 0x1405, // GL_UNSIGNED_INT.
		Float = 0x1406, // GL_FLOAT.
	};

}
}
}
