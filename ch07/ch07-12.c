//학번 : 202511234
//이름 : 전민규
//프로그램 명: 2차원 배열의 선언 및 사용
//날짜: 10월 10일


#include <stdio.h>

#define ROW 3
#define COL 2

int main(void)
{
	arr();

	return 0;
}

int arr()
{
	int data[ROW][COL];
	int i, j, k;

	for (i = 0, k = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			data[i][j] = ++k;
	}

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			printf("%2d", data[i][j]);
		printf("\n");
	}

	printf("sizeof(data) = %d\n", sizeof(data));
	printf("sizeof(data[0]) = %d\n", sizeof(data[0]));
	printf("sizeof(data[0][0]) = %d\n", sizeof(data[0][0]));
	return 0;
}