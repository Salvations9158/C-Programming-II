//학번 : 202511234
//이름 : 전민규
//프로그램 명: counst 포인터의 의미
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	pointer_mean();

	return 0;
}

void pointer_mean()
{
	int a = 10, b = 20;

	const int* p1 = &a;
	int* const p2 = &a;
	const int* const p3 = &a;

	printf("*p1=%d\n", *p1);
	p1 = &b;
	printf("*p=%d\n", *p1);//주소, 값 변경 가능

	*p2 = 100;
	printf("p2=%d\n", *p2);//주소 x //값 O


	printf("*p3=%d\n", *p3);//주소 변경 안됨, 값도 변경 안됨

}