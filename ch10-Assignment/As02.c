//학번 : 202511234
//이름 : 전민규
//프로그램 명: DATE 구조체 정의 및 출력 프로그램
//날짜: 10월 12일

#include <stdio.h>

typedef struct
{
	int year;
	int month;
	int day;
} DATE;

void print_date(DATE date_info);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	DATE my_date;

	printf("연? ");
	if (scanf_s("%d", &my_date.year) != 1) {
		printf("입력 오류\n");
		return;
	}
	while (getchar() != '\n');

	printf("월? ");
	if (scanf_s("%d", &my_date.month) != 1) {
		printf("입력 오류\n");
		return;
	}
	while (getchar() != '\n');

	printf("일? ");
	if (scanf_s("%d", &my_date.day) != 1) {
		printf("입력 오류\n");
		return;
	}
	while (getchar() != '\n');

	print_date(my_date);
}

void print_date(DATE date_info)
{
	printf("%d/%d/%d\n", date_info.year, date_info.month, date_info.day);
}