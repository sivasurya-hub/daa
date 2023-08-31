#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

struct Container {
    int id;
    int capacity;
    int usedSpace;
};

struct Item {
    int id;
    int size;
    int weight;
};

void loadContainers(struct Container containers[], int numContainers, struct Item items[], int numItems) {
    for (int i = 0; i < numItems; i++) {
        for (int j = 0; j < numContainers; j++) {
            if (containers[j].usedSpace + items[i].size <= containers[j].capacity) {
                containers[j].usedSpace += items[i].size;
                printf("Item %d (size: %d, weight: %d) loaded into Container %d\n",
                       items[i].id, items[i].size, items[i].weight, containers[j].id);
                break;
            }
        }
    }
}

int main() {
    int numContainers, numItems;

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    struct Container containers[MAX_CONTAINERS];
    for (int i = 0; i < numContainers; i++) {
        printf("Enter capacity of Container %d: ", i + 1);
        scanf("%d", &containers[i].capacity);
        containers[i].id = i + 1;
        containers[i].usedSpace = 0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    struct Item items[MAX_ITEMS];
    for (int i = 0; i < numItems; i++) {
        printf("Enter size and weight of Item %d: ", i + 1);
        scanf("%d %d", &items[i].size, &items[i].weight);
        items[i].id = i + 1;
    }

    loadContainers(containers, numContainers, items, numItems);

    return 0;
}

