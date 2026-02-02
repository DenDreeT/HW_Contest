/*
*Задание В0 контеста В "Продвинутый Си"
*Требуется реализовать только одну функцию, которая в данном списке
* находит адрес блока памяти занимающий больше всего места.
*Адрес хранится в поле address, поле size - соответствующий размер
* данного блока. 
* Если список пустой, то функция должна возвращать 0. 
* Если есть несколько таких блоков, то вернуть адрес любого из них.
*
*/

#include <stdio.h>
#include <stdint.h>

// прототип структуры
typedef struct list {
	uint64_t address;
	size_t size;
	char comment[64];
	struct list *next;
} list;


// определение функции
uint64_t findMaxBlock(list *head) {
    if (head == NULL) {
        return 0;
    }

    long long int max_addr = head->address;
    size_t max_size = head->size;
    list *current = head->next;

    while (current != NULL) {
        if (current->size > max_size) {
            max_size = current->size;
            max_addr = current->address;
        }
        current = current->next;
    }

    return max_addr;
}


int main () {
	
	uint64_t maxAddress = findMaxBlock(&head);
	if (maxAddress != 0) {
        printf("0x%llu\n", maxAddress);
    } else {
        printf("Список пуст\n");
    }
	
	return 0;
}
