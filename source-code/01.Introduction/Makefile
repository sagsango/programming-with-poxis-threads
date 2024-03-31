CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

.PHONY: all clean

alarm: alarm.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

alarm_fork: alarm_fork.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

alarm_thread: alarm_thread.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

thread_error: thread_error.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


SRC=alarm.c alarm_fork.c alarm_thread.c thread_error.c
EXE=alarm alarm_fork alarm_thread thread_error

all: $(EXE)

clean:
	rm -f $(EXE)
