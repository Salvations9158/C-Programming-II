//학번 : 202511234
//이름 : 전민규
//프로그램 명: 구조체형의 출력 매개변수를 가진 함수를 정의
//날짜: 10월 12일

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct point
{
	int x, y;
}POINT;

void print_point(const POINT* pt);
void set_point(POINT* pt, int x, int y);
void StructPrint();


int main(void)
{
	StructPrint();

	return 0;
}

void StructPrint()
{
	POINT arr[5] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i;

	srand((unsigned int)time(NULL));
	for (i = 0; i < sz; i++)
	{
		int x = rand() % 100;
		int y = rand() % 100;
		set_point(&arr[i], x, y);
	}
	for (i = 0; i < sz; i++)
	{
		print_point(&arr[i]);
		printf(" ");
	}
	printf("\n");
}

void print_point(const POINT* pt)
{
	printf("(%d, %d)", pt->x, pt->y);
}

void set_point(POINT* pt, int x, int y)
{
	pt->x = x;
	pt->y = y;
}