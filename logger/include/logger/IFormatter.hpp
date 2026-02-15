#pragma once

#include "LogRecord.hpp"

namespace logger
{

class IFormatter
{
public:
    virtual ~IFormatter() = default;
    virtual std::string format(const LogRecord &record) = 0;
};

} // namespace logger
