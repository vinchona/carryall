#pragma once

#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <condition_variable>
#include <mutex>

struct semaphore
{
  semaphore(size_t count = 0) : count{count} {}

  semaphore(semaphore const&) = delete;
  semaphore(semaphore&&) = delete;
  semaphore& operator=(semaphore const&) = delete;
  semaphore& operator=(semaphore&&) = delete;

  ~semaphore() = default;

  void signal()
  {
    std::unique_lock<std::mutex> lock(mutex);
    ++count;
    condition_variable.notify_one();
  }

  void wait()
  {
    std::unique_lock<std::mutex> lock(mutex);
    condition_variable.wait(lock, [&] { return count > 0; });
    --count;
  }

private:
  std::mutex mutex;
  std::condition_variable condition_variable;
  size_t count;
};

#endif /* __SEMAPHORE__ */
