/*
 * Задание_G18_контест
 * В фйайле input.txt дана символьная строка не более 1000 символов.
 * Нужно удалить ненужные пробелы в начале предложения
 *  и сдвоеные пробелы. Составить функцию
 * Результат записать в файл output.txt
 *
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Для isspace()

#define SIZE 1001 //размер строки (1000 символов + '\0')

void clean_string(char *str); // прототип функций


int main() {
    FILE *input, *output;
    char buffer[SIZE]; // Буфер для строки (1000 символов + '\0')

    // Открытие файлов
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("ERROR: Ошибка открытия input.txt\n");
        return 1;
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("ERROR: Ошибка открытия output.txt\n");
        fclose(input); // Закрываем уже открытый файл
        return 1;
    }

    // Чтение строки из файла
    if (fgets(buffer, sizeof(buffer), input) != NULL) {
        // Удаляем символ новой строки, если он есть
        buffer[strcspn(buffer, "\n")] = '\0';

        // Обрабатываем строку функцией
        clean_string(buffer);

        // Записываем результат в output.txt
        fprintf(output, "%s\n", buffer);
    }

    // Закрытие файлов
    fclose(input);
    fclose(output);

    return 0;
}

/* ************** определение функции ************ */

// Функция для удаления лишних пробелов
void clean_string(char *str) {
    int i, j = 0;
    int len = strlen(str);
    int prev_is_space = 1;	// Флаг, что предыдущий символ был пробело
							// (или это начало строки)

    // Пропускаем начальные пробелы
    while (j < len && isspace((unsigned char)str[j])) {
        j++;
    }

    // Копируем оставшуюся часть строки
    while (j < len) {
        if (isspace((unsigned char)str[j])) {
            // Если текущий символ - пробел, и предыдущий 
            //тоже был пробелом, пропускаем
            if (!prev_is_space) {
                str[i++] = ' '; // Добавляем один пробел
                prev_is_space = 1;
            }
        } else {
            // Если символ - не пробел, копируем его
            str[i++] = str[j];
            prev_is_space = 0;
        }
        j++;
    }
    // Удаляем пробел в конце, если он образовался
    if (i > 0 && str[i-1] == ' ') {
        i--;
    }
    str[i] = '\0'; // Завершаем новую строку
}
