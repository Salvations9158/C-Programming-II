//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열의 크기보다 초기값을 적게 지정하는 경우
//날짜: 10월 10일

#include <stdio.h>

int main()
{
	arr();

	return 0;

}

int arr()
{
	int amount[5] = { 1,1,5 };
	int price[5] = { 0 };
	int i;

	printf("amount= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", amount[i]);
	}
	printf("\n");

	printf("price= ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", price[i]);
	}
	printf("\n");

	return 0;

}