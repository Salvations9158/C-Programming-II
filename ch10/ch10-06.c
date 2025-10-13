//학번 : 202511234
//이름 : 전민규
//프로그램 명: 구조체 배열의 검색
//날짜: 10월 12일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define STR_SIZE 20

void SrtuctArrSearch();


typedef struct contact
{
	char name[STR_SIZE];
	char phone[STR_SIZE];
	int ringtone;
}CONTACT;


int main(void)
{
	SrtuctArrSearch();

	return 0;
}

void SrtuctArrSearch()
{
	CONTACT arr[] =
	{
		{"김석진","01011112222",0},
		{"전정국","01012345678",1},
		{"박지민","01077778888",2},
		{"김남준","01055556666",9},
		{"민윤기","01011223344",5},
		{"정호석","01055556666",7},
		{"김태형","01048648644",3}
	};

	int size = sizeof(arr) / sizeof(arr[0]);
	int i;
	char name[STR_SIZE];
	int index;

	printf("이름? ");
	scanf("%s", name);

	index = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].name, name) == 0)
		{
			index = i;
			break;
		}
	}
	if (index >= 0)
	{
		printf("%s의 전화번호:%s\n", arr[index].name, arr[index].phone);
	}
	else
	{
		printf("연락처를 찾을 수 없습니다.\n");
	}
}