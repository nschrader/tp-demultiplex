CC=gcc
CFLAGS=-I.
OBJ = demultiplex.o

all:	main

main:	$(OBJ)
			$(CC) -o demultiplex $< $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)
