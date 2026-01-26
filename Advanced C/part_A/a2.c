/*
Задание А2 контеста "Продвинутый СИ"
Циклический сдвиг
Есть беззнаковое 32-х разрядное число N
Сдвинуть вправо на К битов (1<=K<=31)
*/

#include <stdio.h>
#include <stdint.h>


int main() {
    uint32_t N, res;
    int K;
    scanf("%u %d", &N, &K);
    res = ((N >> K) | (N << (32 - K)));
    printf("%u", res);
    return 0;
}
