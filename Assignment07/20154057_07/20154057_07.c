#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

char tok[100000][100];
int count[100000];


int main(int argc, char* argv[])
{	
	for (int i = 0; i < 10000; i++) {

		count[i] = 0;
	}

	FILE* fp1, * fp2;
	if ((fp1 = fopen(argv[1], "rt")) == NULL) { //fail to open file for read
		printf("fail to open file.");
		return 0;
	}
	if ((fp2 = fopen(argv[2], "wt")) == NULL) { //fail to open file for write
		printf("fail to create file for write.");
		return 0;
	}

	char delimiters[66];
	int delnum = 0;
	for (int i = 1; i < 48; i++) {
		delimiters[delnum++] = i;
	}
	for (int i = 58; i < 65; i++) {
		delimiters[delnum++] = i;
	}
	for (int i = 91; i < 97; i++) {
		delimiters[delnum++] = i;
	}
	for (int i = 123; i < 128; i++) {
		delimiters[delnum++] = i;
	}
	delimiters[65] = '\0';

	char* token;
	int tokbe = 0;
	int i = 0;
	char src[100];

	while (!feof(fp1)) {
		fgets(src, sizeof(src), fp1);
		token = strtok(src, delimiters);
		while (token != NULL) {
			strlwr(token);
			for (int iter = 0; iter < i; iter++) {
				if (!strcmp(tok[iter], token)) {
					count[iter]++;
					tokbe = 1;
					break;
				}
			}
			if (tokbe == 0) {
				strcpy(tok[i], token);
				count[i] = 1;
				i++;
			}
			tokbe = 0;
			token = strtok(NULL, delimiters);
		}
	}

	int sum = 0;
	for (int iter = 0; iter<i ; iter++) {
		fprintf(fp2, "[%04d] ", iter+1);
		fprintf(fp2, "%s", tok[iter]);
		fprintf(fp2, " (%d)\n", count[iter]);
		sum += count[iter];
	}

	fputs("[total] ", fp2);
	fprintf(fp2, "%d\n", sum);
	fputs("***---------------------------------------***\n", fp2);
	fputs(" Computer Science & Engineering\n 20154057 KIM SUNG MIN\n", fp2);
	fputs("***---------------------------------------***\n", fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
