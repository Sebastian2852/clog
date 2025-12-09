#pragma once

#include <string>

namespace CLog::Sink
{

	class BaseSink
	{
	public:
		BaseSink()
		{
		}

		~BaseSink() = default;

		virtual void print(std::string &str) = 0;
	};

	class ConsoleSink : public BaseSink
	{
	public:
		void print(std::string &str) override;
	};

}