#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "temp_functions.h"

#define MAX_RECORDS 527040 // Максимум минут в году

int main(int argc, char *argv[]) {
	
	printf("Программа вывода статистики температуры\n");
	printf("Используйте ключ -h для просмотра справочной информации\n\n");
	
    char *filename = NULL;	// название файла
    int month = -1;			// месяц от 1 до 12
    int opt;
	// обработка аргументов командной строки
    while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
        switch (opt) {
            case 'h': print_help(); return 0;
            case 'f': filename = optarg; break;
            case 'm': month = atoi(optarg); break;
            
        }
    }

    if (!filename) {
		printf("Error: Выберите файл. Используйте ключ -f\n");
        return 1;
    }
	
	// резервирование блока памяти под данные из файла
    sensor_data *data = malloc(MAX_RECORDS * sizeof(sensor_data));
    
    // перенос данных из файла в структуру
    int count = read_csv(filename, data, MAX_RECORDS);

	// вывод статистики
    if (count > 0) {
        if (month != -1) {
            calculate_month_stats(data, count, month);
        } else {
            for (int i = 1; i <= 12; i++) calculate_month_stats(data, count, i);
            calculate_year_stats(data, count);
        }
    }
	// освобождение блока памяти
    free(data);
    return 0;
}
