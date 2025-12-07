#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <memory>

#include "LogMessage.hpp"
#include "Utils.hpp"
#include "Sink.hpp"

namespace CLog
{

    class Logger
    {
    public:
        Logger(std::string format, LogLevel minimumLogLevel = LogLevel::Info)
            : m_MinimumLogLevel(minimumLogLevel), m_Format(format)
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

            std::string mutString = m_Format;
            Utils::ReplaceAllInString(mutString, "{MESSAGE}", message);

            std::string messageToLog = mutString + "\n";
            m_MessageBuffer.emplace_back(CLog::LogMessage(messageToLog, level));
        }

        template <typename T, typename... Args>
        void AddSink(Args &&...args)
        {
            m_Sinks.emplace_back(std::make_shared<T>(std::forward<Args>(args)...));
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
        std::vector<std::shared_ptr<Sinks::BaseSink>> m_Sinks;
        std::thread m_Thread;
        std::string m_Format;

        void sinkBuffer()
        {
            if (m_MessageBuffer.size() == 0)
                return;

            for (CLog::LogMessage &message : m_MessageBuffer)
            {
                for (auto &sink : m_Sinks)
                    sink->log(message);
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