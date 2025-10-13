//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터의 사용
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	pointer_use();

	return 0;
}

int pointer_use()
{
	int x = 10;
	int* p = &x;

	printf("x=%d\n", x);
	printf("&x=%p\n", &x);

	printf(" p = %p\n", p);
	printf("*p=%d\n", *p);
	printf("&p=%p\n", &p);

	*p = 20;
	printf("*p=%d\n", *p);

	return 0;
}