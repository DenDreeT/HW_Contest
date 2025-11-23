/*
 *  задание_D11_контеста
 * Рекурсивная Функция подсчета количества '1' числа
  */

#include <stdio.h>

int count;

int get_bin(int);	//прототип функции

int main() {
	int num;
	scanf("%d", &num);
	get_bin(num);
	printf("%d\n", count);
	return 0;
}

/* ************** описание функции************ */

int get_bin(int num)	{
	int k;
	if (num == 0) return;
	get_bin(num / 2);
	k = num % 2;
	if ( k == 1 ) count++; 
	return count;
}
