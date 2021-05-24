// Do all the includes
// This is running on Unix so ignore unistd.h error if working in windows
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
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

    // patch this section with a JMP to the for loop (line 31)
    // Should already have a label attached to it in Ghidra
    int k = 123;
    puts(k);


    // TODO: Make it so this is initialized in a similar way as storytime-2,
    // and has a deciphering function based on the current time.
    // Must be 9:07 to decipher properly.
    char *flag = "bcactf{h1dd3n_c0d3_1s_h1dd3n_238q49eruf5}";
    printf("%s\n", flag);
}

int _definitely_a_normal_function () {
    puts("Hey, what time does the library close?");
}

int flagO_o() {
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
}

int flag_UwU() {
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

int flag_IoI() {
    puts("eveileb I ,01 dna 9 neewteB");
}

int _flag_XvX() {
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
}


int FUN_2300612 () {
    puts("Hey, this book is new.");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye! ");
}

int FUN_2301548() {
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
}

int FUN_2310136() {
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

int FUN_2300612() {
    puts("74 68 65 20 73 65 76 65 6e 74 68 20 6d 69 6e 75 74 65");
}

int _flag_XvX() {
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
}