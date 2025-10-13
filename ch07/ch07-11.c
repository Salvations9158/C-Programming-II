//학번 : 202511234
//이름 : 전민규
//프로그램 명: 선택 정렬
//날짜: 10월 10일


#include <stdio.h>

#define SIZE 5

int main()
{
	selection_sort();

	return 0;
}

int selection_sort()
{
	int data[SIZE] = { 7,3,9,5,1 };
	int i, j;
	int index, temp;

	for (i = 0; i < SIZE; i++)
	{
		index = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (data[index] > data[j])
				index = j;
		}
		if (i != index)
		{
			temp = data[i];
			data[i] = data[index];
			data[index] = temp;
		}
	}
	printf("정렬 후: ");
	for (i = 0; i < SIZE; i++)
		printf("%d ", data[i]);
	printf("\n");
	return 0;

}