//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열에 대한 포인터의 선언 및 사용
//날짜: 10월 11일

#include <stdio.h>

void pointer_use();


int main()
{
	pointer_use();

	return 0;
}

void pointer_use()
{
	int data[3][5] = {
		{1,2,3,4,5,},
		{ 6,7,8,9,10 },
		{ 11,12,13,14,15 }
	};
	int(*p)[5] = &data[0];
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%2d ", data[i][j]);
		}
		printf("\n");
	}
}