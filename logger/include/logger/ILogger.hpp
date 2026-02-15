#pragma once

#include <string>

#include "LogLevel.hpp"

namespace logger
{

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void log(const std::string &message, LogLevel level = LogLevel::Info) = 0;
};

} // namespace logger