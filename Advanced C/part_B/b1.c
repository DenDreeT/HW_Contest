/*
*Задание В1 контеста В "Продвинутый Си"
*Требуется реализовать только одну функцию, которая анализирует
*данный список и возвращает сколько всего памяти используется. 
*Адрес хранится в поле address, поле size - соответствующий размер
* данного блока. Если список пустой, то функция должна возвращать 0.
*
*/

#include <stdio.h>
#include <stdint.h>

// прототип структуры
typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;

// определение функции
size_t totalMemoryUsage(list *head) {
    size_t total_size = 0;
    list *current = head;

    while (current != NULL) {
        total_size += current->size; // Прибавляем размер текущего блока
        current = current->next;     // Переходим к следующему
    }

    return total_size;
}


int main () {
	
	size_t res = totalMemoryUsage(&head);
	printf("%lu", res);
	
	return 0;
}
