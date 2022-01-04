###################################################################################################
# 编译工具链设置
CC = gcc

DEBUG_BUILD ?= yes
SHOW_COMMAND ?= yes

# SHOW_COMMAND=yes，显示编译命令
ifeq (${SHOW_COMMAND}, yes)
QUIET :=
else
QUIET := @
endif

###################################################################################################
# 目录设置
# 中间文件缓存文件夹
TMP_PATH = $(abspath .)/tmp
# 当前路径
PWD_PATH = $(abspath .)

###################################################################################################
# 源文件.c
SRC := ${PWD_PATH}/*.c
# 展开*匹配，获取所有源文件完整路径
SRC := $(wildcard ${SRC})
OBJ := $(patsubst ${PWD_PATH}/%.c,${TMP_PATH}/%.o,${SRC})

TARGET := $(patsubst ${PWD_PATH}/%.c,${PWD_PATH}/%.out,${SRC})

###################################################################################################
# 编译选项
CFLAGS := -fPIC -Wall -Werror
ifeq ("${DEBUG_BUILD}","yes")
CFLAGS += -g
else
CFLAGS += -O3 -DNDEBUG
endif

.PHONY: all clean

all:${TARGET}

# ${PWD_PATH}/%.out:${TMP_PATH}/%.o
${TARGET}:${OBJ}
	@echo "\033[32;32m[Linking]\033[0m $@"
	${QUIET}${CC} $< -o $@ ${CFLAGS}

# ${TMP_PATH}/%.o:${PWD_PATH}/%.c
${OBJ}:${SRC}
	@echo "\033[32;35m[Compiling]\033[0m $@"
	@mkdir $(dir $@) -p
	${QUIET}${CC} -c $< -o $@ ${CFLAGS}

clean:
	@echo "\033[0;31m<cleaning>\033[0m ${TARGET}"
	rm -rf ${TARGET}
	@echo "\033[0;31m<cleaning>\033[0m ${OBJ}"
	rm -rf ${TMP_PATH}