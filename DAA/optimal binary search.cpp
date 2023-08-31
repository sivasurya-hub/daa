#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10

int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;
    int keys[MAX_KEYS];
    int freq[MAX_KEYS];

    printf("Enter the number of keys (up to %d): ", MAX_KEYS);
    scanf("%d", &n);

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    int minCost = optimalBST(keys, freq, n);

    printf("Minimum cost of optimal binary search tree: %d\n", minCost);

    return 0;
}


