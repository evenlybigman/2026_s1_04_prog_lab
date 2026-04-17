// 두개의 텍스트 파일을 비교하는 프로그램
// fp1, fp2받고 지정, fgetc = int 값 반환. 비교하다가 처음 다를 때 프린트 시작 후 같아질 때 까지 프린트
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	//포인터 선언
	FILE* fp1, * fp2;
	fp1 = fp2 = NULL;
	char file1[100], file2[100];

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

	//c1 c2에 txt 값 저장
	int i = 0;
	int c1[1000], c2[1000];
	while ((c1[i] = fgetc(fp1)) != EOF) {
		i++;
	}
	c1[i] = '\0';
	i = 0;
	while ((c2[i] = fgetc(fp2)) != EOF) {
		i++;
	}
	c2[i] = '\0';

	int same = 1; //1이면 같은 파일
	//문자가 다를때까지 반복 ->
	printf("<< ");
	for (int i = 0; c1[i] != '\0'; i++) { //a파일 길이만큼 반복
		if (c1[i] != c2[i]) { //문자 비교 후 다르다면 문장이 끝나면 공백 한번
			printf("%c", c1[i]); //그 문자 출력
			if (c1[i + 1] == ' ') printf("%c", ' ');
			same = 0;
		}
	}
	if (same == 1) printf("파일은 서로 일치함");
	printf(" >> ");
	for (int i = 0; c2[i] != '\0'; i++) { //a파일 길이만큼 반복
		if (c2[i] != c1[i]) { //문자 비교 후 다르다면
			printf("%c", c2[i]); //그 문자 출력
			if (c2[i + 1] == ' ') printf("%c", ' ');
		}
	}

	fclose(fp1);
	fclose(fp2);
}