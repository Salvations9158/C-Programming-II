//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열의 입출력
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void str_inout();


int main()
{
	str_inout();

	return 0;
}

void str_inout()
{
	char in_str[128];
	char out_str[128];
	int hour = 12, min = 30, sec = 45;

	printf("문자열? ");
	gets_s(in_str, sizeof(in_str));
	puts(in_str);
	sprintf(out_str, "%02d:%02d:%02d", hour, min, sec);
	puts(out_str);


}