
#include "../src/stack.h"
#include <stdio.h>

#define len(x) sizeof(x) / sizeof(x[0])

void printIntStackItem(void* itemp);

int main() {

    stack* s = createStack();

    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < len(nums); i++) {
        push(s, &nums[i]);
    }
    printStack(s, printIntStackItem);

    printf("Item on top of stack is: %i\n", *(int*)peek(s));
    printf("Size of stack is: %i\n", getStackSize(s));

    puts("Popping all items from stack");

    for (void* current = pop(s); current; current = pop(s)) {
        printf("Popped: ");
        printIntStackItem(current);
        puts("");
    }

    freeStack(s, false);
}

void printIntStackItem(void* itemp) {
    printf("%i, ", *(int*)itemp);
}