#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int getprime(int a);
// 10을 넣었을 때 : 10의 소수들을 찾는다 -> 소수들의 합을 한다. -> answer의 값이 있으면
int getprime(int a) {
	int isprime = 1;
	for (int i = 2; i < a; i++) { // a가 3이면
		if (a % i == 0) {
			isprime = 0;
			return isprime;
			break;
		}
	}
	return isprime;
}

int main() {
	int answer, flag = 0;
	printf("양의 정수를 입력하시오: ");
	scanf("%d", &answer);
	for (int i = 2; i < answer; i++) { // 소수들을 찾는 식 안에 합을 찾고 있으면 출력
		if (getprime(i) == 1) {
			if (getprime(answer - i)==1) {
				printf("%d = %d + %d\n", answer, i, answer - i);
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf("%d은 소수들의 합으로 표시될 수 없습니다.\n", answer);
	return 0;
	}