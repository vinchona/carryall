#pragma once

#ifndef WORKER_HPP
#define WORKER_HPP

#include <memory>
#include <mutex>
#include <functional>
#include <blocking-queue.hpp>
#include <thread>

namespace carryall
{

  template<typename T>
    struct Worker
    {
      ~Worker()
      {
        std::unique_lock<std::mutex> sync(mutex);
        on_process = on_delete;
        sync.unlock();
        tasks.push(Task{true, T{}} );
        thread.join();
      }

      Worker(std::function<void(T&)> on_process, std::function<void(T&)> on_delete) :
        on_process{on_process},
        on_delete{on_delete},
        thread{&Worker::Employee, this}
      {
      }

      Worker(Worker const&) = delete;
      Worker& operator=(Worker const&) = delete;

      Worker(Worker&&) = delete;
      Worker& operator=(Worker&&) = delete;

      void work(T const & task)
      {
        tasks.push(Task{false, task});
      }

      void work(T&& task)
      {
        tasks.push(Task{false, task});
      }

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

      void Employee(void)
      {
        while(true)
        {
          Task task;
          tasks.pull(task);

          if(task.quit)
            break;

          std::function<void(T&)> todo {nullptr};
          std::unique_lock<std::mutex> sync(mutex);
          todo = on_process;
          sync.unlock();

          if(todo != nullptr)
            todo(task.data);
        }
      }

      std::thread thread;
    };

} // namespace carryall

#endif /* __WORKER__ */
