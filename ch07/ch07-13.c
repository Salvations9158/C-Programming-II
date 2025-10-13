//학번 : 202511234
//이름 : 전민규
//프로그램 명: 2차원 배열의 초기화
//날짜: 10월 10일


#include <stdio.h>
#define ROW 3
#define COL 2

int main()
{
	arr_reset();

	return 0;
}

int arr_reset()
{
	int data[ROW][COL] = {
		{10,20},{30,40},{50,60}
	};
	int i, j;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			printf("%3d ", data[i][j]);
		printf("\n");
	}
	return 0;
}