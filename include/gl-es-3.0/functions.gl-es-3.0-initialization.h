#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace GlEs30
{
	/**
		@brief	Ensure the OpenGL ES 3.0 subsystem initialized and ready to be used.

		Initialization is required since the OpenGL functions are not linked statically.
		Due to process of initialization the subsystem loads the core profile of OpenGL interface, making possible to work with only certain version of OpenGL.

		This function never fails, does not throw the errors and always succeeded. After the function is called it is true that the OpenGL functions may be used.
		But once the function failed, the entire process will be terminated.

		@param	connection	Instance of EGL connection to perform the possible initialization.
	*/
	void GlEnsureInitialized( const Black::EglConnection& connection );
}
}
}
