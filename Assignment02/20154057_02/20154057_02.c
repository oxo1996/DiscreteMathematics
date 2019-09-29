#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int result = 0;

	for (int i = 1; i < argc; i++) {
		if (i % 2) {
			if (!strcmp(argv[i], "+")) result += atoi(argv[i+1]);
			if (!strcmp(argv[i], "-")) result -= atoi(argv[i+1]);
		}
	}

	printf("%d\n", result);
	printf("***-------------------------***\n");
	printf("	ÄÄÇ»ÅÍ°øÇÐºÎ\n	20154057 ±è¼º¹Î\n");
	printf("***-------------------------***\n");
}