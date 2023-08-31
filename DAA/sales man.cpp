#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int tsp(int n, int graph[MAX_CITIES][MAX_CITIES], int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0]; // Return to starting city
    }

    int minCost = INT_MAX;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            int newMask = mask | (1 << city);
            int newCost = graph[pos][city] + tsp(n, graph, newMask, city);
            minCost = (newCost < minCost) ? newCost : minCost;
        }
    }

    return minCost;
}

int main() {
    int n;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the distance matrix (0 for same city, distance otherwise):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startCity = 0;
    int initialMask = 1 << startCity;

    int minCost = tsp(n, graph, initialMask, startCity);

    printf("Approximate minimum cost for the Traveling Salesman Problem: %d\n", minCost);

    return 0;
}

