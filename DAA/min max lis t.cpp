#include <stdio.h>
#include <limits.h>

// Function to calculate the minimum digit in a number
int minDigit(int num) {
    int min = INT_MAX;
    while (num > 0) {
        int digit = num % 10;
        if (digit < min) {
            min = digit;
        }
        num /= 10;
    }
    return min;
}

// Function to calculate the maximum digit in a number
int maxDigit(int num) {
    int max = INT_MIN;
    while (num > 0) {
        int digit = num % 10;
        if (digit > max) {
            max = digit;
        }
        num /= 10;
    }
    return max;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Minimum and Maximum Value Sequences:\n");
    for (int i = 0; i < n; i++) {
        int num = numbers[i];
        int minSeq = minDigit(num);
        int maxSeq = maxDigit(num);

        printf("For %d: Minimum = %d, Maximum = %d\n", numbers[i], minSeq, maxSeq);
    }

    return 0;
}

