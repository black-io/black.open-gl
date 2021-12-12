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
		@brief	Platform-specific implementation of EGL-compatible configuration in terms of Android platform.

		This implementation directly uses the EGL API. It represents the `EGLConfig` type.

		Implements the second layer of platform-agnostic EGL-compatible configuration type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class EglConfiguration<Black::PlatformType::Android> : public Internal::BasicEglConfiguration
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = std::tuple<::EGLDisplay, ::EGLConfig, size32_t>;

	// Platform-specific interface.
	public:
		// Get the corresponded EGL display.
		inline ::EGLDisplay GetDisplayHandle() const							{ return m_display_handle; };

		// Get the corresponded EGL configuration.
		inline const ::EGLConfig GetHandle() const								{ return m_handle; };

		// Get the ordinal index of WGL pixel format.
		inline const size32_t GetIndex() const									{ return m_index; };

		// Get the properties of this configuration.
		inline const Internal::ConfigurationProperties& GetProperties() const	{ return m_properties; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		EglConfiguration()							= delete;
		EglConfiguration( const EglConfiguration& )	= default;
		explicit EglConfiguration( const ConstructionInfo& info );
		~EglConfiguration() = default;

	// Private interface.
	private:
		// Perform the reading of configuration properties.
		void ReadProperties();

	// private state.
	private:
		::EGLDisplay	m_display_handle	= EGL_NO_DISPLAY;	// Corresponded EGL display.
		::EGLConfig		m_handle			= {};				// Corresponded EGL configuration.
		size32_t		m_index				= 0;				// Ordinal number of configuration.

		Internal::ConfigurationProperties m_properties;			// Properties of stored configuration.
	};
}
}
}
}
