include utils.mk

this.carryall-fuzzer-requirements:=$(call get-my-dir)

include $(this.carryall-fuzzer-requirements)/carryall-requirements.mk

CARRYALL_LIBRARY_SRCS:=\
  $(CARRYALL_SRCS)\

CARRYALL_LIBRARY_INCLUDE_DIRECTORIES:=\
  $(CARRYALL_INCLUDE_DIRECTORIES)\

CARRYALL_LIBRARY_INCLUDE_FILES:=\
  $(CARRYALL_INCLUDE_FILES)\

CARRYALL_LIBRARY_CFLAGS:=\
  $(CARRYALL_CFLAGS)\
  -fPIC\

CARRYALL_LIBRARY_LDFLAGS:=\
  $(CARRYALL_LDFLAGS)\
