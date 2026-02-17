/* 
 * Задание С0 контеста "Продвинутый Си
 * Вычеркивание
 * Сколько различных трехзначных чисел можно получить из заданного
 *  натурального N, вычеркивая цифры из его десятичной записи?
 * Формат данных на входе: Единственное натуральное число N.
 * Формат данных на выходе: Единственное целое число – найденное количество.
 *
 *Пример  
 *Ввод
 *1111111111111111111111112
 *Вывод
 *1
 *
 */

#include <stdio.h>
#include <string.h>

int main(void) 
{
    char number[10000];
    scanf("%s", number); 
    int num_length = strlen(number);
    int unique_count = 0;
    int found_numbers[1000] = {0,};

    
    for(int first = 0; first < num_length; first++) 
    {
        for(int second = first + 1; second < num_length; second++) 
        {
            for(int third = second + 1; third < num_length; third++) 
            {
                int three_digit_number = (number[first] - '0') * 100 + (number[second] - '0') * 10 + (number[third] - '0');
                if (number[first] != '0')
                {
                    int is_unique = 1;
                    for (int idx = 0; idx < unique_count; idx++)
                    {
                        if(found_numbers[idx] == three_digit_number)
                        {
                            is_unique = 0;
                            break;
                        }
                    }
                    if(is_unique) {
                        found_numbers[unique_count++] = three_digit_number;
                    }
                }
            }
        }
    }


    printf("%d\n", unique_count);
    return 0;
}
