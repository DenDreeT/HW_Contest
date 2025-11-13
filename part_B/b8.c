/*
 *  задание_B8_контеста
  */

#include <stdio.h>

int main() {
	
    int num, digit, i = 0;
    const int I = 9;				//Константа для сравнения

    scanf("%d", &num);

    while (num > 0) {
		
        digit = num % 10;			// Получаем последнюю цифру
        num /= 10;					// Удаляем последнюю цифру из числа
        if (digit == I) i = ++i;	//Счетчик совпадений	        
    }
    
    (i == 1) ? puts("YES") : puts("NO") ;//Проверка счетчика 
	
	return 0;
}

