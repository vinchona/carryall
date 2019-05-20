include utils.mk

this.carryall-semaphore-requirements:=$(call get-my-dir)

CARRYALL_SEMAPHORE_SRCS:=\
  $(this.carryall-semaphore-requirements)/semaphore.cpp\

CARRYALL_SEMAPHORE_INCLUDE_DIRECTORIES:=\
  $(this.carryall-semaphore-requirements)\

CARRYALL_SEMAPHORE_INCLUDE_FILES:=\

CARRYALL_SEMAPHORE_CFLAGS:=\

CARRYALL_SEMAPHORE_LDFLAGS:=\
