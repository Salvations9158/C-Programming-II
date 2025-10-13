//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터 선언 및 초기화
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	//int &p1 = 0x12345678;
	int* p2 = (int*)0x12345678;

	int a = 10;
	int* p3 = &a;
	int* p4 = 0;
	int* p5 = NULL;

	printf("p2 = %p\n", p2);
	printf("p3 = %p\n", p3);
	printf("p4 = %p\n", p4);
	printf("p5 = %p\n", p5);

	return 0;
}
