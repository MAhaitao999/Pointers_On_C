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
# 当前路径
PWD_PATH = $(abspath .)

###################################################################################################
# 目标文件
TARGET = demo
SRCS = demo.c \
       ${PWD_PATH}/singly_linked_list/singly_linked_list.c \
	   ${PWD_PATH}/doubly_linked_list/doubly_linked_list.c

INC = -I${PWD_PATH}/singly_linked_list -I${PWD_PATH}/doubly_linked_list

OBJS = $(SRCS:.c=.o)

###################################################################################################
# 编译选项
DEBUG_BUILD = yes
CFLAGS := -fPIC -Wall -Werror
ifeq ("${DEBUG_BUILD}","yes")
CFLAGS += -g
else
CFLAGS += -O3 -DNDEBUG
endif

.PHONY: all clean

all:${TARGET}

# ${TARGET}:${OBJS}
# 	@echo "\033[32;32m[Linking]\033[0m $@"
# 	@echo TARGET:$@
# 	@echo OBJECTS:$^
# 	#${QUIET}${CC} $^ -o $@ ${CFLAGS}
# 	$(CC) -o $@ $^

# ${OBJS}:${SRCS}
# 	@echo "\033[32;35m[Compiling]\033[0m $@"
# 	${QUIET}${CC} -c $< -o $@ ${CFLAGS} $(INC)

# clean:
# 	@echo "\033[0;31m[cleaning]\033[0m ${TARGET}"
# 	rm -rf ${TARGET}
# 	@echo "\033[0;31m[cleaning]\033[0m ${OBJS}"
# 	rm -rf ${OBJS}
$(TARGET):$(OBJS)
	@echo "\033[32;32m[Linking]\033[0m $@"
	${QUIET}${CC} $^ -o $@ ${CFLAGS}

clean:
	@echo "\033[0;31m[cleaning]\033[0m ${TARGET}"
	rm -rf ${TARGET}
	@echo "\033[0;31m[cleaning]\033[0m ${OBJS}"
	rm -rf ${OBJS}

%.o:%.c
	@echo "\033[32;35m[Compiling]\033[0m $@"
	${QUIET}${CC} $(CFLAGS) $(INC) -o $@ -c $<
