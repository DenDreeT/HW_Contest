/*
 *  задание_E4_контеста
 * Определить два max из 10-ти чисел в массиве и расчитать их сумму
 * 
 *  */

#include <stdio.h>
#define SIZE 10						//размер массива

int main() {
    int arr[SIZE];
    int max1, max2;
    int i;

    
    for (i = 0; i < SIZE; i++) {	//ввод массива
        scanf("%d", &arr[i]);
    }

    if (arr[0] > arr[1]) {			//принимаем два максимума
        max1 = arr[0];
        max2 = arr[1];
    } else {
        max1 = arr[1];
        max2 = arr[0];
    }

    for (i = 2; i < SIZE; i++) {	//перебираем оставшийся массив
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }

    int sum = max1 + max2;			//выводим сумму двух максимумов

    printf("%d\n", sum);

    return 0;
}
