#ifndef INTEGRAL_H
#define INTEGRAL_H
#include <stddef.h>

// тип для подстановки функции в функцию
typedef float(*function)(float);
// Вычисление интеграла по методу Симпсона
float calcIntegralSimpson(float, float, size_t, function); 


#endif
