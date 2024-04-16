#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void topDownHeapify(int arr[], int n, int i) {
    // Heapify implementation...
}

void buildHeap(int arr[], int n) {
    // buildHeap implementation...
}

void printHeap(int arr[], int n) {
    // printHeap implementation...
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock(); // Start the clock

    buildHeap(arr, n);

    clock_t end = clock(); // Stop the clock

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Heap construction time: %f seconds\n", time_taken);

    printHeap(arr, n);

    free(arr);

    return 0;
}
/*
sample input
Enter the number of elements: 6
Enter the elements:
10
20
15
30
25
5
*/