CC = gcc
CFLAGS = -Wall -g

all: typecast

typecast: main.c
	$(CC) $(CFLAGS) -o typecast main.c

test: typecast
	./typecast

clean:
	rm -f typecast

.PHONY: all test clean
