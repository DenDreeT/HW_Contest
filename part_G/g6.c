/*
 *  задание_G6_контеста
 * Проверка на палиндром
 * В файле .txt символьная строка не более 1000 символов.
 * Необходимо проверить, является ли она палиндромом 
 * (палиндром читается одинаково в обоих направлениях). 
 * Реализовать логическую функцию is_palindrom(str) и 
 * записать ответ в файл .txt.
 * 
 */

#include <stdio.h>
#include <string.h>

const int line_width = 1024;

int is_palindrome(char *line);

int main(void) {
	char *PtrFile_IN = "input.txt";
	char *PtrFile_OUT = "output.txt";
	char line[line_width];
	
	FILE *file_ptr;
	
	file_ptr = fopen(PtrFile_IN, "r");
	fscanf(file_ptr, "%[^\n]", line);
	fclose(file_ptr);
	file_ptr = fopen(PtrFile_OUT, "w");
	fprintf(file_ptr, "%s", is_palindrome(line) ? "YES" : "NO");
	fclose(file_ptr);
	return 0;

}

int is_palindrome(char *line) {
	int len = strlen(line);
	for (int i = 0; i < len / 2; i++)
		if (line[i] != line[len - i - 1])
			return 0;
	return 1;
}
