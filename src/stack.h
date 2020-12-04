#ifndef STACK_H
#define STACK_H

#include <linkedList.h>
#include <stdbool.h>

typedef struct {
    linkedList* _listp;
} stack;

stack* createStack();
bool push(stack* s, void* itemp);
void* pop(stack* s);
void* peek(stack* s);
int getStackSize(stack* s);
void clearStack(stack* s, bool freeValues);
void freeStack(stack* s, bool freeValues);
void printStack(stack* s, void (*printFunc)(void*));

#endif