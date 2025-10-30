#include <stdio.h>
#include <stdlib.h>

#define MAX 100


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
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return -1;
    }
    int val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return val;
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


void interleaveQueue(int n) {
    if (n % 2 != 0) {
        printf("Queue size must be even!\n");
        return;
    }

    int half = n / 2;
    int temp[MAX], tFront = -1, tRear = -1;

  
    for (int i = 0; i < half; i++) {
        int val = dequeue();
        if (tFront == -1) tFront = 0;
        temp[++tRear] = val;
    }

   
    while (tFront <= tRear && !isEmpty()) {
        enqueue(temp[tFront++]); 
        enqueue(dequeue());        \
    }
}

int main() {
    int n, val;
    printf("Enter number of elements (even): ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    printf("Original Queue: ");
    display();

    interleaveQueue(n);

    printf("Interleaved Queue: ");
    display();

    return 0;
}