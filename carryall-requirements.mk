include utils.mk

this.carryall-requirements:=$(call get-my-dir)

CARRYALL_SRCS:=\
  $(this.carryall-requirements)/srcs/command-line.cpp\
  $(this.carryall-requirements)/srcs/semaphore.cpp\

CARRYALL_INCLUDE_DIRECTORIES:=\
  $(this.carryall-requirements)/includes\

CARRYALL_INCLUDE_FILES:=\

CARRYALL_CFLAGS:=\
  -pthread\

CARRYALL_LDFLAGS:=\
  -lpthread\
