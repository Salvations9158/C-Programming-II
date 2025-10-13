//학번 : 202511234
//이름 : 전민규
//프로그램 명: 비트필드의 정의 및 사용
//날짜: 10월 12일

#include <stdio.h>

typedef struct date
{
	unsigned short year : 7;
	unsigned short month : 4;
	unsigned short day : 5;
}DATE;

void bitfield();


int main(void)
{
	bitfield();

	return 0;

}

void bitfield()
{
	DATE dday;
	dday.year = 22;
	dday.month = 11;
	dday.day = 30;

	printf("DATE의 크기 = %d\n", sizeof(DATE));
	printf("%d/%d/%d\n", dday.year, dday.month, dday.day);
}