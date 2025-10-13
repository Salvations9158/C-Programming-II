///학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열 포인터가 문자 배열을 가리키는 경우
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void pointer_arr();


int main()
{
	pointer_arr();

	return 0;
}

void pointer_arr()
{
	char str[64] = "";
	char* p = str;

	strcpy(p, "test string");

	if (islower(p[0]))
		p[0] = toupper(p[0]);

	p = strchr(p, ' ');

	if (islower(p[1]))
		p[1] = toupper(p[1]);
	puts(str);

}