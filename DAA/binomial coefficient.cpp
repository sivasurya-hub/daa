#include <stdio.h>

int binomialCoeff(int n, int k) {
    int C[n + 1][k + 1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i && j <= k; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    
    return C[n][k];
}

int main() {
    int n, k;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    int result = binomialCoeff(n, k);
    printf("The binomial coefficient C(%d, %d) is %d\n", n, k, result);
    
    return 0;
}

