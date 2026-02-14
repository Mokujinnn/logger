#pragma once

#include <chrono>
#include <string>

#include "LogLevel.hpp"

namespace logger
{

struct LogRecord
{
    std::string message;
    std::chrono::system_clock::time_point timestamp;
    LogLevel level;
};

} // namespace logger
