//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열의 비교
//날짜: 10월 10일

#include <stdio.h>

int main()
{
	arr_comprison();

	return 0;

}

int arr_comprison()
{
	int x[5] = { 10,20,30,40,50 };
	int y[5] = { 10,20,30,40,50 };

	int i = 0;
	int is_equal;

	if (x == y)
		printf("두 배열의 주소가 같습니다.\n");

	is_equal = 1;
	for (i = 0; i < 5; i++)
	{
		if (x[i] != y[i])
		{
			is_equal = 0;
			break;
		}
	}
	if (is_qual == 1)
	{
		printf("두 배열의 내용이 같습니다.\n");
	}

	return 0;
}