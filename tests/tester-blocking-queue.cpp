#include <peanuts.hpp>

#include <blocking-queue.hpp>
#include <cstdio>
#include <iostream>

using namespace carryall;

PEANUTS_TEST("BlockingQueue: Creation/Deletion") { BlockingQueue<int> blocking_queue; }
