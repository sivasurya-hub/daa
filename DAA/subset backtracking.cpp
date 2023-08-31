#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isSubsetSumPossible(int set[], int n, int targetSum) {
    if (targetSum == 0)
        return true;

    if (n == 0)
        return false;

    if (set[n - 1] > targetSum)
        return isSubsetSumPossible(set, n - 1, targetSum);

    return isSubsetSumPossible(set, n - 1, targetSum) ||
           isSubsetSumPossible(set, n - 1, targetSum - set[n - 1]);
}

int main() {
    int n;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int set[MAX_SIZE];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    int targetSum;
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    if (isSubsetSumPossible(set, n, targetSum)) {
        printf("Subset with sum %d is possible.\n", targetSum);
    } else {
        printf("Subset with sum %d is not possible.\n", targetSum);
    }

    return 0;
}

