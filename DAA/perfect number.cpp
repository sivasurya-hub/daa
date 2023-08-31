#include <stdio.h>

int isPerfectNumber(int num) {
    int sum = 1; // Initialize sum as 1 since 1 is always a divisor

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if (i * i != num) {
                sum += i + num / i;
            } else {
                sum += i;
            }
        }
    }

    return sum == num;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}

