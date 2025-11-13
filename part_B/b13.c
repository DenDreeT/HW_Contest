/*
 *  задание_B13_контеста
  */

#include <stdio.h>

int main() {
	
    int num, digit, a = 0, b = 0;
    
    scanf("%d", &num);

    while (num > 0) {
		
        digit = num % 10;			// Получаем последнюю цифру
        num /= 10; 					// Удаляем последнюю цифру из числа
        ((digit % 2) == 0) ? (a = ++a) : (b = ++b); //Счетчики четности
         	        
    }	
    printf ("%d %d\n", a, b);
    
    return 0;
}

