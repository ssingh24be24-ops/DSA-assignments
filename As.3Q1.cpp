#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX], top = -1;

// Function prototypes
void push();
void pop();
void display();
void peek();
int isFull();
int isEmpty();

int main() {
    int choice;
    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void push() {
    int item;
    if (isFull()) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter element: ");
        scanf("%d", &item);
        stack[++top] = item;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int isFull() { return top == MAX - 1; }
int isEmpty() { return top == -1; }