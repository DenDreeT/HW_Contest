#include <stdio.h>
#define SIZE 10
/*
* Задание_Е5_контеста
* Вычислить сумму положительных элементов массива
*
*/
int sum;

int sum_positive(int arr[]);    //прототип функции

int main() {
    int arr[SIZE];
                                //запись чисел в массив
    for (int i = 0; i < SIZE; i++ ) {
        scanf("%d", &arr[i]);
    }

    sum_positive(arr);          //вызов функции
    printf("%d\n", sum);

    return 0;
}

int sum_positive(int arr[SIZE]){    //определение функции
    for (int i = 0; i < SIZE; i++ ) {
        if (arr[i] > 0) sum += arr[i];
    }
    return sum;
}
