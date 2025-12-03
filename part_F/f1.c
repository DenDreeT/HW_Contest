/*
 *  задание_F1_контеста
 * Сортировка массива по возрастанию
 * 
 *  */

#include <stdio.h>


void sort_array(int size, int a[]);		//прототипы функций

int main() {
	enum {size = 20};					
	int a[size] = {0};				//инициализация массива '0'
	for(int i=0; i < size; i++) scanf("%d", &a[i]);	//запись
	
	sort_array(size, a);
		//отсортированный массив
	for (int i = 0; i < size; i++) printf("%d ",a[i]);
	return 0;
}

/* *************** определение функции ******************** */

void sort_array(int size, int a[]) {
	 for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                // Поменять элементы местами
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}	




