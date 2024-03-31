CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

.PHONY: all clean

mutex_static:mutex_static.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
mutex_dynamic:mutex_dynamic.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
alarm_mutex:alarm_mutex.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
trylock:trylock.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
backoff:backoff.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
cond_static:cond_static.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
cond_dynamic:cond_dynamic.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
cond:cond.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
alarm_cond:alarm_cond.c
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

EXE=alarm_cond alarm_mutex backoff cond cond_dynamic cond_static mutex_dynamic mutex_static  trylock

all:$(EXE)

clean:
	rm -rf $(EXE)
