/*
 * cancel.c
 *
 * Demonstrate use of synchronous cancellation using
 * pthread_testcancel.
 *
 * Special notes: On a Solaris 2.5 uniprocessor, this test will
 * hang unless a second LWP is created by calling
 * thr_setconcurrency() because threads are not timesliced.
 */

/* TODO: https://man7.org/linux/man-pages/man3/pthread_cancel.3.html */

#include <pthread.h>
#include "errors.h"

static int counter;

/*
 * Loop until cancelled. The thread can be cancelled only
 * when it calls pthread_testcancel, which it does each 1000
 * iterations.
 */
void *thread_routine (void *arg)
{
    DPRINTF (("thread_routine starting\n"));
    for (counter = 0; ; counter++)
        if ((counter % 1000) == 0) {
            DPRINTF (("calling testcancel, %d\n", counter));
            pthread_testcancel ();
	    DPRINTF (("after calling testcancel, %d\n", counter));
        }
}

int main (int argc, char *argv[])
{
    pthread_t thread_id;
    void *result;
    int status;

#ifdef sun
    /*
     * On Solaris 2.5, threads are not timesliced. To ensure
     * that our two threads can run concurrently, we need to
     * increase the concurrency level to 2.
     */
    DPRINTF (("Setting concurrency level to 2\n"));
    thr_setconcurrency (2);
#endif
    status = pthread_create (
        &thread_id, NULL, thread_routine, NULL);
    if (status != 0)
        err_abort (status, "Create thread");
    sleep (2);

    DPRINTF (("calling cancel\n"));
    status = pthread_cancel (thread_id);
    if (status != 0)
        err_abort (status, "Cancel thread");

    DPRINTF (("calling join\n"));
    status = pthread_join (thread_id, &result);
    if (status != 0)
        err_abort (status, "Join thread");
    if (result == PTHREAD_CANCELED)
        printf ("Thread cancelled at iteration %d\n", counter);
    else
        printf ("Thread was not cancelled\n");
    return 0;
}
