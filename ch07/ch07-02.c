//학번 : 202511234
//이름 : 전민규
//프로그램 명: 매크로 상수로 배열의 크기를 지정하는 경우
//날짜: 10월 10일

#include<stdio.h>

#define ARR_SIZE 5

int main(void)
{
	arr();

	return 0;
}

int arr()
{
	int arr[ARR_SIZE];
	int i;

	for (i = 0; i < ARR_SIZE; i++)
	{
		arr[i] = 0;
	}

	printf("arr= ");
	for (i = 0; i < ARR_SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}