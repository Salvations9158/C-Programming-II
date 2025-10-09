//학번 : 202511234
//이름 : 전민규
//프로그램 명: 기차표 예매 프로그램을 작성하려고 한다. 간단한 구현을 위해 좌석은 모두 10개라고 하자. 예매할 좌석수를 입력받아 빈 자리를 할당한다. 예매할 때마다 각 좌석의 상태를 출력한다. 0이면 예매 가능, X는 예매 불가를 의미한다. 더이상 예매할 수 없으면 프로그램을 종료한다.
//날짜: 9월 18일

#include <stdio.h>

void printSeats(int seats[], int size);
void Execution();

int main()
{
    Execution();
    return 0;
}

void printSeats(int seats[], int size) 
{
    printf("현재 좌석: [");
    for (int i = 0; i < size; i++) 
    {
        if (seats[i] == 0) 
        {
            printf(" 0"); 
        }
        else 
        {
            printf(" X"); 
        }
    }
    printf("]\n");
}

void Execution()
{
    int seats[10] = { 0 };
    int totalCapacity = 10;
    int reservedCount = 0;
    int seatsToReserve = 0; 

    while (reservedCount < totalCapacity) 
    {

        printSeats(seats, totalCapacity);

        printf("예약할 좌석수? ");

        if (scanf_s("%d", &seatsToReserve) != 1) 
        {
            printf("잘못된 입력입니다. 숫자를 입력해주세요. 프로그램을 종료합니다.\n");
            while (getchar() != '\n');
            return;
        }

        if (seatsToReserve <= 0) 
        {
            printf("예약할 좌석수는 1개 이상이어야 합니다.\n");
            continue;
        }

        int availableSeats = totalCapacity - reservedCount;

        if (seatsToReserve > availableSeats) 
        {
            printf("예약 가능한 좌석(%d개)이 부족합니다. %d개만 예약할 수 있습니다.\n", availableSeats, availableSeats);
            continue;
        }

        int reservedNow = 0; 
        int reservedNumbers[10];

        for (int i = 0; i < totalCapacity && reservedNow < seatsToReserve; i++) 
        {
            if (seats[i] == 0) 
            { 
                seats[i] = 1; 
                reservedNumbers[reservedNow] = i + 1; 
                reservedCount++;
                reservedNow++;
            }
        }

        if (reservedNow > 0) {
            for (int i = 0; i < reservedNow; i++) 
            {
                printf("%d", reservedNumbers[i]);
                if (i < reservedNow - 1) 
                {
                    printf(" ");
                }
            }
            printf(" 번 좌석을 예매했습니다.\n");
        }
        else 
        {
            printf("예약을 완료하지 못했습니다. 다시 시도해주세요.\n");
        }
    }

    printSeats(seats, totalCapacity);
    printf("모든 좌석이 예약되었습니다. 프로그램을 종료합니다.\n");
}