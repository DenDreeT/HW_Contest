/*
 *  задание_B20_контеста
 * Проверка на простые числа
  */

#include <stdio.h>

int main() {
	
	int num = 0, count = 0;
	scanf("%d", &num);
    if (num > 1) {						//исключение число/цифра '1'
    	for (int i = 2; i*i <= num; i++) {
			if ((num%i) == 0) count++;	//проверка простоты числа
	 	}
	}
	else count++;
	(count == 0) ? puts("YES") : puts("NO");
    
    return 0;
}

