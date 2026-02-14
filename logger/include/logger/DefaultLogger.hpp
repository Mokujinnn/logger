#pragma once

#include <memory>

#include "ILogger.hpp"
#include "ISink.hpp"

namespace logger
{

class DefaultLogger : public ILogger
{
private:
    std::shared_ptr<ISink> sink_;
    LogLevel minlevel_;

public:
    DefaultLogger(std::shared_ptr<ISink> sink, LogLevel level = LogLevel::Info);

    void log(const std::string &message, LogLevel level = LogLevel::Info) override;
};

} // namespace logger