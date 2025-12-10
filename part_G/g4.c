/*
 * Задание_G4_контест
 * В фйайле input.txt даны два слова не более 100 символов каждое,
 * разделенные одним пробелом. Найти только те символы слов,
 *которые встречаются в обеих словах только один раз.
 *Напечатать их через пробел в файл output.txt в лексикографическом порядке.
 *
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 101 //длина слова +1 на '\n' или '\0'
#define SIZE_ASCII 256 //номер символов по таблице ASCII

int main() {
    // Открываем файлы
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output) {
        printf("ERROR: Ошибка открытия файлов\n");
        return 1;
    }

    //Массивы для слов/ записываем слова
    char word1[SIZE], word2[SIZE];
    fscanf(input, "%s %s", word1, word2);

    // Массивы для подсчета вхождений символов
    int count1[SIZE_ASCII] = {0};
    int count2[SIZE_ASCII] = {0};

    // Подсчитываем вхождения символов в первом слове
    for (int i = 0; word1[i]; i++) {
        count1[(unsigned char)word1[i]]++;
    }

    // Подсчитываем вхождения символов во втором слове
    for (int i = 0; word2[i]; i++) {
        count2[(unsigned char)word2[i]]++;
    }

    // Массив для хранения уникальных символов
    char result[SIZE_ASCII];
    int result_size = 0;

    // Находим символы, встречающиеся по одному разу в обоих словах
    for (int i = 0; i < SIZE_ASCII; i++) {
        if (count1[i] == 1 && count2[i] == 1) {
            result[result_size++] = (char)i;
        }
    }
/*
    // Сортируем результат
    qsort(result, result_size, sizeof(char),
          (const void *a, const void *b) {
              return *(char*)a - *(char*)b;
          });
*/
    // Записываем результат в файл
    for (int i = 0; i < result_size; i++) {
        fprintf(output, "%c ", result[i]);
    }

    // Закрываем файлы
    fclose(input);
    fclose(output);

    return 0;
}
