#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#define SIZE 32
#define MAX 100

typedef struct _student
{
	char name[24];
	char id[16];
	char major[32];
	int year;
} Student;

void execution(Student students[], int* count, const char* temp);
void start();
void printstudents(const Student students[], int count);

int main()
{
	start();
	return 0;
}

void start()
{
	Student students[SIZE];
	int stcount = 0;

	while (1)
	{
		char temp[100] = "";
		printf("레코드 한 줄을 입력하시오(이름|학번|학과|학년 또는 exit): ");
		gets_s(temp, 100);

		if (strcmp(temp, "exit") == 0)
		{
			printstudents(students, stcount);
			break;
		}

		if (stcount < SIZE) {
			execution(students, &stcount, temp);
		}
		else {
			printf("더 이상 학생 정보를 저장불가\n");
			break;
		}
	}
}

void execution(Student students[], int* count, const char* temp)
{
	char* nameToken, * idToken, * majorToken, * yearToken;
	char asTemp[MAX];
	char* context = NULL;

	strcpy_s(asTemp, MAX, temp);

	nameToken = strtok_s(asTemp, "|", &context);
	idToken = strtok_s(NULL, "|", &context);
	majorToken = strtok_s(NULL, "|", &context);
	yearToken = strtok_s(NULL, "|", &context);

	if (nameToken && idToken && majorToken && yearToken)
	{
		Student tempstudent;
		strcpy_s(tempstudent.name, 24 ,nameToken);
		strcpy_s(tempstudent.id, 16, idToken);
		strcpy_s(tempstudent.major, SIZE, majorToken);
		tempstudent.year = atoi(yearToken); 

		students[*count] = tempstudent;
		(*count)++;
	}
	else
	{
		printf("잘못 쓴듯\n");
	}
}

void printstudents(const Student students[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d번째 학생 정보\n", i);
		printf("이름: %s 학번: %s, 학과: %s, 학년: %d\n",
			students[i].name, students[i].id, students[i].major, students[i].year);
	}
}