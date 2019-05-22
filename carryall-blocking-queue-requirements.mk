include utils.mk

this.carryall-blocking-queue-requirements:=$(call get-my-dir)

CARRYALL_BLOCKING_QUEUE_SRCS:=\
  $(this.carryall-blocking-queue-requirements)/blocking-queue.cpp\
  $(this.carryall-blocking-queue-requirements)/semaphore.cpp\

CARRYALL_BLOCKING_QUEUE_INCLUDE_DIRECTORIES:=\
  $(this.carryall-blocking-queue-requirements)\

CARRYALL_BLOCKING_QUEUE_INCLUDE_FILES:=\

CARRYALL_BLOCKING_QUEUE_CFLAGS:=\

CARRYALL_BLOCKING_QUEUE_LDFLAGS:=\
