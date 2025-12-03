#include <stdio.h>

/*
* Задание_F5_контест
* Функция вывода максимального элемента из массива
* 
*
*/

int find_max_array(int, int a[]); //прототип функции

int main() {
	enum {size = 10};
	int a[size], max;
	
	find_max_array(size, a);
	printf("%d\n", max);
    return 0;
}
/* ************ определение функций ****************/

int find_max_array(int size, int a[]) {
    int max = a[0];
    int max_index = 0;

    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
            max_index = i;
        }
    }
    return max;
}
