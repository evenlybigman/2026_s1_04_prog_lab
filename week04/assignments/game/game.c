//어드벤처 게임 v2.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAPSIZE_X 10
#define MAPSIZE_Y 10
// 주인공 #, 몬스터 M, 금 G
//system("cls"); 화면 삭제

//게임맵 출력
void print_map(int px, int py, int gx, int gy, int mx1, int my1, int mx2, int my2) {
	system("cls");
	char map[MAPSIZE_X][MAPSIZE_Y];
	for (int x = 0; x < MAPSIZE_X; x++) {
		for (int y = 0; y < MAPSIZE_Y; y++) {
			map[x][y] = '.';
		}
	}
	map[mx1][my1] = 'M';
	map[mx2][my2] = 'M';
	map[gx][gy] = 'G';
	map[px][py] = '#';
	for (int i = 0; i < MAPSIZE_X; i++) {
		for (int j = 0; j < MAPSIZE_Y; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

//몬스터 X좌표 이동 함수
int monster_move_x(int px,int mx) {
	if (px > mx) {
		if (mx == MAPSIZE_X-1);
		else mx++;
		return mx;
	}
	else {
		if (mx == 0);
		else mx--;
		return mx;
	}
}

//몬스터 Y좌표 이동 함수
int monster_move_y(int py,int my) {
	if (py > my) {
		if (my == MAPSIZE_Y-1);
		else my++;
		return my;
	}
	else {
		if (my == 0);
		else my--;
		return my;
	}
}

int main() {
	srand(time(NULL));
	// 각 유닛들 초기 위치 설정
	char input;
	int px = 0, py = 0;
	int gx = MAPSIZE_X - 1, gy = MAPSIZE_Y - 1;
	int mx1 = rand() % 10, my1 = rand() % 10;
	int mx2 = rand() % 10, my2 = rand() % 10;
	// 몬스터1 위치가 플레이어 위치거나 금의 위치면 위치 다시 설정)
	while ((mx1 == 0 && my1 == 0)||(mx1 == MAPSIZE_X - 1 && my1 == MAPSIZE_Y - 1)) {
		mx1 = rand() % 10, my1 = rand() % 10;
	}
	// 몬스터2 위치가 플레이어 위치거나 금의 위치면 위치 다시 설정)
	while ((mx2 == 0 && my2 == 0) || (mx2 == MAPSIZE_X - 1 && my2 == MAPSIZE_Y - 1)) {
		mx2 = rand() % 10, my2 = rand() % 10;
	}
	//게임 방법 설명
	printf("왼쪽 이동:a, 오른쪽 이동: d 위쪽 이동: w, 아래쪽 이동: s\n");
	//게임 진행 반복
	while (1) {
		//몬스터와 닿으면 패배
		print_map(px, py,gx,gy,mx1,my1,mx2,my2);
		if ((px == mx1 && py == my1) || (px == mx2 && py == my2)) {
			printf("Lose");
			break;
		}
		//금과 닿으면 승리
		if (px == gx && py == gy) {
			printf("WIN");
			break;
		}
		//플레이어의 입력을 받고 이동
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
			if (px == MAPSIZE_X-1);
			else px++;
			break;
		case 'd':
			if (py == MAPSIZE_Y-1);
			else py++;
			break;
		default:
			continue;
		}
		//몬스터가 플레이어를 따라오게 이동
		if (rand() % 2 == 0) {
			mx1 = monster_move_x(px, mx1);
		}
		else my1 = monster_move_y(py, my1);
		if (rand() % 2 == 0) {
			mx2 = monster_move_x(px, mx2);
		}
		else my2 = monster_move_y(py,my2);
	}
}