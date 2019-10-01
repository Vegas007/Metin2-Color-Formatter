/*
*	__author__      : VegaS
*	__date__        : 2019-02-19
*	__version__     : 1.1
*	__description__ : https://github.com/Vegas007/Metin2-Color-Formatter
*/

#include "Stdafx.h"
#include "cff.h"
#include <boost/format.hpp>

namespace CFF
{
	/**
	* \brief Initialize the keys and values of color hex map.
	*/
	using TColorHexMapT = std::map<std::string, std::string>;
	static const TColorHexMapT m_ColorHexMap =
	{
		{ "green",       "#15FF00" },
		{ "blue",        "#00C5FF" },
		{ "banana",      "#E3CF57" },
		{ "chocolate",   "#D2691E" },
		{ "darkred",     "#8B0000" },
		{ "gray",        "#808080" },
		{ "red",         "#FF0000" },
		{ "skyblue",     "#87CEEB" },
		{ "slateblue",   "#6A5ACD" },
		{ "snow",        "#FFFAFA" },
		{ "springgreen", "#00FF7F" },
		{ "steelblue",   "#4682B4" },
		{ "white",       "#FFFFFF" },
		{ "yellow",      "#FFFF00" },
	};

	/**
	* \brief Initialize the flags.
	*/
	static const std::string stFlagsData[FLAG_MAX_NUM] = {"\n", "\t", " ", ""};
	
	/**
	* \brief Check if character is hexadecimal digit, hexadecimal digits are any of: 0123456789abcdefABCDEF
	* \param color
	* \return a boolean
	*/
	bool IsHexColor(const std::string & color)
	{
		auto const color_len = color.length();
		if (color_len != HEX_STRING_MAX_LEN)
			return false;

		auto chars_found = 0;
		for (auto const & c : color)
		{
			if (isxdigit(static_cast<unsigned char>(c)))
				++chars_found;
		}

		return color_len == chars_found;
	}

	/**
	* \brief Concatenate specific arguments into an string.
	* \param color
	* \param token
	* \param add_flag
	* \return a string
	*/
	std::string GetFormat(const std::string & color, const std::string & token, const uint8_t add_flag)
	{
		const boost::format fmt = boost::format("%s%s%s%s%s") % CFF_PATTERN_BEGIN % color.c_str() % token.c_str() % CFF_PATTERN_END % stFlagsData[add_flag].c_str();
		return fmt.str();
	}

	/**
	* \brief Get hexadecimal color by a specific name which is defined in @THexColorMapT or by the hexadecimal itself.
	* \param color
	* \return a string
	*/
	std::string GetColor(const std::string & color)
	{
		if (!color.empty())
		{
			if (color[0] == '#')
			{
				auto const colorHexString = color.substr(1, color.length());
				return colorHexString;
			}

			auto const it = m_ColorHexMap.find(color);
			if (it != m_ColorHexMap.end())
				return it->second.substr(1, it->second.length());
		}

		return std::string();
	}

	/**
	* \brief Convert a string with a specific cff color.
	* \param token
	* \param color
	* \param add_flag
	* \return a string
	*/
	std::string format(const std::string & token, const std::string & color, const uint8_t add_flag)
	{
		auto result_color = GetColor(color);

		if (!IsHexColor(result_color))
			result_color = HEX_COLOR_WHITE_STRING;

		std::transform(result_color.begin(), result_color.end(), result_color.begin(), ::tolower);
		return GetFormat(result_color, token, add_flag);
	}

	/**
	* \brief Gives the chance to convert multiple strings with a specific cff color.
	* \param tokenArgs an unlimited list with args like {a, ..., ∞}
	* \param color
	* \param add_flag
	* \return a vector of strings
	*/
	std::vector<std::string> multi_format(const std::initializer_list<std::string> & tokenArgs, const std::string & color, const uint8_t add_flag)
	{
		static std::vector<std::string> vecResult;
		for (auto const & token : tokenArgs)
			vecResult.push_back(format(token, color, add_flag));

		return vecResult;
	}
}
