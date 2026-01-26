/*
Задание À9 контеста "Продвинутый Си"
Необходимо реализовать программу, которая упаковывает переданный ей
 массив из 32-ух элементов 0 и 1 в указанную структуру данных.
Функция должна строго соответствовать указанному прототипу 
*/

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

struct pack_array {
        uint32_t array;     // число
        uint32_t count0:8;  // счетчик нулей в массиве
        uint32_t count1:8;  // счетчик единиц в массиве

};

// функции упаковки в структуру 
void array2struct(int arr[], struct pack_array *result) {
    // инициализация счетчиков
    result->count0 = 0;
    result->count1 = 0;
    // инициализация числа
    uint32_t num = 0;

    // перебор по всем 32 значениям
    for (int i = 0; i < 32; i++) {
		
        
        if (arr[i] == 1) {
			num |= (1 << i);	//устанавливаем бит
            result->count1++;	//увеличиваем счетчик единиц
        }
        else {
			//остальные биты остаются нулями
            result->count0++;	//увеличиваем счетчик нулей
        }
    }
    //записываем значение в структуру
	result->array = num;
}



int main() {
    // запись последовательности из консоли в массив
    int arr[32];
    for (int i=31; i>=0; i--) scanf("%d", &arr[i]);
    // переменная структурного типа
    struct pack_array result;
    // вызов функции
    array2struct(arr, &result);
    // вывод результата в консоль
    printf("%u %d %d\n", result.array, result.count0, result.count1);
    return 0;
}


