#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        int flag = 0;

       
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 1;  
                break;
            }
        }

        if (flag == 0) {
            distinctCount++;
        }
    }

    printf("Total distinct elements: %d\n", distinctCount);

    return 0;
}
