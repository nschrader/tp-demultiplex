CC=gcc
CFLAGS=-I. -std=c99
OBJ = demultiplex.o log.o

all:	main

main:	$(OBJ)
			$(CC) -o demultiplex $< $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)
