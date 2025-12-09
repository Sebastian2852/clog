#include "CLog.hpp"

int main()
{
	CLog::Logger myLogger("CoolLogger");
	myLogger.AddSink<CLog::Sink::ConsoleSink>();
	myLogger.AddSink<CLog::Sink::FileSink>("Debug.log");
	myLogger.Trace("Hello World!");
	myLogger.Debug("Hello World!");
	myLogger.Info("Hello World!");
	myLogger.Warn("Hello World!");
	myLogger.Error("Hello World!");
}