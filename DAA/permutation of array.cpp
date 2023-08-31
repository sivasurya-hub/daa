#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        printArray(arr, end + 1);
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(&arr[start], &arr[i]);
        generatePermutations(arr, start + 1, end);
        swap(&arr[start], &arr[i]); // Backtrack
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array: ");
    printArray(arr, n);

    printf("Permutations:\n");
    generatePermutations(arr, 0, n - 1);

    return 0;
}

