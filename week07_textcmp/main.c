// 두개의 텍스트 파일을 비교하는 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//포인터 선언
	FILE* fp1 = NULL, *fp2 = NULL;
	char file_name1[100], file_name2[100];
	int ch1, ch2;
	int same = 1;
	//file1 열기
	printf("첫 번째 파일 이름: ");
	scanf("%s", file_name1);
	fp1 = fopen(file_name1, "r");
	if (fp1 == NULL) {
		printf("첫 번째 파일을 찾을 수 없습니다.");
		return 1;
	}
	//file2 열기
	printf("두 번째 파일 이름: ");
	scanf("%s", file_name2);
	fp2 = fopen(file_name2, "r");
	if (fp2 == NULL) {
		printf("두 번째 파일을 찾을 수 없습니다.");
		fclose(fp1); //fp1 닫기
		return 1;
	}
	
	//파일 비교문
	while (1) {
		ch1 = fgetc(fp1); 
		ch2 = fgetc(fp2);

		if (ch1 != ch2) {
			same = 0;
			break;
		}

		if (ch1 == EOF || ch2 == EOF)
			break;
	}

	//판별 후 처리
	if (same) 
		printf("파일은 서로 일치함");
	else {
		fseek(fp1, 0L, SEEK_SET);
		printf("<< ");
		while ((ch1 = fgetc(fp1)) != EOF) {
			printf("%c", ch1);
		}
		printf(" >> ");

		fseek(fp2, 0L, SEEK_SET);
		while ((ch2 = fgetc(fp2)) != EOF) {
			printf("%c", ch2);
		}
	}

	fclose(fp1);
	fclose(fp2);

	return 0;
}