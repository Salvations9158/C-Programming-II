//학번 : 202511234
//이름 : 전민규
//프로그램 명: 3 x 3 행렬의 합을 구하는 프로그램을 작성하시오. 행렬로 사용될 2차원 배열은 마음대로 초기화해도 된다.
//날짜: 9월 18일

#include <stdio.h>
#define SIZE 3

void Execusion();
void Printmatrix(int arr[][SIZE], int size);
void Addmatrix(int x[][SIZE], int y[][SIZE], int sum[][SIZE], int size);

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	int x[SIZE][SIZE] =
	{
		{ 10, 20 ,30 },
		{ 40, 50, 60 },
		{ 70, 80, 90 }
	};

	int y[SIZE][SIZE] =
	{
		{ 9, 8 ,7 },
		{ 6, 5, 4 },
		{ 3, 2, 1 }
	};

	int sum[SIZE][SIZE] =
	{
		{ 0 }
	};

	printf("x 행렬:\n");
	Printmatrix(x, SIZE);
	printf("y 행렬:\n");
	Printmatrix(y, SIZE);

	Addmatrix(x, y, sum, SIZE);

	printf("x + y 행렬:\n");
	Printmatrix(sum, SIZE);
}

void Addmatrix(int x[][SIZE], int y[][SIZE], int sum[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sum[i][j] = x[i][j] + y[i][j];
		}
	}
}

void Printmatrix(int arr[][SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
}