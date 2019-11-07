#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int num;

int sumNumbers(int* pNumbers, int nIndex, FILE* fp2)
{
	// basis step
	if (nIndex <= 0)
	{
		return 0;
	}
	// recursive step
	else
	{
		int sum = pNumbers[nIndex - 1] + sumNumbers(pNumbers, nIndex - 1, fp2);
		fprintf(fp2, "[%03d]", num--);
		fprintf(fp2, "%d\n", sum);
		return sum;
	}
}

int main(int argc, char* argv[]) {

	FILE* fp1, * fp2;
	char str[64];   // change the number appropriately to your program
	// read_file = argv[1]
	// write_file = argv[2]

	// see the usage of r, rt, w, wt, r+, w+
	if ((fp1 = fopen(argv[1], "rt")) == NULL) { //fail to open file for read
		printf("fale to open file.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}
	/*
	while (fgets(str, sizeof(str), fp1)) {   // read a file and write to another file line by line
		printf("%s\n", str);
		fputs(str, fp2);
	}*/
	
	int nNumber = 0;
	fscanf_s(fp1, "%d", &nNumber);  // read from the input file
	num = nNumber;
	int* pNumbers = (int*)calloc(nNumber, sizeof(int));

	for (int i = nNumber-1; i >= 0; i--)
	{
		fscanf_s(fp1, "%d", &pNumbers[i]);        // assign numbers from the input file 
	}


	int nSum = sumNumbers(pNumbers, nNumber, fp2);
	free(pNumbers);

	fputs("***---------------------------------------***\n", fp2);
	fputs(" Computer Science & Engineering\n 20154057 KIM SUNG MIN\n", fp2);
	fputs("***---------------------------------------***\n", fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}