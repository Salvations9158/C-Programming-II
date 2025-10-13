//학번 : 202511234
//이름 : 전민규
//프로그램 명: 문자열의 연결
//날짜: 10월 11일

#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	str_connection();

	return 0;
}

int str_connection()
{
	char sentence[100] = "";
	char word[20];

	do {
		printf("단어? ");
		scanf("%s", word);
		strcat(sentence, word);
		strcat(sentence, " ");
	} while (strcmp(word, ".") != 0);
	printf("%s\n", sentence);
}