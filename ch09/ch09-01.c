//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열 배열의 초기화 및 출력
//날짜: 10월 11일

#include <stdio.h>

int main()
{
	str_reset();

	return 0;

}

void str_reset()
{
	char str1[10] = { 'a','b','c' };
	char str2[10] = "abc";
	char str3[] = "abc";
	char str4[20] = "very long string";

	int size = sizeof(str1) / sizeof(str2[0]);
	int i;
	printf("str= ");
	for (i = 0; i < size; i++)
	{
		printf("%c", str1[i]);
	}
	printf("\n");

	printf("str2= %s\n", str2);

	printf("str3= ");
	printf(str3);
	printf("\n");

	printf("str4=%s\n", str4);

	return 0;
}