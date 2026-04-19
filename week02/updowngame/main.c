#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int answer = rand() % 100;
	int try;
	int i;
	int question;
	try = 0;
	do {
		printf("정답을 추측하여 입력하시오: ");
		scanf("%d", &question);
		if (question > answer)
		{
			printf("down.\n");
		}
		else
		{
			printf("up.\n");
		}
		try++;
	} while (question != answer);
	printf("축하합니다. 시도횟수=%d\n", try);
	return 0;
}
