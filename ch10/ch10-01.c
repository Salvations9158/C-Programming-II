//학번 : 202511234
//이름 : 전민규
//프로그램 명: 구조체의 정의
//날짜: 10월 12일

#include <stdio.h>

void StructDefine();
void test();



struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
};

int main(void)
{
	StructDefine();

	return 0;
}

void StructDefine()
{
	printf("contact 구조체의 크기: %d\n", sizeof(struct contact));
	//printf("contact 구조체이 크기=%d\n",sizeof(contact)); //컴파일 에러
}

void test()
{
	struct contact c1;
}