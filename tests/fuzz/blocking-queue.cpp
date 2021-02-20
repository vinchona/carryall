#include <peanuts.hpp>

#include <blocking-queue.hpp>
#include <cstdio>
#include <iostream>

using namespace carryall;

PEANUTS_FUZZ("BlockingQueue: Random number of inputs")
{
  BlockingQueue<char> blocking_queue;
  for (size_t size = 0; size < peanuts_size; size++)
    blocking_queue.push(peanuts_data[size]);

  for (size_t size = 0; size < peanuts_size; size++)
  {
    char value;
    blocking_queue.pull(value);
    PEANUTS_IS_EQUAL_OR_ABORT(peanuts_data[size], value);
  }
}
