/*
 *  задание_E8_контеста
 * Вывести инверсию каждой трети массива из 12-ти чисел
 * 
 *  */

#include <stdio.h>

void aPrint(int *arr, int);				//прототипы функций
void reverseArray(int *array, int);


int main() {
	enum {SIZE = 12};					//количество элементов массива
	int array[SIZE] = {0};				//инициализация массива '0'
	for(int i=0; i < SIZE; i++) scanf("%d", &array[i]);	//запись
	for(int i=0; i<3; i++) reverseArray(array +i*SIZE/3, SIZE/3);
	aPrint(array, SIZE);
	return 0;
}

void aPrint(int *arr, int len) {
	for (int i = 0; i < len; i++) printf("%d ",arr[i]);
}

void reverseArray(int *array, int num) {
	for (int i = 0, j = num - 1; i < j; i++, j--) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

