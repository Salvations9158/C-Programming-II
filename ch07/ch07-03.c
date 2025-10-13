//학번 : 202511234
//이름 : 전민규
//프로그램 명: 가장 기본적인 배열의 초기화
//날짜: 10월 10일

#include <stdio.h>

int main()
{
	arr_reset();

	return 0;

}

int arr_reset()
{
	int arr[5] = { 1,2,3,4,5 };
	int i;

	printf("arr= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}