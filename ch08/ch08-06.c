//학번 : 202511234
//이름 : 전민규
//프로그램 명: '포이터+정수' 연산의 결과
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	printer_integer();

	return 0;
}

void printer_integer()
{
	int* p = (int*)0x100;
	double* q = (double*)0x100;
	char* r = (char*)0x100;

	printf("int*:%p %p %p\n", p, p + 1, p + 2);
	printf("double*:%p %p %p\n", q, q + 1, q + 2);
	printf("char*:%p %p %p\n", r, r + 1, r + 2);

}