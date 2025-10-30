#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insert_at_end(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insert_before_after(int key, int data, char pos) {
    if (head == NULL) return;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 'b' && head->data == key) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp = head, *prev = NULL;
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) return;

    if (pos == 'a') {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        newNode->next = temp;
        prev->next = newNode;
    }
}

void delete_from_beginning() {
    if (head == NULL) return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void delete_from_end() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void delete_specific(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp) {
        prev->next = temp->next;
        free(temp);
    }
}

void search(int key) {
    struct Node *temp = head;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
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
    insert_at_beginning(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_before_after(20, 15, 'b');
    insert_before_after(20, 25, 'a');
    display();
    delete_from_beginning();
    delete_from_end();
    delete_specific(20);
    display();
    search(15);
    return 0;
}
