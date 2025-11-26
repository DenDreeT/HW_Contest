/*
 *  задание_E2_контеста
 * Определить min 5-ти чисел в массиве
 * 
 *  */

#include <stdio.h>
#define SIZE 5						//размер массива

int min;

int min_digit(int arr[]);			//прототип функции

int main() {
	int i;
	int arr[SIZE] = {0};			//инициализация массива нулями	
	for (i=0; i < SIZE ;i++) {		//запись значений в массив
		scanf("%d", &arr[i]);
	}
	min_digit(arr);					//вызов функции
	printf("%d\n", min);
	
	return 0;
}

/* ************* определение функции **************** */

int min_digit(int arr[]) {
	int i;
	min = arr[0];					//принимаем за min 0-е значение
	for (i = 1; i < SIZE; i++)
		if (min > arr[i]) min = arr[i];
	return min;
}
