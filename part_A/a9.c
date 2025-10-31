/*
 *  задание_А9_контеста
 */

#include <stdio.h>
int a, b, c, d, e, res;

int main(void)
{
	scanf ("%d %d %d %d %d",&a,&b,&c,&d,&e);
	res = (a>b) ? a : b;
	res= (res>c) ? res : c;
	res= (res>d) ? res : d;
	res= (res>e) ? res : e;
	printf ("%d",res);
	return 0;
}

