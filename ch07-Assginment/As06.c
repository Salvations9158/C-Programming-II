//학번 : 202511234
//이름 : 전민규
//프로그램 명: 정수를 입력받아 집합의 원소로 추가하고, 그 때마다 집합의 원소들을 출력하시오.
//날짜: 9월 18일
#include <stdio.h>

void Execution();
int contains(const int arr[], int size, int value);

int main()
{
    Execution();
    return 0;
}

void Execution()
{
    int set[10];
    int count = 0;
    int newValue;

    while (count < 10)
    {
        printf("배열에 추가할 원소? ");
        if (scanf_s("%d", &newValue) != 1)
        {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            break;
        }

        if (contains(set, count, newValue))
        {
            printf("해당 원소는 이미 집합에 존재합니다.\n");
        }
        else
        {
            set[count] = newValue;
            count++;
        }

        for (int i = 0; i < count; i++)
        {
            printf("%d ", set[i]);
        }
        printf("\n");
    }

}

int contains(const int arr[], int size, int value) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == value) 
        {
            return 1;
        }
    }
    return 0;
}