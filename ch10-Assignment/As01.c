//학번 : 202511234
//이름 : 전민규
//프로그램 명: LOGIN 구조체 정의 및 출력 프로그램
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#define MAX_LEN 21

typedef struct
{
	char id[MAX_LEN];
	char password[MAX_LEN];
} LOGIN;

void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	LOGIN user_info;

	printf("ID? ");
	scanf_s("%[^\n]s", user_info.id, (unsigned)MAX_LEN);
	while (getchar() != '\n');

	printf("Password? ");
	scanf_s("%[^\n]s", user_info.password, (unsigned)MAX_LEN);
	while (getchar() != '\n');

	printf("ID: %s\n", user_info.id);
	printf("PW: ");

	int len = (int)strlen(user_info.password);
	for (int i = 0; i < len; i++)
	{
		printf("*");
	}
	printf("\n");
}