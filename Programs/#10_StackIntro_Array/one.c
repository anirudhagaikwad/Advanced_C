/*
Implement a stack data structure using an array and perform push, pop, and display operations.
*/
#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    //check for stack is full or not
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("Element %d pushed to the stack\n", value);
}

void pop() {
    //check for stack empty or not
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Element %d popped from the stack\n", stack[top--]);
}

void display() {
    //if top==-1 stack gets empty
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
/*
This program demonstrates the implementation of a stack data structure using an array.
It provides functions to push an element onto the stack, pop an element from the stack, and display the stack's contents.
The program performs operations on the stack and displays the resulting stack after each operation.
*/
/*
Certainly! Let's break down the code step by step with detailed explanations:

```c
#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;
```

- The `#include <stdio.h>` line includes the standard input/output library for using functions like `printf`.
- `#define MAX_SIZE 100` defines a constant `MAX_SIZE` with the value 100.
- `int stack[MAX_SIZE];` declares an integer array named `stack` to store elements of the stack.
- `int top = -1;` initializes the variable `top` to -1. This variable keeps track of the index of the top element in the stack. `-1` indicates an empty stack.

```c
void push(int value) {
    // Check if stack is full or not
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
    printf("Element %d pushed to the stack\n", value);
}
```

- The `push` function is defined to add elements to the stack.
- Inside the function, the condition `if (top == MAX_SIZE - 1)` checks if the stack is already full. If `top` is equal to `MAX_SIZE - 1`, the stack is at its maximum capacity.
- If the condition is true, the program prints "Stack Overflow" and immediately returns, indicating that no more elements can be pushed onto the stack.
- If the stack is not full, the element is pushed onto the stack by incrementing `top` and assigning the value to `stack[top]`. The program also prints a message indicating the element that was pushed.

```c
void pop() {
    // Check if stack is empty or not
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Element %d popped from the stack\n", stack[top--]);
}
```

- The `pop` function is defined to remove elements from the stack.
- Inside the function, the condition `if (top == -1)` checks if the stack is empty. If `top` is -1, the stack is empty.
- If the condition is true, the program prints "Stack Underflow" and immediately returns, indicating that there are no elements to pop.
- If the stack is not empty, the element is popped from the stack by printing its value and then decrementing `top`.

```c
void display() {
    // If top == -1, the stack is empty
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}
```

- The `display` function is defined to show the elements in the stack.
- If `top` is -1, the stack is empty. In that case, the program prints "Stack is empty" and immediately returns.
- If the stack is not empty, the program uses a loop to iterate through the elements in the `stack` array and prints them.

```c
int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
```

- The `main` function is where the program starts its execution.
- It demonstrates the usage of the stack functions.
- It pushes three elements (10, 20, and 30) onto the stack using the `push` function.
- It displays the elements of the stack using the `display` function.
- It pops an element from the stack using the `pop` function.
- It displays the updated elements of the stack again using the `display` function.
- Finally, it returns 0 to indicate successful completion of the program.

*/
