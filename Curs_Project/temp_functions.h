#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdint.h>

// структура данных
typedef struct {
    uint16_t year; 
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} sensor_data;

// Прототипы функции обработки
void print_help();

int read_csv(const char* filename, sensor_data* data, int max_rows);

void calculate_month_stats(sensor_data* data, int count, int month);

void calculate_year_stats(sensor_data* data, int count);

#endif
