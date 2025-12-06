#pragma once

#include <iostream>
#include <vector>
#include <thread>

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

    class Logger
    {
    public:
        Logger(LogLevel minimumLogLevel = LogLevel::Info)
            : m_MinimumLogLevel(minimumLogLevel)
        {
            m_Thread = std::thread([this]()
                                   { this->sinkLoop(); });
        }

        ~Logger()
        {
            m_Running = false;
            if (m_Thread.joinable())
                m_Thread.join();
        }

        void LogMessage(LogLevel level, const std::string &message)
        {
            if (level < m_MinimumLogLevel)
                return;

            std::string prefix;
            switch (level)
            {
            case LogLevel::Info:
                prefix = "[INF]";
                break;
            case LogLevel::Debug:
                prefix = "[DBG]";
                break;
            case LogLevel::Warn:
                prefix = "[WRN]";
                break;
            case LogLevel::Error:
                prefix = "[ERR]";
                break;
            }

            std::string messageToLog = prefix + " " + message + "\n";
            m_MessageBuffer.emplace_back(CLog::LogMessage(messageToLog, level));
        }

        void Info(const std::string &message)
        {
            LogMessage(LogLevel::Info, message);
        }
        void Debug(const std::string &message)
        {
            LogMessage(LogLevel::Debug, message);
        }
        void Warn(const std::string &message)
        {
            LogMessage(LogLevel::Warn, message);
        }
        void Error(const std::string &message)
        {
            LogMessage(LogLevel::Error, message);
        }

    private:
        bool m_Running = true;
        LogLevel m_MinimumLogLevel;
        std::vector<CLog::LogMessage> m_MessageBuffer;
        std::thread m_Thread;

        void sinkBuffer()
        {
            if (m_MessageBuffer.size() == 0)
                return;

            for (CLog::LogMessage &message : m_MessageBuffer)
            {
                std::string colorCode = "0";

                switch (message.Level)
                {
                case LogLevel::Info:
                    colorCode = "94";
                    break;
                case LogLevel::Debug:
                    colorCode = "32";
                    break;
                case LogLevel::Warn:
                    colorCode = "93";
                    break;
                case LogLevel::Error:
                    colorCode = "31";
                    break;
                }

                std::cout << "\033[" << colorCode << "m" << message.Text << "\033[0m";
            }

            std::cout << std::endl;
            m_MessageBuffer.clear();
        }

        void sinkLoop()
        {
            while (m_Running)
            {
                sinkBuffer();
            }

            if (m_MessageBuffer.size() > 0)
                sinkBuffer();
        }
    };

}