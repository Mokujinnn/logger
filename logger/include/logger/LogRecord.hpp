#pragma once

#include <string>

#include "LogLevel.hpp"

namespace logger
{

struct LogRecord
{
    std::string message;
    std::string timestamp;
    LogLevel level;
};

} // namespace logger
