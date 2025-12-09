#pragma once

#include <string>
#include <vector>
#include <memory>

#include "LogLevel.hpp"
#include "Sinks.hpp"

namespace CLog
{

	class Logger
	{
	public:
		Logger(std::string name = "");
		~Logger();
		void Print(LogLevel level, std::string str);

		template <typename T, typename... Args>
		void AddSink(Args &&...args)
		{
			m_Sinks.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
		}

	private:
		std::string GetColorCodeForLevel(LogLevel level);
		std::string GetPrefixForLevel(LogLevel level);

	private:
		std::string m_Name;
		std::string m_LogFormat = "%{COLOR_START}[%{PREFIX}] [%{NAME}] %{MSG}";
		std::vector<std::shared_ptr<Sink::BaseSink>> m_Sinks;
	};

}