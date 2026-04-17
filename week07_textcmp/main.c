// 두개의 텍스트 파일을 비교하는 프로그램
// 파일이 서로 일치함의 조건
// 1. 두 텍스트 파일의 모든 문자가 같은 문자여야함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//포인터 선언
	FILE* fp1, * fp2;
	fp1 = fp2 = NULL;
	char file1[1000], file2[1000];
	char word1[100], word2[100];
	//file1 열기
	printf("첫 번째 파일 이름: ");
	scanf("%s", file1);
	fp1 = fopen(file1, "r");
	if (fp1 == NULL) {
		printf("첫 번째 파일을 찾을 수 없습니다.");
		exit(1);
	}
	//file2 열기
	printf("두 번째 파일 이름: ");
	scanf("%s", file2);
	fp2 = fopen(file2, "r");
	if (fp2 == NULL) {
		printf("두 번째 파일을 찾을 수 없습니다.");
		exit(1);
	}
	
	//일치하면 "파일은 서로 일치함" 다르다면 두 파일 전체 출력
	//str1에 텍스트 내용 저장
	int str1[1000], str2[1000];
	int i = 0;
	while ((str1[i] = fgetc(fp1)) != EOF) { //text가 끝날때까지 반복
		i++;
	}
	str1[i] = '\0'; //문자열의 끝 지정

	i = 0;
	while ((str2[i] = fgetc(fp2)) != EOF) { //text가 끝날때까지 반복
		i++;
	}
	str2[i] = '\0'; //문자열의 끝 지정

	printf("<< ");
	for (i = 0; str1[i] != '\0'; i++) {
		putchar(str1[i]);
	}
	printf(" >> ");

	for (i = 0; str2[i] != '\0'; i++) {
		putchar(str2[i]);
	}

	fclose(fp1);
	fclose(fp2);
}