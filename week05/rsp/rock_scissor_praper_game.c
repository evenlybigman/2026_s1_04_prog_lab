#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum game {
	rock,
	scissor,
	paper
};

const char* toString(enum game g) {
	if (g == rock) return "바위";
	else if (g == scissor) return "가위";
	else return "보";
}

int main() {
	enum game user;
	enum game computer;
	printf("컴퓨터와 가위바위보게임을 시작합니다.\n");
	while (1) {
		printf("가위 (0) 바위 (1) 보 (2) / 종료(-1) : ");
		scanf("%d", &user);

		if (user == -1) {
			printf("게임 종료");
			break;
		}

		srand((unsigned int)time(NULL));
		computer = rand() % 3;

		printf("당신이 낸 수 (%s) / 컴퓨터가 낸 수 (%s)\n", toString(user), toString(computer));
		if (user == computer) {
			printf("비겼습니다\n");
		}
		else if ((user == rock && computer == scissor) ||
			(user == scissor && computer == paper) ||
			(user == paper && computer == rock))
			printf("당신이 이겼습니다.\n");
		else {
			printf("당신이 졌습니다.\n");
		}
	}
}