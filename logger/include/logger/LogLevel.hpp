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

} // namespace logger