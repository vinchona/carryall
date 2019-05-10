include utils.mk

this.carryall-command-line-requirements:=$(call get-my-dir)

CARRYALL_COMMAND_LINE_SRCS:=\
  $(this.carryall-command-line-requirements)/command-line.cpp\

CARRYALL_COMMAND_LINE_INCLUDE_DIRECTORIES:=\
  $(this.carryall-command-line-requirements)\

CARRYALL_COMMAND_LINE_INCLUDE_FILES:=\

CARRYALL_COMMAND_LINE_CFLAGS:=\

CARRYALL_COMMAND_LINE_LDFLAGS:=\
