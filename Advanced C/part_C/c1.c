/*
 * Задача C1 контеста "Продвинутый Си"
 * Префикс и суфикс 
 * На стандартном потоке ввода задаются две символьные строки, разделённые символом перевода строки.
 *  Каждая из строк не превышает по длине 104. В строках не встречаются пробельные символы.
 * На стандартный поток вывода напечатайте два числа, разделённых пробелом:
 *  первое число — длина наибольшего префикса первой строки, являющегося суффиксом второй;
 *  второе число — наоборот, длина наибольшего суффикса первой строки, являющегося префиксом второй.
 *  Сравнение символов проводите с учётом регистра (т.е. символы 'a' и 'A' различны).
 * 
 * Пример №1
 * Данные на входе:
 * don't_panic 
 * nick_is_a_mastodon
 * Данные на выходе:	3 3
 * 
 * Пример №2
 * Данные на входе:
 * monty_python
 * python_has_list_comprehensions
 * Данные на выходе:	0 6
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prefix_suffix(char* str1, char* str2) {
    int str_len1 = strlen(str1);
    int str_len2 = strlen(str2);
    int max_len = 0;

    for (int i = 1; i <= str_len1 && i <= str_len2; i++) {
        if (strncmp(str1, str2 + str_len2 - i, i) == 0) {
            max_len = i;
        }
    }

    return max_len;
}

int suffix_prefix(char* str1, char* str2) {
    int str_len1 = strlen(str1);
    int str_len2 = strlen(str2);
    int max_len = 0;

    for (int i = 1; i <= str_len1 && i <= str_len2; i++) {
        if (strncmp(str1 + str_len1 - i, str2, i) == 0) {
            max_len = i;
        }
    }

    return max_len;
}

int main(void)
{
    char str1[10001], str2[10001];
    scanf("%s", str1);
    scanf("%s", str2);
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    printf("%d %d\n", prefix_suffix(str1, str2), suffix_prefix(str1, str2));
    return 0;
}
