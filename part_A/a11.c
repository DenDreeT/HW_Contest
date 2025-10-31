/*
 *  задание_А11_контеста
 */

#include <stdio.h>
int a, b, c, d, e, max, min, sum;

int main(void)
{
	scanf ("%d %d %d %d %d",&a,&b,&c,&d,&e);
	
	//поиск минимального значения
	min = (a>b) ? b : a;
	min= (min>c) ? c : min;
	min= (min>d) ? d : min;
	min= (min>e) ? e : min;
	
	//поиск максимального значения
	max = (a>b) ? a : b;
	max= (max>c) ? max : c;
	max= (max>d) ? max : d;
	max= (max>e) ? max : e;
	
	//вывод на дисплей суммы максимума и минимума
	printf ("%d",sum=max+min);
	return 0;
}

