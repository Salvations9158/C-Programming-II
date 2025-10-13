//학번 : 202511234
//이름 : 전민규
//프로그램 명: 대소문자를 구분하지 않고 문자열을 비교하는 strcmp_ic 함수
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#include <ctype.h>  
#define MAX_SIZE 100

int strcmp_ic(const char lhs[], const char rhs[]);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
	int result;

	printf("첫 번째 문자열? ");
	scanf_s("%[^\n]s", str1, 20);
	while (getchar() != '\n');

	printf("두 번째 문자열? ");
	scanf_s("%[^\n]s", str2, 20);
	while (getchar() != '\n');

	result = strcmp_ic(str1, str2);

	if (result == 0)
	{
		printf("\"%s\"와 \"%s\"가 같습니다.\n", str1, str2);
	}
	else if (result > 0)
	{
		printf("\"%s\"가 \"%s\"보다 큽니다.\n", str1, str2);
	}
	else 
	{
		printf("\"%s\"가 \"%s\"보다 작습니다.\n", str1, str2);
	}
}

int strcmp_ic(const char lhs[], const char rhs[])
{
	int i = 0;
	int char1_upper, char2_upper;

	while (lhs[i] != '\0' && rhs[i] != '\0')
	{
		char1_upper = toupper((unsigned char)lhs[i]);
		char2_upper = toupper((unsigned char)rhs[i]);

		if (char1_upper != char2_upper)
		{
			return char1_upper - char2_upper;
		}
		i++;
	}
	return toupper((unsigned char)lhs[i]) - toupper((unsigned char)rhs[i]);
}