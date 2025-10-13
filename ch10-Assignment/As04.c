//학번 : 202511234
//이름 : 전민규
//프로그램 명: LOGIN 구조체 배열을 이용한 로그인 프로그램
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 21
#define ARRAY_SIZE 5

typedef struct
{
	char id[MAX_LEN];
	char password[MAX_LEN];
} LOGIN;

int find_user(const LOGIN users[], int size, const char input_id[]);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	LOGIN user_list[ARRAY_SIZE] = {
		{"admin", "pass1234"},
		{"guest", "idontknow"},
		{"user1", "userpass"},
		{"test", "12345"},
		{"student", "cprogram"}
	};

	char input_id[MAX_LEN];
	char input_pw[MAX_LEN];
	int user_index;

	printf("ID? ");
	scanf_s("%[^\n]s", input_id, (unsigned)MAX_LEN);
	while (getchar() != '\n');

	for (int i = 0; input_id[i] != '\0'; i++)
	{
		input_id[i] = (char)tolower(input_id[i]);
	}

	user_index = find_user(user_list, ARRAY_SIZE, input_id);

	if (user_index == -1)
	{
		printf("사용자를 찾을 수 없습니다.\n");
		return;
	}

	printf("PW: ");
	scanf_s("%[^\n]s", input_pw, (unsigned)MAX_LEN);
	while (getchar() != '\n');

	if (strcmp(user_list[user_index].password, input_pw) == 0)
	{
		printf("로그인 성공\n");
	}
	else
	{
		printf("비밀번호가 일치하지 않습니다.\n");
	}
}

int find_user(const LOGIN users[], int size, const char input_id[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(users[i].id, input_id) == 0)
		{
			return i;
		}
	}
	return -1;
}