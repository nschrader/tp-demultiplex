CC=gcc
CFLAGS=-std=c99 -g
OBJ=demultiplex.o log.o io.o input.o output.o
PROG=demultiplex

.PHONY: all
.PHONY: clean
.PHONY:	doc

all:	main doc

main:	$(OBJ)
			$(CC) -o $(PROG) $^ $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

clean:
			rm -rf *.o rejetes.data f? html $(PROG)

doc:
			doxygen
