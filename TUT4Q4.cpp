#include <stdio.h>
#include <string.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

void enqueue(char c) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = c;
}

char dequeue() {
    if (isEmpty()) return '\0';
    char c = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return c;
}

char getFront() {
    if (isEmpty()) return '\0';
    return queue[front];
}

int isRepeated(char str[], int uptoIndex, char ch) {
    int count = 0;
    for (int i = 0; i <= uptoIndex; i++) {
        if (str[i] == ch) count++;
    }
    return (count > 1);
}

void firstNonRepeating(char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') continue;

        enqueue(str[i]);

        while (!isEmpty() && isRepeated(str, i, getFront())) {
            dequeue();
        }

        if (isEmpty()) {
            printf("-1 ");
        } else {
            printf("%c ", getFront());
        }
    }
    printf("\n");
}

int main() {
    char str[MAX];
    printf("Enter a string (characters separated by space): ");
    fgets(str, MAX, stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    firstNonRepeating(str);

    return 0;
}