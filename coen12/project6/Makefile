CC	= gcc
CXX	= g++
CFLAGS	= -g -Wall

all:	maze radix

maze:	maze.o deque.o
	$(CXX) -o maze maze.o deque.o -lcurses

radix:	radix.o deque.o
	$(CXX) -o radix radix.o deque.o -lm

clean:;	rm -f *.o maze radix vradix core
