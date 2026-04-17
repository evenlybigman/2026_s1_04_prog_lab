// 두개의 텍스트 파일을 비교하는 프로그램
// 파일이 서로 일치함의 조건
// 1. 두 텍스트 파일의 모든 문자가 같은 문자여야함
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
		fclose(fp1); //
		return 1;
	}
	
	while (1) {
		ch1 = fgetc(fp1);
		ch2 = fgetc(fp2);
		if (ch1 != ch2) { //문자가 다르면
			same = 0;
			break;
		}

		if (ch1 == EOF || ch2 == EOF)
			break;
	}

	if (same) printf("파일은 서로 일치함");
	else {
		fseek(fp1, 0L, SEEK_SET); //파일 포인터 초기화
		printf("<< ");
		while ((ch1 = fgetc(fp1)) != EOF) {
			printf("%c", ch1);
		}
		printf(" >> ");

		fseek(fp2, 0L, SEEK_SET); //파일 포인터 초기화
		while ((ch2 = fgetc(fp2)) != EOF) {
			printf("%c", ch2);
		}
	}

	//파일 닫기
	fclose(fp1);
	fclose(fp2);

	return 0;
}