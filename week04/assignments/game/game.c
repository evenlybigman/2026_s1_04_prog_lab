//어드벤처 게임 v1.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
void print_map(int px,int py,int gx,int gy,int mx1, int my1,int mx2,int my2);
// 주인공 #, 몬스터 M, 금 G
//system("cls");

void print_map(px, py,gx,gy,mx1,my1,mx2,my2) {
	system("cls");
	char map[10][10];
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			map[x][y] = '.';
		}
	}
	map[mx1][my1] = 'M';
	map[mx2][my2] = 'M';
	map[gx][gy] = 'G';
	map[px][py] = '#';
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

int main() { //1,1 w -> 0, 1
	srand(time(NULL));
	// 각 유닛들 초기 위치 설정
	int px = 0, py = 0;
	int gx = 9, gy = 9;
	int mx1 = rand() % 10, my1 = rand() % 10;
	int mx2 = rand() % 10, my2 = rand() % 10;
	// 몬스터1 위치가 플레이어 위치거나 금의 위치면 위치 다시 설정)
	if ((mx1 + my1) == 0 || (mx1 + my1) == 18) {
		mx1 = rand() % 10, my1 = rand() % 10;
	}
	// 몬스터2 위치가 플레이어 위치거나 금의 위치면 위치 다시 설정)
	if ((mx2 + my2) == 0 || (mx2 + my2) == 18) {
		mx2 = rand() % 10, my2 = rand() % 10;
	}
	char input = '1';
	printf("왼쪽 이동:a, 오른쪽 이동: d 위쪽 이동: w, 아래쪽 이동: s\n");
	while (1) { // 0,9 -> d 0,9  1,0
		print_map(px, py,gx,gy,mx1,my1,mx2,my2);
		if ((px == mx1 && py == my1) || (px == mx2 && py == my2)) {
			printf("Lose");
			break;
		}
		if (px == gx && py == gy) {
			printf("WIN");
			break;
		}
		input = _getch();
		switch (input) {
		case 'w':
			if (px == 0);
			else px--;
			break;
		case 'a':
			if (py == 0);
			else py--;
			break;
		case 's':
			if (px == 9);
			else px++;
			break;
		case 'd':
			if (py == 9);
			else py++;
			break;
		default:
			continue;
		}
	}
}