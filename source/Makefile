# ------------------------------------------------ #
# Darkbot Makefile (c) Jason Hamilton 07.06.98     #
# several ongoing modifications by develop team    #
# ------------------------------------------------ #
# To compile Darkbot, just type 'make'             #
# To compile for Win32 (9x/NT/XP) 'make win'       #
# To compile for Win32 with no console, type       #
# 'make win2'                                      #
#                                                  #
# To compile in debug mode, type 'make debug'      #
# To compile and have all data be logged to        #
# ..darkbot_debug.log, 'make debug2'               #
#						   #
# To compile the database conversion utility, 	   #
# type 'make convertdb'				   #
# ------------------------------------------------ #

CC = gcc
CFLAGS = -DFORK -Wall -O3
DFLAGS = -dm -pg -g -DDEBUG
D2FLAG = -DDEBUG2 -DFORK
EXE_NAME = darkbot
LIBS = -lcrypt

# If you're using Solaris, you'll need to uncomment this next line.
# LIBS = -lcrypt -lsocket -lnsl -lresolv

####################################################

OBJECTS = main.o vars.o chansrv.o permbans.o helpers.o users.o general.o \
          url.o seen.o topics.o random.o sockets.o raw.o signals.o parse.o \
          chan.o server.o comm.o stats.o quiz.o web.o reserved.o

ALL_SRC = main.c vars.c chansrv.c permbans.c helpers.c users.c general.c \
          url.c seen.c topics.c random.c sockets.c raw.c signals.c parse.c \
          chan.c server.c comm.c stats.c quiz.c web.c reserved.c

all : ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} ${LIBS} -o ${EXE_NAME}
	chmod +x .././configure;
	chmod +x ../scripts/.Stripdb; ../scripts/.Stripdb;
	chmod +x ../scripts/.Launch; ../scripts/.Launch;  cp -f ${EXE_NAME} ..;

clean :
	rm -f ${EXE_NAME} ${OBJECTS} convertdb.o

win : ${ALL_SRC}
	${CC} ${CFLAGS} -DWIN32 ${ALL_SRC} ${LIBS} -o ${EXE_NAME}
	chmod +x .././configure;
	chmod +x ../scripts/.Stripdb2; ../scripts/.Stripdb2; cat ../scripts/.info;
	chmod +x ../scripts/.Launch; ../scripts/.Launch; cp -f ${EXE_NAME} ..;

win2 : ${OBJECTS}
	${CC} ${CFLAGS} -DWIN32 ${ALL_SRC} ${LIBS} -DNOCONSOLE -Wl,--subsystem,windows -o darkbot-noconsole -luser32
	chmod +x .././configure;
	chmod +x ../scripts/.Stripdb2; ../scripts/.Stripdb2; cat ../scripts/.info;
	chmod +x ../scripts/.Launch; ../scripts/.Launch;  cp -f ${EXE_NAME} ..;

debug : ${OBJECTS}
	${CC} ${DFLAGS} ${ALL_SRC} ${LIBS} -o ${EXE_NAME}
	cat ../.debug ;  cp -f ${EXE_NAME} ..; gdb ${EXE_NAME}        

debug2 : ${OBJECTS}
	${CC} ${LIBS} ${D2FLAGS} ${ALL_SRC} ${LIBS} -o ${EXE_NAME}
	cat ../.debug2;  cp -f ${EXE_NAME} ..;

convertdb : convertdb.o
	${CC} convertdb.c ${LIBS} -o convertdb
	cp -f convertdb ..;

