/*
 *  задание_D9_контеста
 * Рекурсивная Функция вывода суммы цифр числа N>10
  */

#include <stdio.h>

int sum_digit(int);	//прототип функции

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", sum_digit(N));
	return 0;
}


/* ************* определение функции **************** */

int sum_digit(int N) {
	int sum = N % 10;
	if (N >= 10) sum += sum_digit(N / 10);
	return sum;
}
