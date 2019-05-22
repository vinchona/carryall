#include "semaphore.hpp"

#include <condition_variable>
#include <mutex>

using namespace std;
using namespace carryall;

struct Semaphore::Implementation
{
  std::mutex mutex;
  std::condition_variable condition_variable;
  size_t count;
};

Semaphore::~Semaphore() = default;

Semaphore::Semaphore(size_t count) : implementation{new Implementation{}} { implementation->count = count; }

void Semaphore::signal(void)
{
  unique_lock<mutex> lock(implementation->mutex);
  ++implementation->count;
  implementation->condition_variable.notify_one();
}

void Semaphore::wait(void)
{
  unique_lock<mutex> lock(implementation->mutex);
  implementation->condition_variable.wait(lock, [&] { return implementation->count > 0; });
  --implementation->count;
}
