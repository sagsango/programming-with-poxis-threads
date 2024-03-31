CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

.PHONY: all clean

lifecycle:lifecycle.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

all:lifecycle

clean:
	rm -rf lifecycle
