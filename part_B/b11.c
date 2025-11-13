/*
 *  задание_B11_контеста
  */

#include <stdio.h>

int main() {
	
    int num, digit;
    
    scanf("%d", &num);
	if (num >0) {
		while (num > 0) {
		
			digit = num % 10;			// Получаем последнюю цифру
			num /= 10; 					// Удаляем последнюю цифру из числа
			printf ("%d", digit);		//Выводим число на дисплей
		}
	
    }
    else puts("0");						//В случае, если число = 0
    return 0;
}

