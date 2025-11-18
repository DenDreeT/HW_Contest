/*
 *  задание_C18_контеста
 * Функция подсчета количество цифр в введенной строке
  */

#include <stdio.h>

char c;
int count = 0;

int is_digit(char);		//прототип функции

int main() {
    
    while ((c = getchar())!='.') { // Читаем один символ
	is_digit(c);	//вызываем функцию	

	}
	
	printf("%d\n", count);
	
    return 0;
}

/* ******** определение функции   *******/

int is_digit(char с) {
// Проверяем, является ли символ цифрой
	if (c >= '0' && c <= '9') {
		count++;
	}
	return count;
}
