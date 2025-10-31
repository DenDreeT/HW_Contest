/*
 *  задание_А10_контеста
 */

#include <stdio.h>
int a, b, c, d, e, res;

int main(void)
{
	scanf ("%d %d %d %d %d",&a,&b,&c,&d,&e);
	res = (a>b) ? b : a;
	res= (res>c) ? c : res;
	res= (res>d) ? d : res;
	res= (res>e) ? e : res;
	printf ("%d",res);
	return 0;
}

