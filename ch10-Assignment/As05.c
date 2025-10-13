//학번 : 202511234
//이름 : 전민규
//프로그램 명: PRODUCT 구조체 배열을 이용한 제품 주문 처리 프로그램
//날짜: 10월 12일

#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 5  
#define MAX_NAME_LEN 30

typedef struct
{
	char name[MAX_NAME_LEN]; 
	int price;               
	int stock;             
} PRODUCT;

void print_product_list(const PRODUCT products[], int size);
int find_product_index(const PRODUCT products[], int size, const char name[]);
void process_order(PRODUCT products[], int size);
void Execusion();

int main()
{
	Execusion();
	return 0;
}

void Execusion()
{
	PRODUCT product_list[MAX_PRODUCTS] = {
		{"아메리카노", 4000, 10},
		{"카페라떼", 4500, 10},
		{"플랫화이트", 5000, 10},
		{"카푸치노", 5500, 5},
		{"자몽차", 6000, 8}
	};

	while (1) {
		process_order(product_list, MAX_PRODUCTS);

		print_product_list(product_list, MAX_PRODUCTS);

		printf("\n다른 주문을 시작하려면 제품명을 입력하세요 (종료하려면 '종료' 입력): ");

		char check_exit[MAX_NAME_LEN];
		scanf_s("%s", check_exit, (unsigned)MAX_NAME_LEN);
		while (getchar() != '\n');

		if (strcmp(check_exit, "종료") == 0) {
			break;
		}
	}
}

void process_order(PRODUCT products[], int size)
{
	char order_name[MAX_NAME_LEN];
	int order_quantity;
	int index;

	printf("\n주문할 제품명? ");
	scanf_s("%s", order_name, (unsigned)MAX_NAME_LEN);
	while (getchar() != '\n'); 

	index = find_product_index(products, size, order_name);

	if (index == -1)
	{
		printf("오류: '%s' 제품을 찾을 수 없습니다.\n", order_name);
		return;
	}

	printf("주문할 수량? ");
	if (scanf_s("%d", &order_quantity) != 1 || order_quantity <= 0)
	{
		printf("오류: 올바른 수량을 입력해야 합니다.\n");
		while (getchar() != '\n');
		return;
	}
	while (getchar() != '\n');

	if (products[index].stock < order_quantity)
	{
		printf("오류: '%s'의 재고가 부족합니다. (현재 재고: %d개)\n",
			order_name, products[index].stock);
		return;
	}

	long long total_price = (long long)products[index].price * order_quantity;
	products[index].stock -= order_quantity;

	printf("결제 금액: %lld원 %s 재고: %d\n",
		total_price, products[index].name, products[index].stock);
}

int find_product_index(const PRODUCT products[], int size, const char name[])
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(products[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void print_product_list(const PRODUCT products[], int size)
{
	printf("\n주문할 제품명? \n"); 

	for (int i = 0; i < size; i++)
	{
		if (products[i].stock > 0) {
			printf("[%s %d원 재고:%d]\n",
				products[i].name,
				products[i].price,
				products[i].stock);
		}
	}
}