//학번 : 202511234
//이름 : 전민규
//프로그램 명: LOGIN 구조체 소문자 변환 및 출력 함수
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#define MAX_LEN 21

typedef struct
{
	char id[MAX_LEN];
	char password[MAX_LEN];
} LOGIN;

void make_lower(LOGIN* login_data);
void print_login(const LOGIN* login_data);
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

	make_lower(&user_info);

	print_login(&user_info);
}

void make_lower(LOGIN* login_data)
{
	int i;

	for (i = 0; login_data->id[i] != '\0'; i++)
	{
		login_data->id[i] = (char)tolower(login_data->id[i]);
	}

	for (i = 0; login_data->password[i] != '\0'; i++)
	{
		login_data->password[i] = (char)tolower(login_data->password[i]);
	}
}

void print_login(const LOGIN* login_data)
{
	printf("ID: %s\n", login_data->id);
	printf("PW: ");

	int len = (int)strlen(login_data->password);
	for (int i = 0; i < len; i++)
	{
		printf("*");
	}
	printf("\n");
}