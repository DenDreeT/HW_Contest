/*
 *  задание_D2_контеста
 * Рекурсивная Функция вывода суммы чисел от 1 до N
  */

#include <stdio.h>

int recur_sum(int); //прототип функции


int main() {
	int N;
	scanf("%d",&N);
	printf("%d\n", recur_sum(N)); //вызов функции
	
	return 0;
}

/* ************** описание функции************ */

int recur_sum(int N) {
	return (N == 1) ? 1 : N + recur_sum(N - 1);
}
