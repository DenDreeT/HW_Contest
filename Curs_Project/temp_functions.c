#include <stdio.h>
#include <string.h>
#include "temp_functions.h"


// функция с предложением пользователю ввести аргументы
void print_help() {
    printf("Варианты использования ключей:\n");
    printf("-h                : Справочная информация\n");
    printf("-f <filename.csv> : имя CSV файла с данными\n");
    printf("-m <month_num>    : Вывод статистики за месяц (1-12)\n");
}

// функция считывания и записи данных из файла в структуру
int read_csv(const char* filename, sensor_data* data, int max_rows) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: ошибка считывания файла\n");
        return -1;
    }

    char line[100];
    int count = 0;
    int line_num = 0;

    while (fgets(line, sizeof(line), file) && count < max_rows) {
        line_num++;
        int y, m, d, h, mi, t;
        if (sscanf(line, "%d;%d;%d;%d;%d;%d", &y, &m, &d, &h, &mi, &t) == 6) {
            data[count++] = (sensor_data){y, m, d, h, mi, t};
        } else {
            fprintf(stderr, "Ошибка в строке: %d\n", line_num);
        }
    }
    fclose(file);
    return count;
}

// функция вывода статистики за месяц
void calculate_month_stats(sensor_data* data, int count, int month) {
    int min = 100, max = -100, sum = 0, n = 0, year;
    for (int i = 0; i < count; i++) {
        if (data[i].month == month) {
            if (data[i].temperature < min) min = data[i].temperature;
            if (data[i].temperature > max) max = data[i].temperature;
            year = data[i].year;
            sum += data[i].temperature;
            n++;
        }
    }
    if (n > 0)
        printf("Год %4d Месяц %2d: Средняя=%3d, Минимальная=%3d, Максимальная=%3d\n", year, month, sum/n, min, max);
}

// функция вывода статистики за год
void calculate_year_stats(sensor_data* data, int count) {
    if (count == 0) return;
    int min = 100, max = -100;
    long sum = 0;
    for (int i = 0; i < count; i++) {
        if (data[i].temperature < min) min = data[i].temperature;
        if (data[i].temperature > max) max = data[i].temperature;
        sum += data[i].temperature;
    }
    printf("За год: Средняя=%ld, Мин=%d, Макс=%d\n", sum/count, min, max);
}

