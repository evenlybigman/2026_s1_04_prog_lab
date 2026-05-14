#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

// 방향키 아스키 코드
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

// 게임판 출력 위치
#define BX 5
#define BY 1

// 게임판 크기
#define BW 10
#define BH 20

// 커서 표시 여부
#define NOCURSOR 0
#define NORMALCURSOR 1

// 게임판 상태값
#define EMPTY 0
#define BRICK 1
#define WALL 2

// BOOL 타입 정의
typedef int BOOL;
#define TRUE 1
#define FALSE 0

// 블록 좌표 구조체 정의
typedef struct Point {
	int x, y;
} Point;

int rot = 0;
char* arTile[] = { "  ", "■", "□" }; //비었음, 브릭 있음, 벽
int board[BW + 2][BH + 2];

// 테트리스 블록 데이터 정의 (7가지 블록과 4가지 회전 상태)
// Shape[블록 번호][회전 상태][블록 4칸의 좌표]


Point Shape[][4][4] = {
	// 0번 블록: I자형
	{
		{{0,0},{1,0},{2,0},{-1,0}},
		{{0,0},{0,1},{0,-1},{0,-2}},
		{{0,0},{1,0},{2,0},{-1,0}},
		{{0,0},{0,1},{0,-1},{0,-2}}

	},
	// 1번 블록: ㅁ자형
	{
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}},
		{{0,0},{1,0},{0,1},{1,1}}

	},
	// 2번 블록
	{
		{{0,0},{-1,0},{0,-1},{1,-1}},
		{{0,0},{0,1},{-1,0},{-1,-1}},
		{{0,0},{-1,0},{0,-1},{1,-1}},
		{{0,0},{0,1},{-1,0},{-1,-1}}

	},
	// 3번 블록: ㄹ자형
	{
		{{0,0},{-1,-1},{0,-1},{1,0}},
		{{0,0},{-1,0},{-1,1},{0,-1}},
		{{0,0},{-1,-1},{0,-1},{1,0}},
		{{0,0},{-1,0},{-1,1},{0,-1}}

	},
	// 4번 블록: ㄴ자형
	{
		{{0,0},{-1,0},{1,0},{-1,-1}},
		{{0,0},{0,-1},{0,1},{-1,1}},
		{{0,0},{-1,0},{1,0},{1,1}},
		{{0,0},{0,-1},{0,1},{1,-1}}

	},
	// 5번 블록: ㄱ자형
	{
		{{0,0},{1,0},{-1,0},{1,-1}},
		{{0,0},{0,1},{0,-1},{-1,-1}},
		{{0,0},{1,0},{-1,0},{-1,1}},
		{{0,0},{0,-1},{0,1},{1,1}}

	},
	// 6번 블록: ㅜ자형
	{
		{{0,0},{-1,0},{1,0},{0,1}},
		{{0,0},{0,-1},{0,1},{1,0}},
		{{0,0},{-1,0},{1,0},{0,-1}},
		{{0,0},{-1,0},{0,-1},{0,1}}
	}
};

void gotoxy(int x, int y) {
	COORD pos;

	pos.X = (SHORT)(x - 1);
	pos.Y = (SHORT)(y - 1);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawBoard() {
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			gotoxy(BX + x * 2, BY + y);
			printf("%s", arTile[board[x][y]]);
		}
	}
}

void PrintBlock(int block, int startX, int startY)
{
	// 각 블록 4칸 출력
	for (int i = 0; i < 4; i++) {
		int x = startX + Shape[block][rot][i].x * 2; // 블록 간격을 2로 설정해서 출력
		int y = startY + Shape[block][rot][i].y;

		gotoxy(x, y);
		printf("■");
	}
}

int main(void) {
	int input;
	
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			if (x == 0 || x == BW + 1 || y == BH + 1) board[x][y] = WALL;
			else board[x][y] = EMPTY;
		}
	}

	while (1) {
		system("cls");

		// 블록 7개를 순서대로 출력하는 테스트 코드
		for (int i = 0; i < 7; i++) {
			gotoxy(0, 3 + i * 4); // 각 블록을 아래로 간격을 두고 출력
			printf("블록 %d: ", i);
			PrintBlock(i, 15, 3 + i * 4); // 각 블록을 오른쪽으로 간격을 두고 출력
			printf("\n");
		}

		input = _getch();
		if (input == 224) {
			input = _getch();

			if (input == UP) {
				rot++;
				if (rot > 3) rot = 0;
			}
			else {
				system("cls");
				drawBoard();
				_getch();
			}
		}
	}
		system("cls");
	}