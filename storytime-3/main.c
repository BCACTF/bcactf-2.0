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

int _definitely_a_normal_function () {
    puts("Hey, what time does the library close?");
}

int flag_O_o() {
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("abcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("cabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("abcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("cabcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcabcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
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

int _flag_XvX() {
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
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
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!  ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!   ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!    ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!     ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!     ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!      ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!       ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!        ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!         ");
    puts("According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible. Yellow, black. Yellow, black. Yellow, black. Yellow, black. Ooh, black and yellow! Let's shake it up a little. Barry! Breakfast is ready! Ooming! Hang on a second. Hello? - Barry? - Adam? - Oan you believe this is happening? - I can't. I'll pick you up. Looking sharp. Use the stairs. Your father paid good money for those. Sorry. I'm excited. Here's the graduate. We're very proud of you, son. A perfect report card, all B's. Very proud. Ma! I got a thing going here. - You got lint on your fuzz. - Ow! That's me! - Wave to us! We'll be in row 118,000. - Bye!          ");
}

int FUN_2301548() {
    
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("abcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("cabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("abcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("cabcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcabcabcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfb");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbc");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbca");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcac");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcact");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactf");
    puts("bcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfbcactfb");
}

int FUN_2543102() {
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges.");
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges. ");
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges.  ");
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges.   ");
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges.    ");
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges.     ");
    puts("I usually try to stay polite towards organizers because I know that making a CTF is hard. But there are some issues that need to be fixed. Most importantly, every single challenge is trivially easy. I don't think that's inherently terrible, although it makes the CTF less enjoyable. I think having a CTF where the goal is maxing quickly is defendable. But that means you can't release problems midway through the competition, especially if they are just as easy. Doing that completely nullifying every previous challenge. You also need to check that your challenges work. Both three-step-program and bca-store, the challenges released today, were initially broken. By the time you fix your mistake, many people have solved the challenge. So you now reduce the entire competition to seeing how fast people can refresh and submit their solution to a fixed challenge. I think the best course of action is to get rid of the newly released challenges and to release many more future challenges.      ");
}

int FUN_2310136() {
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
}

int FUN_2310408() {
    puts("74 68 65 20 73 65 63 6f 6e 64 20 6d 69 6e 75 74 65");
}

int FUN_2364432() {
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnerves");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesi");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesik");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesikn");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesikno");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknow");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowa");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowas");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowaso");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowason");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasong");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongt");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongth");
    puts("iknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongthatgetsoneverybodysnervesiknowasongtha");
}

int FUN_2302136(int a, int b, int c, int d, int e, int f, int g, int h, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, int x, int y, int z, int A, int B, int C, int D, int E, int F, int G, int H, int J) {
    
    int nums[0x22] = {0};
    
    nums[0x15] = a;
    nums[0x1c] = b;
    nums[0x07] = c;
    nums[0x0c] = d;
    nums[0x06] = e;
    nums[0x0e] = f;
    nums[0x08] = g;
    nums[0x19] = h;
    nums[0x11] = j;
    nums[0x1d] = k;
    nums[0x13] = l;
    nums[0x10] = m;
    nums[0x1f] = n;
    nums[0x14] = o;
    nums[0x0f] = p;
    nums[0x20] = q;
    nums[0x05] = r;
    nums[0x21] = s;
    nums[0x0b] = t;
    nums[0x12] = u;
    nums[0x1a] = v;
    nums[0x09] = w;
    nums[0x03] = x;
    nums[0x16] = y;
    nums[0x1e] = z;
    nums[0x01] = A;
    nums[0x00] = B;
    nums[0x04] = C;
    nums[0x0d] = D;
    nums[0x02] = E;
    nums[0x1b] = F;
    nums[0x17] = G;
    nums[0x18] = H;
    nums[0x0a] = J;

    char flag[0x22] = {' '};

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    int minute = tm_struct->tm_min;

    for (int i = 0; i < 0x22; i++)
    {
        flag[i] = (char)((nums[i] >> minute) + 21 - (i * minute));
    }

    printf("%s\n", flag);
}

int main()
{
    int lines = 4;
    char *lyrics[50] =
        {"I know a song that gets on everybody's nerves,",
         "Everybody's nerves, yes, on everybody's nerves,",
         "I know a song that gets on everybody's nerves,",
         "And this is how it goes."};

    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);

    while (tm_struct->tm_hour < 25)
    {
        for (int i = 0; i < lines; i++) {
            printf("%s\n", lyrics[i]);
            sleepNanos(1, 500000000);
        }
    }

    // patch with leave return, c9 c3
    printf("%d\n", 123);

    char *falg = "bcactf{n0t_th3_fL4g_L0L}";
    printf("%s\n", falg);

    FUN_2302136(0x1d3, 0x208, 0x186, 0x1c4, 0x1cb, 0x1aa, 0xb3, 0x205, 0x101, 0x15f, 0x109, 0x1bf, 0x185, 0x21a, 0xe7, 0x23f, 0x16d, 0x2aa, 0xd2, 0x1b8, 0x14a, 0x185, 0x151, 0x1fe, 0x22a, 0x142, 0x135, 0x19f, 0x191, 0x143, 0x23e, 0x12a, 0x1ff, 0x18d);
}