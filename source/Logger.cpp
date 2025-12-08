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
		Utils::ReplaceInString(logMessage, "%{MSG}", std::string(str));
		std::cout << GetColorCodeForLevel(level) << logMessage << "\033[0m\n";
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
}
