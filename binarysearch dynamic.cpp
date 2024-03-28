#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}
void printOptimalBST(int root[], int i, int j, int level, int n)
{
    if (i > j) {
        printf("Level %d: Null\n", level);
        return;
    }
    int mid = root[i * n + j];
    printf("Level %d: %d\n", level, mid);
    printOptimalBST(root, i, mid - 1, level + 1, n);
    printOptimalBST(root, mid + 1, j, level + 1, n);
}
int optimalBST(int keys[], int freq[], int n)
{
    int cost[n][n];
    int root[n * n];
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i * n + i] = i;
    }
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i * n + j] = r;
                }
            }
        }
    }
    printf("Optimal BST structure:\n");
    printOptimalBST(root, 0, n - 1, 0, n);
    return cost[0][n - 1];
}
int main()
{
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    int keys[n], freq[n];
    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }
    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }
    printf("Cost of optimal BST is %d\n", optimalBST(keys, freq, n));
    return 0;
}


output:
Enter the number of keys: 4
Enter the keys:
10
20
2
4
Enter the frequencies:
1
2
3
6
Optimal BST structure:
Level 0: 2
Level 1: 1
Level 2: 0
Level 3: Null
Level 3: Null
Level 2: Null
Level 1: 3
Level 2: Null
Level 2: Null
Cost of optimal BST is 22

--------------------------------
Process exited after 17.94 seconds with return value 0
Press any key to continue . . .
