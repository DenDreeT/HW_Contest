/*
 *  задание_D7_контеста
 * Рекурсивная Функция вывода всех цифр от N до 1
  */

#include <stdio.h>

void print_num(int);	//прототип функции


int main() {
	int N;
	scanf("%d", &N);
	print_num(N);
	return 0;
}

/* ************* определение функции ************** */
void print_num(int N) {
	printf("%d ", N);
	if (N > 1) print_num(N - 1);
}
