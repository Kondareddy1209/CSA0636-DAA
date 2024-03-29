#include <stdio.h>
#include <limits.h>
#define N 4 
void branchAndBound(int costMatrix[N][N], int assigned[N], int worker, int cost, int *minCost) {
    if (worker == N) {
        if (cost < *minCost)
            *minCost = cost;
        return;
    }
    if (cost >= *minCost)
        return;
    for (int task = 0; task < N; task++) {
        if (!assigned[task]) {
            assigned[task] = 1;
            branchAndBound(costMatrix, assigned, worker + 1, cost + costMatrix[worker][task], minCost);
            assigned[task] = 0; // Backtrack
        }
    }
}
int main() {
    int costMatrix[N][N];
    int assigned[N] = {0}; 
    int minCost = INT_MAX;
    printf("Enter the cost matrix (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }
    branchAndBound(costMatrix, assigned, 0, 0, &minCost);
    printf("Minimum cost of assignment: %d\n", minCost);
    return 0;
}
