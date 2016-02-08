CC=g++
CFLAGS=-O3
LIB=/usr/local/lib/libpapi.a -lm -lpthread
INCLUDE=-I/usr/local/include
all:
	${CC} -g -O0 ${INCLUDE} -o test main.cpp ${LIB}
dbg:
	${CC} -g -O0 ${INCLUDE} -o test main.cpp ${LIB}
clean:
	${RM} *.o test