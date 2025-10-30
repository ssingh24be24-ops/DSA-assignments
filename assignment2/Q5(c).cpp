#include <stdio.h>

int main() {
    int i, j;
    int size = 3;
    int k = (size * (size + 1)) / 2; 
    int a[k];

    printf("Enter %d values for lower triangular matrix:\n", k);
    for (i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }

    printf("The lower triangular matrix is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i >= j) {
                int index = i * (i + 1) / 2 + j;
                printf("%d ", a[index]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}
