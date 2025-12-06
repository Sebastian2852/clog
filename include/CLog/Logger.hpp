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
            m_MessageBuffer.emplace_back(messageToLog);
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
        LogLevel m_MinimumLogLevel;
        std::vector<std::string> m_MessageBuffer;
        std::thread m_Thread;

        void sinkBuffer()
        {
            if (m_MessageBuffer.size() == 0)
                return;

            for (const std::string &message : m_MessageBuffer)
                std::cout << message;

            std::cout << std::endl;
            m_MessageBuffer.clear();
        }

        void sinkLoop()
        {
            while (true)
            {
                sinkBuffer();
            }
        }
    };

}