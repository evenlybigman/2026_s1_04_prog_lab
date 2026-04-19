//사용자로부터 2개의 시간을 입력 받아서 
// 두 시간 차이를 계산하는 diff_time 함수 만들기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct TIME {
	int seconds;
	int minutes;
	int hours;
};

void diff_time(struct TIME t1, struct TIME t2, struct TIME* differ) {
	if (t1.seconds > t2.seconds) {
		t1.minutes--;
		t1.seconds += 60;
	}
	differ->seconds = t2.seconds - t1.seconds;
	if (t1.minutes > t2.minutes) {
		t1.hours--;
		t1.minutes += 60;
	}
	differ->minutes = t2.minutes - t1.minutes;
	if (t1.hours > t2.hours) {
		printf("시간2의 시간이 더 커야합니다");
	}
	else {
		differ->hours = t2.hours - t1.hours;
	}
}

int main() {
	struct TIME time1, time2, diff;
	printf("시작 시간(시, 분, 초): ");
	scanf("%d%d%d", &time1.hours, &time1.minutes, &time1.seconds);
	printf("종료 시간(시, 분, 초): ");
	scanf("%d%d%d", &time2.hours, &time2.minutes, &time2.seconds);
	diff_time(time1,time2,&diff);
	printf("소요 시간: %d:%d:%d", diff.hours, diff.minutes, diff.seconds);
	return 0;
}