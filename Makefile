CC=gcc
CFLAGS=-g -std=c99 -D_GNU_SOURCE -Wall
PROG=demultiplex
SRC=demultiplex.c log.c io.c input.c output.c
OBJ=${SRC:.c=.o}

.PHONY: all clean doc run

all:	main doc

main:	$(OBJ)
			$(CC) -o $(PROG) $^ $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)

clean:
			rm -rf *.o rejetes.data f? html $(PROG)

doc:
			doxygen

run:	main
			./$(PROG)
			cp rejetes.data f0
