#include <stdio.h>
#define SIZE 12
/*
* Задание_Е6_контеста
* Вычислить среднее арифметическое 12-ти элементов массива
*
*/
float mean;

float arithmetic_mean(int arr[]);    //прототип функции

int main() {
    int arr[SIZE];
                                //запись чисел в массив
    for (int i = 0; i < SIZE; i++ ) {
        scanf("%d", &arr[i]);
    }

    arithmetic_mean(arr);          //вызов функции
    printf("%.2f\n", mean);
    //printf("%d", sum);
    return 0;
}

float arithmetic_mean(int arr[SIZE]){    //определение функции
    int sum = 0;
    for (int i = 0; i < SIZE; i++ ) {
        sum += arr[i];
    }
    mean = (float)sum/SIZE;
    return mean;
}
