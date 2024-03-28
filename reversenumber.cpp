#include <stdio.h>
int reverse(int num, int rev) {
    if (num == 0)
        return rev;
    return reverse(num / 10, rev * 10 + num % 10);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int reversedNum = reverse(num, 0);
    printf("Reverse of %d is %d\n", num, reversedNum);
    return 0;
}

output:
Enter a number: 5503
Reverse of 5503 is 3055

--------------------------------
Process exited after 4.936 seconds with return value 0
Press any key to continue . . .
