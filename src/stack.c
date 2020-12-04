#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack* createStack() {
    linkedList* l = createList();
    stack* s = malloc(sizeof(stack));
    if (!l || !s) {
        return NULL;
    }
    *s = (stack) { l };
    return s;
}

/**
 * @return true if push was successful, false if it failed
 */
bool push(stack* s, void* itemp) {
    return prependToList(s->_listp, itemp);
}

/**
 * @return a pointer to the element removed from the stack. NULL if no items on the stack
 */
void* pop(stack* s) {
    return removeFirst(s->_listp);
}

/**
 * @return a pointer to the element on top of the stack. NULL if no items on the stack 
 */
void* peek(stack* s) {
    if (getListSize(s->_listp)) {
        return getFirst(s->_listp);
    } else {
        return NULL;
    }
}

int getStackSize(stack* s) {
    return getListSize(s->_listp);
}

/**
 * Removes all elements in the stack.
 * @param freeValues element pointers passed into free if true.
 */
void clearStack(stack* s, bool freeValues) {
    clearList(s->_listp, freeValues);
}

void freeStack(stack* s, bool freeValues) {
    clearList(s->_listp, freeValues);
    free(s);
}

void printStack(stack* s, void (*printFunc)(void*)) {
    printf("Top -> ");
    iterateListValues(s->_listp, printFunc);
    puts("");
}