#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Implementation of RHI for GPU adapter device.

		Implements the final, third layer of platform-agnostic GPU adapter type.
		This type is public and may be freely used outside of subsystem.
	*/
	class GlRhiAdapter final : public PlatformSpecific::GlRhiAdapter<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		GlRhiAdapter( const GlRhiAdapter& ) = default;
		explicit GlRhiAdapter( const ConstructionInfo& info );
		~GlRhiAdapter() = default;

	// Contracts of public API.
	public:
		/// @see	GlRhiAdapter::GetIndex
		using PlatformSpecific::GlRhiAdapter<Black::BUILD_PLATFORM>::GetIndex;

	// Public interface.
	public:

	};
}
}
}
