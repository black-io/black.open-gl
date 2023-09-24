#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace Internal
{
	/**
		@brief	Basic implementation of EGL-compatible context object.

		This type implements the first layer of platform-agnostic EGL Context type.
		This type is strictly internal and should never been used outside of subsystem.
	*/
	class BasicEglContext : private Black::NonTransferable
	{
	// Public inner types.
	public:
		// Supported API profiles.
		using ApiProfile = ContextApiProfile;

	// Public interface.
	public:
		// Get the thread Id, where the context is current. Empty thread Id will be returned for context is not current for any thread.
		inline const std::thread::id GetThreadId() const	{ return ( m_is_current )? m_current_thread_id : std::thread::id{}; };

		// Whether the context is current for any thread.
		inline const bool IsCurrent() const					{ return m_is_current; };

		// Whether the context is current for current thread.
		inline const bool IsCurrentForThisThread() const	{ return m_is_current && ( m_current_thread_id == std::this_thread::get_id() ); };

	// Heirs construction and initialization.
	protected:
		BasicEglContext()	= default;
		~BasicEglContext()	= default;

	// Heirs state.
	protected:
		std::thread::id	m_current_thread_id		{};						// Thread ID, where the context is current.

		int32_t			m_major_version			= 0;					// Major version of connected context.
		int32_t			m_minor_version			= 0;					// Minor version of connected context.
		ApiProfile		m_api_profile			= ApiProfile::OpenGl;	// Used API profile.

		union
		{
			uint32_t	m_boolean_bits			= 0;					// Blob for boolean values.

			struct
			{
				bool	m_is_current			: 1;					// Whether the context is set current for any thread.
				bool	m_is_debugable			: 1;					// Whether the context is created with debugging layer.
				bool	m_is_forward_compatible	: 1;					// Whether the context may be created with more high version than requested.
			};
		};
	};
}
}
}
}
}
