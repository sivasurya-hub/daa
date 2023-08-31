#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 10 // Maximum number of workers/tasks

// Function to initialize cost matrix
void initializeCostMatrix(int costMatrix[N][N], int n) {
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }
}

// Function to find the minimum cost worker for a task
int findMinCostWorker(int costMatrix[N][N], bool assignedWorkers[N], int task, int n) {
    int minCost = INT_MAX;
    int minCostWorker = -1;
    
    for (int i = 0; i < n; i++) {
        if (!assignedWorkers[i] && costMatrix[i][task] < minCost) {
            minCost = costMatrix[i][task];
            minCostWorker = i;
        }
    }
    
    return minCostWorker;
}

// Recursive function to find minimum cost using branch and bound
int minCostAssignment(int costMatrix[N][N], bool assignedWorkers[N], int task, int currentCost, int n) {
    if (task == n) {
        return currentCost;
    }
    
    int minCost = INT_MAX;
    
    for (int worker = 0; worker < n; worker++) {
        if (!assignedWorkers[worker]) {
            assignedWorkers[worker] = true;
            int newCost = currentCost + costMatrix[worker][task];
            int subproblemCost = minCostAssignment(costMatrix, assignedWorkers, task + 1, newCost, n);
            minCost = (subproblemCost < minCost) ? subproblemCost : minCost;
            assignedWorkers[worker] = false;
        }
    }
    
    return minCost;
}

int main() {
    int n;
    printf("Enter the number of workers/tasks: ");
    scanf("%d", &n);

    int costMatrix[N][N];
    initializeCostMatrix(costMatrix, n);
    
    bool assignedWorkers[N];
    for (int i = 0; i < n; i++) {
        assignedWorkers[i] = false;
    }

    int totalMinCost = minCostAssignment(costMatrix, assignedWorkers, 0, 0, n);
    printf("Minimum cost of assignment: %d\n", totalMinCost);

    return 0;
}

