/*
 *  задание_G2_контеста
 * Считать число N из файла input.txt. 
 * Сформировать строку из N символов. N четное число, 
 * не превосходящее 26. 
 * На четных позициях должны находится четные цифры в порядке
 * возрастания, кроме 0, на нечетных позициях - 
 * заглавные буквы в порядке следования в английском алфавите.
 * 
 * Результат записать в файл output.txt
 * 
 */

#include <stdio.h>
#include <string.h>

int main(){
	int i, n;
	//указатели на файлы (IN, OUT)
	FILE *PtrFile_IN, *PtrFile_OUT;
	
	//запись название файлов в массив
	char file_in[] = "input.txt";
	char file_out[] = "output.txt";
	
	//открытие файлов для чтения 'r' и cоздания/записи 'w'
	PtrFile_IN = fopen(file_in, "r");
	PtrFile_OUT = fopen(file_out, "w");
	
	//считываем число из файла в переменную n
	fscanf(PtrFile_IN, "%d", &n);
	
	char str[n + 2];
	char c = 'A';
	char c_num = '2';
	for (i = 0; i < n; ++i) {
		if (i%2==0) str[i] = c++;
		else {
			str[i] = c_num;
			if (c_num == '8') c_num = '2';
			else c_num += 2;
		}
	}
	str[i] = '\0';
	
	//вывод строки символов
	fprintf(PtrFile_OUT, "%s", str);
	
	//закрываем файлы
	fclose(PtrFile_IN);
	fclose(PtrFile_OUT);
	
	return 0;
}
