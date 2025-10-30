#include <stdio.h>

void printRowColumnSum(int mat[3][3]) {
    for (int i = 0; i < 3; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += mat[i][j];
            colSum += mat[j][i];
        }
        printf("Row %d Sum = %d, Column %d Sum = %d\n", i + 1, rowSum, i + 1, colSum);
    }
}

int main() {
    int mat[3][3];
    printf("\nEnter a 3x3 Matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &mat[i][j]);
    printf("\nCalculating row and column sums...\n");
    printRowColumnSum(mat);
    return 0;
}

