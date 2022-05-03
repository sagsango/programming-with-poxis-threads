/*
 * alarm_fork.c
 *
 * This version of alarm.c uses fork to create a new process to
 * wait for each alarm to expire.
 */
#include <sys/types.h>
#include <sys/wait.h>
#include "errors.h"

int main (int argc, char *argv[])
{
    int status;
    char line[128];
    int seconds;
    pid_t pid;
    char message[64];

    if( argc == 2 && strcmp(argv[1],"--help") == 0 ){
        printf("%s time[sec] message\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    while (1) {
        printf ("Alarm> ");
        if (fgets (line, sizeof (line), stdin) == NULL) exit (0);
        if (strlen (line) <= 1) continue;

        /*
         * Parse input line into seconds (%d) and a message
         * (%64[^\n]), consisting of up to 64 characters
         * separated from the seconds by whitespace.
         */
        if (sscanf (line, "%d %64[^\n]", 
            &seconds, message) < 2) {
            fprintf (stderr, "Bad command\n");
        } else {
            pid = fork ();
            if (pid == (pid_t)-1)
                errno_abort ("Fork");
            if (pid == (pid_t)0) {
                /*
                 * If we're in the child, wait and then print a message
                 */
                sleep (seconds);
                printf ("(%d) %s\n", seconds, message);
                exit (0);
            } else {
                /*
                 * In the parent, call waitpid() to collect any children that
                 * have already terminated.
                 *
                 * If you pass -1 and WNOHANG, waitpid() will check if any 
                 * zombie-children exist. If yes, one of them is reaped and 
                 * its exit status returned. If not, either 0 is returned 
                 * (if unterminated children exist) or -1 is returned (if 
                 * not) and ERRNO is set to ECHILD (No child processes).
                 */
                do {
                    pid = waitpid ((pid_t)-1, NULL, WNOHANG);
                    if (pid == (pid_t)-1)
                        errno_abort ("Wait for child");
                } while (pid != (pid_t)0);
            }
        }
    }
}
