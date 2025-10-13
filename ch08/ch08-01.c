//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터의 바이트 크기 구하기
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	pointer_bite();

	return 0;
}

void pointer_bite()
{
	int* pi;
	double* pd;
	char* pc;

	printf("sizeof(pi)=%zd\n", sizeof(pi));
	printf("sizeof(pi)=%zd\n", sizeof(pd));
	printf("sizeof(pi)=%zd\n", sizeof(pc));

	printf("sizeof(int*)=%zd\n", sizeof(int*));
	printf("sizeof(double*)=%zd\n", sizeof(double*));
	printf("sizeof(char*)=%zd\n", sizeof(char*));


}