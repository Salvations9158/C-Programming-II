//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열의 비교
//날짜: 10월 11일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10

void str_compare();


int main()
{
	str_change();

	return 0;
}

void str_compare()
{
	char s1[SIZE] = "apple";
	char s2[SIZE] = "apple";
	char password[SIZE];

	if (s1 == s2)
		printf("same address\n");

	if (strcmp(s1, s2) == 0)
		printf("same string\n");

	printf("패스워드? ");
	scanf("%s", password);
	if (strcmp(password, "abcd1234") == 0)
		printf("login succeeded\n");
	else
		printf("login failed\n");

	return 0;
}