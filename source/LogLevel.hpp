#pragma once

#include <string>

namespace CLog
{

	enum LogLevel
	{
		Trace,
		Debug,
		Info,
		Warn,
		Error
	};

	struct LogMessage
	{
		std::string message;
		LogLevel level;
	};

}