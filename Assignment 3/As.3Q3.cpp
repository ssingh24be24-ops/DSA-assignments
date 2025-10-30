#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

int main() {
    char exp[MAX];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty()) { printf("Not Balanced\n"); return 0; }
            char temp = pop();
            if ((exp[i] == ')' && temp != '(') ||
                (exp[i] == '}' && temp != '{') ||
                (exp[i] == ']' && temp != '[')) {
                printf("Not Balanced\n");
                return 0;
            }
        }
    }
    if (isEmpty()) printf("Balanced\n");
    else printf("Not Balanced\n");

    return 0;
}