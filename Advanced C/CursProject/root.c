#include <stdio.h>
#include <math.h>
#include "integral.h"
#include "func.h"
#include "root.h"

// Метод касательных (Ньютона) для нахождения корня уравнения f1(x) = f2(x)
float root(float xn, float eps, function f1, function f2, function df1, function df2, int printIterations) {
    float x1  = xn - (f1(xn) + f2(xn)) / (df1(xn) - df2(xn));
    float x0  = xn;
    int stepcount = 0;
    // Итерационный процесс до достижения точности
    while(fabs(x0 - x1) > eps) {
        if (stepcount > 1000) { // Защита от бесконечного цикла
         
            printf("Нет корней после 1000 итераций.\n");
            return NAN; // Возвращаем "не число" в случае ошибки
        }

        x0 = x1;
        float denominator = df1(x1) - df2(x1);
        if (fabs(denominator) < 1e-10) { // Защита от деления на ноль
         
            printf("Деление на 0.\n");
            return NAN;
        }
        x1 = x1 - (f1(x1) - f2(x1)) / (df1(x1) - df2(x1));
        stepcount++;
    }
    if(printIterations)
        printf("Вычисление корней за %d итераций\n",stepcount);
    return x1;
}
