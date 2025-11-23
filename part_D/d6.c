/*
 *  задание_D6_контеста
 * Рекурсивная Функция вывода строки в обратном порядке
  */

#include <stdio.h>

void reverseString(void);

int main() {
	reverseString();
	return 0;
}

void reverseString(void)	{
	char c;
	if ((c = getchar()) != '.') reverseString();
	if (c != '.') putchar(c);
}
