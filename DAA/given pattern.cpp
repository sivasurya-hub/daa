#include <stdio.h>

void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf("  ");
        }
        
        // Print numbers in ascending order
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
            if (j < i) {
                printf("   ");
            }
        }
        
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printPattern(n);

    return 0;
}

