#include <stdio.h>
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
void printPascalTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoeff(i, j));
        }
        printf("\n");
    }
}
int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);
    printPascalTriangle(numRows);
    return 0;
}


output:
Enter the number of rows for Pascal's triangle: 4
   1
  1 1
 1 2 1
1 3 3 1

--------------------------------
Process exited after 2.885 seconds with return value 0
Press any key to continue . . .
