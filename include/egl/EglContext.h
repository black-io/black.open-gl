#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
	/**
		@brief	EGL-compatible context object.

		Implements the final, third layer of platform-agnostic EGL Context type.
		This type is public and may be freely used outside of subsystem.
	*/
	class EglContext final : public PlatformSpecific::EglContext<Black::BUILD_PLATFORM>
	{
	// Construction and initialization.
	public:
		EglContext() = default;
		~EglContext();

	// Contracts of public API.
	public:
		/// @see	EglContext::GetThreadId
		using PlatformSpecific::EglContext<Black::BUILD_PLATFORM>::GetThreadId;

		/// @see	EglContext::IsCurrent
		using PlatformSpecific::EglContext<Black::BUILD_PLATFORM>::IsCurrent;

		/// @see	EglContext::IsCurrentForThisThread
		using PlatformSpecific::EglContext<Black::BUILD_PLATFORM>::IsCurrentForThisThread;

		/// @see	EglContext::Finalize
		using PlatformSpecific::EglContext<Black::BUILD_PLATFORM>::Finalize;

		/// @see	EglContext::MakeCurrent
		using PlatformSpecific::EglContext<Black::BUILD_PLATFORM>::MakeCurrent;

		/// @see	EglContext::IsConnected
		using PlatformSpecific::EglContext<Black::BUILD_PLATFORM>::IsConnected;

	// Public interface.
	public:
		// Use the settings of given context.
		const bool UseSettings( const EglContext& other );


		// Set the context version. The function may be used only before connection.
		const bool SetVersion( const int32_t major_version, const int32_t minor_version );

		// Select the API profile. The function may be used only before connection.
		const bool SelectApiProfile( const ApiProfile profile );

		// Set the context debugging. The function may be used only before connection.
		const bool SetDebugging( const bool should_debug );

		// Allow the context to be connected with ahead version that requested. The function may be used only before connection.
		const bool SetForwardVersiosCompatible( const bool allow_forward_versions );


		// Get the major version of context.
		inline const int32_t GetMajorVersion() const		{ return m_major_version; };

		// Get the minor version of context.
		inline const int32_t SetMinorVersion() const		{ return m_minor_version; };

		// Get selected API profile.
		inline const ApiProfile GetApiProfile() const		{ return m_api_profile; };

		// Whether the context is debuggable.
		inline const bool IsDebuggable() const				{ return m_is_debugable; };

		// Whether the context is allowed to be created with any ahead version than requested.
		inline const bool AllowForwardVersions() const		{ return m_is_forward_compatible; };
	};
}
}
}
