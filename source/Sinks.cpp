#include "Sinks.hpp"

#include <iostream>

namespace CLog::Sink
{
	void ConsoleSink::print(std::string &str)
	{
		std::cout << str;
	}
}
