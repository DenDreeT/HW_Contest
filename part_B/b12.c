/*
 *  задание_B12_контеста
  */

#include <stdio.h>

int main() {
	
    int num, min = 9, max = 0, digit;
    
    scanf("%d", &num);

    while (num > 0) {
		
        digit = num % 10;			// Получаем последнюю цифру
        num /= 10; 					// Удаляем последнюю цифру из числа
        (digit >= max) ? max = digit : digit; //Проверка на MAX
        (digit <= min) ? min = digit : digit; //Проверка на MIN
         	        
    }	
    printf ("%d %d\n", min, max);
    
    return 0;
}

