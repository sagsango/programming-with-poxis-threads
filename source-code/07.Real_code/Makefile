CC=gcc
CFLAGS=-I./ -I./../00.Include/ -DDEBUG
LDFLAGS=-lpthread

# List of executables
EXE=barrier rwlock rwlock_try workq

.PHONY: all clean

all: $(EXE)

# Compile barrier
barrier: barrier.o barrier_main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Compile rwlock
rwlock: rwlock.o rwlock_main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Compile rwlock_try
rwlock_try: rwlock.o rwlock_try_main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Compile workq
workq: workq.o workq_main.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Compile each source file individually
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf $(EXE) *.o

