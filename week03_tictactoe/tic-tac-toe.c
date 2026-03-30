#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() { // 틱택토 게임
	char board[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3;j++) {
			board[i][j] =  ' ' ;
		}
	}
	int turn = 1; //turn이 1이면 1차례 2면 2차례
	int player1 = 1;// player 1은 X player 2는 O
	int player2 = 2;
	int x = 0, y = 0;
	while (1) {
		if (turn == 1) printf("player1 차례 (x, y) 좌표 : ");
		else printf("player2 차례 (x, y) 좌표 : ");
		scanf("%d %d", &x,&y); //x y를 받으면 지정된 x y배열에 입력하고 프린트
		if (board[x][y] != 'X' && board[x][y] != 'O') {
			if (turn == player1) {
				board[x][y] = 'X';
				turn++;
			}
			else {
				board[x][y] = 'O';
				turn--;
			}
		}
		else {
			printf("이미 칠해진 칸입니다.\n");
		}
		for (int l = 0; l < 3; l++) {
			printf("---|---|--- \n");
			printf(" %c | %c | %c\n", board[l][0], board[l][1], board[l][2]);
		}
	}
	return 0;
}