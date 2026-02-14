#pragma once

namespace logger
{

enum class LogLevel
{
    Debug = 0,
    Info = 4,
    Warning = 8,
    Error = 12,
    Fatal = 16
};

inline std::string to_string(LogLevel level)
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