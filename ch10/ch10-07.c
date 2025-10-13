//학번 : 202511234
//이름 : 전민규
//프로그램 명: 구조체 포인터
//날짜: 10월 12일

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void StructPointer();

#define STR_SIZE 20

typedef struct contact
{
	char name[STR_SIZE];
	char phone[STR_SIZE];
	int ringtone;
}CONTACT;

int main(void)
{
	StructPointer();

	return 0;

}

void StructPointer()
{
	CONTACT ct = { "김석진","01011112222",0 };
	CONTACT* p = &ct;
	p->ringtone = 5;
	strcpy(p->phone, "01011112223");
	printf("이름:%s\n", p->name);
	printf("전화번호:%s\n", p->phone);
	printf("벨소리:%d\n", p->ringtone);
}