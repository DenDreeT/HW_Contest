/*
 *  задание_C1_контеста
 * функция взятия числа по модулю 
  */

#include <stdio.h>


void modul(signed int);	//прототип функции
		
int main() {
	
	signed int number;
	
	scanf("%d", &number);
	modul(number);
	
	return 0;
}

void modul(signed int number) {	//описание функции
	if (number < 0) number = -number;
	else number;
	printf("%d\n", number);	//выводим модуль числа в консоль
	//return number;	//раскомитить если вернуть int
}	
