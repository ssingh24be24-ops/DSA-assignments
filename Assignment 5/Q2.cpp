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
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void count_and_delete(int key) {
    int count = 0;
    while (head && head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        count++;
    }
    struct Node *temp = head;
    while (temp && temp->next) {
        if (temp->next->data == key) {
            struct Node *del = temp->next;
            temp->next = del->next;
            free(del);
            count++;
        } else {
            temp = temp->next;
        }
    }
    printf("Count: %d\n", count);
}

void display() {
    struct Node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    for (int i = 0; i < 7; i++)
        append(arr[i]);
    printf("Original List:\n");
    display();
    count_and_delete(1);
    printf("Updated List:\n");
    display();
    return 0;
}
