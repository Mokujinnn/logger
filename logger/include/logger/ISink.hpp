#pragma once

#include "LogRecord.hpp"

namespace logger
{

class ISink
{
public:
    virtual ~ISink() = default;
    virtual void write(const LogRecord &record) = 0;
};

} // namespace logger
