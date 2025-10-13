//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터가 필요한 경우
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	test1();
}

int test1()
{
	int x = 10;
	test2(x);
	printf("test2 호출 후 x =%d\n", x);


	test3(&x);
	printf("test3호출 후 x =%d\n", x);

	return 0;
}

void test2(int x)
{
	x = 20;
}

void test3(int* p)
{
	*p = 20;
}