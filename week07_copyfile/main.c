#include <stdio.h>

int main() { //a.txt 내용을 b.txt에 복사하는 프로그램 a를 읽고 b의 쓴다
	FILE* fp1, *fp2;
	char text;
	fp1 = NULL;
	fp2 = NULL;
	fp1 = fopen("a.txt","r");
	fp2 = fopen("b.txt","w");
	if (fp1 == NULL || fp2 == NULL) {
		printf("파일을 찾을 수 없습니다.");
	}
	while ((text=fgetc(fp1)) != EOF) {
		fputc(text,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

	
