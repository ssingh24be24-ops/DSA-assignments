#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) postfix[k++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
    return 0;
}