Cxx = g++
CFLAGS = -g3 -Wall
MKDIR = mkdir -p

LIBS=-lm

directorios: 
	$(MKDIR) build dist

funciones.o: directorios funciones.cpp funciones.h
	$(Cxx) $(CFLAGS) -c funciones.cpp -o funciones.o


all: clean funciones.o 
	$(Cxx) $(CFLAGS) $(LIBS) -o programa main.cpp funciones.o
	rm -fr build

clean:
	rm -fr *.o a.out programa dist build

.DEFAULT_GOAL := all