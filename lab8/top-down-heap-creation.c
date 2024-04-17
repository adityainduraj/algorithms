#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void topDownHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        topDownHeapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        topDownHeapify(arr, n, i);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock(); // Stop the clock

    buildHeap(arr, n);

    clock_t end = clock(); // Stop the clock

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Cast the result to double
    
    printf("Heap construction time: %f seconds\n", time_taken);

    printf("Heap array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

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