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
		@brief	Platform-specific information of GPU hardware in terms of Windows Desktop platform.

		On Windows Desktop platform the handle is implemented via DXGI library.
		This type carries only description and ordinal index corresponded of `IDXGIAdapter` instance.

		Implements the second layer of platform-agnostic Adapter Handle type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlAdapterHandle<Black::PlatformType::WindowsDesktop> : public Internal::BasicGlAdapterHandle
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::AdapterHandleInformationConsumer::AdapterInfo;

	// Platform-specific interface.
	public:
		// Get the internal description of device.
		inline const ::DXGI_ADAPTER_DESC1& GetDescription() const	{ return m_description; };

		// Get the ordinal index of adapter.
		inline const size32_t GetIndex() const						{ return m_index; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		GlAdapterHandle()							= delete;
		GlAdapterHandle( const GlAdapterHandle& )	= default;
		GlAdapterHandle( GlAdapterHandle&& )		= default;
		explicit GlAdapterHandle( const ConstructionInfo& info );
		~GlAdapterHandle() = default;


		inline GlAdapterHandle& operator = ( const GlAdapterHandle& )	= default;
		inline GlAdapterHandle& operator = ( GlAdapterHandle&& )		= default;

	// Private state.
	private:
		::DXGI_ADAPTER_DESC1	m_description;			// Internal description of adapter.
		size32_t				m_index			= 0;	// Ordinal index of adapter.
	};
}
}
}
}
}
