CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

.PHONY: all clean

once:once.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

thread:thread.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

mutex_attr:mutex_attr.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

cond_attr:cond_attr.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

thread_attr:thread_attr.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

cancel:cancel.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

cancel_disable:cancel_disable.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

cancel_async:cancel_async.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

cancel_cleanup:cancel_cleanup.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

cancel_subcontract:cancel_subcontract.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

tsd_once:tsd_once.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

tsd_destructor:tsd_destructor.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

sched_attr:sched_attr.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

sched_thread:sched_thread.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

EXE=once thread mutex_attr cond_attr thread_attr cancel cancel_disable cancel_async cancel_cleanup cancel_subcontract tsd_once tsd_destructor sched_attr sched_thread

all:$(EXE)

clean:
	rm -rf $(EXE)
