#pragma once

#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <memory>

struct Semaphore
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

#endif /* __SEMAPHORE__ */
