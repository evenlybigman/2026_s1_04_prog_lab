//1번 문제
#include <stdio.h>
void asterisk(int n) {
	if (n > 0) {
		asterisk(n / 2);
		asterisk(n / 2);
		printf("\n");
	}
	printf("*");
}

int main() {
	asterisk(5);
	return 0;
}

as(5)
as(2) as(2)
as(1) as(1) as(1) as(1)
as(0) as(0) as(0) as(0) as(0) as(0) as(0) as(0)