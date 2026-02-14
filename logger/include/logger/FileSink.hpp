#pragma once

#include <fstream>
#include <mutex>

#include "ISink.hpp"
#include "TextFormatter.hpp"

namespace logger
{

class FileSink : public ISink
{
private:
    std::ofstream file_;
    std::unique_ptr<IFormatter> formatter_;
    std::mutex mutex_;

public:
    FileSink(const std::string &filename, std::unique_ptr<IFormatter> formatter = std::make_unique<TextFormatter>());

    void write(const LogRecord &record) override;
    void setFormatter(std::unique_ptr<IFormatter> formatter) override;
};

} // namespace logger
