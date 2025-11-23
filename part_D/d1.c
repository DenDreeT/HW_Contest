/*
 *  задание_D1_контеста
 * Рекурсивная Функция вывода чисел от 1 до N
  */

#include <stdio.h>

void print_number(int); //прототип функции


int main() {
	int N;
	scanf("%d", &N);
	print_number(N); //вызов функции
	
	return 0;
}

/* ************** описание функции************ */

void print_number(int N) {
	if (N > 1)
	print_number(N - 1);
	printf("%d ", N);
}
