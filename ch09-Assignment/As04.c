//학번 : 202511234
//이름 : 전민규
//프로그램 명: 유효한 시간 문자열인지 확인하는 check_time_str 함수
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h> 
#define MAX_TIME_LEN 7 

int check_time_str(const char time_str[]);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	char time_str[MAX_TIME_LEN];

	printf("시간(. 입력 시 종료)? ");
	scanf_s("%s", time_str, 20);
	while (getchar() != '\n');

	while (strcmp(time_str, ".") != 0)
	{
		if (check_time_str(time_str))
		{
			printf("%s는 유효한 시간입니다.\n", time_str);
		}
		else
		{
			printf("잘못 입력했습니다. hhmmss 형식으로 입력하세요.\n");
		}

		printf("시간(. 입력 시 종료)? ");
		scanf_s("%s", time_str, 20);
		while (getchar() != '\n');
	}
}

int check_time_str(const char time_str[])
{
	if (strlen(time_str) != 6)
	{
		return 0;
	}

	for (int i = 0; i < 6; i++)
	{
		if (!isdigit(time_str[i]))
		{
			return 0;
		}
	}

	char hour_str[3] = { time_str[0], time_str[1], '\0' };
	int hour = atoi(hour_str);

	char min_str[3] = { time_str[2], time_str[3], '\0' };
	int minute = atoi(min_str);

	char sec_str[3] = { time_str[4], time_str[5], '\0' };
	int second = atoi(sec_str);

	if (hour < 0 || hour > 23)
	{
		return 0;
	}

	if (minute < 0 || minute > 59)
	{
		return 0;
	}

	if (second < 0 || second > 59)
	{
		return 0;
	}

	return 1;
}