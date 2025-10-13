//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열 토큰 나누기
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	str_tok();

	return 0;
}

void str_tok()
{
	char phone[] = "02-123-4567";
	char* p = NULL;

	p = strtok(phone, "-");
	printf("area code: %s\n", p);

	p = strtok(NULL, "-");
	printf("prefix:%s\n", p);

	p = strtok(NULL, "-");
	printf("line number: %s\n", p);

}