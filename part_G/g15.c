/*
 *  задание_G15_контеста
 * Cao заменить на Ling
 * В файле .txt дано предложение. Необходимо заменить все имена
 *  «Cao» на «Ling» и записать результат в файл .txt.
 * 
 */

#include <stdio.h>
#include <string.h>

#define SIZE 1001	//ограничение размера строки

char FileNameIn[] = {"input.txt"};
char FileNameOut[] = {"output.txt"};

//функция записи предложения в массив
void input(char *strIn) {
	FILE *file_in;
	file_in = fopen(FileNameIn, "r");
	while(fscanf(file_in, "%[^\n]", strIn) == 1);
	fclose(file_in);
}

//функция замены имени
void changeName(char *strExt, char *buffer) {
	int count = 0;
	for(int i = 0; i < strlen(strExt); i++) {
		if(!memcmp(strExt+i,"Cao",3)) {
			strcat(buffer, "Ling");
			count += 4;
			i += 3;
		}
		buffer[count++] = strExt[i];
	}
}

//функция записи измененного массива в файл
void output(char *strOut) {
	FILE *out;
	out = fopen(FileNameOut, "w");
	fprintf(out, "%s", strOut);
	fclose(out);
}

int main() {
	char str[SIZE]={0}, strFinal[SIZE]={0};
	input(str);
	changeName(str, strFinal);
	output(strFinal);
	return 0;
}
