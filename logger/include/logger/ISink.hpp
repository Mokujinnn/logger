#pragma once

#include <memory>

#include "IFormatter.hpp"
#include "LogRecord.hpp"

namespace logger
{

class ISink
{
public:
    virtual ~ISink() = default;
    virtual void write(const LogRecord &record) = 0;
    virtual void setFormatter(std::unique_ptr<IFormatter> formatter) = 0;
};

} // namespace logger
