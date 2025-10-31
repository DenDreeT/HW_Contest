/*
 *  задание_А18_контеста
 *
  */

#include <stdio.h>

int a, b;

int main(void)
{
	scanf ("%d %d",&a ,&b);
	
	//условие выбора
	if (a>b) {
		printf ("Above\n");
	}
		
	else if (a<b) {
		printf ("Less\n");
	}
	
	else if (a==b) {
		printf ("Equal\n");
	}
	
	else {
		printf ("ERROR\n");
	}
		
	return 0;
}

