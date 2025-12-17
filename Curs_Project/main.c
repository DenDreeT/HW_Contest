#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"

#define SIZE 30

typedef struct data {
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	int8_t temperature;
} data_t;

//typedef struct data data_t;


int main(void) {
    data_t info[SIZE];
    
    return 0;
}
