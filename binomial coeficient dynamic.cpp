#include <stdio.h>
unsigned long long binomialCoeff(int n, int k)
{
    unsigned long long C[n + 1][k + 1];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k && j <= i; j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}
int main()
{
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if (k > n) {
        printf("Invalid input: k must be less than or equal to n.\n");
        return 1;
    }
    printf("Binomial coefficient C(%d, %d) is %llu\n", n, k, binomialCoeff(n, k));
    return 0;
}

output:
Enter the value of n: 6
Enter the value of k: 3
Binomial coefficient C(6, 3) is 20

--------------------------------
Process exited after 2.143 seconds with return value 0
Press any key to continue . . .
