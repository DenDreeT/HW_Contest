/*
 *
 * Задача D1 контеста "Продвинутый Си"
 * Вид сверху
 * В программе описана структура для хранения двоичного дерева:
 * typedef struct tree {
 * datatype key;
 * struct tree *left, *right;
 * } tree;
 *
 * Необходимо реализовать функцию, которая печатает вид дерева сверху.
 * Функция должна строго соответствовать прототипу: void btUpView(tree *root)
 * В качестве ответа загрузите только одну функцию void btUpView(tree *root)
 *
 * Данные на входе:

       10
      /   \
     5     15
    / \   /  \
   3   7 13   18
  /   /
 1   6



Данные на выходе:	1 3 5 10 15 18

*
*/


#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int32_t datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
} tree;


void insert_t(tree **root, datatype key)  // Функция для вставки нового узла в дерево
{
    if(!*root)   // Если дерево пустое, создается новый узел и становится корнем дерева
    {
        *root = (tree *) calloc(1, sizeof(tree));
        (*root)->key = key;
    }
    else if((*root)->key < key) // Если ключ нового узла больше, чем ключ корня, вставка происходит в правое поддерево
    {
        insert_t(&(*root)->right, key);
    }

    else  // Если ключ нового узла меньше, чем ключ корня, вставка происходит в левое поддерево
    {
        insert_t(&(*root)->left, key);
    }
}

// Функция обхода дерева по кроне слева направо
void btUpView(tree *root) {
    if (root == NULL) return;

    // Временный массив для хранения узлов (предполагаем, что глубина дерева <= 100)
    #define MAX_DEPTH 100
    int leftNodes[MAX_DEPTH];
    int leftCount = 0;

    // Собираем левые узлы (от корня вниз до самого левого листа)
    tree *current = root->left;
    while (current != NULL) {
        leftNodes[leftCount++] = current->key;
        current = current->left;  // идём строго влево
    }

    // Выводим левые узлы в обратном порядке (снизу вверх)
    for (int i = leftCount - 1; i >= 0; i--) {
        printf("%d ", leftNodes[i]);
    }

    // Выводим корень
    printf("%d ", root->key);

    // Выводим правые узлы (сверху вниз, от корня к самому правому листу)
    current = root->right;
    while (current != NULL) {
        printf("%d ", current->key);
        current = current->right;  // идём строго вправо
    }
}


int main () {

    tree *my_tree = NULL;
    insert_t(&my_tree, 10);
    insert_t(&my_tree, 5);
    insert_t(&my_tree, 15);
    insert_t(&my_tree, 3);
    insert_t(&my_tree, 7);
    insert_t(&my_tree, 13);
    insert_t(&my_tree, 18);
    insert_t(&my_tree, 1);
    insert_t(&my_tree, 6);
    btUpView(my_tree);

    return 0;
}
