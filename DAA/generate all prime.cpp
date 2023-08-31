#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // If divisible, not a prime number
        }
    }

    return 1; // If not divisible by any number, it's a prime number
}

int main() {
    int limit;

    printf("Enter the upper limit: ");
    scanf("%d", &limit);

    printf("Prime numbers up to %d:\n", limit);
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

