#include <stdio.h>
void printPattern(int n, int row, int col) {
    if (row > n)
        return;
    if (col <= row) {
        printf("%d ", col);
        printPattern(n, row, col + 1);
    } else {
        printf("\n");
        printPattern(n, row + 1, 1);
    }
}
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPattern(n, 1, 1);   
    return 0;
}


output:
Enter the value of n: 4
1
1 2
1 2 3
1 2 3 4

--------------------------------
Process exited after 1.153 seconds with return value 0
Press any key to continue . . .
