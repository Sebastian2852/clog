#include <CLog/CLog.hpp>

int main()
{
    CLog::Logger myLogger;
    myLogger.Info("Hello World!");
    myLogger.Debug("Hello World!");
    myLogger.Warn("Hello World!");
    myLogger.Error("Hello World!");
}