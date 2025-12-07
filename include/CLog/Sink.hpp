#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "LogMessage.hpp"

namespace CLog
{
    namespace Sinks
    {
        class BaseSink
        {
        public:
            virtual ~BaseSink() = default;
            virtual void log(const LogMessage &message) = 0;
        };

        class ConsoleSink : public BaseSink
        {
        public:
            void log(const LogMessage &message) override
            {
                std::string prefix = "";
                switch (message.Level)
                {
                case LogLevel::Info:
                    prefix = "INFO";
                    break;
                case LogLevel::Debug:
                    prefix = "DEBUG";
                    break;
                case LogLevel::Warn:
                    prefix = "WARNING";
                    break;
                case LogLevel::Error:
                    prefix = "ERROR";
                    break;
                }

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

                std::string newString = message.Text;
                Utils::ReplaceAllInString(newString, "{PREFIX}", prefix);
                Utils::ReplaceAllInString(newString, "{COLOR_START}", "\033[" + colorCode + "m");
                Utils::ReplaceAllInString(newString, "{COLOR_END}", "\033[0m");
                std::cout << newString;
            };
        };

        class FileSink : public BaseSink
        {
        public:
            FileSink(const std::string &filename)
            {
                m_File = std::ofstream(filename, std::ios::app);
            }

            ~FileSink()
            {
                m_File.close();
            }

            void log(const LogMessage &message) override
            {
                std::string prefix = "";
                switch (message.Level)
                {
                case LogLevel::Info:
                    prefix = "INFO";
                    break;
                case LogLevel::Debug:
                    prefix = "DEBUG";
                    break;
                case LogLevel::Warn:
                    prefix = "WARNING";
                    break;
                case LogLevel::Error:
                    prefix = "ERROR";
                    break;
                }

                std::string newString = message.Text;
                Utils::ReplaceAllInString(newString, "{PREFIX}", prefix);
                Utils::ReplaceAllInString(newString, "{COLOR_START}", "");
                Utils::ReplaceAllInString(newString, "{COLOR_END}", "");
                m_File << newString;
            };

        private:
            std::ofstream m_File;
        };
    }
}