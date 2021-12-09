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
		@brief	Platform-specific implementation of Display Video mode in term of Windows Desktop platform.

		On Windows Desktop platform the Video Mode is implemented via DXGI library.
		This type carries only the description and the most basic metrics.

		Implements the second layer of platform-agnostic Display Video Mode type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlDisplayVideoMode<Black::PlatformType::WindowsDesktop> : public Internal::BasicGlDisplayVideoMode
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::DisplayVideoModeInformationConsumer::VideoModeInfo;

	// Platform-specific interface.
	public:
		// Get the ordinal index of adapter.
		inline const size32_t GetIndex() const	{ return m_index; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		using BasicGlDisplayVideoMode::BasicGlDisplayVideoMode;
		explicit GlDisplayVideoMode( const ConstructionInfo& info );
		~GlDisplayVideoMode() = default;

	// Heirs interface.
	protected:
		// Swap the state with given instance.
		void Swap( GlDisplayVideoMode<Black::PlatformType::WindowsDesktop>& other );

	// Private state.
	private:
		size32_t m_index = 0; // Ordinal index of adapter.
	};
}
}
}
}
