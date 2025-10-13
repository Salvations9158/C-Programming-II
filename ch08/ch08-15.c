//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열을 입력 매개변수로 사용하는 함수
//날짜: 10월 11일

#include <stdio.h>
#define SIZE 10

void copy_array(const int source[], int target[], int size);
void printf_array(const int arr[], int size);
void array();

int main(void)
{
	array();
	return 0;
}

void array()
{
	int x[SIZE] = { 10,20,30,40,50 };
	int y[SIZE] = { 0 };

	printf("x= ");
	printf_array(x, SIZE);
	copy_array(x, y, SIZE);
	printf("y= ");
	printf_array(y, SIZE);
}

void copy_array(const int source[], int target[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		target[i] = source[i];
	}
}

void printf_array(const int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}