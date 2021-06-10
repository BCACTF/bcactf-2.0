#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int score = (rand() % 6) + 1;
    char outline[50];

    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    setbuf(stderr, NULL);

    puts("Welcome to the IB (World Lit or Lit/Lang) class!");
    puts("The capstone of this year will be the IB internal assessment...");
    puts("The Individual Oral activity!");
    puts("Gee, doesn't that sound like so much fun??");
    sleep(2);

    puts("Don't worry, you'll have plenty of time to prepare.");
    puts("For example, I'll take a look at your outline and give you comments.");

    fgets(outline, sizeof(outline), stdin);

    sleep(2);
    puts("Hmmm...");
    printf("\"");
    printf(outline);
    printf("\"?\n");
    puts("That's okay, but what does it really mean?");

    sleep(2);
    puts("Alright, that's enough practice!");
    printf("Here's your score: %d.\n", score);

    if (score > 7) {
        puts("Wow!");
        puts("IB's final grading scale is 1-7.");
        printf("How did you get a %d?\n", score);
        puts("Well, I guess we're going back to reading policies...");

        FILE *fp = fopen("flag.txt", "r");

        if (fp == NULL) {
            puts("Welp, I can't seem to remember all my IB policies.");
            puts("I wonder if they make a 10 bullet-point version...");
            puts("[If you are seeing this on the remote server, please contact admin].");
            exit(1);
        }

        int c;
        while ((c = getc(fp)) != EOF) {
            putchar(c);
            usleep(20000);
        }
    }
}
