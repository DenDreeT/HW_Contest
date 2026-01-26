/*
Задание А3 контеста "Продвинутый СИ"
Извлечение бит
Есть беззнаковое 32-х разрядное число N
Взять младшие К бит (1<=K<=31) и вывести
полученное число в консоль
*/

#include <stdio.h>
#include <stdint.h>


int main() {
    uint32_t N, K, L = 0, res = 0;

    scanf("%u %d", &N, &K);
    for(int i=0; i<K; i++) L |= (1 << i);
    res = (N & L);
    printf("%u", res);
    return 0;
}
