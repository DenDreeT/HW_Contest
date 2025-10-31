/*
Задание_A12_контеста
 */

#include <stdio.h>

int var,a,b,c,res; 

int main (void) {
	scanf("%d", &var);
	a=var/100;
	b=(var%100)/10;
	c=var%10;
	
    printf("%d\n", res=(a+b+c));

return 0;
}
