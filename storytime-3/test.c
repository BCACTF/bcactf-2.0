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

int main()
{
    // TODO: Make it so this is initialized in a similar way as storytime-2,
    // and has a deciphering function based on the current time.
    // Must be 9:02 to decipher properly.

    // bcactf{h1dd3n_c0d3_1s_h1dd3n_2c8d}

    int nums[0x22] = {0};
    
    nums[0x00] = 0x135;
    nums[0x01] = 0x142;
    nums[0x02] = 0x143;
    nums[0x03] = 0x151;
    nums[0x04] = 0x19f;
    nums[0x05] = 0x16d;
    nums[0x06] = 0x1cb;
    nums[0x07] = 0x186;
    nums[0x08] = 0xb3;
    nums[0x09] = 0x185;
    nums[0x0a] = 0x18d;
    nums[0x0b] = 0xd2;
    nums[0x0c] = 0x1c4;
    nums[0x0d] = 0x191;
    nums[0x0e] = 0x1aa;
    nums[0x0f] = 0xe7;
    nums[0x10] = 0x1bf;
    nums[0x11] = 0x101;
    nums[0x12] = 0x1b8;
    nums[0x13] = 0x109;
    nums[0x14] = 0x21a;
    nums[0x15] = 0x1d3;
    nums[0x16] = 0x1fe;
    nums[0x17] = 0x12a;
    nums[0x18] = 0x1ff;
    nums[0x19] = 0x205;
    nums[0x1a] = 0x14a;
    nums[0x1b] = 0x23e;
    nums[0x1c] = 0x208;
    nums[0x1d] = 0x15f;
    nums[0x1e] = 0x22a;
    nums[0x1f] = 0x185;
    nums[0x20] = 0x23f;
    nums[0x21] = 0x2aa;

    char flag[0x22] = {' '};

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    int hour = tm_struct->tm_hour;
    int minute = tm_struct->tm_min;

    printf("%d\n%d\n", hour, minute);

    for (int i = 0; i < 0x22; i++)
    {
        flag[i] = (char)((nums[i] >> minute) + hour - (i * minute));
    }

    printf("%s\n", flag);
}