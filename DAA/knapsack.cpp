#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    double ratio;
};

int compare(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    return (itemB->ratio - itemA->ratio); // Sort in non-increasing order of ratio
}

double fractionalKnapsack(int W, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            totalValue += (double)remainingWeight / items[i].weight * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    double maxValue = fractionalKnapsack(W, items, n);

    printf("Maximum value that can be obtained: %.2f\n", maxValue);

    return 0;
}

