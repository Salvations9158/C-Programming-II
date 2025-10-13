//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열의 0번 원소를 가리키는 포인터와 '포인터+정수' 연산의 결과
//날짜: 10월 11일

#include <stdio.h>

void study_arr();


int main()
{
	study_arr();

	return 0;
}

void study_arr()
{
	int arr[5] = { 1,2,3,4,5 };
	int* p = &arr[0];

	int i;
	for (i = 0; i < 5; i++)
	{
		printf("p + %d = %p, ", i, p + i);
		printf("*(p + %d) = %d\n", i, *(p + i));
	}

	return 0;
}