#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* fp;
	int number;
	char name[20];
	double score;
	char ch;

	fp = fopen("score.txt", "w");
	if (fp == NULL) {
		printf("성적 파일을 열 수 없습니다.\n");
		exit(1);
	}

	do {
		printf("학번: ");
		scanf("%d", &number);

		printf("이름: ");
		scanf("%s", name);

		printf("성적: ");
		scanf("%lf", &score);

		fprintf(fp, "%d %s %.2lf\n", number, name, score);
		printf("데이터 추가를 계속? (y/n): ");
		scanf(" %c", &ch);

	} while (ch != 'n');

	fclose(fp);
	return 0;
}