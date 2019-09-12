ROOT_PATH=$(DESTDIR)/
CURDIR := $(shell pwd)

vpath %.cpp ../src

OBJS = global.o \
	flag.o \
	rconfig.o \
	isp.o \
	log.o \
	dnsname.o \
	rrecord.o \
	rrset.o \
	namerrset.o \
	acustomernamerrset.o \
	customerrrset.o \
	recordfile.o \
	zone.o \
	dig.o \
	zonemanager.o \
	jsoncpp.o \
	threadpool.o \
	localdnsmsg.o \
	server.o

SERVER = localdnsserver3

INCLUDE = -I../include

CFLAGS += -g -c -mtune=i686 -m64 ${INCLUDE}

CC = g++

.PHONY = clean

#all: $(SERVER)
# .c.o:
# 	${LIBTOOL_MODE_COMPILE} ${CC} ${ALL_CFLAGS} -c $<

$(SERVER):$(OBJS)
	$(CC) $(OBJS) -o ../${SERVER} -lpthread -levent2

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

install:
	@mkdir -p $(DESTDIR)/usr/local/localdnsmodifysourceserver/
	@cp -f $(SERVER) $(DESTDIR)/usr/local/localdnsmodifysourceserver/
	@cp -f config.ini $(DESTDIR)/usr/local/localdnsmodifysourceserver/
	#@cp -f domain.txt $(DESTDIR)/usr/local/localdnsmodifysourceserver/
	#@cp -fr log $(DESTDIR)/usr/local/localdnsmodifysourceserver/


clean:
	@rm -rf *.o
	@rm -rf $(SERVER)
