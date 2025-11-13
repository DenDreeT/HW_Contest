/*
 *  задание_B2_контеста
 */

#include <stdio.h>
#include <math.h>

		
int main() {
	
    int a, b;
    
    double square;

	scanf("%d %d", &a, &b);
	
	while (a<=b) {
	
		// Возведение в квадрат
		square = pow(a, 2);

		printf("%.0f ", square);
		
		a = ++a;
	}
	
    return 0;
}

