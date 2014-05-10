CC = clang++
CXX = clang++

CFLAGS = -g -Wall -O3 $(shell pkg-config --cflags cppunit)
LDFLAGS = -g -Wall $(shell pkg-config --libs cppunit)

.PHONY:
default: Main

.PHONY:
test: TestInversionCounter

Main: Main.o InversionCounter.o

TestInversionCounter: TestInversionCounter.o InversionCounter.o

InversionCounter.o: InversionCounter.h

.PHONY:
all: clean default test

.PHONY:
clean:
	rm -f *.o *.h.gch *.*~ a.out Main TestInversionCounter
