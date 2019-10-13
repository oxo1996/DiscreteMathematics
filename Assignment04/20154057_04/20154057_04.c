#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <wchar.h>

int num = 1;

void subset(char* argv[], int argc, int count, int aindex, char* output[], int oindex, FILE* fp) {
	if (aindex == count) {
		//char* strn = malloc(sizeof(char)*4);
		char strn[10];
		sprintf(strn, "[%04d]", num);
		fputs(strn, fp);
		num++;
		for (int j = 0; j < count; j++) {
			if (j != count - 1) {
				fputs(output[j], fp);
				fputs(", ", fp);
			}
			else fputs(output[j], fp);
		}
		fputs("\n", fp);
		return;
	}

	if (oindex >= argc - 2)
		return;
	output[aindex] = argv[oindex];
	subset(argv, argc, count, aindex + 1, output, oindex + 1, fp);
	subset(argv, argc, count, aindex, output, oindex + 1, fp);
}


int main(int argc, char* argv[]) {

	FILE* fp;
	char str[64];   // change the number appropriately to your program
	char strnum[10];
	// file = argv[1]

	// see the usage of r, rt, w, wt, r+, w+
	if ((fp = fopen(argv[1], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}

	system("chcp 437");
	sprintf(strnum, "[%04d]", num);
	fputs(strnum, fp);
	sprintf(strnum, "%c\n", 0x9B);
	fputs(strnum, fp);
	num++;

	for (int i = 0; i < argc - 2; i++) {
		argv[i] = argv[i + 2];
	}

	int** output = malloc(sizeof(int) * (argc - 1));
	for (int i = 1; i <= argc - 1; i++) {
		subset(argv, argc, i, 0, output, 0, fp);
	}

	fputs("***---------------------------------------***\n", fp);
	fputs(" Computer Science & Engineering\n 20154057 KIM SUNG MIN\n", fp);
	fputs("***---------------------------------------***\n", fp);
	fclose(fp);
	return 0;
}
