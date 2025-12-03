#include <stdio.h>

/*
* Задание_F2_контест
* Функция сортировки четных элементов массва от нечетных
*
*/

void sort_even_odd(int, int a[]);    //прототип функции

int main() {
	enum {n = 20};
						
	int a[n] = {0};				//инициализация массива '0'
	//int n = sizeof(a) / sizeof(a[0]);
	for(int i=0; i < n; i++) scanf("%d", &a[i]);	//запись

	sort_even_odd(n, a);          //вызов функции
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}

void sort_even_odd(int n, int a[]){    //определение функции
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Если первый элемент нечетный, а второй четный, меняем их местами
            if (a[j] % 2 != 0 && a[j + 1] % 2 == 0) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
