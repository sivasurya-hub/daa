#include <stdio.h>

#define MAX_SIZE 100

void display(int arr[], int size) {
    if (size <= 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return size;
    }

    if (position < 0 || position > size) {
        printf("Invalid position. Cannot insert.\n");
        return size;
    }

    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    arr[position] = element;
    return size + 1;
}

    int delete(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return size;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position. Cannot delete.\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                size = insert(arr, size, element, position);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                size = delete(arr, size, position);
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}


