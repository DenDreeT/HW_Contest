/*
 *  задание_B1_контеста
  */

#include <stdio.h>
#include <math.h>

		
int main() {
	
    int number, i = 1;
    
    double square, cube;

	scanf("%d", &number);
	
	while (i<=number) {
	
		// Возведение в квадрат
		square = pow(i, 2);

		// Возведение в куб
		cube = pow(i, 3);

		printf("%d %.0f %.0f\n", i, square, cube);
		
		i = ++i;
	}
	
    return 0;
}

