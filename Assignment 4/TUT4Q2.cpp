#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;


int isEmpty() {
    return (front == -1);
}


int isFull() {
    return ((rear + 1) % MAX == front);
}


void enqueue(int x) {
    if (isFull()) {
        printf("Circular Queue is FULL!\n");
        return;
    }
    if (front == -1) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    cqueue[rear] = x;
    printf("%d enqueued\n", x);
}


void dequeue() {
    if (isEmpty()) {
        printf("Circular Queue is EMPTY!\n");
        return;
    }
    printf("%d dequeued\n", cqueue[front]);
    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void peek() {
    if (isEmpty()) {
        printf("Circular Queue is EMPTY!\n");
    } else {
        printf("Front element = %d\n", cqueue[front]);
    }
}


void display() {
    if (isEmpty()) {
        printf("Circular Queue is EMPTY!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main() {
    int choice, val;
    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}