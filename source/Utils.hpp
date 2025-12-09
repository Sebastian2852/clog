#pragma once

#include <string>
#include "LogLevel.hpp"

namespace CLog::Utils
{
	void ReplaceInString(std::string &fmt, std::string from, std::string to);
	std::string GetColorCodeForLevel(LogLevel level);
	std::string GetPrefixForLevel(LogLevel level);
}
