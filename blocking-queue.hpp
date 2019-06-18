#pragma once

#ifndef BLOCKING_QUEUE_HPP
#define BLOCKING_QUEUE_HPP

#include <mutex>
#include <queue>
#include <semaphore.hpp>

namespace carryall
{

template <typename T> struct BlockingQueue final
{
  ~BlockingQueue() = default;
  BlockingQueue() = default;

  BlockingQueue(BlockingQueue const&) = delete;
  BlockingQueue& operator=(BlockingQueue const&) = delete;

  BlockingQueue(BlockingQueue&&) = delete;
  BlockingQueue& operator=(BlockingQueue&&) = delete;

  void push(T const& value)
  {
    std::unique_lock<std::mutex> lock(mutex);
    queue.push(value);
    lock.unlock();
    semaphore.signal();
  }

  void push(T&& value)
  {
    std::unique_lock<std::mutex> lock(mutex);
    queue.push(value);
    lock.unlock();
    semaphore.signal();
  }

  void pull(T& value)
  {
    semaphore.wait();
    std::unique_lock<std::mutex> lock(mutex);
    value = queue.front();
    queue.pop();
  }

private:
  carryall::Semaphore semaphore;
  std::queue<T> queue;
  std::mutex mutex;
};

} // namespace carryall

#endif /* __BLOCKING_QUEUE__ */
