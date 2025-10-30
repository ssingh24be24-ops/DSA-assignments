#include <stdio.h>


void removeDuplicates(int arr[], int *size) {
    for (int i = 0; i < *size; i++) {
        for (int j = i + 1; j < *size; ) {
            if (arr[i] == arr[j]) {
               
                for (int k = j; k < *size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
            } else {
                j++;
            }
        }
    }
}

int main() {
    int arr[100], size;

    printf("\nHow many elements? ");
    scanf("%d", &size);

    printf("Enter your %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    removeDuplicates(arr, &size);

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

