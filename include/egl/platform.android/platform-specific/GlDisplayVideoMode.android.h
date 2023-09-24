#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	/**
		@brief	Platform-specific implementation of Display Video mode in term of Android platform.

		Implements the second layer of platform-agnostic Display Video Mode type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlDisplayVideoMode<Black::PlatformType::Android> : public Internal::BasicGlDisplayVideoMode
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
		GlDisplayVideoMode()							= default;
		GlDisplayVideoMode( const GlDisplayVideoMode& )	= default;
		GlDisplayVideoMode( GlDisplayVideoMode&& )		= default;
		explicit GlDisplayVideoMode( const ConstructionInfo& info );
		~GlDisplayVideoMode() = default;


		inline GlDisplayVideoMode& operator = ( const GlDisplayVideoMode& )	= default;
		inline GlDisplayVideoMode& operator = ( GlDisplayVideoMode&& )		= default;

	// Heirs interface.
	protected:
		// Swap the state with given instance.
		void Swap( GlDisplayVideoMode<Black::PlatformType::Android>& other );

	// Private state.
	private:
		::Jni::PixelFormatCode	m_pixel_format	= ::Jni::PixelFormatCode::Unknon;	// Used pixel format.

		size32_t				m_index			= 0;								// Ordinal index of adapter.
	};
}
}
}
}
}
