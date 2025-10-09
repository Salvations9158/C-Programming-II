//학번 : 202511234
//이름 : 전민규
//프로그램 명: 크기가 10인 실수형 배열에 대해서 원소들을 역순으로 만드는 프로그램을 작성하시오. 실수형 배열의 초기값은 마음대로 정하시오.
//날짜: 9월 18일

#include <stdio.h>
#define SIZE 10

void Sortfloat(float arr[], int size);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	float arr[SIZE] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };
	int size = sizeof(arr) / sizeof(arr[0]);


	printf("배열:");
	for (int i = 0; i < size; i++)
	{
		printf(" %.1f", arr[i]);
	}
	printf("\n");

	Sortfloat(arr, size);

	printf("역순:");
	for (int j = 0; j < size; j++)
	{
		printf(" %.1f", arr[j]);
	}
	printf("\n");
}

void Sortfloat(float arr[], int size)
{
	float temp[SIZE] = { 0 };
	int index = size - 1;
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[index];
		--index;
	}
	
	for (int j = 0; j < size; j++)
	{
		arr[j] = temp[j];
	}
}