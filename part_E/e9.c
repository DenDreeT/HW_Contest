/*
 *  задание_E9_контеста
 * Циклический сдвиг массива из 10-ти элементов вправо на один элемент
 * 
 *  */

#include <stdio.h>

void shift_array_right(int, int a[]);	//прототип функции

int main() {
	int SIZE = 10;				//размер массива
	int arr[SIZE];						//инициализация массива
	
	for (int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);
		
	shift_array_right(SIZE, arr);
		
	return 0;
}

/* ************* определение функции ************* */
//  циклический сдвиг массива вправо на 1 элемент

void shift_array_right(int size, int a[]) {
	int temp = a[size-1];
	for (int i = size-2; i >= 0; i-- ) {
		a[i+1] = a[i];
	}
	a[0] = temp;
	
	for (int j = 0; j < size; j++) printf("%d ", a[j]);
	
	return ;
}
