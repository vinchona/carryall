#pragma once

#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <memory>

namespace carryall
{

struct Semaphore final
{
  ~Semaphore();
  Semaphore(size_t count = 0);

  Semaphore(Semaphore const&) = delete;
  Semaphore& operator=(Semaphore const&) = delete;

  Semaphore(Semaphore&&) = delete;
  Semaphore& operator=(Semaphore&&) = delete;

  void signal(void);
  void wait(void);

private:
  struct Implementation;
  std::unique_ptr<Implementation> implementation;
};

} // namespace carryall

#endif /* __SEMAPHORE__ */
