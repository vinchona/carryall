#include <peanuts.hpp>

#include <cstdio>
#include <iostream>
#include <blocking-queue.hpp>

using namespace carryall;

PEANUTS_FUZZ("Blocking queue fuzzing input")
{
	 BlockingQueue<char> bloquing_queue;
	 for (size_t size = 0; size < peanuts_size; size++)
		 bloquing_queue.push(peanuts_data[size]);

	 for (size_t size = 0; size < peanuts_size; size++)
	 {
		 char value;
		 bloquing_queue.pull(value);
		 PEANUTS_IS_EQUAL_OR_ABORT(peanuts_data[size], value);
	 }
}
