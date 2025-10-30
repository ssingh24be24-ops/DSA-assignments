#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode *next;
};

struct DNode {
    int data;
    struct DNode *prev, *next;
};

struct CNode *chead = NULL;
struct DNode *dhead = NULL;

void c_insert(int data, int key, char pos) {
    struct CNode *newNode = malloc(sizeof(struct CNode));
    newNode->data = data;
    if (chead == NULL) {
        newNode->next = newNode;
        chead = newNode;
        return;
    }
    struct CNode *temp = chead;
    if (pos == 'f') {
        while (temp->next != chead)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = chead;
        chead = newNode;
        return;
    }
    if (pos == 'l') {
        while (temp->next != chead)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = chead;
        return;
    }
    do {
        if (temp->data == key) {
            if (pos == 'a') {
                newNode->next = temp->next;
                temp->next = newNode;
            } else {
                struct CNode *prev = chead;
                while (prev->next != temp)
                    prev = prev->next;
                prev->next = newNode;
                newNode->next = temp;
                if (temp == chead)
                    chead = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != chead);
}

void c_delete(int key) {
    if (chead == NULL) return;
    struct CNode *temp = chead, *prev = NULL;
    if (chead->data == key) {
        if (chead->next == chead) {
            free(chead);
            chead = NULL;
            return;
        }
        while (temp->next != chead)
            temp = temp->next;
        struct CNode *del = chead;
        temp->next = chead->next;
        chead = chead->next;
        free(del);
        return;
    }
    prev = chead;
    temp = chead->next;
    while (temp != chead) {
        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void c_search(int key) {
    if (chead == NULL) {
        printf("Not found\n");
        return;
    }
    struct CNode *temp = chead;
    int pos = 1;
    do {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    } while (temp != chead);
    printf("Not found\n");
}

void c_display() {
    if (chead == NULL) {
        printf("Empty\n");
        return;
    }
    struct CNode *temp = chead;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != chead);
    printf("(back to %d)\n", chead->data);
}

void d_insert(int data, int key, char pos) {
    struct DNode *newNode = malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    if (dhead == NULL) {
        dhead = newNode;
        return;
    }
    if (pos == 'f') {
        newNode->next = dhead;
        dhead->prev = newNode;
        dhead = newNode;
        return;
    }
    struct DNode *temp = dhead;
    if (pos == 'l') {
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) return;
    if (pos == 'a') {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    } else {
        newNode->prev = temp->prev;
        newNode->next = temp;
        if (temp->prev)
            temp->prev->next = newNode;
        temp->prev = newNode;
        if (temp == dhead)
            dhead = newNode;
    }
}

void d_delete(int key) {
    if (!dhead) return;
    struct DNode *temp = dhead;
    if (temp->data == key) {
        dhead = temp->next;
        if (dhead) dhead->prev = NULL;
        free(temp);
        return;
    }
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp) return;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp->prev)
        temp->prev->next = temp->next;
    free(temp);
}

void d_search(int key) {
    struct DNode *temp = dhead;
    int pos = 1;
    while (temp) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Not found\n");
}

void d_display() {
    struct DNode *temp = dhead;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, key;
    char type, pos;
    while (1) {
        printf("\n1. Insert (C/D)\n2. Delete (C/D)\n3. Search (C/D)\n4. Display (C/D)\n5. Exit\n");
        scanf("%d", &choice);
        if (choice == 5) break;
        printf("Circular (C) or Doubly (D)? ");
        scanf(" %c", &type);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Position: f(first), l(last), a(after), b(before): ");
            scanf(" %c", &pos);
            if (pos == 'a' || pos == 'b') {
                printf("Enter key: ");
                scanf("%d", &key);
            } else key = 0;
            if (type == 'C' || type == 'c') c_insert(data, key, pos);
            else d_insert(data, key, pos);
        } else if (choice == 2) {
            printf("Enter key to delete: ");
            scanf("%d", &key);
            if (type == 'C' || type == 'c') c_delete(key);
            else d_delete(key);
        } else if (choice == 3) {
            printf("Enter key to search: ");
            scanf("%d", &key);
            if (type == 'C' || type == 'c') c_search(key);
            else d_search(key);
        } else if (choice == 4) {
            if (type == 'C' || type == 'c') c_display();
            else d_display();
        }
    }
    return 0;
}
