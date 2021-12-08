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
		@brief	Platform-specific information of Display hardware in terms of Android platform.

		Implements the second layer of platform-agnostic Display Handle type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlDisplayHandle<Black::PlatformType::Android> : public Internal::BasicGlDisplayHandle
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::DisplayHandleInformationConsumer::DisplayInfo;

	// Platform-specific interface.
	public:
		// Get the ordinal index of display.
		inline const size32_t GetIndex() const			{ return m_index; };

		// Get the ordinal index of GPU adapter, where the display is connected.
		inline const size32_t GetAdapterIndex() const	{ return m_adapter_index; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		GlDisplayHandle()							= delete;
		GlDisplayHandle( const GlDisplayHandle& )	= default;
		GlDisplayHandle( GlDisplayHandle&& )		= default;
		explicit GlDisplayHandle( const ConstructionInfo& info );
		~GlDisplayHandle() = default;

	// Private state.
	private:
		size32_t	m_adapter_index;	// Ordinal index of GPU adapter the display connected.
		size32_t	m_index;			// Ordinal index of display.
	};
}
}
}
}
