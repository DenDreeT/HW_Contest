/*
 *  задание_А16_контеста
 *
  */

#include <stdio.h>

int a, b, c;

int main(void)
{
	scanf ("%d %d %d",&a,&b,&c);
	
	//условие порядка возрастания чисел
	if ((a<b)&&(b<c)) {
		printf ("YES\n");
	}	
	else {
		printf ("NO\n");
	}
		
	return 0;
}

