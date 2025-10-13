//학번 : 202511234
//이름 : 전민규
//프로그램 명: POINT 구조체 배열 x좌표 기준 선택 정렬 프로그램
//날짜: 10월 12일

#include <stdio.h>
#define SIZE 10

typedef struct
{
	int x;
	int y;
} POINT;

void swap_point(POINT* p1, POINT* p2);
void selection_sort_by_x(POINT points[], int size);
void print_points(const POINT points[], int size);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	POINT point_array[SIZE] = {
		{7, 4}, {12, 93}, {22, 31}, {1, 20}, {34, 53},
		{41, 2}, {32, 9}, {21, 31}, {8, 2}, {3, 5}
	};

	printf("<<정렬 전>>\n");
	print_points(point_array, SIZE);

	selection_sort_by_x(point_array, SIZE);

	printf("\n<<정렬 후>>\n");
	print_points(point_array, SIZE);
}

void swap_point(POINT* p1, POINT* p2)
{
	POINT temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void selection_sort_by_x(POINT points[], int size)
{
	int i, j, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (points[j].x < points[min_idx].x)
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap_point(&points[i], &points[min_idx]);
		}
	}
}

void print_points(const POINT points[], int size)
{
	printf("(");
	for (int i = 0; i < size; i++)
	{
		printf("%d, %d)", points[i].x, points[i].y);
		if (i < size - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}