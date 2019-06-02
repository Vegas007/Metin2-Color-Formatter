#pragma once
#include <stdint.h>

#define CFF_PATTERN_BEGIN "|cff"
#define CFF_PATTERN_END "|h|r"
#define HEX_COLOR_WHITE_STRING "FFFFFF"

namespace CFF
{
	enum EHex
	{
		HEX_STRING_MAX_LEN = 6,
	};
	
	enum EFlags
	{
		FLAG_NEW_LINE,
		FLAG_NEW_TAB,
		FLAG_NEW_SPACE,
		FLAG_EMPTY_STRING,
		FLAG_MAX_NUM
	};

	bool                        IsHexColor(const std::string & color);
	std::string                 GetColor(const std::string & color);
	std::string                 GetFormat(const ::string & color, const std::string & token, const uint8_t add_flag);

	std::string                 format(const std::string & token, const std::string & color, const uint8_t add_flag = FLAG_EMPTY_STRING);
	std::vector<std::string>    multi_format(const std::initializer_list<std::string> & tokenArgs, const std::string & color, const uint8_t add_flag = FLAG_EMPTY_STRING);
}
