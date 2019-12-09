#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

char* tok[10000];
int count[10000];


int main(int argc, char* argv[])
{	
	for (int i = 0; i < 10000; i++) {
		tok[i] = NULL;
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

	const char delimiters[] = "\/,!*()[]{}-+&^%$#@=<>:;\"\'.?_ \t\r\n\v\f";

	char* token;
	int tokbe = 0;
	int i = 0;
	char src[100];

	while (!feof(fp1)) {
		fgets(src, sizeof(src), fp1);
		token = strtok(src, delimiters);
		while (token != NULL) {
			while (tok[i] != NULL) {
				if (!strcmp(tok[i], token)) {
					count[i]++;
					tokbe = 1;
				}
				i++;
			}
			if (tokbe == 0) {
				tok[i] = (char*)malloc(sizeof(token));
				tok[i] = token;
				count[i] = 1;
			}

			i = 0;
			tokbe = 0;
			token = strtok(NULL, delimiters);
		}
	}

	int sum = 0;
	for (int i = 0; tok[i] != NULL; i++) {
		fprintf(fp2, "[%04d] ", i);
		fprintf(fp2, "%s", tok[i]);
		fprintf(fp2, " (%d)\n", count[i]);
		sum += count[i];
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
