/*
 *  задание_А14_контеста
 */

#include <stdio.h>
int a, ed, dec, sot, max;

int main(void)
{
	scanf ("%d",&a);
	
	//разложение по разрядам
	ed = a%10; //единицы
	dec = (a%100)/10; //десятки
	sot = a/100; //сотни
	
	//поиск максимальной цифры
	max = (ed>dec) ? ed : dec;
	max = (max>sot) ? max : sot;
	
	//вывод результата на дисплей
	printf ("%d", max);
	
	return 0;
}

