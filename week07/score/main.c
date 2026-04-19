#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct student {
	int id;
	char name[20];
	double score;
}Student;

int main() {
	FILE* fp = NULL;
	fp = fopen("scores.txt", "w");
	if (fp == NULL) {
		fprintf(stderr,"socres.txt 파일을 찾을 수 없습니다.\n");
	}

	Student student[100];
	char answer;
	int count = 0;
	int c;

	while (1) {

		printf("학번 : ");
		scanf("%d", &student[count].id);
		fputc(student[count].id,fp);
		printf("이름 : ");
		scanf("%s", student[count].name);
		for (int i = 0; student[count].name != '\0'; i++) {
			fputc(student[count].name[i], fp);
		}
		fputc(student[count].name, fp);
		printf("성적 : ");
		scanf("%d", &student[count].score);
		
		printf("데이터 추가를 계속? (y/n) : ");
		scanf("%d", answer);
		if (answer == 'y') {

			continue;
		}
		else if (answer == 'n') {
			printf("데이터 추가를 종료합니다");
			break;
		}
		else {
			printf("입력 오류");
		}

	}

	return 0;
}
