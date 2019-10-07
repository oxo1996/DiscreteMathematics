#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num = 1;

void subset(int n, int item, int* ptr, char** argv) {
	if (item == n + 1) {
		printf("[%04d] " , num);
		for (int i = 1; i <= n; i++)
			if (ptr[i] == 1) printf("%s, ", argv[i]);
		if (num == 1) {
			unsigned char a = 0x9B;
			printf("%c ", a);
		}
		num++;
		printf("\n");
	}
	else {
		ptr[item] = 0;
		subset(n, item + 1, ptr, argv);
		ptr[item] = 1;
		subset(n, item + 1, ptr, argv);
	}
}

int main(int argc, char* argv[]) {
	int* ptr = malloc(sizeof(int) * argc);
	system("chcp 437");
	subset(argc - 1, 1, ptr, argv);

	printf("***---------------------------------------***\n");
	printf("	Computer Science & Engineering\n	20154057 KIM SUNG MIN\n");
	printf("***---------------------------------------***\n");
}