#include <stdio.h>
#define MAX_SIZE 100
void insertSorted(int arr[], int *size, int num) {
    int i, j;
    for (i = 0; i < *size; i++) {
        if (arr[i] > num)
            break;
    }
    for (j = *size; j > i; j--) {
        arr[j] = arr[j - 1];
    }
    arr[i] = num;
    (*size)++;
}
int main() {
    int arr[MAX_SIZE];
    int size, num, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter %d elements in ascending order: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    insertSorted(arr, &size, num);
    printf("Array after insertion: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
