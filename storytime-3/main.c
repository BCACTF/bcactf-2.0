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

    char *falg = "bcactf{n0t_th3_fL4g_L0L}";
    printf("%s\n", falg);
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
    puts("74 68 65 20 73 65 63 6f 6e 64 20 6d 69 6e 75 74 65");
}

int FUN_2364432() {
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
}

int FUN_2302136() {
    // TODO: Make it so this is initialized in a similar way as storytime-2,
    // and has a deciphering function based on the current time.
    // Must be 9:02 to decipher properly.

    // bcactf{h1dd3n_c0d3_1s_h1dd3n_2c8d}

    int nums[0x25] = {0};

    nums[0x24] = 0xb3;
    nums[0x0e] = 0xb4;
    nums[0x06] = 0xeb;
    nums[0x0d] = 0xcf;
    nums[0x03] = 0xc1;
    nums[0x0a] = 0xd5;
    nums[0x1e] = 0x9a;
    nums[0x1a] = 0x39;
    nums[0x0f] = 0x49;
    nums[0x0c] = 0x48;
    nums[0x14] = 0x40;
    nums[0x04] = 0xe0;
    nums[0x05] = 0xc2;
    nums[0x17] = 0xae;
    nums[0x1d] = 0x37;
    nums[0x23] = 0xa6;
    nums[0x08] = 0xc0;
    nums[0x07] = 0xda;
    nums[0x21] = 0x97;
    nums[0x19] = 0x3d;
    nums[0x11] = 0x9d;
    nums[0x10] = 0xc4;
    nums[0x1c] = 0xb6;
    nums[0x18] = 0x8f;
    nums[0x02] = 0xbf;
    nums[0x13] = 0xbe;
    nums[0x15] = 0xa5;
    nums[0x00] = 0x105;
    nums[0x20] = 0x22;
    nums[0x0b] = 0xa9;
    nums[0x1f] = 0x89;
    nums[0x01] = 0xc4;
    nums[0x12] = 0xa5;
    nums[0x09] = 0x57;
    nums[0x16] = 0x34;
    nums[0x1b] = 0x97;
    nums[0x22] = 0x7e;

    char flag[0x25] = {' '};

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;

    printf("%d\n%d\n", hour, minute);

    for (int i = 0; i < 0x25; i++)
    {
        flag[i] = (char)((nums[i] >> minute) + (hour));
    }
}