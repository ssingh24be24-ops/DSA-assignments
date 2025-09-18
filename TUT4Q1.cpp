#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;


int isEmpty() {
    return (front == -1);
}


int isFull() {
    return (rear == MAX - 1);
}


void enqueue(int x) {
    if (isFull()) {
        printf("Queue is FULL!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
    printf("%d enqueued\n", x);
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) {
        front = rear = -1;  // reset queue
    } else {
        front++;
    }
}


void peek() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front element = %d\n", queue[front]);
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice, val;
    while (1) {
        printf("\n--- Simple Queue Menu ---\n");
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