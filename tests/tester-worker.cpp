#include <peanuts.hpp>

#include <cstdio>
#include <iostream>
#include <worker.hpp>

using namespace carryall;

PEANUTS_TEST("Worker: Creation/Deletion") { Worker<int> worker{nullptr, nullptr}; }
