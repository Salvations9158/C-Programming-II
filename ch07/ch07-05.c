//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열의 원소 사용
//날짜: 10월 10일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARR_SIZE 5

int main()
{
	arr_use();

	return 0;
}

int arr_use()
{
	int arr[ARR_SIZE] = { 0 };
	int i;

	arr[0] = 5;
	arr[1] = arr[0] + 10;
	arr[2] = add(arr[0], arr[0]);
	printf("정수를 2개 입력하세요: ");
	scanf("%d %d", &arr[3], &arr[4]);

	for (i = 0; i < ARR_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;

}

int add(int a, int b)
{
	return a + b;
}