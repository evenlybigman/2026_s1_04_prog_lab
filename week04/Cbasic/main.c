#include <stdio.h>
#define SIZE 5

void print_image(int image[SIZE][SIZE]) {
	for (int r = 0; r < SIZE; r++) {
		for (int c = 0; c < SIZE; c++) {
			printf("%03d ", image[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}

void brighten_image(int image[SIZE][SIZE]) { //image 값에 10 더하고 p 올라가고 반복
	int r, c;
	int* p;
	p = &image[0][0];
	for (c = 0; c < SIZE; c++) {
		for (r = 0; r < SIZE; r++) {
			*p += 10;
			p++;
		}
	}
}

int main() {
	int image[SIZE][SIZE] = {
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50},
		{10,20,30,40,50}
	};
	print_image(image);
	brighten_image(image);
	print_image(image);
}