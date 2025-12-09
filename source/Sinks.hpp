#pragma once

#include <string>
#include <fstream>

#include "LogLevel.hpp"

namespace CLog::Sink
{

	class BaseSink
	{
	public:
		BaseSink()
		{
		}

		~BaseSink() = default;

		virtual void Print(LogMessage &message) = 0;
	};

	class ConsoleSink : public BaseSink
	{
	public:
		void Print(LogMessage &message) override;
	};

	class FileSink : public BaseSink
	{
	public:
		FileSink(const std::string &filename);
		~FileSink();

		void Print(LogMessage &message) override;

	private:
		std::ofstream m_File;
	};
}