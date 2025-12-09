#include "Logger.hpp"
#include "Utils.hpp"

#include <iostream>

namespace CLog
{
	Logger::Logger(std::string name)
		: m_Name(name)
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::Print(LogLevel level, std::string str)
	{
		std::string logMessage = m_LogFormat;
		Utils::ReplaceInString(logMessage, "%{NAME}", m_Name);
		Utils::ReplaceInString(logMessage, "%{COLOR_START}", GetColorCodeForLevel(level));
		Utils::ReplaceInString(logMessage, "%{PREFIX}", GetPrefixForLevel(level));
		Utils::ReplaceInString(logMessage, "%{MSG}", std::string(str));
		logMessage += "\033[0m\n";

		for (auto sink : m_Sinks)
		{
			sink->print(logMessage);
		}
	}

	std::string Logger::GetColorCodeForLevel(LogLevel level)
	{
		switch (level)
		{
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

	std::string Logger::GetPrefixForLevel(LogLevel level)
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
