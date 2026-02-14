#include "DefaultLogger.hpp"
#include "LogRecord.hpp"

using Clock = std::chrono::system_clock;

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
        sink_->write({message, Clock::now(), std::this_thread::get_id(), level});
    }
}

} // namespace logger
