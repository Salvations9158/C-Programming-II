//학번 : 202511234
//이름 : 전민규
//프로그램 명: 직사각형의 넓이와 둘레를 구하는 get_rect_info 함수를 작성하시오. 직사각형의 가로, 세로의 길이를 입력받은 다음 get_rect_info 함수를 이용해서 직사각형의 넓니와 둘레를 구해서 출력하는 프로그램을 작성하시오.
//날짜: 9월 24일

#include <stdio.h>

void get_rext_info(int* width, int* height);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	int width = 0;
	int* pwidth = &width;

	int height = 0;
	int* pheight = &height;


	printf("가로? ");
	scanf_s("%d", &width);
	printf("세로? ");
	scanf_s("%d", &height);

	get_rext_info(pwidth, pheight);
}

void get_rext_info(int* width, int* height)
{
	printf("넓이: %d, 둘레: %d", (*width) * (*height), ((*width) * 2) + ((*height) * 2));
}