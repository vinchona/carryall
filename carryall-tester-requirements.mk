include utils.mk

this.carryall-tester-requirements:=$(call get-my-dir)

include $(this.carryall-tester-requirements)/carryall-requirements.mk
include $(this.carryall-tester-requirements)/third-parties/peanuts/peanuts-tester-requirements.mk

CARRYALL_TESTER_SRCS:=\
  $(CARRYALL_SRCS)\
  $(PEANUTS_TESTER_SRCS:%=$(this.carryall-tester-requirements)/third-parties/peanuts/%)\

CARRYALL_TESTER_INCLUDE_DIRECTORIES:=\
  $(CARRYALL_INCLUDE_DIRECTORIES)\
  $(PEANUTS_TESTER_INCLUDE_DIRECTORIES:%=$(this.carryall-tester-requirements)/third-parties/peanuts/%)\

CARRYALL_TESTER_INCLUDE_FILES:=\
  $(CARRYALL_INCLUDE_FILES)\
  $(PEANUTS_TESTER_INCLUDE_FILES:%=$(this.carryall-tester-requirements)/third-parties/peantus/%)\

CARRYALL_TESTER_CFLAGS:=\
  $(CARRYALL_CFLAGS)\
  $(PEANUTS_TESTER_CFLAGS)\

CARRYALL_TESTER_LDFLAGS:=\
  $(CARRYALL_LDFLAGS)\
  $(PEANUTS_TESTER_LDFLAGS)\
