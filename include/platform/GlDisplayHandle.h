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
	class GlRhiDisplay final : public PlatformSpecific::GlRhiDisplay<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		GlRhiDisplay( const GlRhiDisplay& ) = default;
		explicit GlRhiDisplay( const ConstructionInfo& info );
		~GlRhiDisplay() = default;

	// Contracts of public API.
	public:
		/// @see	GlRhiDisplay::GetIndex
		using PlatformSpecific::GlRhiDisplay<Black::BUILD_PLATFORM>::GetIndex;

	// Public interface.
	public:

	};
}
}
}
