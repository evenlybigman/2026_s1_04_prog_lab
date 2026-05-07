#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

#define DINO_BOTTOM_Y 12	// 공룡이 서 있는 y 좌표
#define TREE_BOTTOM_Y 20	// 나무가 서 있는 y 좌표
#define TREE_BOTTOM_X 45	// 나무가 서 있는 x 좌표

void GotoXY(int x, int y) {
	COORD Pos;		// x, y 좌표를 저장할 구조체 변수 선언
	Pos.X = 2 * x;	// x 좌표 설정 (문자 하나당 2칸씩 띄움)
	Pos.Y = y;		// y 좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	// 콘솔 커서 위치 설정
}

void DrawDino(int dinoY) {
	GotoXY(0, dinoY);	// 공룡의 위치로 이동
	static bool legflag = true;	// 다리 움직임을 위한 플래그 변수

	printf("        $$$$$$  \n");
	printf("       $$ $$$$$ \n");
	printf("       $$$$$$$$ \n");
	printf("$      $$$      \n");
	printf("$$     $$$$$    \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf("  $$$$$$$$$$$   \n");
	printf("   $$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");


	if (legflag) { // 다리 움직임이 true일 때
		printf("    $     $$$   \n");
		printf("    $$     $    \n");
		legflag = false; // 다리 움직임 플래그를 false로 변경하여 다음에는 다른 다리가 움직이도록 설정
	}
	else {	// 다리 움직임이 false 일 때
		printf("      $$$   $   \n");
		printf("      $     $$  \n");
		legflag = true;
	}
}

void DrawTree(int treeX) {
	GotoXY(treeX, TREE_BOTTOM_Y);	// 나무의 위치로 이동
	printf("$$$$");	// 나무 그리기
	GotoXY(treeX, TREE_BOTTOM_Y + 1);	// 나무의 위치에서 한 줄 아래로 이동
	printf(" $$ ");	// 나무 그리기
	GotoXY(treeX, TREE_BOTTOM_Y + 2);	// 나무의 위치에서 두 줄 아래로 이동
	printf(" $$ ");	// 나무 그리기
	GotoXY(treeX, TREE_BOTTOM_Y + 3);	// 나무의 위치에서 세 줄 아래로 이동
	printf(" $$ ");	// 나무 그리기
	GotoXY(treeX, TREE_BOTTOM_Y + 4);	// 나무의 위치에서 네 줄 아래로 이동
}

int GetKeyDown() {
	if (_kbhit() != 0) {	// 키보드 입력이 있는지 확인
		int key = _getch();
		if (key == 224) {	// 방향키 등의 특수 키 입력이 있는 경우
			return _getch();	// 키보드 입력이 있으면 해당 키의 ASCII 코드 반환	
		}
		return key;
	}
	return 0;	// 키보드 입력이 없으면 0 반환
}

bool isCollision(const int treeX, const int dinoY) {
	if (treeX >= 4 && treeX <= 8 && dinoY >= 8) {
		return true;
	}
	else
	return false;
}

void DrawGameOver() {
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("=================================");
	GotoXY(x, y + 1);
	printf("============공룡=멸망============");
	GotoXY(x, y + 2);
	printf("=================================");

	system("pause");
}

int main() {
	bool isJumping = false;	// 공룡이 점프 중인지 여부를 나타내는 변수
	bool isBottom = true;	// 공룡이 바닥에 있는지 여부를 나타내는 변수
	const int gravity = 3;	// 중력 가속도 (공룡이 떨어지는 속도)

	int dinoY = DINO_BOTTOM_Y;	// 공룡의 초기 y 좌표 설정
	int treeX = TREE_BOTTOM_X;	// 나무의 초기 x 좌표 설정

	while (true) {	// 게임 루프 시작
		if (isCollision(treeX, dinoY)) {
			DrawGameOver();
			break;
		}
		if (GetKeyDown() == 72 && isBottom) {
			isJumping = true;	// 위쪽 방향키가 눌렸을 때 점프 시작
			isBottom = false;	// 공룡이 바닥에 있지 않음
		}

		if (isJumping) {
			dinoY -= gravity;	// 공룡이 점프할 때 y 좌표 감소 (위로 이동)
		}
		else {
			dinoY += gravity; // 공룡이 떨어질 때 y 좌표 증가 (아래로 이동)
		}

		if (dinoY >= DINO_BOTTOM_Y) {
			dinoY = DINO_BOTTOM_Y;	// 공룡이 바닥에 닿으면 y 좌표를 바닥으로 고정
			isBottom = true;	// 공룡이 바닥에 있음
		}

		if (dinoY <= 3) {
			isJumping = false;	// 공룡이 너무 높이 올라가면 점프 종료
		}

		treeX -= 2;	// 나무가 왼쪽으로 이동 (속도 조절 가능)
		if (treeX <= 0) {
			treeX = TREE_BOTTOM_X;	// 나무가 화면 왼쪽 끝에 닿으면 초기 위치로 리셋
		}

		DrawDino(dinoY);	// 공룡 그리기
		DrawTree(treeX);	// 나무 그리기
		Sleep(80);	// 게임 루프의 속도를 조절하기 위해 잠시 대기 (80ms)
		system("cls");	// 화면을 지우고 다음 프레임을 그리기 위해 콘솔 클리어
	}
	system("pause");
	return 0;
}