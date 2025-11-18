/*
 *  задание_C2_контеста
 * функция возведения числа 'n' в степень 'p' 
  */

#include <stdio.h>

int res = 1;							//глоб-я переменная для функции
int power(signed int, unsigned int);	//прототип функции
		
int main() {
	
	signed int n;
	unsigned int p;
				;
	scanf("%d %d", &n, &p);
	power(n, p);
	printf("%d\n", res);
	return 0;
}

int power(signed int n, unsigned int p) {	//описание функции
	if (p == 0) return 1; //число в степени 0 равно 1
	else {
		//цикл возведения числа 'n' в степень 'p'
		for (int i = 1; i <= p ;i++) res *= n;
		return res;	//возврат результата из функции
	}	
}	
