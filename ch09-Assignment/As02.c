//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열을 역순으로 만드는 reverse_string 함수 작성 프로그램
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// 함수 선언
void reverse_string(char str[]);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	char str[MAX_SIZE];

	printf("문자열? ");
	gets_s(str, MAX_SIZE);

	reverse_string(str);

	printf("역순으로 된 문자열: %s\n", str);
}

void reverse_string(char str[])
{
	int length = strlen(str);
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}