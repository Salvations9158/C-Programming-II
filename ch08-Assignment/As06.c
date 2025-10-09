//학번 : 202511234
//이름 : 전민규
//프로그램 명: 정수형 배열과 키 값을 매개변수로 전달받아 배열에서 키 값을 모두 찾아 인덱스의 배열에 저장해서 리턴하는 find_all_in_array 함수를 작성하시오. 이 함수는 찾은 항목의 개수를 리턴. 예를 들어 배열에서 12를 2개 찾았으면 2를 리턴하고 찾은 항목의 인덱스는 매개변수인 인덱스 배열에 저장한다. 항목을 찾을 수 없으면  0을 리턴.
//날짜: 9월 24일

#include <stdio.h>
#define SIZE 10

void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	int arr[SIZE] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 };
	int index[SIZE] = { 0 };
	int key = 0;
	int result = 0;

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("찾을 값? ");
	scanf_s("%d", &key);

	result = find_all_in_array(arr, index, SIZE, key);
	printf("찾은 항목은 모두 %d개입니다.\n", result);

	printArray(index, result);
}

int find_all_in_array(int arr[], int index[], int size, int key)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			index[count] = i;
			count++;
		}
	}
	if (count == 0)
	{
		return 0;
	}
	return count;
}

int printArray(int index[], int size)
{
	printf("찾은 항목의 인덱스: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", index[i]);
	}
}