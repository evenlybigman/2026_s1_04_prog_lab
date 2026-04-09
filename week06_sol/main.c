#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define WORDS 5

int main() {
	int i, index;
	char dic[WORDS][2][30] = {
		{"book","책"},
		{"boy","남자"},
		{"computer","컴퓨터"},
		{"language","언어"},
		{"rain","비"},
	};
	char word[30];
	while (1) {
		printf("단어를 입력하시오. (종료: exit): ");
		scanf("%s", &word);
		if (strcmp(word, "exit") == 0) {
			break;
		}
		for (int i = 0; i < WORDS; i++) {
				if (strcmp(word, dic[i][0]) == 0) {
					printf("%s : %s\n", dic [i][0], dic[i][1]);
				}
				else if (strcmp(word,dic[i][1]) == 0) {
					printf("%s : %s\n", dic[i][0], dic[i][1]);
				}
				else printf("없는 단어입니다.\n");
				break;
			}
		}
	}
