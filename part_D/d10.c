/*
 *  задание_D10_контеста
 * Рекурсивная Функция проверки числа на простоту
 * 
 *  */

#include <stdio.h>

int is_prime(int, int);	//прототип функции

int main() {
	int num;
	scanf("%d", &num);
	is_prime(num, 2) ? puts("YES") : puts("NO");
	return 0;
}


/* ************* определение функции **************** */

int is_prime(int num, int delitel) {
	if (num == delitel) return 1;
	if ((num > 1) && (num % delitel != 0)) {
		return is_prime(num, delitel + 1);
	}
	else return 0;
}
