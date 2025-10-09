//학번 : 202511234
//이름 : 전민규
//프로그램 명: 정수형 배열의 모든 원소를 특정 값으로 채우는 fill_array 함수를 작성하시오. 실수형 배열의 초기값은 마음대로 정하시오.
//날짜: 9월 18일

#include <stdio.h>
#define SIZE 20

void fill_array(int arr[], int size, int num);
void PrintArray(int arr[], int size);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	int arr[SIZE] = { 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = 0;

	printf("배열의 원소에 저장할 값? ");
	scanf_s("%d", &num);

	fill_array(arr, size, num);
	PrintArray(arr, size);
}

void fill_array(int arr[], int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = num;
	}
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}