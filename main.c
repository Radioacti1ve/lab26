#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

int main() {
    Stack stack1, stack2;
    int choice, item;
    
    // Инициализация стеков
    stack1 = createStack(100);
    stack2 = createStack(100);
    
    do {
        printf("\nМеню:\n");
        printf("1. Добавить элемент в стек\n");
        printf("2. Удалить последний добавленный элемент из стека\n");
        printf("3. Отсортировать стек алгоритмом сортировки слияния\n");
        printf("4. Слить два стека\n");
        printf("5. Вывести содержимое стека\n");
        printf("6. Выход\n");
        printf("Выберите действие (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Выберите стек (1 или 2): ");
                scanf("%d", &item);
                if (item == 1) {
                    printf("Введите элемент для добавления в стек 1: ");
                    scanf("%d", &item);
                    push(&stack1, item);
                } else if (item == 2) {
                    printf("Введите элемент для добавления в стек 2: ");
                    scanf("%d", &item);
                    push(&stack2, item);
                } else {
                    printf("Неверный выбор стека.\n");
                }
                break;
                
            case 2:
                printf("Выберите стек (1 или 2): ");
                scanf("%d", &item);
                if (item == 1) {
                    item = pop(&stack1);
                    if (item != -1)
                        printf("Удаленный элемент из стека 1: %d\n", item);
                } else if (item == 2) {
                    item = pop(&stack2);
                    if (item != -1)
                        printf("Удаленный элемент из стека 2: %d\n", item);
                } else {
                    printf("Неверный выбор стека.\n");
                }
                break;
                
            case 3:
                printf("Выберите стек (1 или 2): ");
                scanf("%d", &item);
                if (item == 1) {
                    mergeSort(&stack1);
                    printf("Стек 1 отсортирован.\n");
                } else if (item == 2) {
                    mergeSort(&stack2);
                    printf("Стек 2 отсортирован.\n");
                } else {
                    printf("Неверный выбор стека.\n");
                }
                break;
                
            case 4:
                mergeStacks(&stack1, &stack2);
                printf("Стеки слиты.\n");
                break;
                
            case 5:
                printf("Выберите стек (1 или 2): ");
                scanf("%d", &item);
                if (item == 1)
                    printStack(stack1);
                else if (item == 2)
                    printStack(stack2);
                else
                    printf("Неверный выбор стека.\n");
                break;
                
            case 6:
                printf("Программа завершена.\n");
                break;
                
            default:
                printf("Неверный выбор.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}
