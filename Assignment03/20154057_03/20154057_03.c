#include <stdio.h>
#include <stdlib.h>

int num = 1;

void subset(char* argv[], int argc, int count, int aindex, char* output[], int oindex){
	if (aindex == count) {
		printf("[%04d]", num);
		num++;
		for (int j = 0; j < count; j++)
			if(j!=count-1) printf("%s, ", output[j]);
			else printf("%s", output[j]);
		printf("\n");
		return;
	}

	if (oindex >= argc-1)
		return;

	output[aindex] = argv[oindex];
	subset(argv, argc, count, aindex + 1, output, oindex + 1);
	subset(argv, argc, count, aindex, output, oindex + 1);
}

void printsubset(char* argv[], int argc, int count) {

	int** output = malloc(sizeof(int) * (count));

	subset(argv, argc, count, 0, output, 0);
}

int main(int argc, char* argv[]) {
	system("chcp 437");
	
	printf("[%04d]", num);
	printf("%c\n", 0x9B);
	num++;

	for (int i = 0; i < argc - 1; i++) {
		argv[i] = argv[i + 1];
	}

	for (int i = 1; i <= argc-1; i++) {
		printsubset(argv, argc, i);
	}

	printf("***---------------------------------------***\n");
	printf("	Computer Science & Engineering\n	20154057 KIM SUNG MIN\n");
	printf("***---------------------------------------***\n");
}