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
	class EglConfiguration<Black::PlatformType::WindowsDesktop> : public Internal::BasicEglConfiguration
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = std::tuple<::EGLDisplay, ::EGLConfig, size32_t>;

	// Platform-specific interface.
	public:
		//
		inline const ::EGLConfig GetDescription()		{ return m_config; };

		// Get the ordinal index of WGL pixel format.
		inline const size32_t GetIndex() const			{ return m_index; };

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
		::EGLDisplay	m_display;	// Corresponded EGL display.
		::EGLConfig		m_config;	// Corresponded EGL configuration.
		size32_t		m_index;	// Ordinal number of configuration.

		Internal::ConfigurationProperties m_properties; // Properties of stored configuration.
	};
}
}
}
}