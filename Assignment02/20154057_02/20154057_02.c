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
	printf("	��ǻ�Ͱ��к�\n	20154057 �輺��\n");
	printf("***-------------------------***\n");
}