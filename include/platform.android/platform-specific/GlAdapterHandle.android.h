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
		@brief	Platform-specific information of GPU hardware in terms of Android platform.

		Implements the second layer of platform-agnostic Adapter Handle type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	template<>
	class GlAdapterHandle<Black::PlatformType::Android> : public Internal::BasicGlAdapterHandle
	{
	// Public inner types.
	public:
		// Information for instance construction.
		using ConstructionInfo = Internal::AdapterHandleInformationConsumer::AdapterInfo;

	// Platform-specific interface.
	public:
		// Get the ordinal index of adapter.
		inline const size32_t GetIndex() const	{ return m_index; };

	// Platform-agnostic interface.
	public:

	// Heirs construction and initialization.
	protected:
		GlAdapterHandle()							= delete;
		GlAdapterHandle( const GlAdapterHandle& )	= default;
		GlAdapterHandle( GlAdapterHandle&& )		= default;
		explicit GlAdapterHandle( const ConstructionInfo& info );
		~GlAdapterHandle() = default;

	// Private state.
	private:
		size32_t m_index = 0; // Ordinal index of adapter.
	};
}
}
}
}
