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
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);

    srand(time(NULL));
    system("clear");
    // https://patorjk.com/software/taag/#p=display&f=Big%20Money-ne&t=Lucky%0ALotto
    sleepNanos(0, 500000000);
    puts(" /$$                           /$$                ");
    puts("| $$                          | $$                ");
    puts("| $$       /$$   /$$  /$$$$$$$| $$   /$$ /$$   /$$");
    puts("| $$      | $$  | $$ /$$_____/| $$  /$$/| $$  | $$");
    puts("| $$      | $$  | $$| $$      | $$$$$$/ | $$  | $$");
    puts("| $$      | $$  | $$| $$      | $$_  $$ | $$  | $$");
    puts("| $$$$$$$$|  $$$$$$/|  $$$$$$$| $$ \\  $$|  $$$$$$$");
    puts("|________/ \\______/  \\_______/|__/  \\__/ \\____  $$");
    puts("                                         /$$  | $$");
    puts("                                        |  $$$$$$/");
    puts("                                         \\______/ ");
    sleepNanos(0, 500000000);
    puts(" /$$                   /$$     /$$                ");
    puts("| $$                  | $$    | $$                ");
    puts("| $$        /$$$$$$  /$$$$$$ /$$$$$$    /$$$$$$   ");
    puts("| $$       /$$__  $$|_  $$_/|_  $$_/   /$$__  $$  ");
    puts("| $$      | $$  \\ $$  | $$    | $$    | $$  \\ $$  ");
    puts("| $$      | $$  | $$  | $$ /$$| $$ /$$| $$  | $$  ");
    puts("| $$$$$$$$|  $$$$$$/  |  $$$$/|  $$$$/|  $$$$$$/  ");
    puts("|________/ \\______/    \\___/   \\___/   \\______/   ");
    puts("");
    puts("");
    puts("");
    sleepNanos(1, 0);
    puts("Welcome to the Lucky Lotto Slot Machine!");
    sleepNanos(1, 500000000);
    puts("Let's see if you're today's big winner!");
    sleepNanos(1, 500000000);
    // Check on programatic, can they parse & respond correctly?
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};
    char c = alphabet[rand() % 26];
    printf("Enter the letter \"%c\" to pull the lever...\n", c);
    while ((getchar()) != c);
    system("clear");
    puts("Spinning...");
    sleepNanos(0, 500000000);
    // Get three letters ready
    char first, second, third = ' ';
    // "Spin" three slots.
    // Having the ending \r fixes spacing issues and the extra closing brackets but makes the "spin" less pretty.
    time_t start = time(NULL);
    time_t current = time(NULL);
    do {
        current = time(NULL);
        printf("\r           " /*\r*/);
        first = alphabet[rand() % 26];
        printf("[[[ %c ]]]", first);
        sleepNanos(0, 100);
    } while (difftime(current, start) < 1);
    puts("");
    sleepNanos(0, 500000000);
    start = time(NULL);
    current = time(NULL);
    do {
        current = time(NULL);
        printf("\r           " /*\r*/);
        second = alphabet[rand() % 26];
        printf("[[[ %c ]]]", second);
        sleepNanos(0, 100);
    } while (difftime(current, start) < 1);
    puts("");
    sleepNanos(0, 500000000);
    start = time(NULL);
    current = time(NULL);
    do {
        current = time(NULL);
        printf("\r           " /*\r*/);
        third = alphabet[rand() % 26];
        printf("[[[ %c ]]]", third);
        sleepNanos(0, 100);
    } while (difftime(current, start) < 3);
    puts("");
    sleepNanos(1, 0);
    // If all the letters match, print the flag.
    if (first == second && first == third)
    {
        puts("Congratulations! You won the grand prize!");
        sleepNanos(1, 500000000);
        puts("It's a flag!");
        sleepNanos(1, 500000000);
        puts("");
        puts("   .^.");
        puts("  (( ))");
        puts("   |#|_______________________________");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#||$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|");
        puts("   |#|\'\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\'");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("   |#|");
        puts("");
        sleepNanos(1, 500000000);
        puts("bcactf{y0u_g0t_1ucKy_af23dd97g64n}");
    }
    else if (first == second)
    {
        puts("Congratulations! You won a prize!");
        sleepNanos(1, 500000000);
        puts("It's a zstegasaurus plushie!");
        sleepNanos(1, 500000000);
        // https://www.asciiart.eu/animals/reptiles/dinosaurs
        puts("");
        puts("                         .       .");
        puts("                        / `.   .' \\");
        puts("                .---.  <    > <    >  .---.");
        puts("                |    \\  \\ - ~ ~ - /  /    |");
        puts("                 ~-..-~             ~-..-~");
        puts("             \\~~~\\.'                    `./~~~/");
        puts("   .-~~^-.    \\__/                        \\__/");
        puts(" .'  O    \\     /               /       \\  \\");
        puts("(_____,    `._.'               |         }  \\/~~~/");
        puts(" `----.          /       }     |        /    \\__/");
        puts("       `-.      |       /      |       /      `. ,~~|");
        puts("           ~-.__|      /_ - ~ ^|      /- _      `..-'   f: f:");
        puts("                |     /        |     /     ~-.     `-. _||_||_");
        puts("                |_____|        |_____|         ~ - . _ _ _ _ _>");
        puts("");
        sleepNanos(1, 500000000);
        puts("It should magically appear on your desk within the next 12 half-lives of carbon!");
    }
    else if (first == third)
    {
        puts("Congratulations! You won a prize!");
        sleepNanos(1, 500000000);
        puts("It's my respect!");
        sleepNanos(1, 500000000);
        // https://textart4u.blogspot.com/2012/04/smiley-face-with-thumbs-up-text-art.html
        puts("");
        puts("                      ¶¶¶¶¶¶¶¶¶");
        puts("                    ¶¶          ¶¶");
        puts("      ¶¶¶¶¶       ¶¶              ¶¶");
        puts("     ¶     ¶    ¶¶     ¶¶    ¶¶     ¶¶");
        puts("     ¶     ¶   ¶¶      ¶¶    ¶¶       ¶¶");
        puts("     ¶    ¶  ¶¶        ¶¶    ¶¶        ¶¶");
        puts("      ¶   ¶   ¶                         ¶¶");
        puts("    ¶¶¶¶¶¶¶¶¶¶¶¶                        ¶¶");
        puts("   ¶            ¶ ¶¶             ¶¶     ¶¶");
        puts("  ¶¶            ¶  ¶¶           ¶¶      ¶¶");
        puts(" ¶¶   ¶¶¶¶¶¶¶¶¶¶¶    ¶¶       ¶¶        ¶¶");
        puts(" ¶               ¶     ¶¶¶¶¶¶¶         ¶¶");
        puts(" ¶¶              ¶                    ¶¶.");
        puts("  ¶   ¶¶¶¶¶¶¶¶¶¶¶¶                   ¶¶");
        puts("  ¶¶           ¶  ¶¶                ¶¶");
        puts("   ¶¶¶¶¶¶¶¶¶¶¶¶     ¶¶            ¶¶");
        puts("                       ¶¶¶¶¶¶¶¶¶¶¶");
        puts("");
        sleepNanos(1, 500000000);
        puts("Hey, you're pretty cool, dood!");
    }
    else if (second == third)
    {
        puts("");
        puts("Congratulations! You won a prize!");
        sleepNanos(1, 500000000);
        puts("It's a MISSINGNO.!");
        sleepNanos(1, 500000000);
        // https://botwiki.org/bot/missingno/
        puts("");
        puts("     ▞▚▟▛▚");
        puts("     ▞▗▝▗▜");
        puts("     ▙▖▞▝▜");
        puts("     ▝▖▝▗▘");
        puts("     ▞▚▗▚▖");
        puts("     ▜▞▛▘▝");
        puts("▙▙▗▟▖▘▞▖▜▞");
        puts("▞▙▟▛▙█▞▝▙▛");
        puts("▝▟▞█▘▞█▖▙▝");
        puts("▛▖▞▜▙▞▚▜▙█");
        puts("▗▜▝▛▘▝▟▘▞▙");
        puts("▗▜▝▘▘▝▗▚▟▞");
        puts("▜▘▞▚▚▞▜█▛▚");
        puts("▝▚▝▝▝▙▜▟▘▞");
        puts("▞▛▝▞▘▘▙▚▛█");
        puts("");
        sleepNanos(1, 500000000);
        puts("Wǫw, I hǫpε τhiς dǫεςη'τ hανε αny αdνεrςε εffεcτς!");
        sleepNanos(1, 500000000);
    }
    else
    {
        puts("");
        puts("You didn't win anything. Try matching more letters next time!");
    }
    puts("");
    sleepNanos(1, 500000000);
    if (second == third && first != second)
    {
        puts("Cǫmε bαcκ nεχτ τimε!");
    }
    else
    {
        puts("Come back next time!");
    }
    sleepNanos(0, 500000000);
}
