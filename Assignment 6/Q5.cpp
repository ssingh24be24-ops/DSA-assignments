#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void append(int data) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = data;
    new->next = NULL;
    if (!head) {
        head = new;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

int isCircular() {
    if (!head) return 0;
    struct Node *temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return temp == head;
}

int main() {
    for (int i = 1; i <= 5; i++)
        append(i);
    printf("Circular? %s\n", isCircular() ? "Yes" : "No");
    head->next->next->next->next->next = head;
    printf("Circular? %s\n", isCircular() ? "Yes" : "No");
    return 0;
}
