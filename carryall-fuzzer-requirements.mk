include utils.mk

this.carryall-fuzzer-requirements:=$(call get-my-dir)

include $(this.carryall-fuzzer-requirements)/carryall-requirements.mk
include $(this.carryall-fuzzer-requirements)/third-parties/peanuts/peanuts-fuzzer-requirements.mk

CARRYALL_FUZZER_SRCS:=\
  $(CARRYALL_SRCS)\
  $(PEANUTS_FUZZER_SRCS:%=$(this.carryall-fuzzer-requirements)/third-parties/peanuts/%)\
  $(this)/tests/fuzz/blocking-queue.cpp\

CARRYALL_FUZZER_INCLUDE_DIRECTORIES:=\
  $(CARRYALL_INCLUDE_DIRECTORIES)\
  $(PEANUTS_FUZZER_INCLUDE_DIRECTORIES:%=$(this.carryall-fuzzer-requirements)/third-parties/peanuts/%)\

CARRYALL_FUZZER_INCLUDE_FILES:=\
  $(CARRYALL_INCLUDE_FILES)\
  $(PEANUTS_FUZZER_INCLUDE_FILES:%=$(this.carryall-fuzzer-requirements)/third-parties/peantus/%)\

CARRYALL_FUZZER_CFLAGS:=\
  $(CARRYALL_CFLAGS)\
  $(PEANUTS_FUZZER_CFLAGS)\

CARRYALL_FUZZER_LDFLAGS:=\
  $(CARRYALL_LDFLAGS)\
  $(PEANUTS_FUZZER_LDFLAGS)\
