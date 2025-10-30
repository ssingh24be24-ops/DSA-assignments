#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

void append(char c) {
    struct Node *new = malloc(sizeof(struct Node));
    new->data = c;
    new->next = NULL;
    new->prev = NULL;
    if (!head) {
        head = new;
        return;
    }
    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
    new->prev = temp;
}

int isPalindrome() {
    if (!head) return 1;
    struct Node *start = head, *end = head;
    while (end->next)
        end = end->next;
    while (start != end && end->next != start) {
        if (start->data != end->data)
            return 0;
        start = start->next;
        end = end->prev;
    }
    return 1;
}

int main() {
    char s[] = "madam";
    for (int i = 0; s[i] != '\0'; i++)
        append(s[i]);
    if (isPalindrome())
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
