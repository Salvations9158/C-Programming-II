//학번 : 202511234
//이름 : 전민규
//프로그램 명: count_space 함수의 정의
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gap_str();
int count_space(const char* s);



int main(void)
{
	gap_str();

	return 0;
}

void gap_str()
{
	char str[64] = "this program\ttests const pointer to string\n";

	puts(str);
	printf("공백 문자의 개수: %d\n", count_space(str));

}

int count_space(const char* s)
{
	int count = 0;
	while (s[0] != '\0')
	{
		if (isspace(s[0]))
			count++;
		s++;
	}
	return count;
}