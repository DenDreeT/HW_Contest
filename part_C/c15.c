/*
 *  задание_C15_контеста
 * Функция проверки числа с цифрами по возрастанию
  */

#include <stdio.h>

int num, digit1, digit2, i = 0;

int grow_up(int);	//прототип функции

int main() {
	
    scanf("%d", &num);
	grow_up(num);	//вызов функции
    
	return 0;
}

int grow_up(int) {	//прототип функции
	while (num > 0) {
		
        digit1 = num % 10;			// Получаем последнюю цифру
        num /= 10; 					// Удаляем последнюю цифру из числа
        digit2 = num % 10;			//Берем соседнюю цифру 
        if (digit1 <= digit2) i = ++i;//Проверка убывания по разрядам 	        
    }	
    
    (i == 0) ? puts("YES") : puts("NO") ;//Проверка счетчика
    return 0;
}
