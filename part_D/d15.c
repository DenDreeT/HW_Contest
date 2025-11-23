/*
 *  задание_D15_контеста
 * Рекурсивная Функция вывода наибольшего числа из последовательности
 * Ограничитель последовательности цифра '0'
 *  */

#include <stdio.h>

int max_find(int); //прототип функции

int main()	{
	printf("%d\n", max_find(0));
	return 0;
}

/* ************* определение функции **************** */

int max_find(int max)	{
	int input;
	scanf("%d", &input);
	if (input == 0) return max;
	if ((max == 0) || (input > max)) max = input;
	return max_find(max);
}
