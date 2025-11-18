/*
 *  задание_C16_контеста
 * Проверка на простые числа
  */

#include <stdio.h>

int num = 0, count = 0;

int is_prime(int);	//прототип функции

int main() {
	
	scanf("%d", &num);
    is_prime(num);
    (count == 0) ? puts("YES") : puts("NO");
    
    return 0;
}

/* **********определение функции *************/

int is_prime(int num) {					
	if (num > 1) {						//исключение число/цифра '1'
    	for (int i = 2; i*i <= num; i++) {
			if ((num%i) == 0) count++;	//проверка простоты числа
	 	}
	}
	else count++;
	//(count == 0) ? puts("YES") : puts("NO");
}
