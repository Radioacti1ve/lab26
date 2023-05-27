#ifndef STACK_H
#define STACK_H

// Структура стека
typedef struct {
    int *data;  // Массив данных
    int top;    // Индекс верхнего элемента
    int size;   // Размер стека
} Stack;

// Функции работы со стеком
Stack createStack(int size);
void push(Stack *stack, int item);
int pop(Stack *stack);
void mergeStacks(Stack *stack1, Stack *stack2);
void mergeSort(Stack *stack);
void printStack(Stack stack);

#endif
