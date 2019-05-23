include utils.mk

this.carryall-requirements:=$(call get-my-dir)

CARRYALL_SRCS:=\
  $(this.carryall-requirements)/command-line.cpp\
  $(this.carryall-requirements)/semaphore.cpp\

CARRYALL_INCLUDE_DIRECTORIES:=\
  $(this.carryall-requirements)\

CARRYALL_INCLUDE_FILES:=\

CARRYALL_CFLAGS:=\
  -pthread\

CARRYALL_LDFLAGS:=\
  -lpthread\
