int findMissingLinear(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  // Missing number found
        }
    }
    return size + 1;  // If no mismatch, missing number is n
}
