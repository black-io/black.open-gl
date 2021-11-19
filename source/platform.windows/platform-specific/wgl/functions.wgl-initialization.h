#pragma once


namespace Wgl
{
	// Initialize the WGL interface for required display output device.
	const bool InitializeBindings( const Black::EglConnection& connection, const Black::EglDisplay& display );

	// Perform the core interface loading for WGL API.
	const bool LoadCoreProfile( const Black::EglConnection& connection );

	// Perform the loading of WGL extensions.
	const bool LoadExtensions( const Black::EglConnection& connection );
}
