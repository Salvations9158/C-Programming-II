//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열의 소문자를 대문자로, 대문자를 소문자로 변환하는 프로그램
//날짜: 10월 12일

#include <stdio.h>
#include <ctype.h> 
#define MAX_SIZE 100

void ConvertCase(char str[]);
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

	ConvertCase(str);

	printf("변환 후: %s\n", str);
}

void ConvertCase(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
		else if (islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}

		i++;
	}
}