#include "FileSink.hpp"

namespace logger
{

FileSink::FileSink(const std::string &filename, std::unique_ptr<IFormatter> formatter)
    : file_(filename)
    , formatter_(std::move(formatter))
{
}

void FileSink::write(const LogRecord &record)
{
    std::lock_guard<std::mutex> lock(mutex_);
    file_ << formatter_->format(record);
}

void FileSink::setFormatter(std::unique_ptr<IFormatter> formatter)
{
    std::lock_guard<std::mutex> lock(mutex_);
    formatter_ = std::move(formatter);
}

} // namespace logger
