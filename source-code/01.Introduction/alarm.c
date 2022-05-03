/*
 * alarm.c
 *
 * Simple synchronous alarm program. This is used as a
 * reference for progressive examples of asynchronous
 * alarm programs.
 */
#include "errors.h"

int main (int argc, char *argv[])
{
    int seconds;
    char line[128];
    char message[64];

    if( argc == 2 && strcmp(argv[1],"--help") ==  0){
        printf("%s time[sec] message\n", argv[0]);
        exit(EXIT_SUCCESS);
    }

    while (1) {
        printf ("Alarm> ");
        if (fgets (line, sizeof (line), stdin) == NULL) 
          exit (0);
        if (strlen (line) <= 1) 
          continue;

        /*
         * Parse input line into seconds (%d) and a message
         * (%64[^\n]), consisting of up to 64 characters
         * separated from the seconds by whitespace.
         */
        if (sscanf (line, "%d %64[^\n]", 
            &seconds, message) < 2) {
            fprintf (stderr, "Bad command\n");
        } else {
            sleep (seconds);
            printf ("(%d) %s\n", seconds, message);
        }
    }
}
