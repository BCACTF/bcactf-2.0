#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>

int main(int argc, char** argv);

int perms(void *addr) {
    // Move the pointer to the page boundary
    int page_size = getpagesize();
    addr -= (unsigned long)addr % page_size;

    if(mprotect(addr, page_size, PROT_READ | PROT_WRITE | PROT_EXEC) == -1) {
        return -1;
    }

    return 0;
}

int check_flag(char* flag) {
	int len = strlen(flag);
	if (len != 47)
		return 47;
	long long *stuff = &&hello;
	long long *fl = flag;
	if (perms((void*)stuff)) {
		printf("My innocent flag checker can't run with such high security...\n");
		return 1;
	}
	stuff[0] ^= fl[0];
hello:
	stuff[1] ^= fl[1];
	stuff[2] ^= fl[2];
	stuff[3] ^= fl[3];
	stuff[4] ^= fl[4];
	stuff[5] ^= fl[5];
	return 0;
}

int main(int argc, char** argv) {
	if (perms((void*)main)) {
		printf("My innocent flag checker can't run with such high security...\n");
		return 1;
	}
	if (argc < 2) {
		printf("I need a flag to check!\n");
		return 1;
	}
	printf("Checking your flag...\n");
	int t = check_flag(argv[1]);
	if (!t)
		printf("Flag correct!\n");
	else if (t == 47)
		printf("Did you even read the assembly?\n");
	else
		printf("How did you survive that with an incorrect flag???\n");
	return 0;
}
