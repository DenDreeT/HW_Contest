/*
 *  задание_G1_контеста
 * Открыть файл и скопировать содержимое в другой файл 
 * три раза
 * 
 *  */

#include <stdio.h>

char line[256];	//строка в 255 символов
char c;			//переменная для символа


int main() {

	int count = 0;		//счетчик символов
	FILE *PtrFile_IN;	//указатель на файл считывания
	FILE *PtrFile_OUT;	//указатель на файл записи	
	
    //проверка на открытие файла
    if ((PtrFile_IN = fopen("input.txt","r")) == NULL) {
        puts("ERROR: файл input.txt не открыт");
        return 1;
    }
    //файл открыт, считываем символы
    else {
		while(((c = getc(PtrFile_IN)) != EOF) && (c != '\n')) 
			line[count++] = c;
		line[count] = '\0';
		fclose(PtrFile_IN);    
	}
	//проверка на открытие/создание файла
	if((PtrFile_OUT = fopen("output.txt", "w")) == NULL) {
		puts("ERROR: файл output.txt не открыт");
		return 1;
	}
	//запись в файл
	for (int i = 0; i < 3; i++) {
		if (i) fprintf(PtrFile_OUT, ", ");
		fprintf(PtrFile_OUT, "%s", line);
	}
	fprintf(PtrFile_OUT, " %d", count);	//вывод счетчика символов
	fclose(PtrFile_OUT);
		
    return 0;
}
