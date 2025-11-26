/*
 *  задание_E3_контеста
 * Определить min и max из 10-ти чисел в массиве и их номера
 * Вывод в формате через пробел: 
 * 		номер max, значение, номер min, значение
 *  */

#include <stdio.h>
#define SIZE 10						//размер массива

int main() {
	int min, max, minIndex, maxIndex;
	int arr[SIZE] = {5};			//инициализация массива	
    // Инициализация min, max и их индексов первым элементом массива
    min = arr[0];
    max = arr[0];
    minIndex = 0;
    maxIndex = 0;
	
	
	for (int i = 0; i < SIZE ;i++) {		//запись значений в массив
		scanf("%d", &arr[i]);
	}
	
	// Проходим по массиву  и ищем max и min
    for (int i = 0; i < SIZE; i++) {
		
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i+1;
        }
        
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i+1;
        }
    }	
	
	printf("%d %d %d %d\n", maxIndex, max, minIndex, min);
	
	return 0;
}
