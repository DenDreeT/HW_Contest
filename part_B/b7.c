/*
 *  задание_B7_контеста
  */

#include <stdio.h>

int main() {
	
    int num, digit1, digit2, count=0;

    scanf("%d", &num);

    while (num > 0) {
		
        digit1 = num % 10; // Получаем последнюю цифру
        num /= 10;         // Удаляем последнюю цифру из числа
        
        while (num > 0) {
			digit2 = num % 10; // Получаем соседнюю цифру
			num /= 10;         // Удаляем последнюю цифру из числа
			if (digit1 == digit2) count++;
		}		
	        
    }
    //Проверка состояния флага и вывод "YES" "NO"
    (count != 0) ? puts("YES") : puts ("NO"); 
	
	return 0;
}

