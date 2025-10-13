//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열의 0번 원소를 가리키는 포인터에 증감 연산을 수행한 결과
//날짜: 10월 11일

#include <stdio.h>

void arr_plus();

int main()
{
	arr_plus();

	return 0;
}

void arr_plus()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = &arr[0];

	int i;

	for (i = 0; i < 5; i++, p++)
	{
		printf("p=%p, ", p);
		printf("*p=%d\n", *p);
	}
}