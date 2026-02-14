#pragma once

#include <chrono>
#include <string>
#include <thread>

#include "LogLevel.hpp"

namespace logger
{

struct LogRecord
{
    std::string message;
    std::chrono::system_clock::time_point timestamp;
    std::thread::id threadId;
    LogLevel level;
};

} // namespace logger
