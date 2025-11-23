/*
 *  задание_D3_контеста
 * Рекурсивная Функция вывода цифры числа в обратном порядке через ' '
  */

#include <stdio.h>

void recur_num(int); //прототип функции


int main() {
	int N;
	scanf("%d", &N);
	(N >= 1) ? recur_num(N) : printf("0\n");	//вызов функции
	
	return 0;
}

/* ************** описание функции************ */

void recur_num(int N) {
	
	if (N == 0) return;
	printf("%d ", N%10);
	recur_num(N/10);
	
}
