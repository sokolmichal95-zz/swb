CC=gcc
CFLAGS=-c -Wall

all: calc

calc: main.o libutils.so
	$(CC) main.o -o calc -L. -lutils
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

libutils.so: utils.o rect.o 
	$(CC) -shared -o libutils.so utils.o rect.o

%.o: %.cpp 
	$(CC) $(CFLAGS) $*.cpp -o $*.o

.PHONY:clean
clean:
	rm -f *o *~ *txt *a *so calc
