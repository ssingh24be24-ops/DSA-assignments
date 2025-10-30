#include <stdio.h>

int main() {
    int i, j;
    int size = 3;
    int k = (size * (size + 1)) / 2; 
    int a[k];

    printf("Enter %d values for upper triangular matrix:\n", k);
    for (i = 0; i < k; i++) {
        scanf("%d", &a[i]);
    }

    printf("The upper triangular matrix is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i >= j) {
                int index = i * (i + 1) / 2 + j;
                printf("%d ", a[index]);
            }
			 else {
			 	 int index = j * (j + 1) / 2 + i;
                printf("%d ", a[index]);
               
            }
        }
        printf("\n");
    }

    return 0;
}
