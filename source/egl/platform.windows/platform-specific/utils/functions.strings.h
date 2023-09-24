#pragma once


namespace Black
{
inline namespace OpenGl
{
inline namespace Egl
{
inline namespace Platform
{
namespace PlatformSpecific
{
	// Wrap for WinAPI function that hides the constant arguments.
	inline const size_t WideCharToMultiByte( const Black::PlainView<char> output_buffer, const std::wstring_view input_buffer )
	{
		return ::WideCharToMultiByte(
			CP_UTF8,
			WC_NO_BEST_FIT_CHARS,
			input_buffer.data(),
			int32_t( input_buffer.size() ),
			output_buffer.data(),
			int32_t( output_buffer.size() ),
			nullptr,
			nullptr
		);
	}

	// Perform the conversion from wide string to multi-byte one.
	inline std::string ConvertWideString( const std::wstring_view wide_string )
	{
		std::string result;

		const size_t result_length = WideCharToMultiByte( {}, wide_string );
		result.resize( result_length, 'X' );
		const size_t converted_length = WideCharToMultiByte( { result.data(), result_length }, wide_string );

		EXPECTS_DEBUG( converted_length > 0 );
		EXPECTS_DEBUG( converted_length == result_length );

		return result;
	}
}
}
}
}
}
