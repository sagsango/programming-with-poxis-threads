CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

.PHONY: all clean

atfork:atfork.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

flock:flock.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

putchar:putchar.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

getlogin:getlogin.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

susp:susp.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

sigwait:sigwait.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

sigev_thread:sigev_thread.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

semaphore_signal:semaphore_signal.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

EXE=atfork flock putchar getlogin susp sigwait sigev_thread semaphore_signal

all:$(EXE)

clean:
	rm -rf $(EXE)
