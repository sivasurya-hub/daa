#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &val[i], &wt[i]);
    }

    int W;
    printf("Enter the maximum weight capacity: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);
    printf("Optimal cost: %d\n", result);

    return 0;
}

