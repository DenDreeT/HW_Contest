/*
 *  задание_B18_контеста
  */

#include <stdio.h>

int main( void )
{
    unsigned int number, i, x1, x2, m;
    scanf("%d", &number);
    x1 = 1;
    x2 = 1;
    if (number == 1)
        printf("1");
    else
        if (number != 0) {
        
            printf("1 1 ");
            for (i = 2; i < number; ++i) {
                m = x1 + x2;
                x1 = x2;	//смена значений на сумму предыдущих
                x2 = m;
                printf("%u ", x2);
            }
        }
    //puts("\n");	//перевод строки
    
    return 0;
}

