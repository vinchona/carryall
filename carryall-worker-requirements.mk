include utils.mk

this.carryall-worker-requirements:=$(call get-my-dir)

CARRYALL_WORKER_SRCS:=\

CARRYALL_WORKER_INCLUDE_DIRECTORIES:=\
  $(this.carryall-worker-requirements)\

CARRYALL_WORKER_INCLUDE_FILES:=\

CARRYALL_WORKER_CFLAGS:=\
  -pthread\

CARRYALL_WORKER_LDFLAGS:=\
  -lpthread\
