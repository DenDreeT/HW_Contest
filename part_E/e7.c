#include <stdio.h>
#define SIZE 10
#define HALF_SIZE 5
/*
* Задание_Е7_контеста
* Инверсия двух половин массива из 10-ти элементов
*
*/


void half_inversion(int arr[]);    //прототип функции

int main() {
    int arr[SIZE], i;
                                    //запись чисел в массив
    for (i = 0; i < SIZE; i++ ) {
        scanf("%d", &arr[i]);
    }
    half_inversion(arr);          //вызов функции

    return 0;
}

void half_inversion(int arr[SIZE]){    //определение функции
    int temp = 0, j = 4;
    for (int i = 0; i < HALF_SIZE; i++ ) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
    for (int i = HALF_SIZE; i < SIZE; i++ ) {
        j = 9;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }

    for (int i = 0; i < SIZE; i++ ) {
        printf("%d ", arr[i]);
    }
    return 0;
}
