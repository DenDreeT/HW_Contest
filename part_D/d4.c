/*
 *  задание_D4_контеста
 * Рекурсивная Функция вывода цифры числа в прямом порядке через ' '
  */

#include <stdio.h>

void print_num(int); //прототип функции


int main() {
	int N;
	scanf("%d", &N);
	(N >= 1) ? print_num(N) : printf("0\n");	//вызов функции
	
	return 0;
}

/* ************** описание функции************ */

void print_num(int N) {
	if (N == 0) return;
	print_num(N/10);
	printf("%d ", N%10);
}
