/*
 *  задание_D12_контеста
 * Рекурсивная Функция вывода монотонной последовательности, где
 *  num - предельное количество выводимых чисел
 * 
 *  */

#include <stdio.h>

void print_sequence(int, int);	//прототип функции

int main() {
	int num;
	scanf("%d", &num);
	print_sequence(num, 1);
	return 0;
}


/* ************* определение функции **************** */

void print_sequence(int num, int k) {
	for (int i = 1; i <= k; i++) {
		printf("%d ", k);
		num--;
		if (num == 0) return;
	}
	print_sequence(num, k + 1);
}
