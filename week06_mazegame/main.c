#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define BOARD_SIZE 10

char board[BOARD_SIZE][BOARD_SIZE] = { 
 {'#', '#', '#', '#', '.', '.', '.', '.', '.', '.' },
 {'.', '.', '.', '.', '.', '#', '.', '.', '.', '.' },
 {'#', '#', '#', '.', '#', '.', '.', '.', '.', '.' },
 {'.', '.', '#', '.', '.', '#', '.', '.', '.', '.' },
 {'.', '.', '#', '.', '.', '#', '.', '.', '.', '.' },
 {'.', '.', '#', '.', '.', '#', '.', '.', '.', '.' },
 {'.', '.', '.', '#', '.', '.', '#', '#', '.', '.' },
 {'.', '.', '.', '.', '#', '.', '.', '.', '#', '#' },
 {'.', '.', '.', '.', '.', '#', '.', '.', '.', '.' },
 {'.', '.', '.', '.', '.', '#', '#', '#', '#', '#' } 
};

void printBoard(int *xpos,int *ypos) {
	board[*xpos][*ypos] = '@';
	for (int r = 0; r < BOARD_SIZE; r++) {
		for (int c = 0; c < BOARD_SIZE; c++) {
			printf("%c", board[r][c]);
		}
		printf("\n");
	}
	board[*xpos][*ypos] = '.';
	printf("\n");
}

int main() {
	int xpos = 1;
	int ypos = 0;
	printBoard(&xpos,&ypos);
	printf("왼쪽: <-, 오른쪽: ->, 위: ^, 아래: v\n\n");
	while (1) {
		int ch = _getch();
		if (ch == 224) {
			int ch2 = _getch();
			if (ch2 == 75) ypos--;
			else if (ch2 == 80) xpos++;
			else if (ch2 == 72) xpos--;
			else if (ch2 == 77) ypos++;
		}
		system("cls");
		if (board[xpos][ypos] == '#') {
			printBoard(&xpos, &ypos);
			printf("사망");
			break;
		}
		else if (xpos == 8 && ypos == 9) {
			printBoard(&xpos, &ypos);
			printf("생존!");
			break;
		}
		printBoard(&xpos, &ypos);
	}
	return 0;
}