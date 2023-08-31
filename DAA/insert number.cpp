#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int list[100]; // Assuming a maximum of 100 elements
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    int newNumber, position;
    printf("Enter the new number to insert: ");
    scanf("%d", &newNumber);

    printf("Enter the position to insert the new number (0-indexed): ");
    scanf("%d", &position);

    if (position < 0 || position > n) {
        printf("Invalid position.\n");
        return 1;
    }

    // Shift elements to the right to make space for the new number
    for (int i = n; i > position; i--) {
        list[i] = list[i - 1];
    }

    list[position] = newNumber;
    n++; // Increase the size of the list

    printf("Updated list after inserting %d at position %d:\n", newNumber, position);
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}

