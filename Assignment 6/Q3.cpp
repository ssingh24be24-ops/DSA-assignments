#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev, *next;
};

struct CNode {
    int data;
    struct CNode *next;
};

struct DNode *dhead = NULL;
struct CNode *chead = NULL;

void d_append(int data) {
    struct DNode *new = malloc(sizeof(struct DNode));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    if (!dhead) {
        dhead = new;
        return;
    }
    struct DNode *temp = dhead;
    while (temp->next) temp = temp->next;
    temp->next = new;
    new->prev = temp;
}

void c_append(int data) {
    struct CNode *new = malloc(sizeof(struct CNode));
    new->data = data;
    if (!chead) {
        chead = new;
        chead->next = chead;
        return;
    }
    struct CNode *temp = chead;
    while (temp->next != chead)
        temp = temp->next;
    temp->next = new;
    new->next = chead;
}

int d_size() {
    int count = 0;
    struct DNode *temp = dhead;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int c_size() {
    if (!chead) return 0;
    int count = 0;
    struct CNode *temp = chead;
    do {
        count++;
        temp = temp->next;
    } while (temp != chead);
    return count;
}

int main() {
    for (int i = 1; i <= 5; i++) {
        d_append(i * 10);
        c_append(i * 10);
    }
    printf("Size of Doubly Linked List: %d\n", d_size());
    printf("Size of Circular Linked List: %d\n", c_size());
    return 0;
}
