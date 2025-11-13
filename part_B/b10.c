/*
 *  задание_B10_контеста
  */

#include <stdio.h>

int main() {
	
    int num, digit1, digit2, i = 0;
    
    scanf("%d", &num);

    while (num > 0) {
		
        digit1 = num % 10;			// Получаем последнюю цифру
        num /= 10; 					// Удаляем последнюю цифру из числа
        digit2 = num % 10;			//Берем соседнюю цифру 
        if (digit1 <= digit2) i = ++i;//Проверка убывания по разрядам 	        
    }	
    
    (i == 0) ? puts("YES") : puts("NO") ;//Проверка счетчика 
	
	return 0;
}

