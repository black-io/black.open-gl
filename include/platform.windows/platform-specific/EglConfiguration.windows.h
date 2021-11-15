#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	/**
		@brief	Platform-specific implementation of EGL-compatible configuration in terms of Windows Desktop platform.

		On Windows desktop platform EGL configuration is emulated by pixel format descriptor.

		Implements the second layer of platform-agnostic EGL-compatible configuration type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglConfiguration<Black::PlatformType::WindowsDesktop> : public Internal::BasicEglConfiguration
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = std::tuple<::PIXELFORMATDESCRIPTOR, Internal::PixelBufferSettings, size32_t>;

	// Platform-specific interface.
	public:
		// Get the description of WGL pixel format.
		inline const ::PIXELFORMATDESCRIPTOR& GetDescription() const				{ return m_description; };

		// Get the settings for pixel buffers.
		inline const Internal::PixelBufferSettings& GetPixelBufferSettings() const	{ return m_pixel_buffer_settings; };

		// Get the ordinal index of WGL pixel format.
		inline const size32_t GetIndex() const										{ return m_index; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		EglConfiguration()							= delete;
		EglConfiguration( const EglConfiguration& )	= default;
		explicit EglConfiguration( const ConstructionInfo& info );
		~EglConfiguration() = default;

	// private state.
	private:
		::PIXELFORMATDESCRIPTOR			m_description;				// Description of pixel format.
		Internal::PixelBufferSettings	m_pixel_buffer_settings;	// Pixel buffer settings for this format.
		size32_t						m_index;					// Ordinal number of configuration.
	};
}
}
}
}
