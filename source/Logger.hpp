#pragma once

#include <string>
#include "LogLevel.hpp"

namespace CLog
{

	class Logger
	{
	public:
		Logger(std::string name = "");
		~Logger();
		void Print(LogLevel level, std::string str);

	private:
		std::string GetColorCodeForLevel(LogLevel level);

	private:
		std::string m_Name;
		std::string m_LogFormat = "[%{NAME}] %{MSG}";
	};

}