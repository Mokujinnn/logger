#pragma once

#include <string>

namespace logger
{

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Log(const std::string &message) = 0;
};

} // namespace logger