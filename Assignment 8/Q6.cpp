#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int val) {
    if (size == MAX) return;
    heap[size++] = val;
    int i = size - 1;
    while (i != 0 && heap[(i-1)/2] < heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

int extractMax() {
    if (size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[--size];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, largest = i;
        if (l < size && heap[l] > heap[largest]) largest = l;
        if (r < size && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
    return root;
}

void display() {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(15);
    insert(30);

    printf("Priority Queue (Max-Heap): ");
    display();

    printf("Extracted Max: %d\n", extractMax());
    printf("After extraction: ");
    display();
    return 0;
}
