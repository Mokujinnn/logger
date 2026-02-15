#pragma once

#include <string>

#include "logger/LogLevel.hpp"

struct UserMessage
{
    logger::LogLevel level;
    std::string text;
};