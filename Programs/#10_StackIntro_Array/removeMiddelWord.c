// Remove middel word from stack
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    char words[MAX_SIZE][50]; // Assuming each word has a maximum length of 50 characters
    int top;
};

void push(struct Stack *stack, const char *word) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack->top++;
    strcpy(stack->words[stack->top], word);
}

char* pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }
    return stack->words[stack->top--];
}

void removeMiddle(struct Stack *stack) {
    int middle = (stack->top + 1) / 2;
    struct Stack tempStack;
    tempStack.top = -1;

    // Push words to tempStack until the middle is reached
    for (int i = 0; i < middle; i++) {
        push(&tempStack, pop(stack));
    }

    // Pop the middle word
    pop(stack);

    // Push words back from tempStack to original stack
    while (tempStack.top != -1) {
        push(stack, pop(&tempStack));
    }
}

int main() {
    struct Stack stack;
    stack.top = -1;

    push(&stack, "hello");
    push(&stack, "how");
    push(&stack, "are");
    push(&stack, "you");
    //push(&stack, "doing");

    printf("Original Stack:\n");
    for (int i = 0; i <= stack.top; i++) {
        printf("%s ", stack.words[i]);
    }
    printf("\n");

    removeMiddle(&stack);

    printf("Stack after removing middle word:\n");
    for (int i = 0; i <= stack.top; i++) {
        printf("%s ", stack.words[i]);
    }
    printf("\n");

    return 0;
}

/*
We include necessary header files for input/output, string manipulation, and dynamic memory allocation. The MAX_SIZE constant defines the maximum number of words the stack can hold. We define a structure Stack that holds an array of words and the current top index.

The push and pop functions are used to add and remove elements from the stack, respectively. These functions are the same as before, allowing us to interact with the stack.

The removeMiddle function calculates the index of the middle word based on the stack's current size. It then creates a temporary stack tempStack to hold words before the middle word.

It first pushes words from the original stack to tempStack until the middle is reached. This effectively removes the middle word from the original stack.
Then, it pops the middle word from the original stack.
Finally, it pushes the words back from tempStack to the original stack, restoring the order without the middle word.

In the main function, we create a Stack structure and push five words onto it. We then print the original stack's content.

After calling removeMiddle(&stack), we print the stack's content again to show that the middle word has been successfully removed.
*/
