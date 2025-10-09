//학번 : 202511234
//이름 : 전민규
//프로그램 명: 크기가 같은 2개의 정수형 배열을 매개변수로 전달받아 두 배열의 원소들의 값을 맞바꾸는 swap_aray 함수를 작성하시오. swap_array 함수를 이용해서 크기가 10인 두 배열의 값을 맞바꾸는 프로그램을 작성하시오. 배열의 초기값은 마음대로 정해도 된다.
//날짜: 9월 24일

#include <stdio.h>
#define SIZE 10

void swap_array(int arr1[], int arr2[], int size);
void PrintArray(int arr[], int size);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	int arr1[SIZE] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int arr2[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18 };

	printf("a: ");
	PrintArray(arr1, SIZE);
	printf("b: ");
	PrintArray(arr2, SIZE);

	swap_array(arr1, arr2, SIZE);
	printf("<< swap_array 호출 후 >>\n");

	printf("a: ");
	PrintArray(arr1, SIZE);
	printf("b: ");
	PrintArray(arr2, SIZE);
}

void swap_array(int arr1[], int arr2[], int size)
{
	int temp[SIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr2[i];
		arr2[i] = arr1[i];
		arr1[i] = temp[i];
	}
}

void PrintArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

