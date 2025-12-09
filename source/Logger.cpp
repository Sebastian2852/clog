#include "Logger.hpp"
#include "Utils.hpp"

#include <iostream>

namespace CLog
{
	Logger::Logger(std::string name, std::string format)
		: m_Name(name), m_LogFormat(format)
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

		LogMessage msg;
		msg.message = logMessage;
		msg.level = level;

		for (auto sink : m_Sinks)
		{
			sink->Print(msg);
		}
	}
}
