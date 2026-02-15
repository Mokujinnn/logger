#include <iostream>
#include <optional>
#include <sstream>
#include <thread>

#include "logger/DefaultLogger.hpp"
#include "logger/FileSink.hpp"
#include "logger/LogLevel.hpp"
#include "logger/LogRecord.hpp"
#include "logger/TextFormatter.hpp"

#include "ThreadSafeQueue.hpp"
#include "UserMessage.hpp"

std::optional<logger::LogLevel> toLogLevel(const std::string &level)
{
    if (level == "debug")
        return logger::LogLevel::Debug;
    else if (level == "info")
        return logger::LogLevel::Info;
    else if (level == "error")
        return logger::LogLevel::Error;
    else if (level == "warning")
        return logger::LogLevel::Warning;
    else if (level == "fatal")
        return logger::LogLevel::Fatal;
    else
        return std::nullopt;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Usage: ./app <log_file> <default_level>\n";
        return 1;
    }

    std::string logFile = argv[1];
    logger::LogLevel defaultLevel = logger::LogLevel::Info;

    {
        std::string lvl = argv[2];

        auto level = toLogLevel(lvl);
        if (level)
            defaultLevel = *level;
        else
        {
            std::cerr << "Invalid default level: " << lvl << '\n';
            return 1;
        }
    }

    auto sink = std::make_shared<logger::FileSink>(logFile);
    logger::DefaultLogger logger(sink, logger::LogLevel::Debug);

    ThreadSafeQueue<UserMessage> queue;

    std::thread writer([&] {
        UserMessage msg;

        while (queue.pop(msg))
        {
            logger.log(msg.text, msg.level);
        }

        std::cout << "Writer thread stopped\n";
    });

    std::cout << "Enter messages (format: <level> <text>), or 'quit'\n";

    std::string line;
    while (true)
    {
        std::getline(std::cin, line);

        if (line == "quit")
            break;

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string levelStr;
        ss >> levelStr;

        logger::LogLevel lvl = defaultLevel;
        std::string message;

        auto level = toLogLevel(levelStr);
        if (level)
            lvl = *level;
        else
        {
            std::cerr << "Invalid level: " << levelStr << '\n';
            continue;
        }

        std::getline(ss, message);

        if (!message.empty() && message[0] == ' ')
            message.erase(0, 1);

        queue.push(UserMessage{lvl, message});
    }

    queue.stop();
    writer.join();

    std::cout << "Application finished.\n";
    return 0;
}
