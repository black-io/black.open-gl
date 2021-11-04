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
	class RhiAdapter final : public PlatformSpecific::RhiAdapter<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		RhiAdapter( const RhiAdapter& ) = default;
		explicit RhiAdapter( const ConstructionArguments& arguments );
		~RhiAdapter() = default;

	// Contracts of public API.
	public:
		/// @see	RhiAdapter::GetIndex
		using PlatformSpecific::RhiAdapter<Black::BUILD_PLATFORM>::GetIndex;

	// Public interface.
	public:

	};
}
}
}
