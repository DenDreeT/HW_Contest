#include <stdio.h>
#include <string.h>

#define SIZE 1000

/*
* Задание_G3_контест
* В фйайле input.txt дана строка из не более 1000 символов.
* Показать номера символов, совпадающих с последним символом строки
* Результат записать в файл output.txt
*
*/

int main() {
    int i;
    char str[SIZE]; //длина строки +1 для нулеваго символа
    char file_in[] = {"input.txt"};
    char file_out[] = {"output.txt"};

    FILE *PtrFile_IN, *PtrFile_OUT;

    //проверка открытия файлов
    if ((PtrFile_IN = fopen(file_in, "r")) == NULL) {
        puts("ERROR: файл input.txt не открыт");
        return 1;
    }
    else if ((PtrFile_OUT = fopen(file_out, "w")) == NULL) {
        puts("ERROR: файл output.txt не открыт");
        return 1;
    }
   // else {
        //запись строки из файла в массив
        fgets(str, SIZE, PtrFile_IN);

        // Удаляем символ новой строки, если он есть
        size_t len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0';
            len--;
        }
        // Получаем последний символ
        char last_char = str[len-1];

        // Ищем совпадения и записываем в файл
        for (size_t i = 0; (i < (len-1)); i++) {
            if (str[i] == last_char) {
                fprintf(PtrFile_OUT, "%zu ", i);
            }
        }

    // Закрываем файлы
    fclose(PtrFile_IN);
    fclose(PtrFile_OUT);
   // }

    return 0;
}
