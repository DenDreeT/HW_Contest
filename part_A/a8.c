/*
 *  задание_А8_контеста
 */

#include <stdio.h>
int a, b, c, res;

int main(void)
{
	scanf ("%d %d %d",&a,&b,&c);
	res = (a>b) ? a : b;
	res= (res>c) ? res : c;
	printf ("%d",res);
	return 0;
}

