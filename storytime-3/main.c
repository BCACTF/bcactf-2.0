// Do all the includes
// This is running on Unix so ignore unistd.h error if working in windows
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#ifndef __INTELLISENSE__
#include <unistd.h>
#endif

void sleepNanos(int seconds, int nanos)
{ // cross-platform sleep function
    // https://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds
    struct timespec ts;
    ts.tv_sec = seconds;
    ts.tv_nsec = nanos;
    nanosleep(&ts, NULL);
}

int main()
{
    int lines = 4;
    for (;;)
    {

        char *lyrics[50] =
            {"I know a song that gets on everybody's nerves,",
             "Everybody's nerves, yes, on everybody's nerves,",
             "I know a song that gets on everybody's nerves,",
             "And this is how it goes."};

        for (int i = 0; i < lines; i++)
        {
            printf("%s\n", lyrics[i]);
            sleepNanos(1, 500000000);
        }
    }

    char *flag = "bcactf{w0ol_m4k3s_str1ng_ziv4mk3ca91b}";
    printf("%s\n", flag);
}
