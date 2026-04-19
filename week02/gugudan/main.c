#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, l;
	for (l = 2; l <= 9; l++) {
		for (i = 1; i <= 9; i++) {
			printf("%d X %d = %d\n", l, i, l * i);
		}
	}
	return 0;
}