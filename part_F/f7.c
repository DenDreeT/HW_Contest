#include <stdio.h>

/*
* Задание_F7_контест
* Функция преобразования массива  (сжатие)
* 
*
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int compression(int a [], int b [], int N);

void read_input(int *pa) {
	int n_items = 0;
	n_items = scanf("%d", pa);
	if(n_items != 1) {
		printf("Error: invalid input, expected any 1 integer\n");
		abort();
	}
}

void read_input_arr(int size, int arr []) {
	for(int i = 0; i < size; i++) {
	read_input(arr + i);
	}	
}

void print_arr(int size, int arr []) {
	for(int i = 0; i < size; i++)
	printf("%d ", arr[i]);
}

int main() {
	int b_n;
	int arr[SIZE];
	int b[SIZE];
	read_input_arr(SIZE, arr);
	b_n = compression(arr, b, SIZE);
	print_arr(b_n, b);
	return 0;
}

int compression(int a [], int b [], int N) {
	int b_n = 0;
	int curr = 0;
	int prew = 0;
	for(int i = 0; i < N; i++) {
		if(a[i] != curr) {
			curr = a[i];
			b[b_n++] = i - prew;
			prew = i;
			i--;
		}
		else if(i == N - 1)
			b[b_n++] = i - prew + 1;
	}
return b_n;
}
