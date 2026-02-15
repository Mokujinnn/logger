#pragma once
#include <condition_variable>
#include <mutex>
#include <queue>

template <typename T> class ThreadSafeQueue
{
private:
    std::queue<T> queue_;
    std::mutex m_;
    std::condition_variable cv_;
    bool stop_ = false;

public:
    void push(T value)
    {
        {
            std::lock_guard<std::mutex> lock(m_);
            queue_.push(std::move(value));
        }
        cv_.notify_one();
    }

    bool pop(T &out)
    {
        std::unique_lock<std::mutex> lock(m_);

        cv_.wait(lock, [&] { return !queue_.empty() || stop_; });

        if (queue_.empty())
            return false;

        out = std::move(queue_.front());
        queue_.pop();
        return true;
    }

    void stop()
    {
        {
            std::lock_guard<std::mutex> lock(m_);
            stop_ = true;
        }
        cv_.notify_all();
    }
};
