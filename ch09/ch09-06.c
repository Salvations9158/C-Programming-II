//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열의 검색
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void str_search();


int main(void)
{
	str_search();

	return 0;
}

void str_search()
{

	char filename[] = "readme.txt";
	char* p = NULL;

	p = strchr(filename, '.');
	if (p != NULL)
		printf("file extension: %s\n", p + 1);

	p = strstr(filename, ".txt");
	if (p != NULL)
		printf("file type:TEXT file\n");


}