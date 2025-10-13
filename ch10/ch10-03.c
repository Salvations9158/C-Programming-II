//학번 : 202511234
//이름 : 전민규
//프로그램 명: 구조체 변수 간의 초기화와 대입
//날짜: 10월 12일
#include <stdio.h>
#include <string.h>

void StructReset();


struct contact
{
	char name[20];
	char phone[20];
	int ringtone;
};

int main(void)
{
	StructReset();

	return 0;

}

void StructReset()
{
	struct contact ct = { "김석진","01011112222",0 };
	struct contact ct1 = { "전정국","01012345678",1 };
	struct contact ct2 = ct1; //구조체 변수로 초기화할 수 있다.
	printf("ct1으로 초기화 후의 ct2 =%s,%s,%d\n", ct.name, ct2.phone, ct2.ringtone);

	ct2 = ct;
	printf("ct를 대입한 후의 ct2=%s,%s,%d\n", ct2.name, ct2.phone, ct2.ringtone);

}