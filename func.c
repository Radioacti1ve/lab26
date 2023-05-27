#include <stdio.h>
#include <stdlib.h>
#include "modul.h"

// Создание стека заданного размера
Stack createStack(int size) {
    Stack stack;
    stack.data = (int*)malloc(size * sizeof(int));
    stack.top = -1;
    stack.size = size;
    return stack;
}

// Добавление элемента в стек
void push(Stack *stack, int item) {
    if (stack->top == stack->size - 1) {
        printf("Стек полон. Невозможно добавить элемент.\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// Удаление и возврат последнего добавленного элемента из стека
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("Стек пуст. Невозможно удалить элемент.\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Слияние двух стеков
void mergeStacks(Stack *stack1, Stack *stack2) {
    Stack tempStack = createStack(stack1->size + stack2->size);
    while (stack1->top != -1 && stack2->top != -1) {
        if (stack1->data[stack1->top] < stack2->data[stack2->top])
            push(&tempStack, pop(stack1));
        else
            push(&tempStack, pop(stack2));
    }
    while (stack1->top != -1)
        push(&tempStack, pop(stack1));
    while (stack2->top != -1)
        push(&tempStack, pop(stack2));
    
    while (tempStack.top != -1)
        push(stack1, pop(&tempStack));
}

// Алгоритм сортировки слиянием
void mergeSort(Stack *stack) {
    if (stack->top < 1)
        return;

    Stack leftStack = createStack(stack->size / 2);
    Stack rightStack = createStack(stack->size - stack->size / 2);

    while (stack->top >= 0) {
        if (leftStack.top < leftStack.size / 2)
            push(&leftStack, pop(stack));
        else
            push(&rightStack, pop(stack));
    }

    mergeSort(&leftStack);
    mergeSort(&rightStack);
    mergeStacks(&leftStack, &rightStack);

    while (leftStack.top >= 0)
        push(stack, pop(&leftStack));
}

// Вывод содержимого стека
void printStack(Stack stack) {
    printf("Содержимое стека: ");
    for (int i = stack.top; i >= 0; i--)
        printf("%d ", stack.data[i]);
    printf("\n");
}
