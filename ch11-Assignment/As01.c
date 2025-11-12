//학번 : 202511234
//이름 : 전민규
//프로그램 명: 정수를 전달해서 정수에 있는 숫자의 개수를 구하는 함수를 재귀함수로 정의
//날짜: 10월 15일

#include <stdio.h>

void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	CountNum();
}

int CountNum()
{
	int num = 0;
	if (num == 0)
	{
		return 0;
	}
	printf("정수? ");
	scanf_s("%d", &num);0

}