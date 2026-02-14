#include "DefaultLogger.hpp"
#include "LogRecord.hpp"

namespace name
{

} // namespace name

namespace logger
{
DefaultLogger::DefaultLogger(std::shared_ptr<ISink> sink, LogLevel level)
    : sink_(sink)
    , minlevel_(level)
{
}

void DefaultLogger::log(const std::string &message, LogLevel level)
{
    if (minlevel_ < level)
    {
        sink_->write({message, std::chrono::system_clock::now(), level});
    }
}

} // namespace logger
