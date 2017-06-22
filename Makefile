
CC=gcc
CFLAGS=-c -Wall

all: x86_64 arm

x86_64: main.o librect.a libutils.so
	$(CC) $^ -o $@

arm: main.cpp usage.cpp utils.cpp rect.cpp
	./tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc $^ -o $@

libutils.so: usage.o 
	$(CC) -shared -o $@ $^

librect.a: utils.o rect.o
	ar -rcv $@ $^

%.o: %.cpp 
	$(CC) $(CFLAGS) $*.cpp -o $*.o

.PHONY:clean
clean:
	rm -f *o *~ *txt *a *so x86_64 arm
