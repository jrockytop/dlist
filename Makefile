INSTALL=/usr/local
CC=gcc
CFLAGS=-I. -O2 -fPIC

OS := $(shell uname)
ifeq ($(OS),Darwin)
        LIBNAME=libdlist.dylib
else
        LIBNAME=libdlist.so
endif

all: libdlist.a $(LIBNAME)

libdlist.a: dlist.o
	ar -r libdlist.a dlist.o

libdlist.dylib: dlist.o
	$(CC) -o libdlist.dylib dlist.o -dynamiclib

libdlist.so: dlist.o
	$(CC) -shared -Wl,-soname,libdlist.so  -o libdlist.so dlist.o

install: libdlist.a
	cp dlist.h $(INSTALL)/include
	cp libdlist.a $(INSTALL)/lib
	cp $(LIBNAME) $(INSTALL)/lib

clean:
	rm -f *.o $(LIBNAME) libdlist.a
