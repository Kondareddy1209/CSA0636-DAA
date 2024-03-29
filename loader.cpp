#include <stdio.h>
#include <stdbool.h>
#define MAX_ITEMS 100
#define MAX_CONTAINERS 100
int loadContainers(int items[], int n, int capacity) {
    int containers[MAX_CONTAINERS] = {0};
    int containerCount = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < containerCount; j++) {
            if (containers[j] >= items[i]) {
                containers[j] -= items[i];
                break;
            }
        }
        if (j == containerCount) {
            containerCount++;
            containers[j] = capacity - items[i];
        }
    }
    return containerCount;
}
int main() {
    int items[MAX_ITEMS], n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the dimensions of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }
    printf("Enter the capacity of each container: ");
    scanf("%d", &capacity);
    int containersNeeded = loadContainers(items, n, capacity);
    printf("Minimum number of containers needed: %d\n", containersNeeded);
    return 0;
}
