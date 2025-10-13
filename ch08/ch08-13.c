//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터에 의한 전달 방법으로 구현한 swap 함수
//날짜: 10월 11일

#include <stdio.h>

void pointer_swap();
void swap(int* x, int* y);



int main()
{
	pointer_swap();

	return 0;
}

void pointer_swap()
{
	int a = 3, b = 7;

	printf("a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d", a, b);
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}