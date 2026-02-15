#include <string>

#include "LogLevel.hpp"

namespace logger
{

std::string to_string(LogLevel level)
{
    switch (level)
    {
    case LogLevel::Debug:
        return "Debug";
    case LogLevel::Info:
        return "Info";
    case LogLevel::Warning:
        return "Warning";
    case LogLevel::Error:
        return "Error";
    case LogLevel::Fatal:
        return "Fatal";
    default:
        return "Unknown";
    }
}

} // namespace logger
