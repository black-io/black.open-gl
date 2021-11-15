#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Handle of usable display device.

		This handle may be used to store the information about Display hardware in system.
		Handles are used to connect the EGL Display object with target GPU.

		Implements the final, third layer of platform-agnostic Display Handle type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlDisplayHandle final : public PlatformSpecific::GlDisplayHandle<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		GlDisplayHandle( const GlDisplayHandle& )	= default;
		GlDisplayHandle( GlDisplayHandle&& )		= default;
		explicit GlDisplayHandle( const ConstructionInfo& info );
		~GlDisplayHandle() = default;


		inline GlDisplayHandle& operator = ( const GlDisplayHandle& )	= default;
		inline GlDisplayHandle& operator = ( GlDisplayHandle&& )		= default;

	// Contracts of public API.
	public:

	// Public interface.
	public:

	};
}
}
}
