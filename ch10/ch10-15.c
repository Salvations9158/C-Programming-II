//학번 : 202511234
//이름 : 전민규
//프로그램 명: 공용체의 정의 및 사용
//날짜: 10월 12일

#include <stdio.h>

union test
{
	int i;
	char c;
	short s;
};

void UnionDefine();

int main(void)
{
	UnionDefine();

	return 0;
}

void UnionDefine()
{
	union test t1 = { 0x12345678 };

	printf("sizeof(union test)=%d\n", sizeof(union test));

	printf("t1.i의 주소=%p\n", &t1.i);
	printf("t1.c의 주소=%p\n", &t1.c);
	printf("t1.s의 주소=%p\n", &t1.s);

	printf("t1.i의 주소=%x\n", t1.i);
	printf("t1.c의 주소=%x\n", t1.c);
	printf("t1.s의 주소=%x\n", t1.s);


}