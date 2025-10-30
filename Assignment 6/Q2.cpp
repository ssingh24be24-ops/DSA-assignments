#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void append(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void display() {
    if (!head) return;
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d\n", head->data);
}

int main() {
    int arr[] = {20, 100, 40, 80, 60};
    for (int i = 0; i < 5; i++) append(arr[i]);
    display();
    return 0;
}
