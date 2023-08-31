#include <stdio.h>

int main() {
    int num, originalNum, remainder, sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &num);

    originalNum = num;

    while (num > 0) {
        remainder = num % 10;
        sum += remainder;
        num /= 10;
    }

    printf("The sum of digits of %d is %d\n", originalNum, sum);

    return 0;
}

