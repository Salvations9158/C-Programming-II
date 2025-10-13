//학번 : 202511234
//이름 : 전민규
//프로그램 명: 배열의 바이트 크기와 크기 구하기
//날짜: 10월 10일

#include <stdio.h>

int main(void)
{
	arr_bite();

	return 0;
}

int arr_bite(void)
{
	int arr[5];
	int byte_size = 0;
	int size = 0;
	int i;

	byte_size = sizeof(arr);
	printf("배열의 바이트 크기:%d", byte_size);

	size = sizeof(arr) / sizeof(arr[0]);
	printf("배열의 크기:%d\n", size);

	for (i = 0; i < size; i++)
		arr[i] = 0;

	return 0;

}