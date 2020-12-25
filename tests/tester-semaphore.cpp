#include <peanuts.hpp>

#include <cstdio>
#include <iostream>
#include <semaphore.hpp>

using namespace carryall;

PEANUTS_TEST("Semaphore: Creation{0]/Deletion") { Semaphore semaphore; }
PEANUTS_TEST("Semaphore: Creation{1}/Deletion") { Semaphore semaphore{1}; }
