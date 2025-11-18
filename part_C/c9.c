/*
 *  задание_C9_контеста
 * Функция расчета факториала числа N
  */

#include <stdio.h>

unsigned int N, fact = 1;

unsigned int factorial(unsigned int);	//прототип функции

int main() {
    
    scanf("%d", &N); // Считываем число
    
	factorial(N);	//вызываем функцию	
	printf("%d", fact);
    return 0;
}

//определение функции расчета факториала
unsigned int factorial(unsigned int N) {
	
	for (int i = 1; i <= N; i++) {
            fact *= i;
    }
    return fact;

}
