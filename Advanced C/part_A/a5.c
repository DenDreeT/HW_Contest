/*
Задание А5 контеста "Продвинутый СИ"
Подсчет битов
Есть беззнаковое 32-х разрядное число N
Найти количество "1" в двоичном представдлении
числа
*/

#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t N;
    int count = 0, masc, res;
    scanf("%u", &N);
    for(int i=0; i<32; i++) {
        masc = (1 << i);
        res = ((N & masc) >> i);
        if (res == 1) count++;
    }

    printf("%d", count);
    return 0;
}
