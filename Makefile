CC=gcc
CFLAGS=-I.
OBJ = 

all:	main

main:	$(OBJ)
			$(CC) -o demultiplex $< $(CFLAGS)

%.o:	%.c
			$(CC) -c -o $@ $< $(CFLAGS)
