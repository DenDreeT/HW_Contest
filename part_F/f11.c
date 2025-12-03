#include <stdio.h>

/*
* Задание_F11_контест
* Функция поиска двух элементов массива, сумма которых минимальна
* 
*
*/

void sum_min(int, signed int a[]); //прототип функции

int main() {
	enum {size = 30};
	signed int a[size];
	for(int i=0; i < size; i++) scanf("%d", &a[i]);	//запись в массив
	sum_min(size, a);
	
    return 0;
}
/* ************ определение функций ****************/

void sum_min(int size, signed int a[]) {
	int firstMin = 30, firstMin_Index;
    int secondMin = 30, secondMin_Index;
	// Проходим по массиву, чтобы найти два минимальных элемента
    for (int i = 0; i < size; i++) {
        if (a[i] < firstMin) {
            secondMin = firstMin; // Предыдущий первый минимум становится вторым
            firstMin = a[i];    // Текущий элемент — новый первый минимум
            firstMin_Index = i;
        } else if (a[i] < secondMin) {
            secondMin = a[i]; // Элемент меньше второго, но не равен первому
            secondMin_Index = i;
        } //else if (firstMin == secondMin) firstMin_Index = secondMin_Index;
        
    }
    printf("%d %d\n", firstMin_Index, secondMin_Index);
}
