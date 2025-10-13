//학번 : 202511234
//이름 : 전민규
//프로그램 명: 포인터 배열의 선언 및 사용
//날짜: 10월 11일

#include <stdio.h>

void pointer_use();


int main()
{
	pointer_use();

	return 0;
}

void pointer_use()
{
	int a, b, c, d, e;
	int* arr[5] = { &a, &b, &c, &d, &e };
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		*arr[i] = i;
		printf("%d ", *arr[i]);
	}
	printf("\n");

	return 0;
}