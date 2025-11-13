/*
 *  задание_B6_контеста
  */

#include <stdio.h>

int main() {
	
    int num, digit1, digit2, i=0;

    scanf("%d", &num);

    while (num > 0) {
		
        digit1 = num % 10; // Получаем последнюю цифру
        num /= 10;         // Удаляем последнюю цифру из числа
        digit2 = num % 10; // Получаем соседнюю цифру
        if (digit1 == digit2) {
			puts ("YES");
			i = 1;			//флаг события "YES"
		}
	        
    }
    if (i == 0) puts ("NO");//Проверка состояния флага и вывод "NO" 
	
	return 0;
}

