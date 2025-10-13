//학번 : 202511234
//이름 : 전민규
//프로그램 명: 열거체와 열거 상수의 정의 및 사용
//날짜: 10월 12일

#include <stdio.h>

enum direction { NORTH, SOUTH, EAST, WEST };
void EnumDefine();


int main()
{
	EnumDefine();

	return 0;

}

void EnumDefine()
{
	enum direction d1 = NORTH;

	d1 = EAST;
	printf("d1=%d\n", d1);

	switch (d1)
	{
	case NORTH:
		printf("북쪽으로 이동합니다.\n");
		break;
	case SOUTH:
		printf("남쪽으로 이동합니다.\n");
		break;
	case EAST:
		printf("동쪽으로 이동합니다.\n");
		break;
	case WEST:
		printf("서쪽으로 이동합니다.\n");
		break;
	}
}