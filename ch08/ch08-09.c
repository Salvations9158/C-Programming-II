//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터를 배열인 것처럼 사용하는 경우
//날짜: 10월 11일

#include <stdio.h>

void pointer_arr();


int main()
{
	pointer_arr();

	return 0;

}

void pointer_arr()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;

	int i;

	for (i = 0; i < 5; i++)
	{
		printf("p[%d] = %d\n", i, p[i]);
	}

}