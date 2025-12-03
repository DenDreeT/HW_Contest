#include <stdio.h>

/*
* Задание_F6_контест
* Функция поиска двух одинаковых элементов в массиве
* 
*
*/

int is_two_same(int, int a[]); //прототип функции

int main() {
	enum {size = 10};
	int a[size];
	
	is_two_same(size, a);
	
    return 0;
}
/* ************ определение функций ****************/

int is_two_same(int size, int a[]) {
	for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] == a[j]) {
                // Найдены два одинаковых элемента
                //printf("%d, индексы %d и %d\n", arr[i], i, j);
                return 1; // возвращаем 1,найдена хотя бы одна пара
            }
        }
    }
    // Одинаковые элементы не найдены
    return 0;
}
