//학번 : 202511234
//이름 : 전민규
//프로그램 명: 공용체를 이용한 RGB 색상 표현
//날짜: 10월 12일

#include <stdio.h>

void UnionRGB();


typedef union color_t
{
	unsigned int color;
	unsigned char rgb[4];
}COLOR_T;

int main(void)
{
	UnionRGB();

	return 0;

}

void UnionRGB()
{
	COLOR_T c1;

	c1.rgb[0] = 0xFF;
	c1.rgb[1] = 0xAB;
	c1.rgb[2] = 0x1F;
	c1.rgb[3] = 0x0;

	printf("rgb color = %08X\n", c1.color);
}