/*
 *  задание_А7_контеста
 */

#include <stdio.h>
signed int a, b;

int main(void)
{
	scanf ("%d %d",&a,&b);
	(a>b) ? printf ("%d %d",b ,a) : printf ("%d %d",a ,b);
	
	return 0;
}

