/*
задание_С5_контеста
функция подсчета суммы всех предшествующих 
чисел до введенноно 'N'
*/

#include <stdio.h>

int sum = 0;		//глобальная переменная для функции

int summa(int);    //прототип функции

int main (void) {
	int N;
	scanf("%d", &N);
	summa(N);   //вызов функции
	printf("%d\n", sum);
   
    return 0;
}

//определение функции посчета суммы чисел до N включительно 
int summa(int N) {
	for (int i=0; i <= N ; i++) {
	sum += i;
    }
	return sum;
}

