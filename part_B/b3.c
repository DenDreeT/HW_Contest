/*
 *  задание_B3_контеста
 */

#include <stdio.h>
#include <math.h>

		
int main() {
	
    int a, b, sum_square = 0;
    
    double square;

	scanf("%d %d", &a, &b);
	
	while (a<=b) {
	
		// Возведение в квадрат
		square = pow(a, 2);
		
		sum_square = sum_square + square;
		
		a = ++a;
		
	}
	
	printf("%d\n", sum_square);
	
    return 0;
}

