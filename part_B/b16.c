/*
 *  задание_B16_контеста
  */

#include <stdio.h>

int main() {
	
    int a = 0, b = 0, t = 0;
    
    scanf("%d %d", &a, &b);

    while (b != 0) {
	        
		t = b;
		b = a % b;
		a = t; 	        
    }	
    printf ("%d\n", a);
    
    return 0;
}

