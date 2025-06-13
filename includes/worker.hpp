#pragma once

#ifndef WORKER_HPP
#define WORKER_HPP

#include <blocking-queue.hpp>
#include <functional>
#include <memory>
#include <mutex>
#include <thread>

namespace carryall
{

template <typename T> struct Worker final
{
  ~Worker()
  {
    std::unique_lock<std::mutex> sync{mutex};
    on_process = on_delete;
    sync.unlock();
    tasks.push(Task{true, T{}});
    thread.join();
  }

  Worker(std::function<void(T&)> on_process, std::function<void(T&)> on_delete)
      : on_process{on_process}, on_delete{on_delete}, thread{&Worker::employee, this}
  {
  }

  Worker(Worker const&) = delete;
  Worker& operator=(Worker const&) = delete;

  Worker(Worker&&) = delete;
  Worker& operator=(Worker&&) = delete;

  void work(T const& task) { tasks.push(Task{false, task}); }
  void work(T&& task) { tasks.push(Task{false, task}); }

private:
  struct Task
  {
    bool quit;
    T data;
  };
  carryall::BlockingQueue<Task> tasks;
  std::mutex mutex;
  std::function<void(T&)> on_process;
  std::function<void(T&)> on_delete;

  void employee(void)
  {
    while (true)
    {
      Task task;
      tasks.pull(task);

      if (task.quit)
        return;

      std::function<void(T&)> todo{nullptr};
      std::unique_lock<std::mutex> sync{mutex};
      todo = on_process;
      sync.unlock();

      if (todo != nullptr)
        todo(task.data);
    }
  }

  std::thread thread;
};

} // namespace carryall

#endif /* __WORKER__ */
