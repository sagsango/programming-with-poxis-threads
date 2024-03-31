CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

.PHONY: all clean
crew:crew.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
pipe:pipe.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
server:server.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

EXE=crew pipe server

all:$(EXE)

clean:
	rm -rf $(EXE)
