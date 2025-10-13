//학번 : 202511234
//이름 : 전민규
//프로그램 명: 탐색의 성공, 실패를 확인하는 경우
//날짜: 10월 10일

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	arr_exploration();

	return 0;

}

int arr_exploration()
{
	int data[] = { 78,34,52,15,63,15,25 };
	int size;
	int key, i;
	int found;

	size = sizeof(data) / sizeof(data[0]);

	printf("arr= ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");

	printf("찾을 값(키)? ");
	scanf("%d", &key);

	found = 0;
	for (i = 0; i < size; i++)
	{
		if (data[i] == key)
		{
			found = 1;
			break;
		}
	}

	if (found == 1)
		printf("찾은 원소의 인덱스: %d\n", i);

	else
		printf("탐색 실패\n");

	return 0;
}