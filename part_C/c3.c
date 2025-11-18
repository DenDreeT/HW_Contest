/*
 *  задание_C3_контеста
 * функция подсчета среднего арифметического двух чисел 
  */

#include <stdio.h>

int res = 0;			//Да, пока без указателей :))

int middle(int, int);	//прототип функции
		
int main() {
	
	int a, b;
	scanf("%d %d", &a, &b);
	middle(a, b);		//вызов функции
	printf("%d\n", res);
	return 0;
}

int middle(int a, int b) {	//описание функции
	return (res = (a+b)/2);	//возврат результата из функции
}	
