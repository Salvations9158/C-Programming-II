//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열 원소를 가리키는 포인터를 이용해서 실수형 배열의 평균을 구하는 프로그램을 작성하시오.
//날짜: 9월 18일

#include <stdio.h>

void Execution();
float Calc(const float arr[], int size);

int main()
{
	Execution();
	return 0;
}

void Execution()
{
	float arr[10] = { 0.10, 2.00, 3.40, 5.20, 4.50, 7.80, 9.70, 1.40, 6.60, 7.20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	float result = 0.0f;

	printf("배열: ");
	for (int i = 0; i < size; i++)
	{
		printf("%.2f ", arr[i]);
	}
	printf("\n");

	result = Calc(arr, size);
	printf("평균: %.4f\n", result);
}

float Calc(const float arr[], int size)
{
	float allsum = 0.0f;
	const float* ptr = arr;

	for (int i = 0; i < size; i++)
	{
		allsum += *ptr;
		ptr++;
	}
	return allsum / size;
}