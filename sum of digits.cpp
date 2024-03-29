#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100
void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void findSubsets(int set[], int subset[], int n, int subsetSize, int sum, int targetSum, int k) {
    if (sum == targetSum) {
        printSubset(subset, subsetSize);
        findSubsets(set, subset, n, subsetSize - 1, sum - set[k], targetSum, k + 1);
        return;
    } else {
        for (int i = k; i < n; i++) {
            subset[subsetSize] = set[i];
            findSubsets(set, subset, n, subsetSize + 1, sum + set[i], targetSum, i + 1);
        }
    }
}
void sumOfSubsets(int set[], int n, int targetSum) {
    int subset[MAX_SIZE] = {0};
    findSubsets(set, subset, n, 0, 0, targetSum, 0);
}
int main() {
    int set[MAX_SIZE], n, targetSum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    printf("Subsets with sum %d are:\n", targetSum);
    sumOfSubsets(set, n, targetSum);
    return 0;
}