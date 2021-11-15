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
		@brief	Platform dependent GPU adapter implementation in terms of windows desktop platform.

		On Windows Desktop platform the RHI to GPU adapter is implemented via DXGI library.
		This type carries only description and ordinal index corresponded of `IDXGIAdapter` instance.

		Implements the second layer of platform-agnostic GPU adapter type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlRhiAdapter<Black::PlatformType::WindowsDesktop> : public Internal::BasicGlRhiAdapter
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::RhiAdapterInformationConsumer::AdapterInfo;

	// Platform-specific interface.
	public:
		// Get the internal description of device.
		inline const ::DXGI_ADAPTER_DESC1& GetDescription() const	{ return m_description; };

	// Platform-agnostic interface.
	public:
		// Get the ordinal index of adapter.
		inline const size32_t GetIndex() const						{ return m_index; };

	// Heirs construction and initialization.
	protected:
		GlRhiAdapter()						= delete;
		GlRhiAdapter( const GlRhiAdapter& )	= default;
		explicit GlRhiAdapter( const ConstructionInfo& info );
		~GlRhiAdapter() = default;

	// Private state.
	private:
		::DXGI_ADAPTER_DESC1	m_description;			// Internal description of adapter.
		size32_t				m_index			= 0;	// Ordinal index of adapter.
	};
}
}
}
}
