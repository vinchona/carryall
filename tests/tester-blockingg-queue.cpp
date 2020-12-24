#include <peanuts.hpp>

#include <cstdio>
#include <iostream>
#include <blocking-queue.hpp>


using namespace carryall;

PEANUTS_TEST("BlockingQueue: Creation/Deletion")
{ 
  BlockingQueue<int> bloquing_queue;
}
