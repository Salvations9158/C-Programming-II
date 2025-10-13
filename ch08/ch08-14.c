//학번 : 202511234
//이름 : 전민규
//프로그램 명: 함수의 처리 결과를 매개변수로 전달하는 get_sum_product 함수
//날짜: 10월 11일

#include <stdio.h>

void get_sum_product(int x, int y, int* sum, int* product);
int first();


int main()
{

	first();

	return 0;
}

int first()
{
	int result1, result2;

	get_sum_product(10, 20, &result1, &result2);
	printf("sum=%d,  product = %d", result1, result2);
}

void get_sum_product(int x, int y, int* sum, int* product)
{
	*sum = x + y;
	*product = x * y;
}