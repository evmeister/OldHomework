CC	= gcc
CFLAGS	= -g -Wall

all:	maze radix vradix

maze:	maze.o deque.o
	$(CC) -o maze maze.o deque.o -lcurses

radix:	radix.o deque.o
	$(CC) -o radix radix.o deque.o -lm

vradix:	vradix.o deque.o
	$(CC) -o vradix vradix.o deque.o -lcurses -lm

clean:;	rm -f *.o maze radix vradix core
