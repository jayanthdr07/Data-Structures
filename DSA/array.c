#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr;
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
	printf("Memory allocation failed.\n");
	return 1;
    }
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
	printf("Element %d: ", i + 1);
	scanf("%d", &arr[i]);
    }
    printf("\nThe entered array is:\n");
    for (i = 0; i < n; i++) {
	printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}