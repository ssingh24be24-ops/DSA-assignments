#include <stdio.h>

#define MAX 100

int arr[MAX], n = 0;

void create() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void display() {
    printf("Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert() {
    int pos, val;
    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    if (pos < 0 || pos > n) { 
        printf("Invalid position.\n"); 
        return; 
    }
    printf("Enter value: ");
    scanf("%d", &val);
    for (int i = n; i > pos; i--) 
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void delete() {
    int pos;
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) { 
        printf("Invalid position.\n"); 
        return; 
    }
    for (int i = pos; i < n - 1; i++) 
        arr[i] = arr[i + 1];
    n--;
}

void linear_search() {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) 
        printf("Not Found\n");
}

int main() {
    int ch;
    do {
        printf("\nMENU:\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: delete(); break;
            case 5: linear_search(); break;
            case 6: printf("Exiting.\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 6);
    return 0;
}

