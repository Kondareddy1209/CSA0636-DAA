#include <stdio.h>
#define MAX_ITEMS 100
int max(int a, int b) {
    return (a > b) ? a : b;
}
int knapsack(int weights[], int profits[], int n, int capacity) {
    int dp[MAX_ITEMS + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}
int main() {
    int weights[MAX_ITEMS], profits[MAX_ITEMS];
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter weights and profits of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &weights[i], &profits[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    int maxProfit = knapsack(weights, profits, n, capacity);
    printf("Maximum profit: %d\n", maxProfit);
    return 0;
}
