//학번 : 202511234
//이름 : 전민규
//프로그램 명: 노래 제목 관리 프로그램 (최대 20개 저장)
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#define MAX_SONGS 20 
#define MAX_TITLE_LEN 41 

int find_song_index(const char titles[][MAX_TITLE_LEN], int count, const char title[]);
void add_song(char titles[][MAX_TITLE_LEN], int* count);
void modify_song(char titles[][MAX_TITLE_LEN], int count);
void list_songs(const char titles[][MAX_TITLE_LEN], int count);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	char song_titles[MAX_SONGS][MAX_TITLE_LEN] = { 0 };
	int song_count = 0; 
	int choice = -1;  

	do
	{
		printf("\n[ 0.종료 1.추가 2.수정 3.목록 ] 선택? ");
		if (scanf_s("%d", &choice) != 1)
		{
			printf("잘못된 입력입니다.\n");
			while (getchar() != '\n');
			choice = -1;
			continue;
		}
		while (getchar() != '\n'); 

		switch (choice)
		{
		case 1:
			add_song(song_titles, &song_count);
			break;
		case 2:
			modify_song(song_titles, song_count);
			break;
		case 3:
			list_songs(song_titles, song_count);
			break;
		case 0:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("잘못된 메뉴 선택입니다 (0~3). 다시 선택하세요.\n");
			break;
		}
	} while (choice != 0);
}

int find_song_index(const char titles[][MAX_TITLE_LEN], int count, const char title[])
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(titles[i], title) == 0)
		{
			return i;
		}
	}
	return -1;
}

void add_song(char titles[][MAX_TITLE_LEN], int* count)
{
	if (*count >= MAX_SONGS)
	{
		printf("노래 목록이 가득 찼습니다. (최대 %d개)\n", MAX_SONGS);
		return;
	}

	printf("노래 제목? ");
	scanf_s("%[^\n]s", titles[*count], (unsigned)MAX_TITLE_LEN);
	while (getchar() != '\n'); 

	(*count)++;
	printf("노래가 추가되었습니다.\n");
}

void modify_song(char titles[][MAX_TITLE_LEN], int count)
{
	if (count == 0)
	{
		printf("수정할 노래가 없습니다. 먼저 노래를 추가하세요.\n");
		return;
	}

	char search_title[MAX_TITLE_LEN];
	char new_title[MAX_TITLE_LEN];
	int index;

	printf("찾을 노래 제목? ");
	scanf_s("%[^\n]s", search_title, (unsigned)MAX_TITLE_LEN);
	while (getchar() != '\n'); 

	index = find_song_index(titles, count, search_title);

	if (index == -1)
	{
		printf("'%s'라는 제목의 노래를 찾을 수 없습니다.\n", search_title);
		return;
	}

	printf("수정할 제목? ");
	scanf_s("%[^\n]s", new_title, (unsigned)MAX_TITLE_LEN);
	while (getchar() != '\n'); 

	strcpy_s(titles[index], MAX_TITLE_LEN, new_title); 

	printf("노래 제목이 수정되었습니다.\n");
}

void list_songs(const char titles[][MAX_TITLE_LEN], int count)
{
	printf("\n<< 노래 목록 >>\n");
	if (count == 0)
	{
		printf("목록에 노래가 없습니다.\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%s\n", titles[i]);
	}
}