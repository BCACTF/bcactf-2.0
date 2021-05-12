#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_flag(char* flag) {
	int len = strlen(flag);
	if (len != 47)
		return 1;
	int i = 1 + 1;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	i = i + i;
	return 0;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("I need a flag to check!\n");
		return 1;
	}
	printf("Checking your flag...\n");
	if (!check_flag(argv[1]))
		printf("Flag correct!\n");
	else
		printf("How did you survive that with an incorrect flag???\n");
	return 0;
}
