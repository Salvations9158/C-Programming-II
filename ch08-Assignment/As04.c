//학번 : 202511234
//이름 : 전민규
//프로그램 명: 열 크기가 5인 2차원 int 배열의 모든 원소를 특정 값으로 채우는 fill_2d_array 함수를 작성하시오. 함수의 매개변수로 배열 전체에 대한 포인터와 배열의 행 크기를 전달한다. 열 크기가 5, 행 크기가 4인 2차원 배열을 입력받은 값으로 채우고 출력하는 프로그램을 작성하시오.
//날짜: 9월 24일

#include <stdio.h>
#define RAW 4
#define COL 5

void Execusion();
void fill_2d_array(int arr[][COL], int raw, int col, int num);
void printMatrix(int arr[][COL], int raw, int col);

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	int matrix[RAW][COL] = { 0 };
	int num = 0;

	printf("배열의 원소에 저장할 값? ");
	scanf_s("%d", &num);

	fill_2d_array(matrix, RAW, COL, num);
	printMatrix(matrix, RAW, COL);
}

void fill_2d_array(int arr[][COL], int raw, int col, int num)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = num;
		}
	}
}

void printMatrix(int arr[][COL], int raw, int col)
{
	for (int i = 0; i < raw; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}