/*
 * Задание_G5_контест
 * В фйайле input.txt дана символьная строка не более 1000 символов.
 * Нужно заменить все буквы а на буквы b и наоборот, как заглавные,
 * так и строчные.
 * Результат записать в файл output.txt
 *
*/

#include <stdio.h>
#include <string.h>

#define SIZE 1001 //длина слова +1 на '\n' или '\0'


int main() {

    // Открываем файлы
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    if (!input || !output) {
        printf("ERROR: Ошибка открытия файлов\n");
        return 1;
    }

    //Массив для чтения строки
    char buffer[SIZE];

    //Читаем строку из входного файла
    fgets(buffer, sizeof(buffer), input);

    //Проходим по каждому символу и меняем
    for(int i = 0; i < strlen(buffer); i++) {
        switch(buffer[i]) {
            case 'a': buffer[i] = 'b'; break;
            case 'A': buffer[i] = 'B'; break;
            case 'b': buffer[i] = 'a'; break;
            case 'B': buffer[i] = 'A'; break;
        }
    }

    //Записываем результат в выходной файл
    fputs(buffer, output);

    //Закрываем файлы
    fclose(input);
    fclose(output);

    return 0;
}
