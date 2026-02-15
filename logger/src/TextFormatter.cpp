#include <iomanip>

#include "TextFormatter.hpp"

using Clock = std::chrono::system_clock;

namespace logger
{

std::string TextFormatter::format(const LogRecord &record)
{
    std::ostringstream oss;
    auto t = Clock::to_time_t(record.timestamp);

    oss << "[" << std::put_time(std::localtime(&t), "%Y-%m-%d %H:%M:%S") << "] [" << record.threadId << "] [" << to_string(record.level)
        << "] " << record.message << '\n';

    return oss.str();
}

} // namespace logger
