/*
 *  задание_B5_контеста
  */

#include <stdio.h>

int main() {
	
    int n, sum = 0, digit;

    scanf("%d", &n);

    while (n > 0) {
		
        digit = n % 10; // Получаем последнюю цифру
        
        sum += digit;   // Прибавляем её к сумме
        
        n /= 10;        // Удаляем последнюю цифру из числа
    }

    printf("%d\n", sum);
	
	return 0;
}

