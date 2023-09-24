#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Handle of usable GPU adapter.

		This handle may be used to store the information about GPU hardware in system.
		Handles are used to connect the EGL Display object with target GPU.

		Implements the final, third layer of platform-agnostic Adapter Handle type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlAdapterHandle final : public PlatformSpecific::GlAdapterHandle<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		GlAdapterHandle( const GlAdapterHandle& )	= default;
		GlAdapterHandle( GlAdapterHandle&& )		= default;
		explicit GlAdapterHandle( const ConstructionInfo& info );
		~GlAdapterHandle() = default;


		inline GlAdapterHandle& operator = ( const GlAdapterHandle& )	= default;
		inline GlAdapterHandle& operator = ( GlAdapterHandle&& )		= default;

	// Contracts of public API.
	public:

	// Public interface.
	public:

	};
}
}
}
