#include <stdio.h>

int countInversionsNaive(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int inversionCount = countInversionsNaive(arr, n);
    printf("Number of inversions: %d\n", inversionCount);

    return 0;
}
