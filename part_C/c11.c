/*
 *  задание_C11_контеста
 * Функция определения НОД для двух чисел
  */

#include <stdio.h>

int a =0, b = 0, t = 0;
int *pa = &a; //указатель на переменную 'a'

int nod(int, int);	//прототип функции

int main() {
	    
    scanf("%d %d", &a, &b);
    nod(a, b);
	printf ("%d\n", a);
	
   return 0;
}

int nod(int a, int b) {
	
	while (b != 0) {
	        
		t = b;
		b = *pa % b;
		*pa = t; 	        
    }	
    return *pa;	//возврат значения переменной 'a'
}
