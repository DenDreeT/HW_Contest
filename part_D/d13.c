/*
 *  задание_D13_контеста
 * Рекурсивная Функция вывода всех простых множителей числа
 * 
 *  */

#include <stdio.h>

void rec(int a,int b) {
	if(a==1)return;
	for(;;) {
		if(a%b==0) {
			printf("%d ",b);
			rec(a/b,b);
			return;
		}
		b++;
	}
}

// разложение заданного натурального числа n на простые множители
void Prime_factors( int n, int divisor) {
	if( divisor > n ) return;
	if( n % divisor == 0 ) {
		printf( "%d ", divisor );
		n /= divisor;
	}
	else divisor++;
	Prime_factors( n, divisor );
}

int main() {
	int a;
	scanf("%d",&a);
	rec(a,2);
	return 0;
}

/* ************* определение функции **************** */


