#ifndef ROOT_H
#define ROOT_H


typedef float(*function)(float);

// Прототип функции для метода касательных (Ньютона)
float root(float, float, function, function, function, function, int);


#endif
