/*
 *  задание_B19_контеста
  */

#include <stdio.h>

int main() {
	int num = 0, sum = 0;
    scanf("%d", &num);
    while (num != 0) {
	    sum += num % 10;
		num /= 10;
	}
	(sum == 10) ? puts("YES") : puts("NO");
    
    return 0;
}

