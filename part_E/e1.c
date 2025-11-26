/*
 *  задание_E1_контеста
 * Среднее арифметическое 5-ти чисел в массиве
 * 
 *  */

#include <stdio.h>
#define SIZE 5						//количество элементов массива

float res;

float arithmetic_mean(int num[]);	//прототип функции

int main() {
	int i;
	int num[SIZE] = {0};			//инициализация массива нулями	
	for (i=0; i < SIZE ;i++) {		//запись значений в массив
		scanf("%d", &num[i]);
	}
	arithmetic_mean(num);			//вызов функции
	printf("%.3f\n", res);
	
	return 0;
}

/* ************* определение функции **************** */

float arithmetic_mean(int num[]) {
	int sum = 0;
	for (int i=0; i < SIZE ;i++) {	//запись значений в массив
		sum += num[i];				//расчет суммы значений массива
	}
	
	return res = (float)sum/SIZE;	//возврат среднего из функции
}
