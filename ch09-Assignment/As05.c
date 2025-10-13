//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열을 지정된 수만큼 왼쪽/오른쪽으로 회전(Rotate)시키는 프로그램
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

void reverse(char str[], int start, int end);
void rotate_string(char str[], int shift);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	char str[MAX_SIZE];
	int shift = -1;

	printf("문자열? ");
	scanf_s("%[^\n]s", str, 20);
	while (getchar() != '\n');

	while (shift != 0)
	{
		printf("이동할 글자 수? ");
		if (scanf_s("%d", &shift) != 1)
		{
			printf("잘못된 입력입니다.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');

		if (shift == 0)
		{
			break; 
		}

		rotate_string(str, shift);

		printf("회전 결과: %s\n", str);
	}

	printf("프로그램을 종료합니다.\n");
}

void reverse(char str[], int start, int end)
{
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

void rotate_string(char str[], int shift)
{
	int length = strlen(str);
	if (length == 0 || shift == 0)
	{
		return;
	}

	shift = shift % length;
	if (shift < 0)
	{
		shift = length + shift;
	}

	if (shift == 0) return;

	int a_end = length - shift - 1;
	int b_start = length - shift;
	int total_end = length - 1;

	reverse(str, 0, a_end);

	reverse(str, b_start, total_end);

	reverse(str, 0, total_end);
}