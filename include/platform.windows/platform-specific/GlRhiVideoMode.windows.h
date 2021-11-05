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
		@brief	Platform dependent display video mode implementation.

		On Windows Desktop platform the RHI to display video mode is implemented via DXGI library.
		This type carries only the description and the most basic metrics of display video mode.

		Implements the second layer of platform-agnostic display video mode type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlRhiVideoMode<Black::PlatformType::WindowsDesktop> : public Internal::BasicRhiVideoMode
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::RhiVideoModeInformationConsumer::VideoModeInfo;

	// Platform-specific interface.
	public:
		// Get the internal description of video mode.
		inline const ::DXGI_MODE_DESC& GetModeDescription() const	{ return m_mode_desc; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		using BasicRhiVideoMode::BasicRhiVideoMode;
		explicit GlRhiVideoMode( const ConstructionInfo& info );
		~GlRhiVideoMode() = default;

	// Heirs interface.
	protected:
		// Swap the state with given instance.
		void Swap( GlRhiVideoMode<Black::PlatformType::WindowsDesktop>& other );

	// Private state.
	private:
		::DXGI_MODE_DESC m_mode_desc; // Internal description of video mode.
	};
}
}
}
}
