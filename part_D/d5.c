/*
 *  задание_D5_контеста
 * Рекурсивная Функция перевода числа в двоичный вид
  */

#include <stdio.h>
void get_bin(int num);	//прототип функции

int main() {
	int num;
	scanf("%d", &num);
	get_bin(num);
	return 0;
}

/* ************** описание функции************ */

void get_bin(int num)	{
	if (num > 1) {
		get_bin(num / 2);
	}
	printf("%d", num % 2);
}
