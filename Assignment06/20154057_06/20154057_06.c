#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>

int num = 1;

void swap(char* a, char* b) {
	char temp = *b;
	*b = *a;
	*a = temp;
}

void permutation(char* clist, int start, int end, FILE* fp2)
{
	if (start >= end)
	{	
		fprintf(fp2, "[%03d]", num++);
		for (int i = 0; i < end; i++) {
			fprintf(fp2, "%c", clist[i]);
		}
		fprintf(fp2, "\n");
	}
	else
	{
		for (int i = start; i < end; i++) {
			swap(&clist[start], &clist[i]);
			permutation(clist, start + 1, end, fp2);
			swap(&clist[start], &clist[i]); // backtrack 
		}
	}
}

int main(int argc, char* argv[]) {

	FILE* fp1, * fp2;
	// read_file = argv[1]
	// write_file = argv[2]

	// see the usage of r, rt, w, wt, r+, w+
	if ((fp1 = fopen(argv[1], "rt")) == NULL) { //fail to open file for read
		printf("fail to open file.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}

	int count;
	fscanf_s(fp1, "%d", &count);
	char* clist = (char*)calloc(count, sizeof(char));
	
	char temp[5] = {0,0,0,0,0};
	fgets(temp, 5, fp1);
	for (int i = 0; i < count; i++)
	{
		fgets(temp, 5, fp1);
		clist[i] = temp[0];       // assign numbers from the input file 
	}

	permutation(clist, 0, count, fp2);

	free(clist);
	fputs("***---------------------------------------***\n", fp2);
	fputs(" Computer Science & Engineering\n 20154057 KIM SUNG MIN\n", fp2);
	fputs("***---------------------------------------***\n", fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}