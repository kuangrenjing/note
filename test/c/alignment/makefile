OOT_PATH=$(DESTDIR)/
CURDIR := $(shell pwd)

INCLUDE = -I/usr/include -I../

#CFLAGS += -g -c -mtune=i686 -m64 ${INCLUDE}
#-g 创建符号表，不做任何优化，调试模式。与-O2冲突？
#-c 仅执行编译操作，不进行连接操作。
CFLAGS += -g -c ${INCLUDE}

CC = gcc

.PHONY = clean

#all: $(SERVER)
# .c.o:
# 	${LIBTOOL_MODE_COMPILE} ${CC} ${ALL_CFLAGS} -c $<
#all:$(SERVER) $(CLIENT)

test:basic.o main.o
	$(CC) main.o basic.o -o test -lpthread

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -rf *.o
	@rm -rf $(SERVER)
	@rm -rf $(CLIENT)