#pragma once

#include "IFormatter.hpp"

namespace logger
{

class TextFormatter : public IFormatter
{
public:
    std::string format(const LogRecord &record) override;
};

} // namespace logger