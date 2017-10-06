CC=gcc
CFLAGS=-I. -std=c99
OBJ=demultiplex.o log.o functions.o input.o output.o
PROG=demultiplex

.PHONY: all
.PHONY: clean

all:	main

main:	$(OBJ)
			$(CC) -o $(PROG) $^ $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

clean:
			rm -f *.o $(PROG)
