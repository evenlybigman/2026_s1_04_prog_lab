//도서관 관리 프로그램 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct book {
	int id;
	char name[20];
	char author[10];
}book;

typedef struct library_management {
	book eabooks[50];
}LM;

void print_menu() {
	printf("\n");
	printf("========================================\n");
	printf("1. 도서 번호로 책 찾기\n");
	printf("2. 저자 이름으로 책 찾기\n");
	printf("3. 제목으로 책 찾기\n");
	printf("4. 새로운 책 추가\n");
	printf("5. 도서관이 소장한 도서의 수 표시\n");
	printf("6. 종료\n");
	printf("========================================\n");
}


int main() {
	printf("2371209 김주혁\n");
	LM library;
	int count_book = 0;
	int booknumber = 0;
	char namecmp[20];
	char authorcmp[10];
	int count = 0;
	while (1) {
		print_menu();
		printf("메뉴 중에서 하나를 선택하세요: ");
		int input;
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("도서 번호 입력: ");
			scanf("%d", &booknumber);
			if (count_book == 0) {
				printf("추가된 책이 없습니다. 책을 추가해주십시오.\n");
				break;
			}
			else if (booknumber < 0 || booknumber >= count_book) {
				printf("해당 번호의 책이 없습니다. 현재 책 개수 %d\n", count_book);
				break;
			}
			printf("책이름 = %s\n", library.eabooks[booknumber].name);
			printf("저자 = %s\n", library.eabooks[booknumber].author);
			break;
		case 2:
			printf("저자 이름 입력: ");
			scanf("%9s", authorcmp);
			count = 0; //책을 찾으면 1로 바뀜
			for (int i = 0; i < count_book; i++) {
				if (strcmp(authorcmp, library.eabooks[i].author) == 0) {
					printf("ID: %d | %s | %s\n", library.eabooks[i].id, library.eabooks[i].name, library.eabooks[i].author);
					count = 1;
				}
			}
			if (count == 0) {
				printf("해당 도서가 없습니다.\n");
			}
			break;
		case 3:
			printf("제목 이름 입력: ");
			scanf("%19s", namecmp);
			count = 0;
			for (int i = 0; i < count_book; i++) {
				if (strcmp(namecmp, library.eabooks[i].name) == 0) {
					printf("ID: %d | %s | %s\n", library.eabooks[i].id, library.eabooks[i].name, library.eabooks[i].author);
					count = 1;
				}
			}
			if (count == 0) {
				printf("해당 도서가 없습니다.\n");
			}
			break;
		case 4:
			if (count_book == 50) {
				printf("더 이상 책을 추가할 수 없습니다.\n");
				break;
			}
			printf("책 이름: ");
			scanf("%19s", library.eabooks[count_book].name);
			printf("저자 이름: ");
			scanf("%9s", library.eabooks[count_book].author);
			printf("책이 추가 되었습니다.\n");
			library.eabooks[count_book].id = count_book;
			count_book++;
			break;
		case 5:
			printf("총 도서 수: %d\n", count_book);
			for (int i = 0; i < count_book; i++) {
				printf("ID: %d | %s | %s\n", library.eabooks[i].id, library.eabooks[i].name, library.eabooks[i].author);
			}
			break;
		case 6:
			return 0;
		default:
			continue;
		}
	}
	return 0;
}