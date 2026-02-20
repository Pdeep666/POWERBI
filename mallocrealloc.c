#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i, newSize;

    // Step 1: Initial size input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Step 2: Allocate memory using malloc
    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Step 3: Input elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // Step 4: Increase size using realloc
    printf("Enter new size: ");
    scanf("%d", &newSize);

    ptr = (int *)realloc(ptr, newSize * sizeof(int));

    if (ptr == NULL) {
        printf("Reallocation failed!\n");
        return 1;
    }

    // Step 5: Input additional elements
    printf("Enter additional elements:\n");
    for (i = n; i < newSize; i++) {
        scanf("%d", &ptr[i]);
    }

    // Step 6: Display all elements
    printf("Final array elements:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", ptr[i]);
    }

    // Step 7: Free memory
    free(ptr);

    return 0;
}
