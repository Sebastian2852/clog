#pragma once

#include <string>

namespace CLog
{
    enum LogLevel
    {
        Info,
        Debug,
        Warn,
        Error
    };

    struct LogMessage
    {
        LogMessage(const std::string &text, LogLevel level)
            : Text(text), Level(level)
        {
        }

        std::string Text;
        LogLevel Level;
    };
}