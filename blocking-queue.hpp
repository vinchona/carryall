#pragma once

#ifndef BLOCKING_QUEUE_HPP
#define BLOCKING_QUEUE_HPP

#include <memory>

template<typename T>
struct BlockingQueue
{
  ~BlockingQueue();
  BlockingQueue();

  BlockingQueue(BlockingQueue const&) = delete;
  BlockingQueue& operator=(BlockingQueue const&) = delete;

  BlockingQueue(BlockingQueue&&) = delete;
  BlockingQueue& operator=(BlockingQueue&&) = delete;

  void push(T const & value);
  void push(T&& value);
  void pull(T& value);

private:
  struct Implementation;
  std::unique_ptr<Implementation> implementation;
};

#endif /* __BLOCKING_QUEUE__ */
