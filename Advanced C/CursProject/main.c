#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include "main.h"
#include "root.h"
#include "integral.h"
#include "func.h"



int main(int argc, char* argv[]) {
    
    int rez = 0;
    int printRoots = 0, printIterations = 0, printArea = 0, printTest = 0;
    float eps1 = 0.0001; // Точность для нахождения корней
    float eps2 = 1000;  // Точность для вычисления интеграла

    // Если аргументы не переданы, выводим справку
    if(argc <= 1) {
        printf(OPTIONS_USAGE);
        printf(OPTIONS_HELP);
    }   
    
    // Обработка аргументов командной строки            
    while((rez = getopt(argc, argv,"hHriate:E:")) != -1) {
        switch(rez) {
            case 'H':
            case 'h':
            // Вывод справки
                printf(OPTIONS_DESCRIPTION
                    OPTIONS_r
                    OPTIONS_i
                    OPTIONS_a
                    OPTIONS_e
                    OPTIONS_E
                    OPTIONS_t
                    OPTIONS_USAGE);
                break;
            case 't':
                printTest = 1; // Включить тестирование
                break;
            case 'a':
                printArea = 1; // Вычислить площадь
                break;
            case 'r':
                printRoots = 1; // Найти корни
                break;
            case 'i':
                printIterations = 1; // Вывести количество итераций
                break;
            case 'e':
                eps1 = atof(optarg); // Установить точность для корней
                break;
            case 'E':
                eps2 = atof(optarg); // Установить точность для интеграла
                break;
            case '?':
                printf(OPTIONS_ERROR); // Ошибка аргумента
                return 1;
                break;
        }
    }
    
	// вычисление корней
    if(printRoots) {
        printf("Root for f1 - f2 = 0: %f\n\n", root(0., eps1, f1, f2, df1, df2, printIterations)); 
        printf("Root for f2 - f3 = 0: %f\n\n", root(2., eps1, f2, f3, df2, df3, printIterations));
        printf("Root for f1 - f3 = 0: %f\n", root(0.5, eps1, f3, f1, df3, df1, printIterations));
    }
    
    // Вычисление площади между функциями
    if(printArea) {
        float r1 =  root(0.5, eps1, f3, f1, df3, df1, 0);
        float r2 =  root(2., eps1, f2, f3, df2, df3, 0);
        float r3 =  root(0., eps1, f1, f2, df1, df2, 0);
		// вычисление площади
        printf("\n Площадь фигуры между графиками функций f1, f2, f3 = %f\n",  calcIntegralSimpson(r1, r3, eps2, f1) - 
        (calcIntegralSimpson(r1, r2, eps2, f3) + calcIntegralSimpson(r2, r3, eps2, f2))); 
    }

    // Тестирование функций
    if(printTest) {
        printf("\n=== Тест вычисления корней функции f(x) = 8x^4 + 32x^3 + 40x^2 + 16x + 1 - [-1.5, -1.2] [-0.8, -0.4] : ===\n");
        printf("==================== Референтные значения: -1.382 and -0.617 ===============================\n");
        float root1 = root(-1.5, 0.0001, test_f1, test_f2, test_df1, test_df2, 0);
        printf("%f\n", root1);
        printf("%s\n", (int)(root1 * 100) / 100. == -1.38  ? "Тест пройден" : "Тест провален");

        float root2 = root(-0.8, 0.0001, test_f1, test_f2, test_df1, test_df2, 0);
        printf("%f\n", root2);
        printf("%s\n", (int)(root2 * 100) / 100. == -0.61  ? "Тест пройден" : "Тест провален");
        
        printf("\n================== Тест вычисления площади: вычисление площади квадрата 2x2 =================\n");
        float integral = calcIntegralSimpson(0, 2, eps2, test_integral);
        printf("%f\n", integral);
        printf("%s\n", (int)(integral * 100) / 100. == 3.99  ? "Тест пройден" : "Тест провален");

    }
    return 0;
}
