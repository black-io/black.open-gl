#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Platform
{
	/**
		@brief	Implementation of RHI for display device.

		Implements the final, third layer of platform-agnostic display type.
		This type is public and may be freely used outside of subsystem.
	*/
	class RhiDisplay final : public PlatformSpecific::RhiDisplay<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		RhiDisplay( const RhiDisplay& ) = default;
		explicit RhiDisplay( const ConstructionArguments& arguments );
		~RhiDisplay() = default;

	// Contracts of public API.
	public:
		/// @see	RhiDisplay::GetIndex
		using PlatformSpecific::RhiDisplay<Black::BUILD_PLATFORM>::GetIndex;

	// Public interface.
	public:

	};
}
}
}
