#include "blocking-queue.hpp"

#include <semaphore.hpp>
#include <mutex>
#include <queue>

using namespace std;

template<typename T>
struct BlockingQueue<T>::Implementation
{
  Semaphore semaphore;
  std::queue<T> queue;
  std::mutex mutex;
};

template<typename T>
BlockingQueue<T>::BlockingQueue() : implementation{new Implementation{}}
{
}

template<typename T>
BlockingQueue<T>::~BlockingQueue() = default;

template<typename T>
void BlockingQueue<T>::push(T const& value)
{
  unique_lock<mutex> lock(implementation->mutex);
  implementation->queue.push(value);
  lock.unlock();
  implementation->semaphore.signal();
}

template<typename T>
void BlockingQueue<T>::push(T&& value)
{
  unique_lock<mutex> lock(implementation->mutex);
  implementation->queue.push(value);
  lock.unlock();
  implementation->semaphore.signal();
}

template<typename T>
void BlockingQueue<T>::pull(T& value)
{
  implementation->semaphore.wait();
  unique_lock<mutex> lock(implementation->mutex);
  value = implementation->queue.front();
  implementation->queue.pop();
}
