#define CRT_SECURE_NO_WRARNINGS
#include <stdio.h>
#define SIZE 5

//배열 평균 계산 함수
double get_array_avg(int values[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += values[i];
	}
	return sum / n;
}

//배열 출력 함수
void printf_array(int values[], int n) {
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", values[i]);
	}
	printf("]\n");
	return;
}

int main() {
	int data[SIZE] = { 10, 20, 30, 40, 50 };
	double result = get_array_avg(data,5);
	printf_array(data, 5);
	printf("배열 원소들의 평균 = %lf", result);
	return 0;
}

int main() {
	int data[SIZE] = { 10, 20, 30, 40, 50 };
	printf_array(data, 5);
	printf("배열 원소들의 평균 = %lf", get_array_avg(data,5));
	return 0;
}