//학번 : 202511234
//이름 : 전민규
//프로그램 명: swap_string 함수의 정의 및 호출
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 128

void StrSwap();
int swap_string(char* lhs, char* rhs, int size);

int main(void)
{
	StrSwap();

	return 0;
}

void StrSwap()
{
	char str1[SIZE] = "";
	char str2[SIZE] = "";

	printf("문자열 2개? ");
	scanf("%s %s", str1, str2);

	printf("str1=%s, str2=%s\n", str1, str2);
	swap_string(str1, str2, SIZE);
	printf("str1=%s, str2=%s\n", str1, str2);
}

int swap_string(char* lhs, char* rhs, int size)
{
	int lhs_len = strlen(lhs);
	int rhs_len = strlen(rhs);
	char temp[SIZE] = "";

	if (lhs_len + 1 > size || rhs_len + 1 > size)
		return 0;

	strcpy(temp, lhs);
	strcpy(lhs, rhs);
	strcpy(rhs, temp);
	return 1; //swap 성공할 경우
}