//학번 : 202511234
//이름 : 전민규
//프로그램 명: 특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾아서 출력하는 프로그램을 작성하시오. 배열의 초기값은 마음대로 정하시오.
//날짜: 9월 18일

#include <stdio.h>
#define SIZE 10

void Execution();
int Maxvalue(int arr[], int size);
int Minvalue(int arr[], int size);

int main()
{
	Execution();
	return 0;
}

void Execution()
{
	int arr[SIZE] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int max, min = 0;

	printf("배열:");
	for (int i = 0; i < size; i++)
	{
		printf(" %d", arr[i]);
	}
	printf("\n");

	max = Maxvalue(arr, size);
	min = Minvalue(arr, size);
	
	printf("최댓값: %d\n", max);
	printf("최솟값: %d\n", min);

}

int Maxvalue(int arr[], int size)
{
	int temp = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (temp < arr[i])
		{
			temp = arr[i];
		}
	}
	return temp;
}

int Minvalue(int arr[], int size)
{
	int temp = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (temp > arr[i])
		{
			temp = arr[i];
		}
	}
	return temp;
}