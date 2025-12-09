#include "Utils.hpp"

namespace CLog::Utils
{
	void ReplaceInString(std::string &fmt, std::string from, std::string to)
	{
		if (from.empty())
			return;

		int pos = 0;
		while ((pos = fmt.find(from, pos)) != std::string::npos)
		{
			fmt.replace(pos, from.length(), to);
			pos += to.length();
		}
	}

	std::string GetColorCodeForLevel(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Trace:
			return "\033[0m";
		case LogLevel::Info:
			return "\033[94m";
		case LogLevel::Debug:
			return "\033[32m";
		case LogLevel::Warn:
			return "\033[93m";
		case LogLevel::Error:
			return "\033[31m";
		}
		return "\033[0m";
	}

	std::string GetPrefixForLevel(LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Trace:
			return "TRACE";
		case LogLevel::Info:
			return "INFO";
		case LogLevel::Debug:
			return "DEBUG";
		case LogLevel::Warn:
			return "WARNING";
		case LogLevel::Error:
			return "ERROR";
		}
		return "";
	}
}
